#ifndef LIBMOTOR_H
#define LIBMOTOR_H

#include <inttypes.h>


/*** CAN-bus spesific ***/
#define MOTOR_PC_ID     0x02
#define MOTOR_EPOS_L_ID 0x03
#define MOTOR_EPOS_R_ID 0x01


/*** Tuning ***/
#define MOTOR_MAX_SPEED     1200      /* [mm/sec]    */
#define MOTOR_MAX_ACC        650      /* [mm/sec^2]  */
#define MOTOR_MAX_QUICK_ACC  350      /* [mm/sec^2]  */


/*** Errors ***/
#define MOTOR_ERROR   (-1)
#define MOTOR_TIMEOUT (-2)


// Implemented subset of Epos_mode from epos.h
enum Motor_mode {
	Motor_mode_Velocity = 9,
	Motor_mode_Torque = 10,
	Motor_mode_Position = 1,
};


extern int motor_pdo_fd;
extern int motor_cfg_fd;

/*!
 * Opens the can connection,
 * and configures the two motors
 * \return 0 on success, MOTOR_ERROR (-1) on error
 */
int motor_init();


/*! Closes the CAN connection */
void motor_close(void);


/*!
 * Turns the motors on
 * \return 0 on success, MOTOR_ERROR (-1) on error
 */
int motor_enable();


/*!
 * Stops the motors as quickly as possible, and holds them there.
 * Run motor_enable() to re-enable the controller.
 */
int motor_halt(void);


/*!
 * Turns the motors off (no power).
 * \return 0 on success, MOTOR_ERROR (-1) on error
 */
int motor_disable(void);

/*!
 * Sets the opperation mode (Velocity or Position)
 * \return 0 on success, MOTOR_ERROR (-1) on error
 */
int motor_setmode(enum Motor_mode mode);


#endif // LIBMOTOR_H
