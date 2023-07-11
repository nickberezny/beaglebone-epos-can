#include "set_motor.h"
#include "epos.h"
#include "canopen/PDO.h"

#include <inttypes.h>
#include <math.h>

void set_motor(int fd, double set_val)
{
	printf("Set torque: %d\n", (int)set_val);
	PDO_send(fd, PDO_TX1_ID+MOTOR_EPOS_R_ID, 2, (int)set_val);

	return;
}