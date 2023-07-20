/*
 * controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.86
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Jul 20 09:46:01 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controller.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "controller_private.h"

/* Block signals (default storage) */
B_controller_T controller_B;

/* Real-time model */
static RT_MODEL_controller_T controller_M_;
RT_MODEL_controller_T *const controller_M = &controller_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (controller_M->Timing.TaskCounters.TID[2])++;
  if ((controller_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.01s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[2] = 0;
  }

  (controller_M->Timing.TaskCounters.TID[3])++;
  if ((controller_M->Timing.TaskCounters.TID[3]) > 9999999) {/* Sample time: [10000.0s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/* Model step function */
void controller_step(void)
{
  real_T rtb_CCaller1[2];
  real_T tmp;
  int32_T rtb_DataTypeConversion12;
  if (controller_M->Timing.TaskCounters.TID[3] == 0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    tmp = floor(controller_P.Constant1_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    /* CCaller: '<Root>/C Caller5' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion2'
     */
    controller_B.CCaller5 = init_can(tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
      (int32_T)(uint32_T)tmp);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion7' incorporates:
   *  Constant: '<Root>/Constant7'
   */
  tmp = floor(controller_P.Constant7_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  /* CCaller: '<Root>/C Caller1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   */
  get_encoder(controller_B.CCaller5, tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
              (int32_T)(uint32_T)tmp, &rtb_CCaller1[0]);

  /* DataTypeConversion: '<Root>/Data Type Conversion9' */
  tmp = floor(rtb_CCaller1[0]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion9' */
  controller_B.DataTypeConversion9 = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
    (int32_T)(uint32_T)tmp;
  if (controller_M->Timing.TaskCounters.TID[2] == 0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion8' incorporates:
     *  Constant: '<Root>/Constant8'
     */
    tmp = floor(controller_P.Constant8_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    rtb_DataTypeConversion12 = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)
      (uint32_T)tmp;

    /* End of DataTypeConversion: '<Root>/Data Type Conversion8' */

    /* CCaller: '<Root>/C Caller2' */
    print_input(controller_B.DataTypeConversion9, rtb_DataTypeConversion12);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion10' */
  tmp = floor(rtb_CCaller1[1]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion10' */
  controller_B.DataTypeConversion10 = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
    (int32_T)(uint32_T)tmp;
  if (controller_M->Timing.TaskCounters.TID[2] == 0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion11' incorporates:
     *  Constant: '<Root>/Constant9'
     */
    tmp = floor(controller_P.Constant9_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    /* CCaller: '<Root>/C Caller8' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion11'
     */
    print_input(controller_B.DataTypeConversion10, tmp < 0.0 ? -(int32_T)
                (uint32_T)-tmp : (int32_T)(uint32_T)tmp);

    /* DataTypeConversion: '<Root>/Data Type Conversion12' incorporates:
     *  Constant: '<Root>/Constant10'
     */
    tmp = floor(controller_P.Constant10_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    rtb_DataTypeConversion12 = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)
      (uint32_T)tmp;

    /* End of DataTypeConversion: '<Root>/Data Type Conversion12' */
  }

  /* Step: '<Root>/Step' */
  if (controller_M->Timing.t[0] < controller_P.Step_Time) {
    controller_B.Saturation = controller_P.Step_Y0;
  } else {
    controller_B.Saturation = controller_P.Step_YFinal;
  }

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Step: '<Root>/Step'
   */
  if (controller_B.Saturation > controller_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    controller_B.Saturation = controller_P.Saturation_UpperSat;
  } else if (controller_B.Saturation < controller_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    controller_B.Saturation = controller_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (controller_M->Timing.TaskCounters.TID[2] == 0) {
    /* CCaller: '<Root>/C Caller3' */
    set_motor(controller_B.CCaller5, rtb_DataTypeConversion12,
              controller_B.Saturation);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++controller_M->Timing.clockTick0)) {
    ++controller_M->Timing.clockTickH0;
  }

  controller_M->Timing.t[0] = controller_M->Timing.clockTick0 *
    controller_M->Timing.stepSize0 + controller_M->Timing.clockTickH0 *
    controller_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    controller_M->Timing.clockTick1++;
    if (!controller_M->Timing.clockTick1) {
      controller_M->Timing.clockTickH1++;
    }
  }

  rate_scheduler();
}

/* Model initialize function */
void controller_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)controller_M, 0,
                sizeof(RT_MODEL_controller_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&controller_M->solverInfo,
                          &controller_M->Timing.simTimeStep);
    rtsiSetTPtr(&controller_M->solverInfo, &rtmGetTPtr(controller_M));
    rtsiSetStepSizePtr(&controller_M->solverInfo,
                       &controller_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&controller_M->solverInfo, (&rtmGetErrorStatus
      (controller_M)));
    rtsiSetRTModelPtr(&controller_M->solverInfo, controller_M);
  }

  rtsiSetSimTimeStep(&controller_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&controller_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(controller_M, &controller_M->Timing.tArray[0]);
  controller_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &controller_B), 0,
                sizeof(B_controller_T));
}

/* Model terminate function */
void controller_terminate(void)
{
  /* (no terminate code required) */
}
