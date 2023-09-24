# beaglebone-epos-can #
  Provides functions for Maxon EPOS4 CAN drivers with Beaglebone Blue using Simulink Hardware ...

# Steps #

1. Edit the "Initialize" block parameters (number of motors, max speed, etc)
2. Edit the "Main Control" to build controller based on encoder readings
3. Build the simulink model to the Beaglebone Blue
4. On the Beaglenbone, from beaglebone-epos-can/CANopen/, run:
```
sudo make all
sudo ./change_makefile
```
5. On the Beaglebone, from the Matlab build folder, run:
```
sudo make -f controller.mk all
```
6. Execute the control system by running:
 ```
sudo make -f controller.mk execute
```

init_can: set number of motors, max speed, max acceleration
set_motor: pdo id, motor id, set torque
get_encoder: 
stop_motor
print_input
init_datalog
print_data





Navigate to the build matlab and run


