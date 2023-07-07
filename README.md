"# beaglebone-epos-can" 
WIP
Uses code from epos2...

Steps:
build shared libraries
move to usr/lib
move init_can.c, init_can.h, and motor/ folder to simulink folder
edit simulink.mk:
	- add to TOOLCHAIN_LIBS: -lsocketcan -lcanopen -lmotor 