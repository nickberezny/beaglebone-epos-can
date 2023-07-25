#include "motor.h"
#include "epos.h"

#include "socketcan/socketcan.h"
#include "socketcan/printd.h"
#include "canopen/canopen.h"


#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>



int motor_pdo_fd = -1; //!< Process CAN-connection.
int motor_cfg_fd = -1; //!< Configuration CAN-connection.


static int motor_config_node(uint16_t node, int32_t maxSpeed, int32_t maxAccel) {
	int err = 0;
	int num_PDOs;

	// Set Configuration parameters
	err |= epos_Maximal_Velocity(node, maxSpeed);
	if( err != 0 ) {
		printd(LOG_FATAL, "Motor: error configuring node %d, no power?\n", node);
		return err;
	}

	err |= epos_Maximal_Accel(node, maxAccel);

	if(err != 0) {
		printd(LOG_FATAL, "Motor: error configuring node %d.\n", node);
		return err;
	}


	// PDO cob id's
	err |= epos_Receive_PDO_n_Parameter(node, 1, PDO_RX1_ID + node);
	err |= epos_Receive_PDO_n_Parameter(node, 2, PDO_RX2_ID + node);
	err |= epos_Transmit_PDO_n_Parameter(node, 1, PDO_TX1_ID + node);
	err |= epos_Transmit_PDO_n_Parameter(node, 2, PDO_TX2_ID + node);


	/*** Communication, from pc to epos ***/

	// PDO RX1 target speed (used in profile pos mode)
	num_PDOs = 2;
	Epos_pdo_mapping target_pos[] = {
		{0x607A, 0x00, 32},   // Target Possition
		{0x6040, 0x00, 16}    // Controlword
	};
	err |= epos_Receive_PDO_n_Mapping(node, 1, num_PDOs, target_pos);

	// PDO RX2 targer velocity (used in profile vel mode)
	num_PDOs = 2;
	Epos_pdo_mapping target_vel[] = {
		{0x6071, 0x00, 16},  // Target Velocity 0x60ff
		{0x6040, 0x00, 16}   // Controlword
	};
	err |= epos_Receive_PDO_n_Mapping(node, 2, num_PDOs, target_vel);

	// Disable the rest
	err |= epos_Receive_PDO_n_Mapping(node, 3, 0, NULL);
	err |= epos_Receive_PDO_n_Mapping(node, 4, 0, NULL);


	/*** Communication, from epos to pc ***/

	// PDO TX1 Statusword
	num_PDOs = 1;
	Epos_pdo_mapping status[] = {
		{0x6041, 0x00, 16}   // Statusword
	};
	err |= epos_Transmit_PDO_n_Mapping(node, 1, num_PDOs, status);

	// PDO TX2 Position and speed
	num_PDOs = 2;
	Epos_pdo_mapping enc[] = {
		{0x6064, 0x00, 32},  // Position Actual value
		{0x606C, 0x00, 32}   // Velocity Actual value
	};
	err |= epos_Transmit_PDO_n_Mapping(node, 2, num_PDOs, enc);

	// Disable the rest
	err |= epos_Transmit_PDO_n_Mapping(node, 3, 0, NULL);
	err |= epos_Transmit_PDO_n_Mapping(node, 4, 0, NULL);


	return err;
}


