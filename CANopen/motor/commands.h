#include <inttypes.h>

int set_torque(int pdo_id, int16_t set, uint16_t nodeid);
int vel_read(int pdo_id, int size, int32_t* pos, int timeout);