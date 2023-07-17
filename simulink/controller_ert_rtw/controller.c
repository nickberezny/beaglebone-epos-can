/*
 * controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.79
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Jul 17 13:44:11 2023
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
  (controller_M->Timing.TaskCounters.TID[1])++;
  if ((controller_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[1] = 0;
  }

  (controller_M->Timing.TaskCounters.TID[2])++;
  if ((controller_M->Timing.TaskCounters.TID[2]) > 9999999) {/* Sample time: [10000.0s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model step function */
void controller_step(void)
{
  real_T rtb_Saturation;
  real_T tmp;

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  tmp = floor(controller_P.Constant1_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  controller_B.DataTypeConversion2 = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
    (int32_T)(uint32_T)tmp;
  if (controller_M->Timing.TaskCounters.TID[2] == 0) {
    /* CCaller: '<Root>/C Caller5' */
    controller_B.CCaller5 = init_can(controller_B.DataTypeConversion2);
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
              (int32_T)(uint32_T)tmp, &rtb_Saturation);

  /* DataTypeConversion: '<Root>/Data Type Conversion9' */
  tmp = floor(rtb_Saturation);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion9' */
  controller_B.DataTypeConversion9 = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
    (int32_T)(uint32_T)tmp;
  if (controller_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion8' incorporates:
     *  Constant: '<Root>/Constant8'
     */
    tmp = floor(controller_P.Constant8_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    /* CCaller: '<Root>/C Caller2' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion8'
     */
    print_input(controller_B.DataTypeConversion9, tmp < 0.0 ? -(int32_T)
                (uint32_T)-tmp : (int32_T)(uint32_T)tmp);
  }

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  if (controller_P.Constant6_Value > controller_P.Saturation_UpperSat) {
    rtb_Saturation = controller_P.Saturation_UpperSat;
  } else if (controller_P.Constant6_Value < controller_P.Saturation_LowerSat) {
    rtb_Saturation = controller_P.Saturation_LowerSat;
  } else {
    rtb_Saturation = controller_P.Constant6_Value;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* CCaller: '<Root>/C Caller3' */
  set_motor(controller_B.CCaller5, controller_B.DataTypeConversion2,
            rtb_Saturation);
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

  /* block I/O */
  (void) memset(((void *) &controller_B), 0,
                sizeof(B_controller_T));
}

/* Model terminate function */
void controller_terminate(void)
{
  /* (no terminate code required) */
}
