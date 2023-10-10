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



void read_write(int pdo_id, int num_motor, double* set_val, double* pos)
{
	for(int i = 0; i < num_motor; i++)
	{
		set_torque(pdo_id, (int)set_val[i], i);
	}

	for(int i = 0; i < num_motor; i++)
		pos[i] = 0.0;

	vel_read(pdo_id, num_motor, pos, 10);
	
	return;
}

