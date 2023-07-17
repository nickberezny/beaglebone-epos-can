#include "socketcan/socketcan.h"
#include "canopen/canopen.h"
#include "motor/motor.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdbool.h>


int init_can(int id){

	motor_init(id);
	motor_enable(id);

	return motor_pdo_fd;
}

