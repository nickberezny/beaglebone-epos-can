#include <inttypes.h>
#include "socketcan/socketcan.h"

int sort_read(int size, double* pos, my_can_frame f, int * num_of_reads, int * num_of_breaks);
int set_torque(int pdo_id, int16_t set, uint16_t nodeid);
int vel_read(int pdo_id, int size, double* pos, int timeout);