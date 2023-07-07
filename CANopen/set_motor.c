#include "set_motor.h"
#include "epos.h"
#include "canopen/PDO.h"

#include <inttypes.h>
#include <math.h>

void set_motor(int fd, double set_val)
{

	PDO_send(fd, PDO_TX1_ID+MOTOR_EPOS_ID, 2, set_val);

	return;
}