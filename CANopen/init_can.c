#include "socketcan/socketcan.h"
#include "canopen/canopen.h"
#include "motor/motor.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdbool.h>


extern void init_can(int num_motors, double maxSpeed, double maxAccel, int* fds){

	motor_init(num_motors, (int)maxSpeed, (int)maxAccel, fds);
	motor_enable(num_motors);

	return;
}

