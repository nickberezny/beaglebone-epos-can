#include "set_motor.h"
#include "motor/epos.h"
#include "motor/motor.h"
#include "canopen/PDO.h"

#include <inttypes.h>
#include <math.h>

void set_motor(int fd, double set_val)
{
	printf("Set torque: %d\n", (int)set_val);
	//PDO_send(fd, PDO_TX1_ID+MOTOR_EPOS_R_ID, 2, (int)set_val);
	//vel_set_speed_right((int)set_val);
	PDO_send(motor_pdo_fd, PDO_RX2_ID + MOTOR_EPOS_R_ID, 2, (int)set_val);
	return;
}