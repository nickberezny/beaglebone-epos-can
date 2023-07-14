#include "PDO.h"
#include "SDO.h"
#include "socketcan/printd.h"
#include <string.h>
#include <stdio.h>


int PDO_send(int fp, uint16_t pdo_id, uint8_t length, Socketcan_t data[]) {
	//uint16_t cob = 0x200 + id;
	return socketcan_write(fp, pdo_id, length, data);
}


int PDO_read(int fp, my_can_frame* pdo, int timeout) {
	// Don't touch callers struct unless we have to
	int err, func;
	my_can_frame f;

	err = socketcan_read(fp, &f, timeout);
	if(err != 0) {
		// Read error, or no data
		return err;
	}

	func = f.id & (~0x7f); // COB function code
	if(func == 0 || func == SDO_RX || func == SDO_TX) {
		// Not a PDO!
		printd(LOG_WARN, "PDO.c recived non pdo-pkg\n");
		return SOCKETCAN_ERROR;
	}

	printf("data %d,%d,%d,%d,%d,%d,%d,%d\n",f.data[0],f.data[1],f.data[2],f.data[3],f.data[4],f.data[5],f.data[6],f.data[7]);

	// Copy data to return struct
	memcpy(pdo, &f, sizeof(f));
	return 0;
}
