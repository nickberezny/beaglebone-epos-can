#include <inttypes.h>

int set_torque(int pdo_id, int16_t set, uint16_t nodeid);
int vel_read(int pdo_id, int32_t* pos_left, int32_t* vel_left, int32_t* pos_right, int32_t* vel_right, int timeout);