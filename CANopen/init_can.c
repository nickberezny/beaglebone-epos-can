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
	motor_enable(fds[0], num_motors);

	printf("sdo_fd %d\n", fds[0]);
	printf("pdo_fd %d\n", fds[1]);

	return;
}

