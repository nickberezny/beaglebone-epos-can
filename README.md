"# beaglebone-epos-can" 
Provides functions for Maxon EPOS4 CAN drivers with Beaglebone Blue using Simulink Hardware ...

#Steps
 Markup :	1. Edit the "Initialize" block parameters (number of motors, max speed, etc)
 		2. Edit the "Main Control" to build controller based on encoder readings
  		3. Build the  simulink model to the Beaglebone Blue
   		4. 

init_can: set number of motors, max speed, max acceleration
set_motor: pdo id, motor id, set torque
get_encoder: 
stop_motor
print_input
init_datalog
print_data

From beaglebone-epos-can/CANopen/ run

```
sudo make all
sudo ./change_makefile
```

Navigate to the build matlab and run

```
sudo make -f controller.mk all
sudo make -f controller.mk execute
```
