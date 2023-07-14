#include "socketcan/socketcan.h"
#include "canopen/canopen.h"
#include "motor/motor.h"
#include "init_can.h"
#include "get_encoder.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdbool.h>



int init_can()
{
	int fd = motor_init();
	printf("init: %d\n",fd);
	printf("enable: %d\n",motor_enable());
	sleep(1);

	for(int i = 0; i < 10; i++)
	{
		get_encoder(fd,1000);
		sleep(1);
	}
	

	return fd;
}