#include "commands.h"
#include "motor.h"
#include "epos.h"
#include "../canopen/PDO.h"

#include<stdio.h>
#include <inttypes.h>
#include <math.h>

#include "socketcan/printd.h"
#include "canopen/canopen.h"

int set_torque(int pdo_id, int16_t set, uint16_t nodeid) {
	int err = 0;
	const int16_t rpm = 100;//set;
	Socketcan_t target_vel[2] = {
		{2, rpm},
		{2, Switch_On_And_Enable_Operation}
	};

	err = PDO_send(pdo_id, PDO_RX2_ID + nodeid, 2, target_vel);
	return err;
}

int vel_read(int32_t* pos_left, int32_t* vel_left, int32_t* pos_right,
             int32_t* vel_right, int timeout) {

	int err;
	int status = 0;

	my_can_frame f;
	err = PDO_read(motor_pdo_fd, &f, timeout);

	if(err != 0) {
		return err;
	}

	uint32_t enc, rpm;
	switch(f.id) {
		case(PDO_TX1_ID + MOTOR_EPOS_R_ID):
			status = (f.data[0]<<0) | (f.data[1]<<8);
			break;
		case(PDO_TX1_ID + MOTOR_EPOS_L_ID):
			status = (f.data[0]<<0) | (f.data[1]<<8);
			break;
		case(PDO_TX2_ID + MOTOR_EPOS_R_ID):
			enc = ((uint32_t)f.data[0]<<0) | ((uint32_t)f.data[1]<<8) | ((uint32_t)f.data[2]<<16) | ((uint32_t)f.data[3]<<24);
			rpm = ((uint32_t)f.data[4]<<0) | ((uint32_t)f.data[5]<<8) | ((uint32_t)f.data[6]<<16) | ((uint32_t)f.data[7]<<24);
			*pos_right = enc;//motor_enc_to_mm(enc);
			*vel_right = rpm;//motor_rpm_to_mmsec(rpm);
			printf("right! %d, %d\n", (int)rpm, (int)enc);
			break;
		case(PDO_TX2_ID + MOTOR_EPOS_L_ID):
			enc = ((uint32_t)f.data[0]<<0) | ((uint32_t)f.data[1]<<8) | ((uint32_t)f.data[2]<<16) | ((uint32_t)f.data[3]<<24);
			rpm = ((uint32_t)f.data[4]<<0) | ((uint32_t)f.data[5]<<8) | ((uint32_t)f.data[6]<<16) | ((uint32_t)f.data[7]<<24);
			*pos_left = -enc;//motor_enc_to_mm(-enc);
			*vel_left = -rpm;//motor_rpm_to_mmsec(-rpm);
			break;
		default:
			printd(LOG_WARN, "motor/vel.c recived unkown PDO pkg 0x%x\n", f.id);
			break;
	}

	if(status & 0x08) {
		// The epos reported an error
		printd(LOG_ERROR, "The epos %d reported an error! status=0x%x\n", f.id-PDO_TX1_ID, status);
		return -11;  // TODO: uniq error codes
	} else if(status & 0x80) {
		// The epos reported an warning
		printd(LOG_ERROR, "The epos %d reported an warning! status=0x%x\n", f.id-PDO_TX1_ID, status);
		return -12;
	}

	return 0;
}
