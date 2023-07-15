#include "socketcan/socketcan.h"
#include "motor/epos.h"
#include "motor/motor.h"
#include "canopen/PDO.h"

#include <inttypes.h>
#include <math.h>
#include <stdio.h>

double get_encoder(int fd, int dt)
{
	int32_t pos_left;
	int32_t vel_left;
	int32_t pos_right;
	int32_t vel_right;
	int32_t pos = 0;

	printf("encoder %d\n", motor_pdo_fd);

	if(dt > 40)
	{
		vel_read(&pos_left, &vel_left, &pos_right, &vel_right, 10);
		//vel_read(&pos_left, &vel_left, &pos_right, &vel_right, 1000);
		//vel_read(&pos_left, &vel_left, &pos_right, &vel_right, 1000);
		//vel_read(&pos_left, &vel_left, &pos_right, &vel_right, 1000);

		pos = pos_right;
	}

	printf("pos: %d\n", pos);
	
	return (double)pos;
}