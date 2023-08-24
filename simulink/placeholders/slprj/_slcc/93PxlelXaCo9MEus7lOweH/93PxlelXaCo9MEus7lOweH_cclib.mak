#------------------------ Tool Specifications & Options ----------------------

COMPILER  =  lcc

CC        =  "C:\Program Files\MATLAB\R2022b\sys\lcc64\lcc64\bin\lcc64.exe"
LD        =  "C:\Program Files\MATLAB\R2022b\sys\lcc64\lcc64\bin\lcclnk64.exe"
LIBCMD    =  "C:\Program Files\MATLAB\R2022b\sys\lcc64\lcc64\bin\lcclib64.exe"
CFLAGS    =  -dll -noregistrylookup  -c -Zp8 -DLCC_WIN64 -DMATLAB_MEX_FILE -nodeclspec
LDFLAGS   =  -s -dll -entry LibMain 93PxlelXaCo9MEus7lOweH_cclib.def -L"C:\Program Files\MATLAB\R2022b\sys\lcc64\lcc64\lib64"

OBJECTS = \
	   init_can.obj \
	   set_motor.obj \
	   get_encoder.obj \
	   print_input.obj \
	   stop_motor.obj \
	   datalog.obj \
	   slcc_interface_93PxlelXaCo9MEus7lOweH.obj \
	   lccstub.obj \

STATICLIBS = \

#------------------------------ Include/Lib Path ------------------------------

INCLUDE_PATH = \
     -I"c:\program files\matlab\r2022b\extern\include" \
     -I"c:\program files\matlab\r2022b\simulink\include" \
     -I"c:\users\abl\documents\beaglebone-epos-can\simulink\placeholders\slprj\_slcc\93pxlelxaco9meus7loweh" \
     -I"c:\users\abl\documents\beaglebone-epos-can\simulink\placeholders" \
     -I"c:\users\abl\documents\beaglebone-epos-can\simulink" \
     -I"c:\program files\matlab\r2022b\sys\lcc64\lcc64\include64" \
     -I"c:\program files\matlab\r2022b\sys\lcc64\lcc64\mex" \

#--------------------------------- Rules --------------------------------------

93PxlelXaCo9MEus7lOweH_cclib.dll : $(MAKEFILE) $(OBJECTS)
	$(LD) $(LDFLAGS) /OUT:93PxlelXaCo9MEus7lOweH_cclib.dll $(OBJECTS)  $(STATICLIBS) "C:\Program Files\MATLAB\R2022b\extern\lib\win64\microsoft\libmex.lib" "C:\Program Files\MATLAB\R2022b\extern\lib\win64\microsoft\libmx.lib"
init_can.obj :	c:\users\abl\DOCUME~1\BEAGLE~1\simulink\PLACEH~1\init_can.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "c:\users\abl\documents\beaglebone-epos-can\simulink\placeholders\init_can.c"
set_motor.obj :	c:\users\abl\DOCUME~1\BEAGLE~1\simulink\PLACEH~1\SET_MO~1.C
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "c:\users\abl\documents\beaglebone-epos-can\simulink\placeholders\set_motor.c"
get_encoder.obj :	c:\users\abl\DOCUME~1\BEAGLE~1\simulink\PLACEH~1\GET_EN~1.C
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "c:\users\abl\documents\beaglebone-epos-can\simulink\placeholders\get_encoder.c"
print_input.obj :	c:\users\abl\DOCUME~1\BEAGLE~1\simulink\PLACEH~1\PRINT_~1.C
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "c:\users\abl\documents\beaglebone-epos-can\simulink\placeholders\print_input.c"
stop_motor.obj :	c:\users\abl\DOCUME~1\BEAGLE~1\simulink\PLACEH~1\STOP_M~1.C
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "c:\users\abl\documents\beaglebone-epos-can\simulink\placeholders\stop_motor.c"
datalog.obj :	c:\users\abl\DOCUME~1\BEAGLE~1\simulink\PLACEH~1\datalog.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "c:\users\abl\documents\beaglebone-epos-can\simulink\placeholders\datalog.c"
slcc_interface_93PxlelXaCo9MEus7lOweH.obj :	C:\Users\ABL\DOCUME~1\BEAGLE~1\simulink\PLACEH~1\slprj\_slcc\93PXLE~1\SLCC_I~1.C
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Users\ABL\Documents\beaglebone-epos-can\simulink\placeholders\slprj\_slcc\93PxlelXaCo9MEus7lOweH\slcc_interface_93PxlelXaCo9MEus7lOweH.c"
lccstub.obj :	C:\PROGRA~1\MATLAB\R2022b\sys\lcc64\lcc64\mex\lccstub.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2022b\sys\lcc64\lcc64\mex\lccstub.c"
