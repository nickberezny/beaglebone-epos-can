typedef struct {
	uint32_t size; //!< in bytes (1=unit8_t, 2=uint16_t, 3=unit24_t, 4=uint32_t)
	uint32_t data;
} Socketcan_t;

typedef struct {
	uint16_t id;
	uint8_t dlc;
	uint8_t data[8];
} my_can_frame;


int socketcan_read(int fp, my_can_frame* frame, int timeout);
int socketcan_write(int fp, uint16_t id, uint8_t length, Socketcan_t data[]);
