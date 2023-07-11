#include "socketcan/socketcan.h"
#include "motor/epos.h"
#include "canopen/PDO.h"

#include <inttypes.h>
#include <math.h>

double get_encoder(int fd)
{
	const int timeout = 1000;
	my_can_frame f;

	int ret = PDO_read(fd, &f, timeout);

	int32_t pos = ((uint32_t)f.data[0]<<0) | ((uint32_t)f.data[1]<<8) | ((uint32_t)f.data[2]<<16) | ((uint32_t)f.data[3]<<24);
	int32_t vel = ((uint32_t)f.data[4]<<0) | ((uint32_t)f.data[5]<<8) | ((uint32_t)f.data[6]<<16) | ((uint32_t)f.data[7]<<24);

	printf("Position: %d\n", pos);
	return (double)pos;
}