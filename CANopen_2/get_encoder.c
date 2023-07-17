#include "socketcan/socketcan.h"
#include "motor/epos.h"
#include "motor/motor.h"
#include "canopen/PDO.h"

#include <inttypes.h>
#include <math.h>
#include <stdio.h>

double get_encoder(int fd, int dt)
{
	int32_t pos = 0;
	if(dt > 40)
	{
		printf("fd (get encoder): %d\n",fd);

		const int timeout = 1;
		my_can_frame f;

		int ret = PDO_read(fd, &f, timeout);
		printf("PDO ret: %d\n", ret);

		

		if(f.id == PDO_TX2_ID + MOTOR_EPOS_R_ID)
		{
			int32_t pos = ((uint32_t)f.data[0]<<0) | ((uint32_t)f.data[1]<<8) | ((uint32_t)f.data[2]<<16) | ((uint32_t)f.data[3]<<24);
			int32_t vel = ((uint32_t)f.data[4]<<0) | ((uint32_t)f.data[5]<<8) | ((uint32_t)f.data[6]<<16) | ((uint32_t)f.data[7]<<24);
			printf("Position: %d\n", pos);
		}
	
	}
	
	return (double)pos;
}