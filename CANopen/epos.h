#ifndef EPOS_H
#define EPOS_H

#include <inttypes.h>

/**
 * All functions return 0 on success and error codes as defined by SDO_write in
 * libsocketcan on error.
 * */

//uint8_t epos_Error_Register(uint16_t node_id);

int epos_Receive_PDO_n_Parameter(int fd, uint16_t node_id, uint8_t n, uint32_t cob);

typedef struct {
	uint16_t index;
	uint8_t subindex;
	uint8_t length;
} Epos_pdo_mapping;

int epos_Receive_PDO_n_Mapping(int fd, uint16_t node_id, uint8_t n, uint8_t num_objects, Epos_pdo_mapping* objects);

int epos_Transmit_PDO_n_Parameter(int fd, uint16_t node_id, uint8_t n, uint32_t cob);

int epos_Transmit_PDO_n_Mapping(int fd, uint16_t node_id, uint8_t n, uint8_t num_objects, Epos_pdo_mapping* objects);

enum Epos_misc_conf {
	Disable_sensor_supervised_by_software = (1<<0),
	Disable_sensor_supervised_by_hardware = (1<<1),
	Meassure_DC_motor_resistance_at_every_change_to_enable = (1<<2),
	Meassure_main_position_sensors_motor_speed_exacting_by_detecting_encoder_pulse_time = (1<<3),
	Meassure_auxiliary_position_sensors_motor_speed_exacting_by_detecting_encoder_pulse_time = (1<<4),
	Polarity_bit = (1<<8)
};


enum Epos_ctrl {
	Shutdown = 0x06,
	Switch_On = 0x07,
	Switch_On_And_Enable_Operation = 0x0f,
	Disable_Voltage = 0x00,
	Quickstop = 0x02,
	Disable_Operation = 0x07,
	Enable_Operation = 0x0f,
};

// Operatin Mode-specific
/*Profile_Position_New_Setpoint = (1<<4),
Profile_Position_Change_Set_Immediately = (1<<5),
Profile_Position_Relative = (1<<6),
Profile_Position_Halt = (1<<8)*/


enum Epos_mode {
	Interpolated_Position_Mode = 7,
	Homing_Mode = 6,
	Profile_Velocity_Mode = 3,
	Profile_Position_Mode = 1,
	Position_Mode = -1,
	Velocity_Mode = -2,
	Current_Mode = -3,
	Diagnostic_Mode = -4,
	Master_Encoder_Mode = -5,
	Step_Direction_Mode = -6
};

int epos_Modes_of_Operation(int fd, uint16_t node_id, enum Epos_mode mode);



#endif
