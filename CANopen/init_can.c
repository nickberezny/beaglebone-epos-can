#include "init_can.h"
#include "epos.h"

#include "socketcan/socketcan.h"
#include "socketcan/printd.h"
#include "canopen/canopen.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

static int motor_config_node(int fd, uint16_t node) {
	int err = 0;
	int num_PDOs;

	/*** Communication, from pc to epos ***/
	err |= epos_Maximal_Profile_Velocity(node, MOTOR_MAX_SPEED);

	// PDO RX1 target current
	num_PDOs = 2;
	Epos_pdo_mapping target_pos[] = {
		{0x6071, 0x00, 32},   // Target Current
		{0x6040, 0x00, 16}    // Controlword
	};
	err |= epos_Receive_PDO_n_Mapping(fd, node, 1, num_PDOs, target_pos);

	// Disable the rest
	err |= epos_Receive_PDO_n_Mapping(fd, node, 3, 0, NULL);
	err |= epos_Receive_PDO_n_Mapping(fd, node, 4, 0, NULL);


	/*** Communication, from epos to pc ***/

	// PDO TX1 Statusword
	num_PDOs = 1;
	Epos_pdo_mapping status[] = {
		{0x6041, 0x00, 16}   // Statusword
	};
	err |= epos_Transmit_PDO_n_Mapping(fd, node, 1, num_PDOs, status);

	// PDO TX2 Position and speed
	num_PDOs = 2;
	Epos_pdo_mapping enc[] = {
		{0x6064, 0x00, 32},  // Position Actual value
		{0x606C, 0x00, 32}   // Velocity Actual value
	};
	err |= epos_Transmit_PDO_n_Mapping(fd, node, 2, num_PDOs, enc);

	// Disable the rest
	err |= epos_Transmit_PDO_n_Mapping(fd, node, 3, 0, NULL);
	err |= epos_Transmit_PDO_n_Mapping(fd, node, 4, 0, NULL);


	return err;
}

int motor_setmode(int fd, enum Motor_mode mode) {
	int err = 0;
	err |= epos_Modes_of_Operation(fd, MOTOR_EPOS_ID, (enum Epos_mode)mode);
	return err;
}


int init_can()
{
	int fd = -1;
	//open socket

	int err = 0;

	// Open two connections to the CAN-network
	uint16_t pdo_masks[2] = {COB_MASK, COB_MASK};
	uint16_t pdo_filters[2] = {
		PDO_TX1_ID + MOTOR_EPOS_ID,
		PDO_TX2_ID + MOTOR_EPOS_ID
	};
	fd = socketcan_open(pdo_filters, pdo_masks, 2);

	// Check that we connected OK
	if (fd == -1) {
		return MOTOR_ERROR;
	}

	printf("fd: %d\n",fd);

	// Configure each node
	err |= NMT_change_state(fd, CANOPEN_BROADCAST_ID, NMT_Enter_PreOperational);
	if (err != 0) {
		return MOTOR_ERROR;
	}


	err |= motor_config_node(fd, MOTOR_EPOS_ID);
	if (err != 0) {
		return MOTOR_ERROR;
	}

	
	// Set the default mode (torque)
	motor_setmode(fd, Motor_mode_Torque);
	if (err != 0) {
		return MOTOR_ERROR;
	}
	

	return fd;
}