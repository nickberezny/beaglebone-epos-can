#include "socketcan/socketcan.h"
#include "motor/epos.h"
#include "motor/motor.h"
#include "motor/commands.h"
#include "canopen/PDO.h"

#include <inttypes.h>
#include <math.h>
#include <stdio.h>

extern void get_encoder(int pdo_id, int size, double* pos)
{

	vel_read(pdo_id, size, pos, 10);

	return;
}