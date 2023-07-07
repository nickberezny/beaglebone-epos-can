#define MOTOR_EPOS_ID 0x01

static int motor_config_node(uint16_t node);
int motor_setmode(enum Motor_mode mode);
int init_can();