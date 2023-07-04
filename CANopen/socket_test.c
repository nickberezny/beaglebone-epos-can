#include "socketcan.h"
#include "printd.h"

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>

#include <linux/can.h>
#include <linux/can/raw.h>

enum PDO_n_ID {
	PDO_TX1_ID = 0x180,
	PDO_TX2_ID = 0x280,

	PDO_RX1_ID = 0x200, /* +node id */
	PDO_RX2_ID = 0x300  /* +node id */
};


#define MOTOR_EPOS_ID 0x01

#define CANOPEN_BROADCAST_ID 0x00

// Canopen Identifier masks
#define COB_MASK      0x7ff
#define COB_ID_MASK   0x07f
#define COB_FUNC_MASK 0x780
#define NMT_TX 0x700

enum SDO_ID {
	SDO_TX = 0x580, /* +node id */
	SDO_RX = 0x600  /* +node id */
};



int socketcan_open(uint16_t filter[], uint16_t filtermask[], uint16_t num_filters) {
	int fd =  -1;
	// Create the socket
	fd = socket( PF_CAN, SOCK_RAW, CAN_RAW );
	if(fd  == -1) {
		printd(LOG_ERROR, "socketcan: Error opening socket\n");
		return fd;
	}

	// Locate the interface you wish to use
	struct ifreq ifr;
	strcpy(ifr.ifr_name, "can0");
	ioctl(fd, SIOCGIFINDEX, &ifr); // ifr.ifr_ifindex gets filled with that device's index

	// Set Filter for this conection
	struct can_filter rfilter[num_filters];
	for(int i=0; i<num_filters; i++) {
		rfilter[i].can_id   = filter[i];
		rfilter[i].can_mask = filtermask[i];
	}
	setsockopt(fd, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter));
	
	// Select that CAN interface, and bind the socket to it.
	struct sockaddr_can addr;
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;
	bind(fd, (struct sockaddr*)&addr, sizeof(addr));

	// Set to non blocking
	fcntl(fd, F_SETFL, O_NONBLOCK);

	return fd;
}

int NMT_change_state(int fd, uint8_t nodeid, enum NMT_transisions state) {

	Socketcan_t data[2];
	data[0].size = 1;
	data[0].data = state;
	data[1].size = 1;
	data[1].data = nodeid;

	return socketcan_write(fd, 0, 2, data);
	
}



int motor_init() {
	int err = 0;

	// Open two connections to the CAN-network
	uint16_t pdo_masks[2] = {COB_MASK, COB_MASK};
	uint16_t pdo_filters[2] = {
		PDO_TX1_ID + MOTOR_EPOS_ID,
		PDO_TX2_ID + MOTOR_EPOS_ID
	};
	motor_pdo_fd = socketcan_open(pdo_filters, pdo_masks, 2);

	uint16_t cfg_masks[3] = {COB_MASK, COB_MASK, COB_MASK, COB_MASK, COB_MASK};
	uint16_t cfg_filters[3] = {
		0x00,
		NMT_TX + MOTOR_EPOS_ID,
		SDO_TX + MOTOR_EPOS_ID
	};
	motor_cfg_fd = socketcan_open(cfg_filters, cfg_masks, 3);

	// Check that we connected OK
	if (motor_pdo_fd == -1 || motor_cfg_fd == -1) {
		return MOTOR_ERROR;
	}

	// Configure each node
	err |= NMT_change_state(motor_cfg_fd, CANOPEN_BROADCAST_ID, NMT_Enter_PreOperational);
	if (err != 0) {
		return MOTOR_ERROR;
	}

	err |= motor_config_node(MOTOR_EPOS_L_ID);
	if (err != 0) {
		return MOTOR_ERROR;
	}


}

int main() {
	motor_init();
}