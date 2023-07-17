
CC = gcc
CFLAGS = -std=gnu99 -fPIC -Wall -Werror -Wextra -Wno-unused -O2 -I .
LDFLAGS = -std=gnu99 -Werror -L . -Wl,-rpath=.
LDFLAGS_SO = $(LDFLAGS) -shared -fPIC


.SUFFIXES: .c .h .o .so
.PHONY: build all  clean


SOCKETCAN_SRC = socketcan/socketcan.c socketcan/printd.c
SOCKETCAN_OBJ = $(SOCKETCAN_SRC:.c=.o)
SOCKETCAN_LIB = libsocketcan.so

CANOPEN_SRC = canopen/NMT.c canopen/PDO.c canopen/SDO.c
CANOPEN_OBJ = $(CANOPEN_SRC:.c=.o)
CANOPEN_LIB = libcanopen.so

MOTOR_SRC = motor/epos.c motor/motor.c
MOTOR_OBJ = $(MOTOR_SRC:.c=.o)
MOTOR_LIB = libmotor.so



#TEST_SRC=socketcan_sniffer.c


## Targets ##

build: $(MOTOR_LIB)

$(SOCKETCAN_LIB): $(SOCKETCAN_OBJ)
	$(CC) $(SOCKETCAN_OBJ) $(LDFLAGS_SO)  -o $(SOCKETCAN_LIB)

$(CANOPEN_LIB): $(CANOPEN_OBJ) $(SOCKETCAN_LIB)
	$(CC) $(CANOPEN_OBJ) $(LDFLAGS_SO) -lsocketcan -o $(CANOPEN_LIB)

$(MOTOR_LIB): $(MOTOR_OBJ) $(CANOPEN_LIB)
	$(CC) $(MOTOR_OBJ) $(LDFLAGS_SO) -lsocketcan -lcanopen -o $(MOTOR_LIB)

move:
	sudo cp *.so /usr/lib/
	sudo cp init_can* ../../controller_ert_rtw/
	sudo cp set_motor* ../../controller_ert_rtw/
	sudo cp get_encoder* ../../controller_ert_rtw/
	sudo cp -r socketcan ../../controller_ert_rtw/
	sudo cp -r canopen ../../controller_ert_rtw/
	sudo cp -r motor ../../controller_ert_rtw/

clean:
	$(RM) -r $(SOCKETCAN_OBJ) $(CANOPEN_OBJ) $(MOTOR_OBJ) $(MOTORTEST_OBJ)
	$(RM) -r $(SOCKETCAN_LIB) $(CANOPEN_LIB) $(MOTOR_LIB) $(MOTORTEST_TARG)

%.o: %.c $(wildcard *.h)
	$(CC) -c $< $(CFLAGS) -o $@

