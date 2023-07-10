#include "init_can.h"

#include "socketcan/socketcan.h"
#include "socketcan/printd.h"
#include "canopen/canopen.h"
#include "motor/motor.h"
#include "motor/epos.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>


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