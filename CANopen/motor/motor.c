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


static int motor_config_node(uint16_t node) {
	int err = 0;
	int num_PDOs;

	// Set Configuration parameters
	err |= epos_Maximal_Profile_Velocity(node, 5000);
	if( err != 0 ) {
		printd(LOG_FATAL, "Motor: error configuring node %d, no power?\n", node);
		return err;
	}
	err |= epos_Quickstop_Deceleration(node,10000);
	err |= epos_Profile_Acceleration(node, 5000);
	err |= epos_Profile_Deceleration(node, 5000);
	err |= epos_Motion_Profile_Type(node, trapezodial_profile);
	//err |= epos_Miscellaneous_Configuration(node, Meassure_main_position_sensors_motor_speed_exacting_by_detecting_encoder_pulse_time);
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


int motor_init() {
	int err = 0;

	// Open two connections to the CAN-network
	uint16_t pdo_masks[4] = {COB_MASK, COB_MASK, COB_MASK, COB_MASK};
	uint16_t pdo_filters[4] = {
		PDO_TX1_ID + 1,
		PDO_TX2_ID + 1,
		PDO_TX1_ID + 2,
		PDO_TX2_ID + 2
	};
	motor_pdo_fd = socketcan_open(pdo_filters, pdo_masks, 2);

	uint16_t cfg_masks[5] = {COB_MASK, COB_MASK, COB_MASK, COB_MASK, COB_MASK};
	uint16_t cfg_filters[5] = {
		0x00,
		NMT_TX + 1,
		SDO_TX + 1,
		NMT_TX + 2,
		SDO_TX + 2
	};
	motor_cfg_fd = socketcan_open(cfg_filters, cfg_masks, 3);

	// Check that we connected OK
	if (motor_pdo_fd == -1 || motor_cfg_fd == -1) {
		return MOTOR_ERROR;
	}

	printf("fd: %d\n",motor_pdo_fd);

	// Configure each node
	err |= NMT_change_state(motor_cfg_fd, CANOPEN_BROADCAST_ID, NMT_Enter_PreOperational);
	if (err != 0) {
		return MOTOR_ERROR;
	}


	err |= motor_config_node(1);
	if (err != 0) {
		return MOTOR_ERROR;
	}

	err |= motor_config_node(2);
	if (err != 0) {
		return MOTOR_ERROR;
	}

	// Set the default mode
	motor_setmode(Motor_mode_Torque);
	if (err != 0) {
		return MOTOR_ERROR;
	}

	return 0;
}


void motor_close(void) {
	socketcan_close(motor_pdo_fd);
	socketcan_close(motor_cfg_fd);
}


int motor_enable() {
	int err = 0;
	err |= NMT_change_state(motor_cfg_fd, CANOPEN_BROADCAST_ID, NMT_Enter_PreOperational); // switch_on_disabled -> switch_on_enabled
	err |= epos_Controlword(1, Shutdown);
	err |= epos_Controlword(1, Switch_On_And_Enable_Operation);
	err |= epos_Controlword(2, Shutdown);
	err |= epos_Controlword(2, Switch_On_And_Enable_Operation);

	// Open PDO-communication
	err |= NMT_change_state(motor_cfg_fd, CANOPEN_BROADCAST_ID, NMT_Start_Node);

	return err;
}


int motor_disable(void) {
	int err = 0;

	// Stop PDO-communication
	err |= NMT_change_state(motor_cfg_fd, CANOPEN_BROADCAST_ID, NMT_Enter_PreOperational);
	err |= epos_Controlword(MOTOR_EPOS_R_ID, Disable_Voltage);
	err |= NMT_change_state(motor_cfg_fd, CANOPEN_BROADCAST_ID, NMT_Stop_Node);

	return err;
}


int motor_halt(void) {
	int err = 0;

	// Stop PDO-communication
	err |= NMT_change_state(motor_cfg_fd, CANOPEN_BROADCAST_ID, NMT_Enter_PreOperational);
	err |= epos_Controlword(MOTOR_EPOS_R_ID, Quickstop);
	err |= NMT_change_state(motor_cfg_fd, CANOPEN_BROADCAST_ID, NMT_Stop_Node);

	return err;
}


int motor_setmode(enum Motor_mode mode) {
	int err = 0;
	err |= epos_Modes_of_Operation(MOTOR_EPOS_R_ID, (enum Epos_mode)mode);
	return err;
}


