#include "commands.h"
#include "motor.h"
#include "epos.h"
#include "../canopen/PDO.h"

#include <stdio.h>
#include <inttypes.h>
#include <math.h>

#include "socketcan/printd.h"
#include "socketcan/socketcan.h"
#include "canopen/canopen.h"

int set_torque(int pdo_id, int16_t set, uint16_t nodeid) {
	int err = 0;
	const int16_t rpm = set;
	Socketcan_t target_vel[2] = {
		{2, rpm},
		{2, Switch_On_And_Enable_Operation}
	};

	err = PDO_send(pdo_id, PDO_RX2_ID + nodeid, 2, target_vel);
	return err;
}

int vel_read(int pdo_id, int size, double* pos, int timeout) {

	int err = 0;
	int status = 0;
	int num_of_reads = 0;
	my_can_frame f;

	while(num_of_reads < size)
	{
		printf("f.id %d, num reads %d\n", f.id, num_of_reads);
		err = PDO_read(pdo_id, &f, timeout);
		sort_read(pos, f, &num_of_reads);
	}

	if(err != 0) {
		return err;
	}


	return 0;
}


int sort_read(double* pos, my_can_frame f, int * num_of_reads)
{
	uint32_t enc;

	switch(f.id) {
		case(PDO_TX2_ID + 1):
			enc = ((uint32_t)f.data[0]<<0) | ((uint32_t)f.data[1]<<8) | ((uint32_t)f.data[2]<<16) | ((uint32_t)f.data[3]<<24);
			pos[0] = (double)enc;//motor_enc_to_mm(enc);
			*num_of_reads = *num_of_reads + 1;
			printf("Node 1: %d\n", enc);
			break;
		case(PDO_TX2_ID + 2):
			enc = ((uint32_t)f.data[0]<<0) | ((uint32_t)f.data[1]<<8) | ((uint32_t)f.data[2]<<16) | ((uint32_t)f.data[3]<<24);
			pos[1] = (double)enc;//motor_enc_to_mm(-enc);
			*num_of_reads = *num_of_reads + 1;
			printf("Node 2: %d\n", enc);
			break;
		default:
			break;
	}

	return 0;

}