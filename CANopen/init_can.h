#include <inttypes.h>

#define MOTOR_EPOS_ID 0x01
#define MOTOR_ERROR   (-1)
#define MOTOR_TIMEOUT (-2)

enum Motor_mode {
	Motor_mode_Velocity = 3,
	Motor_mode_Torque = 10,
};

static int motor_config_node(int fd, uint16_t node);
int motor_setmode(enum Motor_mode mode);
int init_can();