#include "epos.h"

#include "canopen/canopen.h"

/*
uint8_t epos_Error_Register(uint16_t node_id) {
	SDO_data d;
	d.nodeid = node_id;
	d.index = 0x1001;
	d.subindex = 0x00;
	d.data.size = SDO_type_uint8;
	SDO_read(motor_cfg_fd, &d);
	return *(d.data.uint8_p);
}
*/


int epos_Receive_PDO_n_Parameter(int fd, uint16_t node_id, uint8_t n, uint32_t cob) {
	SDO_data d;
	d.nodeid = node_id;
	//d.index = 0x1400 + n-1;
	//d.subindex = 0x01;
	d.index = 0x1000;
	d.subindex = 0x00;
	d.data.size = 4;
	d.data.data = cob;
	return SDO_write(fd, &d);
}


int epos_Receive_PDO_n_Mapping(int fd, uint16_t node_id,  uint8_t n, uint8_t num_objects, Epos_pdo_mapping* objects) {
	int err = 0;

	// Set number of objects to zero
	SDO_data d;
	d.nodeid = node_id;
	d.index = 0x1600 + n-1;
	d.subindex = 0x00;
	d.data.size = 1;
	d.data.data = 0;

	err = SDO_write(fd, &d);
	if (err != 0) {
		return err;
	}

	// Write objects
	d.data.size = 4;
	for(int i=0; i<num_objects; i++) {
		Epos_pdo_mapping obj = objects[i];

		d.subindex = i+1;
		d.data.data = ((uint32_t)obj.index << 16) | (obj.subindex<<8) | (obj.length);
		err = SDO_write(motor_cfg_fd, &d);
		if (err != 0) {
			return err;
		}
	}

	// Set Correct number of objects
	d.subindex = 0x00;
	d.data.size = 1;
	d.data.data = num_objects;
	return SDO_write(motor_cfg_fd, &d);
}


int epos_Transmit_PDO_n_Parameter(int fd, uint16_t node_id, uint8_t n, uint32_t cob) {
	SDO_data d;
	d.nodeid = node_id;
	d.index = 0x1800 + n-1;
	d.subindex = 0x01;
	d.data.size = 4;
	d.data.data = cob;
	return SDO_write(fd, &d);
}


int epos_Transmit_PDO_n_Mapping(int fd, uint16_t node_id, uint8_t n, uint8_t num_objects, Epos_pdo_mapping* objects) {
	int err = 0;

	// Set number of objects to zero
	SDO_data d;
	d.nodeid = node_id;
	d.index = 0x1A00 + n-1;
	d.subindex = 0x00;
	d.data.size = 1;
	d.data.data = 0;

	err = SDO_write(fd, &d);
	if (err != 0) {
		return err;
	}

	// Write objects
	d.data.size = 4;
	for(int i=0; i<num_objects; i++) {
		Epos_pdo_mapping obj = objects[i];

		d.subindex = i+1;
		d.data.data = ((uint32_t)obj.index << 16) | (obj.subindex<<8) | (obj.length);
		err = SDO_write(fd, &d);
		if (err != 0) {
			return err;
		}
	}

	// Set Correct number of objects
	d.subindex = 0x00;
	d.data.size = 1;
	d.data.data = num_objects;

	return SDO_write(fd, &d);
}

int epos_Modes_of_Operation(int fd, uint16_t node_id, enum Epos_mode mode) {
	SDO_data d;
	d.nodeid = node_id;
	d.index = 0x6060;
	d.subindex = 0x00;
	d.data.size = 1;
	d.data.data = mode;

	return SDO_write(fd, &d);
}

