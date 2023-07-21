#include "socketcan/socketcan.h"
#include "canopen/canopen.h"
#include "motor/motor.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdbool.h>


extern void init_can(double maxSpeed, double maxAccel, int* fds){

	motor_init((int)maxSpeed, (int)maxAccel, fds);
	motor_enable();

	return;
}

