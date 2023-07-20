#include "socketcan/socketcan.h"
#include "canopen/canopen.h"
#include "motor/motor.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdbool.h>


int init_can(double maxSpeed, double maxAccel){

	motor_init((int)maxSpeed, (int)maxAccel);
	motor_enable();

	return motor_pdo_fd;
}

