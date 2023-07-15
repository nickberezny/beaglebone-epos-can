#include "set_motor.h"
#include "motor/epos.h"
#include "motor/motor.h"
#include "canopen/PDO.h"

#include <inttypes.h>
#include <math.h>

#include<stdio.h>

#include "socketcan/printd.h"
#include "canopen/canopen.h"


static int set_torque(int16_t set, uint16_t nodeid) {
	int err = 0;
	const int16_t rpm = set;
	Socketcan_t target_vel[2] = {
		{2, rpm},
		{2, Switch_On_And_Enable_Operation}
	};

	err = PDO_send(motor_pdo_fd, PDO_RX2_ID + nodeid, 2, target_vel);
	return err;
}

void set_motor(int fd, double set_val)
{
	printf("Set torque: %d\n", (int)set_val);
	//PDO_send(fd, PDO_TX1_ID+MOTOR_EPOS_R_ID, 2, (int)set_val);
	//vel_set_speed_right((int)set_val);
	set_torque((int)set_val, MOTOR_EPOS_R_ID);
	return;
}

