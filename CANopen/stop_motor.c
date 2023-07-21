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



void stop_motor()
{
	epos_Controlword(1, Quickstop);
	epos_Controlword(2, Quickstop);
	return;
}

