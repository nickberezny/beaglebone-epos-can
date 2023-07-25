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



void stop_motor(int cfg_fd, int num_motors)
{
	printf("test pdo: %d\n", motor_cfg_fd);
	motor_halt(cfg_fd,num_motors);
	sleep(0.5);
	printf("enabled? %d\n",motor_enable(cfg_fd,num_motors));
	return;
}

void e_stop(int cfg_fd, int num_motors)
{
	stop_motor(cfg_fd, num_motors);
	motor_disable(cfg_fd,num_motors);
	return;
}

