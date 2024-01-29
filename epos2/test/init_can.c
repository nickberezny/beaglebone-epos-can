#include "socketcan/socketcan.h"
#include "canopen/canopen.h"
#include "motor/motor.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdbool.h>


int init_can(){

	motor_init();
	motor_enable();
	sleep(1);

	printf("init_can %d\n", motor_pdo_fd);


	return 0;
}

