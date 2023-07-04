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

int socketcan_read(int fd, my_can_frame* frame, int timeout) {
	// Wait for data or timeout
	int bytes, t;
	struct can_frame f;
	struct pollfd p[1];

	p[0].fd = fd;
	p[0].events = POLLIN;

	t = poll(p, 1, timeout);

	// Try to read available data
	bytes = read(fd, &f, sizeof(f));

	if(bytes <= 0) {
		// Error, no bytes read
		frame->id = 0;
		frame->dlc = 0;
		if (bytes == 0) {
			return SOCKETCAN_TIMEOUT;
		}
		//printd(LOG_ERROR, "socketcan: Could not read data from CAN-bus\n");
		return SOCKETCAN_ERROR;
	}

	// Copy data
	frame->id = f.can_id;
	frame->dlc = f.can_dlc;
	memcpy(frame->data, f.data, sizeof(frame->data));
	return 0;
}


int socketcan_write(int fd, uint16_t id, uint8_t length, Socketcan_t data[]) {
	int bytes;
	uint8_t byte, n;
	struct can_frame frame;
	frame.can_id = id;

	byte = 0;
	for(int i=0; i<length; i++) {
		n = 0;
		while(n < data[i].size) {
			frame.data[byte] = (data[i].data >> 8*n);
			n++;
			byte++;
		}
	}

	frame.can_dlc = byte;

	bytes = write(fd, &frame, sizeof(frame));
	if(bytes < 0) {
		// Error, no data written
		printd(LOG_ERROR, "socketcan: Could not write data to CAN-bus\n");
		return SOCKETCAN_ERROR;
	}
	return 0;
}