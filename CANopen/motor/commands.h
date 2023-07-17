#include <inttypes.h>

int sort_read(int32_t* pos, my_can_frame f, int * num_of_reads);
int set_torque(int pdo_id, int16_t set, uint16_t nodeid);
int vel_read(int pdo_id, int size, int32_t* pos, int timeout);