#include "set_motor.h"
#include "motor/epos.h"
#include "motor/motor.h"
#include "motor/commands.h"
#include "canopen/PDO.h"

#include <inttypes.h>
#include <math.h>

#include<stdio.h>

#include "socketcan/printd.h"
#include "socketcan/socketcan.h"
#include "canopen/canopen.h"



void set_motor(int pdo_id, double set_val)
{
	set_torque(pdo_id, (int)set_val, MOTOR_EPOS_R_ID);
	return;
}

