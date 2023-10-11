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



extern void read_write(int pdo_id, int num_motor, double t, double* val)
{
	printf("time: %f\n",t);
	for(int i = 0; i < num_motor; i++)
	{
		set_torque(pdo_id, (int)val[i+num_motor], i+1);
	}

	for(int i = 0; i < num_motor; i++)
		val[i] = 0.0;

	vel_read(pdo_id, num_motor, val, 10);
	
	return;
}