int motor_init(int num_motors, int32_t maxSpeed, int32_t maxAccel, int* fds) {
	int err = 0;

	// Open two connections to the CAN-network

	uint16_t pdo_masks[2*num_motors];
	uint16_t pdo_filters[2*num_motors];

	for(int i = 0; i < 2*num_motors; i +=2 )
	{
		pdo_masks[i] =  COB_MASK;
		pdo_masks[i+1] = COB_MASK;
		pdo_filters[i] = PDO_TX1_ID + (i/2 + 1);
		pdo_filters[i+1] = PDO_TX2_ID + (i/2 + 1);
	}

/*
	uint16_t pdo_masks[4] = {COB_MASK, COB_MASK, COB_MASK, COB_MASK};
	uint16_t pdo_filters[4] = {
		PDO_TX1_ID + 1,
		PDO_TX2_ID + 1,
		PDO_TX1_ID + 2,
		PDO_TX2_ID + 2
	};
	*/

	motor_pdo_fd = socketcan_open(pdo_filters, pdo_masks, 2*num_motors);

	uint16_t cfg_masks[2*num_motors + 1];
	uint16_t cfg_filters[2*num_motors + 1];

	cfg_masks[0] = COB_MASK;
	cfg_filters[0] = 0x00;

	for(int i = 0; i < 2*num_motors+1; i +=2 )
	{
		pdo_masks[i+1] =  COB_MASK;
		pdo_masks[i+2] = COB_MASK;
		pdo_filters[i+1] = PDO_TX1_ID + (i/2 + 1);
		pdo_filters[i+2] = PDO_TX2_ID + (i/2 + 1);
	}

	/*
	uint16_t cfg_masks[5] = {COB_MASK, COB_MASK, COB_MASK, COB_MASK, COB_MASK};
	uint16_t cfg_filters[5] = {
		0x00,
		NMT_TX + 1,
		SDO_TX + 1,
		NMT_TX + 2,
		SDO_TX + 2
	};
	*/
	motor_cfg_fd = socketcan_open(cfg_filters, cfg_masks, 2*num_motors + 1);

	// Check that we connected OK
	if (motor_pdo_fd == -1 || motor_cfg_fd == -1) {
		return MOTOR_ERROR;
	}

	// Configure each node
	err |= NMT_change_state(motor_cfg_fd, CANOPEN_BROADCAST_ID, NMT_Enter_PreOperational);
	if (err != 0) {
		return MOTOR_ERROR;
	}

	for(int i = 0; i < num_motors; i++)
	{
		err |= motor_config_node(i+1,maxSpeed,maxAccel);
		if (err != 0) {
			return MOTOR_ERROR;
		}
	}
	

	// Set the default mode
	motor_setmode(Motor_mode_Torque, num_motors);
	if (err != 0) {
		return MOTOR_ERROR;
	}

	fds[0] = motor_cfg_fd;
	fds[1] = motor_pdo_fd;

	return 0;
}


void motor_close(void) {
	socketcan_close(motor_pdo_fd);
	socketcan_close(motor_cfg_fd);
}


int motor_enable(int cfg_fd, int num_motors) {
	int err = 0;
	err |= NMT_change_state(cfg_fd, CANOPEN_BROADCAST_ID, NMT_Enter_PreOperational); // switch_on_disabled -> switch_on_enabled
	for(int i = 0; i < num_motors; i++)
	{
		err |= epos_Controlword(i+1, Shutdown);
		err |= epos_Controlword(i+1, Switch_On_And_Enable_Operation);
	}
	


	// Open PDO-communication
	err |= NMT_change_state(cfg_fd, CANOPEN_BROADCAST_ID, NMT_Start_Node);

	return err;
}


int motor_disable(int cfg_fd, int num_motors) {
	int err = 0;

	// Stop PDO-communication
	err |= NMT_change_state(cfg_fd, CANOPEN_BROADCAST_ID, NMT_Enter_PreOperational);
	for(int i = 0; i < num_motors; i++)
	{
		err |= epos_Controlword(i+1, Disable_Voltage);
	}
	//err |= NMT_change_state(cfg_fd, CANOPEN_BROADCAST_ID, NMT_Stop_Node);

	return err;
}


int motor_halt(int cfg_fd, int num_motors) {
	int err = 0;

	// Stop PDO-communication
	err |= NMT_change_state(cfg_fd, CANOPEN_BROADCAST_ID, NMT_Enter_PreOperational);
	for(int i = 0; i < num_motors; i ++)
	{
		err |= epos_Controlword(i+1, Quickstop);
	}
	
	//err |= NMT_change_state(cfg_fd, CANOPEN_BROADCAST_ID, NMT_Stop_Node);

	return err;
}


int motor_setmode(enum Motor_mode mode, int num_motors) {
	int err = 0;
	for(int i = 0; i<num_motors; i++)
	{
		err |= epos_Modes_of_Operation(i+1, (enum Epos_mode)mode);
	}

	return err;
}


