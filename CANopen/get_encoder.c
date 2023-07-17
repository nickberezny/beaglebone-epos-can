#include "socketcan/socketcan.h"
#include "motor/epos.h"
#include "motor/motor.h"
#include "motor/commands.h"
#include "canopen/PDO.h"

#include <inttypes.h>
#include <math.h>
#include <stdio.h>

double get_encoder(int pdo_id)
{
	int32_t pos_left;
	int32_t vel_left;
	int32_t pos_right;
	int32_t vel_right;
	int32_t pos = 0;

	vel_read(pdo_id, &pos_left, &vel_left, &pos_right, &vel_right, 10);
	pos = pos_right;

	return (double)pos;
}