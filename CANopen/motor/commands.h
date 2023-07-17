#include <inttypes.h>

static int set_torque(int16_t set, uint16_t nodeid);
int vel_read(int32_t* pos_left, int32_t* vel_left, int32_t* pos_right, int32_t* vel_right, int timeout);