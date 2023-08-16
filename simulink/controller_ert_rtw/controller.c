/*
 * controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.318
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Aug 16 15:04:38 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controller.h"
#include "rtwtypes.h"
#include "controller_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "controller_types.h"
#include "zero_crossing_types.h"
#include <string.h>

/* Block signals (default storage) */
B_controller_T controller_B;

/* Block states (default storage) */
DW_controller_T controller_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_controller_T controller_PrevZCX;

/* Real-time model */
static RT_MODEL_controller_T controller_M_;
RT_MODEL_controller_T *const controller_M = &controller_M_;

/* Forward declaration for local functions */
static void controller_getLocalTime(real_T *t_tm_nsec, real_T *t_tm_sec, real_T *
  t_tm_min, real_T *t_tm_hour, real_T *t_tm_mday, real_T *t_tm_mon, real_T
  *t_tm_year, boolean_T *t_tm_isdst);
static creal_T controller_split(real_T b_a);
static creal_T controller_two_prod(real_T b_a);
static creal_T controller_times(const creal_T b_a);
static creal_T controller_two_sum(real_T b_a, real_T b);
static creal_T controller_plus(const creal_T b_a, real_T b);
static creal_T controller_two_diff(real_T b_a, real_T b);
static creal_T controller_floor(const creal_T b_a);
static creal_T controller_minus(const creal_T b_a, const creal_T b);
static void rate_scheduler(void);
int32_T div_s32(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T tempAbsQuotient;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    tempAbsQuotient = (numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
                       numerator) / (denominator < 0 ? ~(uint32_T)denominator +
      1U : (uint32_T)denominator);
    quotient = (numerator < 0) != (denominator < 0) ? -(int32_T)tempAbsQuotient :
      (int32_T)tempAbsQuotient;
  }

  return quotient;
}

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
  if ((controller_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.1s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[2] = 0;
  }

  (controller_M->Timing.TaskCounters.TID[3])++;
  if ((controller_M->Timing.TaskCounters.TID[3]) > 999) {/* Sample time: [1.0s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[3] = 0;
  }

  (controller_M->Timing.TaskCounters.TID[4])++;
  if ((controller_M->Timing.TaskCounters.TID[4]) > 99999) {/* Sample time: [100.0s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[4] = 0;
  }

  (controller_M->Timing.TaskCounters.TID[5])++;
  if ((controller_M->Timing.TaskCounters.TID[5]) > 9999999) {/* Sample time: [10000.0s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[5] = 0;
  }
}

/* Start for atomic system: */
void controller_AnalogInput_Start(DW_AnalogInput_controller_T *localDW,
  P_AnalogInput_controller_T *localP)
{
  /* Start for MATLABSystem: '<Root>/Analog Input' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.SampleTime = localP->AnalogInput_SampleTime;
  localDW->obj.isInitialized = 1;
  rc_adc_init();
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void controller_AnalogInput(B_AnalogInput_controller_T *localB,
  DW_AnalogInput_controller_T *localDW, P_AnalogInput_controller_T *localP)
{
  /* MATLABSystem: '<Root>/Analog Input' */
  if (localDW->obj.SampleTime != localP->AnalogInput_SampleTime) {
    localDW->obj.SampleTime = localP->AnalogInput_SampleTime;
  }

  /* MATLABSystem: '<Root>/Analog Input' */
  localB->AnalogInput = rc_adc_read_raw(0);
}

/* Termination for atomic system: */
void controller_AnalogInput_Term(DW_AnalogInput_controller_T *localDW)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      rc_adc_cleanup();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */
}

/*
 * System initialize for enable system:
 *    '<Root>/Home1'
 *    '<Root>/Home3'
 */
void controller_Home1_Init(DW_Home1_controller_T *localDW, P_Home1_controller_T *
  localP)
{
  /* InitializeConditions for Delay: '<S10>/Delay' */
  localDW->Delay_DSTATE[0] = localP->Delay_InitialCondition;
  localDW->Delay_DSTATE[1] = localP->Delay_InitialCondition;

  /* InitializeConditions for Derivative: '<S10>/Derivative' */
  localDW->TimeStampA = (rtInf);
  localDW->TimeStampB = (rtInf);
}

/*
 * Disable for enable system:
 *    '<Root>/Home1'
 *    '<Root>/Home3'
 */
void controller_Home1_Disable(DW_Home1_controller_T *localDW)
{
  localDW->Home1_MODE = false;
}

/*
 * Start for enable system:
 *    '<Root>/Home1'
 *    '<Root>/Home3'
 */
void controller_Home1_Start(DW_Home1_controller_T *localDW)
{
  localDW->Home1_MODE = false;
}

/*
 * Outputs for enable system:
 *    '<Root>/Home1'
 *    '<Root>/Home3'
 */
void controller_Home1(RT_MODEL_controller_T * const controller_M, boolean_T
                      rtu_Enable, real_T rtu_motor_id, real_T rtu_home_speed,
                      boolean_T rtu_LS1, const real_T *rtd_GR1, const real_T
                      *rtd_GR2, const real_T *rtd_num_motors, const int32_T
                      *rtd_pdo_id, real_T *rtd_state, B_Home1_controller_T
                      *localB, DW_Home1_controller_T *localDW,
                      P_Home1_controller_T *localP, ZCE_Home1_controller_T
                      *localZCE)
{
  real_T rtb_CCaller1_m[2];
  real_T (*lastU)[2];
  real_T rtb_DataStoreRead7_b;
  real_T rtb_DataStoreRead8_m;
  int32_T rtb_DataStoreRead2_c;
  int32_T rtb_DataTypeConversion1_i;
  int32_T rtb_DataTypeConversion_k;
  boolean_T rtb_Compare_f;
  boolean_T rtb_Compare_p_idx_0;
  boolean_T rtb_Compare_p_idx_1;

  /* Outputs for Enabled SubSystem: '<Root>/Home1' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  if (rtu_Enable) {
    localDW->Home1_MODE = true;
  } else if (localDW->Home1_MODE) {
    controller_Home1_Disable(localDW);
  }

  if (localDW->Home1_MODE) {
    /* RelationalOperator: '<S16>/Compare' incorporates:
     *  Constant: '<S16>/Constant'
     */
    rtb_Compare_f = (rtu_LS1 == localP->CompareToConstant1_const);

    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S10>/Constant1'
     */
    if (rtb_Compare_f) {
      rtb_DataStoreRead7_b = localP->Constant1_Value;
    } else {
      /* DataStoreRead: '<S20>/Data Store Read' */
      rtb_DataStoreRead7_b = *rtd_state;
    }

    /* End of Switch: '<S20>/Switch' */

    /* DataStoreWrite: '<S20>/Data Store Write' */
    *rtd_state = rtb_DataStoreRead7_b;
    if (controller_M->Timing.TaskCounters.TID[2] == 0) {
      /* DataStoreRead: '<S19>/Data Store Read2' */
      rtb_DataStoreRead2_c = *rtd_pdo_id;

      /* DataTypeConversion: '<S19>/Data Type Conversion1' */
      rtb_DataStoreRead7_b = floor(rtu_motor_id);
      if (rtIsNaN(rtb_DataStoreRead7_b) || rtIsInf(rtb_DataStoreRead7_b)) {
        rtb_DataStoreRead7_b = 0.0;
      } else {
        rtb_DataStoreRead7_b = fmod(rtb_DataStoreRead7_b, 4.294967296E+9);
      }

      rtb_DataTypeConversion1_i = rtb_DataStoreRead7_b < 0.0 ? -(int32_T)
        (uint32_T)-rtb_DataStoreRead7_b : (int32_T)(uint32_T)
        rtb_DataStoreRead7_b;

      /* End of DataTypeConversion: '<S19>/Data Type Conversion1' */
    }

    /* DataStoreRead: '<S10>/Data Store Read2' */
    rtb_DataTypeConversion_k = *rtd_pdo_id;

    /* DataStoreRead: '<S10>/Data Store Read7' */
    rtb_DataStoreRead7_b = *rtd_num_motors;

    /* DataTypeConversion: '<S10>/Data Type Conversion7' */
    rtb_DataStoreRead7_b = floor(rtb_DataStoreRead7_b);
    if (rtIsNaN(rtb_DataStoreRead7_b) || rtIsInf(rtb_DataStoreRead7_b)) {
      rtb_DataStoreRead7_b = 0.0;
    } else {
      rtb_DataStoreRead7_b = fmod(rtb_DataStoreRead7_b, 4.294967296E+9);
    }

    /* CCaller: '<S10>/C Caller1' incorporates:
     *  DataTypeConversion: '<S10>/Data Type Conversion7'
     */
    get_encoder(rtb_DataTypeConversion_k, rtb_DataStoreRead7_b < 0.0 ? -(int32_T)
                (uint32_T)-rtb_DataStoreRead7_b : (int32_T)(uint32_T)
                rtb_DataStoreRead7_b, &rtb_CCaller1_m[0]);

    /* RelationalOperator: '<S17>/Compare' incorporates:
     *  Constant: '<S17>/Constant'
     */
    rtb_Compare_p_idx_0 = (rtb_CCaller1_m[0] != localP->Constant_Value);
    rtb_Compare_p_idx_1 = (rtb_CCaller1_m[1] != localP->Constant_Value);

    /* Switch: '<S10>/Switch' */
    if (rtb_Compare_p_idx_0) {
      /* Switch: '<S10>/Switch' */
      localB->Switch[0] = rtb_CCaller1_m[0];
    } else {
      /* Switch: '<S10>/Switch' incorporates:
       *  Delay: '<S10>/Delay'
       */
      localB->Switch[0] = localDW->Delay_DSTATE[0];
    }

    if (rtb_Compare_p_idx_1) {
      /* Switch: '<S10>/Switch' */
      localB->Switch[1] = rtb_CCaller1_m[1];
    } else {
      /* Switch: '<S10>/Switch' incorporates:
       *  Delay: '<S10>/Delay'
       */
      localB->Switch[1] = localDW->Delay_DSTATE[1];
    }

    /* End of Switch: '<S10>/Switch' */

    /* DataStoreRead: '<S10>/Data Store Read1' */
    rtb_DataStoreRead7_b = *rtd_GR1;

    /* DataStoreRead: '<S10>/Data Store Read8' */
    rtb_DataStoreRead8_m = *rtd_GR2;

    /* Gain: '<S10>/Gain2' incorporates:
     *  Gain: '<S10>/Gain'
     *  Gain: '<S10>/Gain1'
     *  Product: '<S10>/Divide'
     */
    localB->Gain2[0] = localB->Switch[0] / (localP->Gain_Gain *
      rtb_DataStoreRead7_b) * localP->Gain2_Gain;
    localB->Gain2[1] = localB->Switch[1] / (localP->Gain1_Gain *
      rtb_DataStoreRead8_m) * localP->Gain2_Gain;

    /* Derivative: '<S10>/Derivative' */
    rtb_DataStoreRead7_b = controller_M->Timing.t[0];
    if ((localDW->TimeStampA >= rtb_DataStoreRead7_b) && (localDW->TimeStampB >=
         rtb_DataStoreRead7_b)) {
      rtb_CCaller1_m[0] = 0.0;
      rtb_CCaller1_m[1] = 0.0;
    } else {
      rtb_DataStoreRead8_m = localDW->TimeStampA;
      lastU = &localDW->LastUAtTimeA;
      if (localDW->TimeStampA < localDW->TimeStampB) {
        if (localDW->TimeStampB < rtb_DataStoreRead7_b) {
          rtb_DataStoreRead8_m = localDW->TimeStampB;
          lastU = &localDW->LastUAtTimeB;
        }
      } else if (localDW->TimeStampA >= rtb_DataStoreRead7_b) {
        rtb_DataStoreRead8_m = localDW->TimeStampB;
        lastU = &localDW->LastUAtTimeB;
      }

      rtb_DataStoreRead8_m = rtb_DataStoreRead7_b - rtb_DataStoreRead8_m;
      rtb_DataStoreRead7_b = (localB->Gain2[0] - (*lastU)[0]) /
        rtb_DataStoreRead8_m;
      rtb_DataStoreRead8_m = (localB->Gain2[1] - (*lastU)[1]) /
        rtb_DataStoreRead8_m;
      rtb_CCaller1_m[0] = rtb_DataStoreRead7_b;
      rtb_CCaller1_m[1] = rtb_DataStoreRead8_m;
    }

    /* End of Derivative: '<S10>/Derivative' */

    /* Gain: '<S10>/Gain3' incorporates:
     *  Sum: '<S10>/Sum1'
     */
    localB->Saturation = (rtb_CCaller1_m[0] - rtu_home_speed) *
      localP->Gain3_Gain;

    /* Saturate: '<S10>/Saturation' */
    if (localB->Saturation > localP->Saturation_UpperSat) {
      /* Gain: '<S10>/Gain3' incorporates:
       *  Saturate: '<S10>/Saturation'
       */
      localB->Saturation = localP->Saturation_UpperSat;
    } else if (localB->Saturation < localP->Saturation_LowerSat) {
      /* Gain: '<S10>/Gain3' incorporates:
       *  Saturate: '<S10>/Saturation'
       */
      localB->Saturation = localP->Saturation_LowerSat;
    }

    /* End of Saturate: '<S10>/Saturation' */
    if (controller_M->Timing.TaskCounters.TID[2] == 0) {
      /* CCaller: '<S19>/C Caller3' */
      set_motor(rtb_DataStoreRead2_c, rtb_DataTypeConversion1_i,
                localB->Saturation);
    }

    /* Outputs for Triggered SubSystem: '<S10>/Stop Motor1' incorporates:
     *  TriggerPort: '<S18>/Trigger'
     */
    if (rtb_Compare_f && (localZCE->StopMotor1_Trig_ZCE_f != POS_ZCSIG)) {
      /* DataStoreRead: '<S18>/Data Store Read1' */
      rtb_DataStoreRead2_c = *rtd_pdo_id;

      /* DataStoreRead: '<S18>/Data Store Read7' */
      rtb_DataStoreRead7_b = *rtd_num_motors;

      /* DataTypeConversion: '<S18>/Data Type Conversion' */
      rtb_DataStoreRead7_b = floor(rtb_DataStoreRead7_b);
      if (rtIsNaN(rtb_DataStoreRead7_b) || rtIsInf(rtb_DataStoreRead7_b)) {
        rtb_DataStoreRead7_b = 0.0;
      } else {
        rtb_DataStoreRead7_b = fmod(rtb_DataStoreRead7_b, 4.294967296E+9);
      }

      /* CCaller: '<S18>/C Caller4' incorporates:
       *  DataTypeConversion: '<S18>/Data Type Conversion'
       */
      stop_motor(rtb_DataStoreRead2_c, rtb_DataStoreRead7_b < 0.0 ? -(int32_T)
                 (uint32_T)-rtb_DataStoreRead7_b : (int32_T)(uint32_T)
                 rtb_DataStoreRead7_b);
    }

    localZCE->StopMotor1_Trig_ZCE_f = rtb_Compare_f;

    /* End of Outputs for SubSystem: '<S10>/Stop Motor1' */
  }

  /* End of Outputs for SubSystem: '<Root>/Home1' */
}

/*
 * Update for enable system:
 *    '<Root>/Home1'
 *    '<Root>/Home3'
 */
void controller_Home1_Update(RT_MODEL_controller_T * const controller_M,
  B_Home1_controller_T *localB, DW_Home1_controller_T *localDW)
{
  real_T (*lastU)[2];

  /* Update for Enabled SubSystem: '<Root>/Home1' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  if (localDW->Home1_MODE) {
    /* Update for Delay: '<S10>/Delay' */
    localDW->Delay_DSTATE[0] = localB->Switch[0];
    localDW->Delay_DSTATE[1] = localB->Switch[1];

    /* Update for Derivative: '<S10>/Derivative' */
    if (localDW->TimeStampA == (rtInf)) {
      localDW->TimeStampA = controller_M->Timing.t[0];
      lastU = &localDW->LastUAtTimeA;
    } else if (localDW->TimeStampB == (rtInf)) {
      localDW->TimeStampB = controller_M->Timing.t[0];
      lastU = &localDW->LastUAtTimeB;
    } else if (localDW->TimeStampA < localDW->TimeStampB) {
      localDW->TimeStampA = controller_M->Timing.t[0];
      lastU = &localDW->LastUAtTimeA;
    } else {
      localDW->TimeStampB = controller_M->Timing.t[0];
      lastU = &localDW->LastUAtTimeB;
    }

    (*lastU)[0] = localB->Gain2[0];
    (*lastU)[1] = localB->Gain2[1];

    /* End of Update for Derivative: '<S10>/Derivative' */
  }

  /* End of Update for SubSystem: '<Root>/Home1' */
}

/*
 * System initialize for trigger system:
 *    '<S11>/Stop Motor1'
 *    '<S13>/Stop Motor1'
 */
void controller_StopMotor1_Init(B_StopMotor1_controller_T *localB,
  P_StopMotor1_controller_T *localP)
{
  /* SystemInitialize for CCaller: '<S23>/C Caller1' incorporates:
   *  Outport: '<S23>/enc'
   */
  localB->CCaller1[0] = localP->enc_Y0;
  localB->CCaller1[1] = localP->enc_Y0;
}

/*
 * Output and update for trigger system:
 *    '<S11>/Stop Motor1'
 *    '<S13>/Stop Motor1'
 */
void controller_StopMotor1(boolean_T rtu_Trigger, const real_T *rtd_num_motors,
  const int32_T *rtd_pdo_id, B_StopMotor1_controller_T *localB,
  P_StopMotor1_controller_T *localP, ZCE_StopMotor1_controller_T *localZCE)
{
  real_T rtb_DataStoreRead7_f;
  int32_T rtb_DataTypeConversion_h;

  /* Outputs for Triggered SubSystem: '<S11>/Stop Motor1' incorporates:
   *  TriggerPort: '<S23>/Trigger'
   */
  if (rtu_Trigger && (localZCE->StopMotor1_Trig_ZCE != POS_ZCSIG)) {
    /* DataStoreRead: '<S23>/Data Store Read2' */
    rtb_DataTypeConversion_h = *rtd_pdo_id;

    /* DataTypeConversion: '<S23>/Data Type Conversion7' incorporates:
     *  Constant: '<S23>/Constant7'
     */
    rtb_DataStoreRead7_f = floor(localP->Constant7_Value);
    if (rtIsNaN(rtb_DataStoreRead7_f) || rtIsInf(rtb_DataStoreRead7_f)) {
      rtb_DataStoreRead7_f = 0.0;
    } else {
      rtb_DataStoreRead7_f = fmod(rtb_DataStoreRead7_f, 4.294967296E+9);
    }

    /* CCaller: '<S23>/C Caller1' incorporates:
     *  DataTypeConversion: '<S23>/Data Type Conversion7'
     */
    get_encoder(rtb_DataTypeConversion_h, rtb_DataStoreRead7_f < 0.0 ? -(int32_T)
                (uint32_T)-rtb_DataStoreRead7_f : (int32_T)(uint32_T)
                rtb_DataStoreRead7_f, &localB->CCaller1[0]);

    /* DataStoreRead: '<S23>/Data Store Read1' */
    rtb_DataTypeConversion_h = *rtd_pdo_id;

    /* DataStoreRead: '<S23>/Data Store Read7' */
    rtb_DataStoreRead7_f = *rtd_num_motors;

    /* DataTypeConversion: '<S23>/Data Type Conversion' */
    rtb_DataStoreRead7_f = floor(rtb_DataStoreRead7_f);
    if (rtIsNaN(rtb_DataStoreRead7_f) || rtIsInf(rtb_DataStoreRead7_f)) {
      rtb_DataStoreRead7_f = 0.0;
    } else {
      rtb_DataStoreRead7_f = fmod(rtb_DataStoreRead7_f, 4.294967296E+9);
    }

    /* CCaller: '<S23>/C Caller4' incorporates:
     *  DataTypeConversion: '<S23>/Data Type Conversion'
     */
    stop_motor(rtb_DataTypeConversion_h, rtb_DataStoreRead7_f < 0.0 ? -(int32_T)
               (uint32_T)-rtb_DataStoreRead7_f : (int32_T)(uint32_T)
               rtb_DataStoreRead7_f);
  }

  localZCE->StopMotor1_Trig_ZCE = rtu_Trigger;

  /* End of Outputs for SubSystem: '<S11>/Stop Motor1' */
}

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
static void controller_getLocalTime(real_T *t_tm_nsec, real_T *t_tm_sec, real_T *
  t_tm_min, real_T *t_tm_hour, real_T *t_tm_mday, real_T *t_tm_mon, real_T
  *t_tm_year, boolean_T *t_tm_isdst)
{
  coderLocalTime(&controller_B.origStructTm);
  *t_tm_nsec = (real_T)controller_B.origStructTm.tm_nsec;
  *t_tm_sec = controller_B.origStructTm.tm_sec;
  *t_tm_min = controller_B.origStructTm.tm_min;
  *t_tm_hour = controller_B.origStructTm.tm_hour;
  *t_tm_mday = controller_B.origStructTm.tm_mday;
  *t_tm_mon = controller_B.origStructTm.tm_mon;
  *t_tm_year = controller_B.origStructTm.tm_year;
  *t_tm_isdst = (controller_B.origStructTm.tm_isdst != 0);
}

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
static creal_T controller_split(real_T b_a)
{
  creal_T aout;
  if (fabs(b_a) <= 6.69692879491417E+299) {
    controller_B.temp = 1.34217729E+8 * b_a;
    controller_B.temp -= controller_B.temp - b_a;
    aout.re = controller_B.temp;
    aout.im = b_a - controller_B.temp;
  } else if ((!rtIsInf(b_a)) && (!rtIsNaN(b_a))) {
    b_a *= 3.7252902984619141E-9;
    controller_B.temp = 1.34217729E+8 * b_a;
    controller_B.temp -= controller_B.temp - b_a;
    aout.re = controller_B.temp * 2.68435456E+8;
    aout.im = (b_a - controller_B.temp) * 2.68435456E+8;
  } else {
    aout.re = b_a;
    aout.im = 0.0;
  }

  return aout;
}

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
static creal_T controller_two_prod(real_T b_a)
{
  creal_T c;
  controller_B.da = controller_split(b_a);
  controller_B.shi_f = b_a * 8.64E+7;
  controller_B.slo = (controller_B.da.re * 8.64E+7 - controller_B.shi_f) +
    controller_B.da.im * 8.64E+7;
  controller_B.trueCount_g = 0;
  if (rtIsNaN(controller_B.slo)) {
    controller_B.trueCount_g = 1;
  }

  if (controller_B.trueCount_g - 1 >= 0) {
    controller_B.slo = 0.0;
  }

  c.re = controller_B.shi_f;
  c.im = controller_B.slo;
  return c;
}

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
static creal_T controller_times(const creal_T b_a)
{
  creal_T c;
  c = controller_two_prod(b_a.re);
  controller_B.b = b_a.im * 8.64E+7;
  controller_B.alo_p = c.im;
  controller_B.ahi_c = c.re;
  if (controller_B.b != 0.0) {
    controller_B.alo_p = c.im + controller_B.b;
    controller_B.ahi_c = c.re + controller_B.alo_p;
    controller_B.alo_p -= controller_B.ahi_c - c.re;
  }

  if (rtIsNaN(controller_B.alo_p)) {
    controller_B.alo_p = 0.0;
  }

  c.re = controller_B.ahi_c;
  c.im = controller_B.alo_p;
  return c;
}

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
static creal_T controller_two_sum(real_T b_a, real_T b)
{
  creal_T c;
  controller_B.shi_n = b_a + b;
  controller_B.bb_p = controller_B.shi_n - b_a;
  controller_B.bb_p = (b_a - (controller_B.shi_n - controller_B.bb_p)) + (b -
    controller_B.bb_p);
  controller_B.trueCount_l = 0;
  if (rtIsNaN(controller_B.bb_p)) {
    controller_B.trueCount_l = 1;
  }

  if (controller_B.trueCount_l - 1 >= 0) {
    controller_B.bb_p = 0.0;
  }

  c.re = controller_B.shi_n;
  c.im = controller_B.bb_p;
  return c;
}

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
static creal_T controller_plus(const creal_T b_a, real_T b)
{
  creal_T c;
  c = controller_two_sum(b_a.re, b);
  controller_B.t_c = controller_two_sum(b_a.im, 0.0);
  controller_B.alo_g = c.im;
  controller_B.ahi_g = c.re;
  if (controller_B.t_c.re != 0.0) {
    controller_B.alo_g = c.im + controller_B.t_c.re;
    controller_B.ahi_g = c.re + controller_B.alo_g;
    controller_B.alo_g -= controller_B.ahi_g - c.re;
  }

  if (rtIsNaN(controller_B.alo_g)) {
    controller_B.alo_g = 0.0;
  }

  controller_B.b_ahi_m = controller_B.ahi_g;
  if (controller_B.t_c.im != 0.0) {
    controller_B.alo_g += controller_B.t_c.im;
    controller_B.b_ahi_m = controller_B.ahi_g + controller_B.alo_g;
    controller_B.alo_g -= controller_B.b_ahi_m - controller_B.ahi_g;
  }

  if (rtIsNaN(controller_B.alo_g)) {
    controller_B.alo_g = 0.0;
  }

  c.re = controller_B.b_ahi_m;
  c.im = controller_B.alo_g;
  return c;
}

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
static creal_T controller_two_diff(real_T b_a, real_T b)
{
  creal_T c;
  controller_B.shi_b = b_a - b;
  controller_B.bb = controller_B.shi_b - b_a;
  controller_B.bb = (b_a - (controller_B.shi_b - controller_B.bb)) - (b +
    controller_B.bb);
  controller_B.trueCount_d = 0;
  if (rtIsNaN(controller_B.bb)) {
    controller_B.trueCount_d = 1;
  }

  if (controller_B.trueCount_d - 1 >= 0) {
    controller_B.bb = 0.0;
  }

  c.re = controller_B.shi_b;
  c.im = controller_B.bb;
  return c;
}

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
static creal_T controller_floor(const creal_T b_a)
{
  creal_T b;
  b.re = floor(b_a.re);
  b.im = 0.0;
  if (b.re == b_a.re) {
    controller_B.b_b = floor(b_a.im);
    controller_B.alo_l = 0.0;
    controller_B.b_ahi_j = b.re;
    if (controller_B.b_b != 0.0) {
      controller_B.b_ahi_j = b.re + controller_B.b_b;
      controller_B.alo_l = controller_B.b_b - (controller_B.b_ahi_j - b.re);
    }

    if (rtIsNaN(controller_B.alo_l)) {
      controller_B.alo_l = 0.0;
    }

    b.re = controller_B.b_ahi_j;
    b.im = controller_B.alo_l;
  }

  return b;
}

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
static creal_T controller_minus(const creal_T b_a, const creal_T b)
{
  creal_T cout;
  controller_B.c = controller_two_diff(b_a.re, b.re);
  controller_B.t_m = controller_two_diff(b_a.im, b.im);
  controller_B.alo = controller_B.c.im;
  controller_B.ahi = controller_B.c.re;
  if (controller_B.t_m.re != 0.0) {
    controller_B.alo = controller_B.c.im + controller_B.t_m.re;
    controller_B.ahi = controller_B.c.re + controller_B.alo;
    controller_B.alo -= controller_B.ahi - controller_B.c.re;
  }

  if (rtIsNaN(controller_B.alo)) {
    controller_B.alo = 0.0;
  }

  controller_B.b_ahi = controller_B.ahi;
  if (controller_B.t_m.im != 0.0) {
    controller_B.alo += controller_B.t_m.im;
    controller_B.b_ahi = controller_B.ahi + controller_B.alo;
    controller_B.alo -= controller_B.b_ahi - controller_B.ahi;
  }

  if (rtIsNaN(controller_B.alo)) {
    controller_B.alo = 0.0;
  }

  cout.re = controller_B.b_ahi;
  cout.im = controller_B.alo;
  return cout;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void controller_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_Compare_b;

  {
    real_T (*lastU)[2];
    if (controller_M->Timing.TaskCounters.TID[2] == 0) {
      controller_AnalogInput(&controller_B.AnalogInput,
        &controller_DW.AnalogInput, &controller_P.AnalogInput);

      /* DataStoreWrite: '<Root>/Data Store Write5' */
      controller_DW.F1 = controller_B.AnalogInput.AnalogInput;
      controller_AnalogInput(&controller_B.AnalogInput1,
        &controller_DW.AnalogInput1, &controller_P.AnalogInput1);

      /* DataStoreWrite: '<Root>/Data Store Write6' */
      controller_DW.F2 = controller_B.AnalogInput1.AnalogInput;
    }

    /* DataStoreWrite: '<Root>/Data Store Write10' incorporates:
     *  Constant: '<Root>/Constant12'
     */
    controller_DW.GR2 = controller_P.Constant12_Value;
    if (controller_M->Timing.TaskCounters.TID[5] == 0) {
      /* DataStoreWrite: '<Root>/Data Store Write11' incorporates:
       *  Constant: '<Root>/Constant13'
       */
      controller_DW.state = controller_P.Constant13_Value;
    }

    /* DataStoreWrite: '<Root>/Data Store Write12' incorporates:
     *  Constant: '<Root>/Constant15'
     */
    controller_DW.debug = controller_P.Constant15_Value;

    /* DataStoreWrite: '<Root>/Data Store Write2' incorporates:
     *  Constant: '<Root>/Constant4'
     */
    controller_DW.num_motors = controller_P.Constant4_Value_g;

    /* DataStoreWrite: '<Root>/Data Store Write7' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    controller_DW.max_speed = controller_P.Constant5_Value;

    /* DataStoreWrite: '<Root>/Data Store Write8' incorporates:
     *  Constant: '<Root>/Constant6'
     */
    controller_DW.max_accel = controller_P.Constant6_Value;

    /* DataStoreWrite: '<Root>/Data Store Write9' incorporates:
     *  Constant: '<Root>/Constant7'
     */
    controller_DW.GR1 = controller_P.Constant7_Value;
    if (controller_M->Timing.TaskCounters.TID[2] == 0) {
      /* MATLABSystem: '<Root>/Digital Read' */
      if (controller_DW.obj_b.SampleTime != controller_P.DigitalRead_SampleTime)
      {
        controller_DW.obj_b.SampleTime = controller_P.DigitalRead_SampleTime;
      }

      /* DataStoreWrite: '<Root>/Data Store Write' incorporates:
       *  MATLABSystem: '<Root>/Digital Read'
       */
      controller_DW.LS1_R = MW_digitalIO_read
        (controller_DW.obj_b.MW_DIGITALIO_HANDLE);

      /* MATLABSystem: '<Root>/Digital Read1' */
      if (controller_DW.obj_a.SampleTime != controller_P.DigitalRead1_SampleTime)
      {
        controller_DW.obj_a.SampleTime = controller_P.DigitalRead1_SampleTime;
      }

      /* DataStoreWrite: '<Root>/Data Store Write1' incorporates:
       *  MATLABSystem: '<Root>/Digital Read1'
       */
      controller_DW.LS1_L = MW_digitalIO_read
        (controller_DW.obj_a.MW_DIGITALIO_HANDLE);

      /* MATLABSystem: '<Root>/Digital Read2' */
      if (controller_DW.obj_l.SampleTime != controller_P.DigitalRead2_SampleTime)
      {
        controller_DW.obj_l.SampleTime = controller_P.DigitalRead2_SampleTime;
      }

      /* DataStoreWrite: '<Root>/Data Store Write3' incorporates:
       *  MATLABSystem: '<Root>/Digital Read2'
       */
      controller_DW.LS2_R = MW_digitalIO_read
        (controller_DW.obj_l.MW_DIGITALIO_HANDLE);

      /* MATLABSystem: '<Root>/Digital Read3' */
      if (controller_DW.obj.SampleTime != controller_P.DigitalRead3_SampleTime)
      {
        controller_DW.obj.SampleTime = controller_P.DigitalRead3_SampleTime;
      }

      /* DataStoreWrite: '<Root>/Data Store Write4' incorporates:
       *  MATLABSystem: '<Root>/Digital Read3'
       */
      controller_DW.LS2_L = MW_digitalIO_read
        (controller_DW.obj.MW_DIGITALIO_HANDLE);
    }

    if (controller_M->Timing.TaskCounters.TID[3] == 0) {
      /* DataStoreRead: '<Root>/Data Store Read1' */
      controller_B.DataStoreRead1_c = controller_DW.state;

      /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
       *  DataStoreRead: '<Root>/Data Store Read1'
       */
      controller_B.shi = floor(controller_DW.state);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
       *  Constant: '<Root>/Constant14'
       */
      controller_B.rtb_Derivative_idx_0 = floor(controller_P.Constant14_Value);
      if (rtIsNaN(controller_B.rtb_Derivative_idx_0) || rtIsInf
          (controller_B.rtb_Derivative_idx_0)) {
        controller_B.rtb_Derivative_idx_0 = 0.0;
      } else {
        controller_B.rtb_Derivative_idx_0 = fmod
          (controller_B.rtb_Derivative_idx_0, 4.294967296E+9);
      }

      /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<Root>/Data Store Read9'
       */
      controller_B.b_alo = floor(controller_DW.debug);
      if (rtIsNaN(controller_B.b_alo) || rtIsInf(controller_B.b_alo)) {
        controller_B.b_alo = 0.0;
      } else {
        controller_B.b_alo = fmod(controller_B.b_alo, 4.294967296E+9);
      }

      /* CCaller: '<Root>/C Caller3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion'
       *  DataTypeConversion: '<Root>/Data Type Conversion1'
       *  DataTypeConversion: '<Root>/Data Type Conversion2'
       */
      print_input(controller_B.shi < 0.0 ? -(int32_T)(uint32_T)-controller_B.shi
                  : (int32_T)(uint32_T)controller_B.shi,
                  controller_B.rtb_Derivative_idx_0 < 0.0 ? -(int32_T)(uint32_T)
                  -controller_B.rtb_Derivative_idx_0 : (int32_T)(uint32_T)
                  controller_B.rtb_Derivative_idx_0, controller_B.b_alo < 0.0 ?
                  -(int32_T)(uint32_T)-controller_B.b_alo : (int32_T)(uint32_T)
                  controller_B.b_alo);

      /* Outputs for Enabled SubSystem: '<Root>/Initialize' incorporates:
       *  EnablePort: '<S14>/Enable'
       */
      /* RelationalOperator: '<S2>/Compare' incorporates:
       *  Constant: '<S2>/Constant'
       */
      if (controller_B.DataStoreRead1_c == controller_P.CompareToConstant2_const)
      {
        controller_DW.Initialize_MODE = true;
        if (controller_M->Timing.TaskCounters.TID[5] == 0) {
          /* DataTypeConversion: '<S14>/Data Type Conversion2' incorporates:
           *  DataStoreRead: '<S14>/Data Store Read7'
           */
          controller_B.shi = floor(controller_DW.num_motors);
          if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
            controller_B.shi = 0.0;
          } else {
            controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
          }

          /* CCaller: '<S14>/C Caller5' incorporates:
           *  Constant: '<S14>/Constant1'
           *  DataTypeConversion: '<S14>/Data Type Conversion2'
           */
          init_can(controller_B.shi < 0.0 ? -(int32_T)(uint32_T)
                   -controller_B.shi : (int32_T)(uint32_T)controller_B.shi,
                   controller_P.Constant1_Value_f,
                   controller_P.Constant1_Value_f, &controller_B.CCaller5[0]);

          /* DataStoreWrite: '<S14>/Data Store Write' */
          controller_DW.cfg_id = controller_B.CCaller5[0];

          /* DataStoreWrite: '<S14>/Data Store Write2' */
          controller_DW.pdo_id = controller_B.CCaller5[1];

          /* RelationalOperator: '<S36>/Compare' incorporates:
           *  Constant: '<S36>/Constant'
           */
          controller_B.Compare_a = (controller_B.CCaller5[1] !=
            controller_P.CompareToConstant_const);

          /* Switch: '<S37>/Switch' */
          if (controller_B.Compare_a) {
            /* DataStoreWrite: '<S37>/Data Store Write' incorporates:
             *  Constant: '<S14>/Constant'
             */
            controller_DW.state = controller_P.Constant_Value_d;
          }

          /* End of Switch: '<S37>/Switch' */
        }

        if (controller_M->Timing.TaskCounters.TID[4] == 0) {
          /* CCaller: '<S14>/C Caller3' */
          init_datalog();
        }
      } else {
        controller_DW.Initialize_MODE = false;
      }

      /* End of RelationalOperator: '<S2>/Compare' */
      /* End of Outputs for SubSystem: '<Root>/Initialize' */
    }

    /* DataStoreRead: '<Root>/Data Store Read10' */
    controller_B.DataStoreRead10 = controller_DW.LS1_L;

    /* RelationalOperator: '<S1>/Compare' incorporates:
     *  Constant: '<S1>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read'
     */
    controller_B.Compare = (controller_DW.state ==
      controller_P.CompareToConstant1_const);

    /* Outputs for Enabled SubSystem: '<Root>/Home1' */
    /* Constant: '<Root>/Constant' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    controller_Home1(controller_M, controller_B.Compare,
                     controller_P.Constant_Value_c,
                     controller_P.Constant1_Value_iv,
                     controller_B.DataStoreRead10, &controller_DW.GR1,
                     &controller_DW.GR2, &controller_DW.num_motors,
                     &controller_DW.pdo_id, &controller_DW.state,
                     &controller_B.Home1, &controller_DW.Home1,
                     &controller_P.Home1, &controller_PrevZCX.Home1);

    /* End of Outputs for SubSystem: '<Root>/Home1' */

    /* RelationalOperator: '<S3>/Compare' incorporates:
     *  Constant: '<S3>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read3'
     */
    controller_B.Compare_p = (controller_DW.state ==
      controller_P.CompareToConstant3_const);

    /* Outputs for Enabled SubSystem: '<Root>/Home2' incorporates:
     *  EnablePort: '<S11>/Enable'
     */
    controller_DW.Home2_MODE = controller_B.Compare_p;
    if (controller_DW.Home2_MODE) {
      /* RelationalOperator: '<S21>/Compare' incorporates:
       *  Constant: '<S21>/Constant'
       *  DataStoreRead: '<Root>/Data Store Read4'
       */
      controller_B.Compare_bf = (controller_DW.LS1_R ==
        controller_P.CompareToConstant1_const_p);

      /* Outputs for Triggered SubSystem: '<S11>/Stop Motor1' */
      controller_StopMotor1(controller_B.Compare_bf, &controller_DW.num_motors,
                            &controller_DW.pdo_id, &controller_B.StopMotor1,
                            &controller_P.StopMotor1,
                            &controller_PrevZCX.StopMotor1);

      /* End of Outputs for SubSystem: '<S11>/Stop Motor1' */

      /* DataStoreWrite: '<S11>/Data Store Write' */
      controller_DW.q01 = controller_B.StopMotor1.CCaller1[0];

      /* Switch: '<S25>/Switch' */
      if (controller_B.Compare_bf) {
        /* DataStoreWrite: '<S25>/Data Store Write' incorporates:
         *  Constant: '<S11>/Constant1'
         */
        controller_DW.state = controller_P.Constant1_Value_i;
      }

      /* End of Switch: '<S25>/Switch' */
      if (controller_M->Timing.TaskCounters.TID[2] == 0) {
        /* DataStoreRead: '<S24>/Data Store Read2' */
        controller_B.DataTypeConversion1_c = controller_DW.pdo_id;

        /* DataTypeConversion: '<S24>/Data Type Conversion1' incorporates:
         *  Constant: '<Root>/Constant2'
         */
        controller_B.shi = floor(controller_P.Constant2_Value_h);
        if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
          controller_B.shi = 0.0;
        } else {
          controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
        }

        controller_B.DataStoreRead2_m = controller_B.shi < 0.0 ? -(int32_T)
          (uint32_T)-controller_B.shi : (int32_T)(uint32_T)controller_B.shi;

        /* End of DataTypeConversion: '<S24>/Data Type Conversion1' */
      }

      /* DataTypeConversion: '<S11>/Data Type Conversion7' incorporates:
       *  DataStoreRead: '<S11>/Data Store Read7'
       */
      controller_B.shi = floor(controller_DW.num_motors);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S11>/C Caller1' incorporates:
       *  DataStoreRead: '<S11>/Data Store Read2'
       *  DataTypeConversion: '<S11>/Data Type Conversion7'
       */
      get_encoder(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)
                  (uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                  controller_B.shi, &controller_B.CCaller1_k[0]);

      /* RelationalOperator: '<S22>/Compare' incorporates:
       *  Constant: '<S22>/Constant'
       */
      controller_B.Compare_a = (controller_B.CCaller1_k[0] !=
        controller_P.Constant_Value_e);
      controller_B.rtb_Compare_e_idx_1 = (controller_B.CCaller1_k[1] !=
        controller_P.Constant_Value_e);

      /* Switch: '<S11>/Switch' */
      if (controller_B.Compare_a) {
        /* Switch: '<S11>/Switch' */
        controller_B.Switch_f[0] = controller_B.CCaller1_k[0];
      } else {
        /* Switch: '<S11>/Switch' incorporates:
         *  Delay: '<S11>/Delay'
         */
        controller_B.Switch_f[0] = controller_DW.Delay_DSTATE_h[0];
      }

      if (controller_B.rtb_Compare_e_idx_1) {
        /* Switch: '<S11>/Switch' */
        controller_B.Switch_f[1] = controller_B.CCaller1_k[1];
      } else {
        /* Switch: '<S11>/Switch' incorporates:
         *  Delay: '<S11>/Delay'
         */
        controller_B.Switch_f[1] = controller_DW.Delay_DSTATE_h[1];
      }

      /* End of Switch: '<S11>/Switch' */

      /* Gain: '<S11>/Gain2' incorporates:
       *  DataStoreRead: '<S11>/Data Store Read1'
       *  DataStoreRead: '<S11>/Data Store Read8'
       *  Gain: '<S11>/Gain'
       *  Gain: '<S11>/Gain1'
       *  Product: '<S11>/Divide'
       */
      controller_B.Gain2_p[0] = controller_B.Switch_f[0] /
        (controller_P.Gain_Gain * controller_DW.GR1) * controller_P.Gain2_Gain;
      controller_B.Gain2_p[1] = controller_B.Switch_f[1] /
        (controller_P.Gain1_Gain * controller_DW.GR2) * controller_P.Gain2_Gain;

      /* Derivative: '<S11>/Derivative' */
      controller_B.shi = controller_M->Timing.t[0];
      if ((controller_DW.TimeStampA_g >= controller_B.shi) &&
          (controller_DW.TimeStampB_f >= controller_B.shi)) {
        controller_B.rtb_Derivative_idx_0 = 0.0;
      } else {
        controller_B.DataStoreRead1_c = controller_DW.TimeStampA_g;
        lastU = &controller_DW.LastUAtTimeA_o;
        if (controller_DW.TimeStampA_g < controller_DW.TimeStampB_f) {
          if (controller_DW.TimeStampB_f < controller_B.shi) {
            controller_B.DataStoreRead1_c = controller_DW.TimeStampB_f;
            lastU = &controller_DW.LastUAtTimeB_n;
          }
        } else if (controller_DW.TimeStampA_g >= controller_B.shi) {
          controller_B.DataStoreRead1_c = controller_DW.TimeStampB_f;
          lastU = &controller_DW.LastUAtTimeB_n;
        }

        controller_B.rtb_Derivative_idx_0 = (controller_B.Gain2_p[0] - (*lastU)
          [0]) / (controller_B.shi - controller_B.DataStoreRead1_c);
      }

      /* End of Derivative: '<S11>/Derivative' */

      /* Gain: '<S11>/Gain3' incorporates:
       *  Constant: '<Root>/Constant3'
       *  Sum: '<S11>/Sum1'
       */
      controller_B.Saturation_n = (controller_B.rtb_Derivative_idx_0 -
        controller_P.Constant3_Value) * controller_P.Gain3_Gain;

      /* Saturate: '<S11>/Saturation' */
      if (controller_B.Saturation_n > controller_P.Saturation_UpperSat) {
        /* Gain: '<S11>/Gain3' incorporates:
         *  Saturate: '<S11>/Saturation'
         */
        controller_B.Saturation_n = controller_P.Saturation_UpperSat;
      } else if (controller_B.Saturation_n < controller_P.Saturation_LowerSat) {
        /* Gain: '<S11>/Gain3' incorporates:
         *  Saturate: '<S11>/Saturation'
         */
        controller_B.Saturation_n = controller_P.Saturation_LowerSat;
      }

      /* End of Saturate: '<S11>/Saturation' */
      if (controller_M->Timing.TaskCounters.TID[2] == 0) {
        /* CCaller: '<S24>/C Caller3' */
        set_motor(controller_B.DataTypeConversion1_c,
                  controller_B.DataStoreRead2_m, controller_B.Saturation_n);
      }
    }

    /* End of Outputs for SubSystem: '<Root>/Home2' */

    /* DataStoreRead: '<Root>/Data Store Read7' */
    controller_B.rtb_Derivative_idx_0 = controller_DW.q01;

    /* DataStoreRead: '<Root>/Data Store Read8' */
    controller_B.DataStoreRead1_c = controller_DW.q02;

    /* RelationalOperator: '<S4>/Compare' incorporates:
     *  Constant: '<S4>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read2'
     */
    controller_B.Compare_j = (controller_DW.state ==
      controller_P.CompareToConstant4_const);

    /* Outputs for Enabled SubSystem: '<Root>/Main Control' incorporates:
     *  EnablePort: '<S15>/Enable'
     */
    controller_DW.MainControl_MODE = controller_B.Compare_j;
    if (controller_DW.MainControl_MODE) {
      /* Switch: '<S41>/Switch' incorporates:
       *  Constant: '<S38>/Constant'
       *  DataStoreRead: '<S15>/Data Store Read3'
       *  RelationalOperator: '<S38>/Compare'
       */
      if (controller_DW.LS1_R == controller_P.CompareToConstant_const_g) {
        /* DataStoreWrite: '<S41>/Data Store Write' incorporates:
         *  Constant: '<S15>/Constant4'
         */
        controller_DW.state = controller_P.Constant4_Value;
      }

      /* End of Switch: '<S41>/Switch' */

      /* MATLAB Function: '<S15>/MATLAB Function' */
      controller_getLocalTime(&controller_B.fracSecs, &controller_B.second,
        &controller_B.shi, &controller_B.b_alo, &controller_B.d_ahi_c,
        &controller_B.c_tm_mon, &controller_B.c_tm_year, &controller_B.Compare_a);
      controller_B.fracSecs /= 1.0E+6;
      controller_B.check = (((((controller_B.c_tm_year + controller_B.c_tm_mon)
        + controller_B.d_ahi_c) + controller_B.b_alo) + controller_B.shi) +
                            controller_B.second) + controller_B.fracSecs;
      if ((!rtIsInf(controller_B.check)) && (!rtIsNaN(controller_B.check))) {
        if ((controller_B.c_tm_mon < 1.0) || (controller_B.c_tm_mon > 12.0)) {
          controller_B.check = floor((controller_B.c_tm_mon - 1.0) / 12.0);
          controller_B.c_tm_year += controller_B.check;
          controller_B.c_tm_mon = ((controller_B.c_tm_mon - 1.0) -
            controller_B.check * 12.0) + 1.0;
        }

        if (controller_B.c_tm_mon < 3.0) {
          controller_B.c_tm_year--;
          controller_B.c_tm_mon += 9.0;
        } else {
          controller_B.c_tm_mon -= 3.0;
        }

        if ((controller_B.fracSecs < 0.0) || (controller_B.fracSecs >= 1000.0))
        {
          controller_B.check = floor(controller_B.fracSecs / 1000.0);
          controller_B.second += controller_B.check;
          controller_B.fracSecs -= controller_B.check * 1000.0;
        }

        controller_B.d_data.re = ((((((365.0 * controller_B.c_tm_year + floor
          (controller_B.c_tm_year / 4.0)) - floor(controller_B.c_tm_year / 100.0))
          + floor(controller_B.c_tm_year / 400.0)) + floor((153.0 *
          controller_B.c_tm_mon + 2.0) / 5.0)) + controller_B.d_ahi_c) + 60.0) -
          719529.0;
        controller_B.d_data.im = 0.0;
        controller_B.d_data = controller_plus(controller_plus(controller_plus
          (controller_times(controller_B.d_data), (60.0 * controller_B.b_alo +
          controller_B.shi) * 60000.0), controller_B.second * 1000.0),
          controller_B.fracSecs);
      } else {
        controller_B.d_data.re = controller_B.check;
        controller_B.d_data.im = 0.0;
      }

      controller_B.b_c.re = controller_B.d_data.re / 8.64E+7;
      controller_B.t = controller_two_prod(controller_B.b_c.re);
      controller_B.c_s.re = 0.0;
      controller_B.c_s.im = 0.0;
      if (controller_B.d_data.re != controller_B.t.re) {
        controller_B.c_s = controller_two_diff(controller_B.d_data.re,
          controller_B.t.re);
      }

      controller_B.c_s.re = (0.0 * controller_B.d_data.im + controller_B.c_s.re)
        - 0.0 * controller_B.t.im;
      controller_B.c_s.im = (controller_B.c_s.im + controller_B.d_data.im) -
        controller_B.t.im;
      controller_B.shi = (controller_B.c_s.re + controller_B.c_s.im) / 8.64E+7;
      controller_B.b_alo = 0.0;
      controller_B.d_ahi_c = controller_B.b_c.re;
      if (controller_B.shi != 0.0) {
        controller_B.d_ahi_c = controller_B.b_c.re + controller_B.shi;
        controller_B.b_alo = controller_B.shi - (controller_B.d_ahi_c -
          controller_B.b_c.re);
      }

      if (rtIsNaN(controller_B.b_alo)) {
        controller_B.b_alo = 0.0;
      }

      controller_B.d_ahi.re = controller_B.d_ahi_c;
      controller_B.d_ahi.im = controller_B.b_alo;
      controller_B.d_data = controller_minus(controller_B.d_data,
        controller_times(controller_floor(controller_B.d_ahi)));
      controller_B.b_c.re = controller_B.d_data.re / 1000.0;
      controller_B.t = controller_split(controller_B.b_c.re);
      controller_B.shi = controller_B.b_c.re * 1000.0;
      controller_B.b_alo = (controller_B.t.re * 1000.0 - controller_B.shi) +
        controller_B.t.im * 1000.0;
      controller_B.trueCount = 0;
      if (rtIsNaN(controller_B.b_alo)) {
        controller_B.trueCount = 1;
      }

      if (controller_B.trueCount - 1 >= 0) {
        controller_B.b_alo = 0.0;
      }

      controller_B.c_s.re = 0.0;
      controller_B.c_s.im = 0.0;
      if (controller_B.d_data.re != controller_B.shi) {
        controller_B.c_s = controller_two_diff(controller_B.d_data.re,
          controller_B.shi);
      }

      controller_B.c_s.re = (0.0 * controller_B.d_data.im + controller_B.c_s.re)
        - 0.0 * controller_B.b_alo;
      controller_B.c_s.im = (controller_B.c_s.im + controller_B.d_data.im) -
        controller_B.b_alo;
      controller_B.shi = (controller_B.c_s.re + controller_B.c_s.im) / 1000.0;
      controller_B.b_alo = 0.0;
      controller_B.d_ahi_c = controller_B.b_c.re;
      if (controller_B.shi != 0.0) {
        controller_B.d_ahi_c = controller_B.b_c.re + controller_B.shi;
        controller_B.b_alo = controller_B.shi - (controller_B.d_ahi_c -
          controller_B.b_c.re);
      }

      if (rtIsNaN(controller_B.b_alo)) {
        controller_B.b_alo = 0.0;
      }

      controller_B.d_data.re = controller_B.d_ahi_c;
      controller_B.d_data.im = controller_B.b_alo;
      controller_B.t = controller_floor(controller_B.d_data);
      controller_B.b_c = controller_minus(controller_B.d_data, controller_B.t);
      controller_B.shi = controller_B.t.re + controller_B.t.im;
      if ((controller_B.shi >= 0.0) && (controller_B.shi <= 2.147483647E+9)) {
        controller_B.trueCount = (int32_T)rt_roundd_snf(controller_B.shi);
        controller_B.trueCount -= 3600 * div_s32(controller_B.trueCount, 3600);
        controller_B.shi = controller_B.trueCount - 60 * div_s32
          (controller_B.trueCount, 60);
      } else {
        controller_B.shi -= floor((controller_B.shi - floor(controller_B.shi /
          3600.0) * 3600.0) / 60.0) * 60.0;
      }

      controller_B.b_alo = (controller_B.b_c.re + controller_B.b_c.im) +
        controller_B.shi;
      if (controller_B.b_alo == 60.0) {
        controller_B.b_alo = 59.999999999999993;
      }

      /* DataTypeConversion: '<S15>/Data Type Conversion7' incorporates:
       *  DataStoreRead: '<S15>/Data Store Read7'
       */
      controller_B.shi = floor(controller_DW.num_motors);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S15>/C Caller1' incorporates:
       *  DataStoreRead: '<S15>/Data Store Read2'
       *  DataTypeConversion: '<S15>/Data Type Conversion7'
       */
      get_encoder(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)
                  (uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                  controller_B.shi, &controller_B.CCaller1[0]);

      /* Sum: '<S15>/Sum' */
      controller_B.rtb_Derivative_idx_0 = controller_B.CCaller1[0] -
        controller_B.rtb_Derivative_idx_0;
      controller_B.DataStoreRead1_c = controller_B.CCaller1[1] -
        controller_B.DataStoreRead1_c;

      /* RelationalOperator: '<S39>/Compare' incorporates:
       *  Constant: '<S39>/Constant'
       */
      controller_B.Compare_e[0] = (controller_B.CCaller1[0] !=
        controller_P.Constant_Value_p);
      controller_B.Compare_e[1] = (controller_B.CCaller1[1] !=
        controller_P.Constant_Value_p);

      /* Delay: '<S15>/Delay' */
      controller_B.Delay[0] = controller_DW.Delay_DSTATE[0];

      /* Switch: '<S15>/Switch' */
      if (controller_B.Compare_e[0]) {
        /* Switch: '<S15>/Switch' */
        controller_B.Switch[0] = controller_B.rtb_Derivative_idx_0;
      } else {
        /* Switch: '<S15>/Switch' */
        controller_B.Switch[0] = controller_B.Delay[0];
      }

      /* Delay: '<S15>/Delay' */
      controller_B.Delay[1] = controller_DW.Delay_DSTATE[1];

      /* Switch: '<S15>/Switch' */
      if (controller_B.Compare_e[1]) {
        /* Switch: '<S15>/Switch' */
        controller_B.Switch[1] = controller_B.DataStoreRead1_c;
      } else {
        /* Switch: '<S15>/Switch' */
        controller_B.Switch[1] = controller_B.Delay[1];
      }

      /* Gain: '<S15>/Gain2' incorporates:
       *  DataStoreRead: '<S15>/Data Store Read1'
       *  DataStoreRead: '<S15>/Data Store Read8'
       *  Gain: '<S15>/Gain'
       *  Gain: '<S15>/Gain1'
       *  Product: '<S15>/Divide'
       */
      controller_B.Gain2[0] = controller_B.Switch[0] / (controller_P.Gain_Gain_m
        * controller_DW.GR1) * controller_P.Gain2_Gain_b1;
      controller_B.Gain2[1] = controller_B.Switch[1] /
        (controller_P.Gain1_Gain_g * controller_DW.GR2) *
        controller_P.Gain2_Gain_b1;

      /* SignalConversion generated from: '<S15>/C Caller4' incorporates:
       *  MATLAB Function: '<S15>/MATLAB Function'
       */
      controller_B.TmpSignalConversionAtCCalle[0] = controller_B.b_alo;
      controller_B.TmpSignalConversionAtCCalle[1] = controller_B.Gain2[0];
      controller_B.TmpSignalConversionAtCCalle[2] = controller_B.Gain2[1];

      /* DataTypeConversion: '<S15>/Data Type Conversion2' incorporates:
       *  Constant: '<S15>/Constant2'
       */
      controller_B.shi = floor(controller_P.Constant2_Value);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S15>/C Caller4' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion2'
       */
      print_data(&controller_B.TmpSignalConversionAtCCalle[0], controller_B.shi <
                 0.0 ? -(int32_T)(uint32_T)-controller_B.shi : (int32_T)
                 (uint32_T)controller_B.shi);

      /* Sin: '<S15>/Sine Wave' */
      controller_B.SineWave = sin(controller_P.SineWave_Freq *
        controller_M->Timing.t[0] + controller_P.SineWave_Phase) *
        controller_P.SineWave_Amp + controller_P.SineWave_Bias;

      /* DataTypeConversion: '<S42>/Data Type Conversion1' incorporates:
       *  Constant: '<S15>/Constant'
       */
      controller_B.shi = floor(controller_P.Constant_Value_iy);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S42>/C Caller3' incorporates:
       *  DataStoreRead: '<S42>/Data Store Read2'
       *  DataTypeConversion: '<S42>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)
                (uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                controller_B.shi, controller_B.SineWave);

      /* DataTypeConversion: '<S43>/Data Type Conversion1' incorporates:
       *  Constant: '<S15>/Constant1'
       */
      controller_B.shi = floor(controller_P.Constant1_Value_m);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S43>/C Caller3' incorporates:
       *  DataStoreRead: '<S43>/Data Store Read2'
       *  DataTypeConversion: '<S43>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)
                (uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                controller_B.shi, controller_B.SineWave);
    }

    /* End of Outputs for SubSystem: '<Root>/Main Control' */

    /* DataStoreRead: '<Root>/Data Store Read11' */
    controller_B.DataStoreRead11 = controller_DW.LS2_L;

    /* RelationalOperator: '<S5>/Compare' incorporates:
     *  Constant: '<S5>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read5'
     */
    controller_B.Compare_pw = (controller_DW.state ==
      controller_P.CompareToConstant5_const);

    /* Outputs for Enabled SubSystem: '<Root>/Home3' */
    /* Constant: '<Root>/Constant8' incorporates:
     *  Constant: '<Root>/Constant9'
     */
    controller_Home1(controller_M, controller_B.Compare_pw,
                     controller_P.Constant8_Value, controller_P.Constant9_Value,
                     controller_B.DataStoreRead11, &controller_DW.GR1,
                     &controller_DW.GR2, &controller_DW.num_motors,
                     &controller_DW.pdo_id, &controller_DW.state,
                     &controller_B.Home3, &controller_DW.Home3,
                     &controller_P.Home3, &controller_PrevZCX.Home3);

    /* End of Outputs for SubSystem: '<Root>/Home3' */

    /* RelationalOperator: '<S6>/Compare' incorporates:
     *  Constant: '<S6>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read12'
     */
    controller_B.Compare_pd = (controller_DW.state ==
      controller_P.CompareToConstant6_const);

    /* Outputs for Enabled SubSystem: '<Root>/Home4' incorporates:
     *  EnablePort: '<S13>/Enable'
     */
    controller_DW.Home4_MODE = controller_B.Compare_pd;
    if (controller_DW.Home4_MODE) {
      /* RelationalOperator: '<S31>/Compare' incorporates:
       *  Constant: '<S31>/Constant'
       *  DataStoreRead: '<Root>/Data Store Read13'
       */
      rtb_Compare_b = (controller_DW.LS2_R ==
                       controller_P.CompareToConstant1_const_e);

      /* Outputs for Triggered SubSystem: '<S13>/Stop Motor1' */
      controller_StopMotor1(rtb_Compare_b, &controller_DW.num_motors,
                            &controller_DW.pdo_id, &controller_B.StopMotor1_d,
                            &controller_P.StopMotor1_d,
                            &controller_PrevZCX.StopMotor1_d);

      /* End of Outputs for SubSystem: '<S13>/Stop Motor1' */

      /* DataStoreWrite: '<S13>/Data Store Write' */
      controller_DW.q02 = controller_B.StopMotor1_d.CCaller1[0];

      /* Switch: '<S35>/Switch' */
      if (rtb_Compare_b) {
        /* DataStoreWrite: '<S35>/Data Store Write' incorporates:
         *  Constant: '<S13>/Constant1'
         */
        controller_DW.state = controller_P.Constant1_Value_ih;
      }

      /* End of Switch: '<S35>/Switch' */
      if (controller_M->Timing.TaskCounters.TID[2] == 0) {
        /* DataStoreRead: '<S34>/Data Store Read2' */
        controller_B.DataStoreRead2_m = controller_DW.pdo_id;

        /* DataTypeConversion: '<S34>/Data Type Conversion1' incorporates:
         *  Constant: '<Root>/Constant10'
         */
        controller_B.shi = floor(controller_P.Constant10_Value);
        if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
          controller_B.shi = 0.0;
        } else {
          controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
        }

        controller_B.DataTypeConversion1_c = controller_B.shi < 0.0 ? -(int32_T)
          (uint32_T)-controller_B.shi : (int32_T)(uint32_T)controller_B.shi;

        /* End of DataTypeConversion: '<S34>/Data Type Conversion1' */
      }

      /* DataTypeConversion: '<S13>/Data Type Conversion7' incorporates:
       *  DataStoreRead: '<S13>/Data Store Read7'
       */
      controller_B.shi = floor(controller_DW.num_motors);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S13>/C Caller1' incorporates:
       *  DataStoreRead: '<S13>/Data Store Read2'
       *  DataTypeConversion: '<S13>/Data Type Conversion7'
       */
      get_encoder(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)
                  (uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                  controller_B.shi, &controller_B.CCaller1_k[0]);

      /* RelationalOperator: '<S32>/Compare' incorporates:
       *  Constant: '<S32>/Constant'
       */
      controller_B.Compare_a = (controller_B.CCaller1_k[0] !=
        controller_P.Constant_Value_i);
      controller_B.rtb_Compare_e_idx_1 = (controller_B.CCaller1_k[1] !=
        controller_P.Constant_Value_i);

      /* Switch: '<S13>/Switch' */
      if (controller_B.Compare_a) {
        /* Switch: '<S13>/Switch' */
        controller_B.Switch_j[0] = controller_B.CCaller1_k[0];
      } else {
        /* Switch: '<S13>/Switch' incorporates:
         *  Delay: '<S13>/Delay'
         */
        controller_B.Switch_j[0] = controller_DW.Delay_DSTATE_m[0];
      }

      if (controller_B.rtb_Compare_e_idx_1) {
        /* Switch: '<S13>/Switch' */
        controller_B.Switch_j[1] = controller_B.CCaller1_k[1];
      } else {
        /* Switch: '<S13>/Switch' incorporates:
         *  Delay: '<S13>/Delay'
         */
        controller_B.Switch_j[1] = controller_DW.Delay_DSTATE_m[1];
      }

      /* End of Switch: '<S13>/Switch' */

      /* Gain: '<S13>/Gain2' incorporates:
       *  DataStoreRead: '<S13>/Data Store Read1'
       *  DataStoreRead: '<S13>/Data Store Read8'
       *  Gain: '<S13>/Gain'
       *  Gain: '<S13>/Gain1'
       *  Product: '<S13>/Divide'
       */
      controller_B.Gain2_j[0] = controller_B.Switch_j[0] /
        (controller_P.Gain_Gain_b * controller_DW.GR1) *
        controller_P.Gain2_Gain_b;
      controller_B.Gain2_j[1] = controller_B.Switch_j[1] /
        (controller_P.Gain1_Gain_d * controller_DW.GR2) *
        controller_P.Gain2_Gain_b;

      /* Derivative: '<S13>/Derivative' */
      controller_B.shi = controller_M->Timing.t[0];
      if ((controller_DW.TimeStampA >= controller_B.shi) &&
          (controller_DW.TimeStampB >= controller_B.shi)) {
        controller_B.rtb_Derivative_idx_0 = 0.0;
      } else {
        controller_B.DataStoreRead1_c = controller_DW.TimeStampA;
        lastU = &controller_DW.LastUAtTimeA;
        if (controller_DW.TimeStampA < controller_DW.TimeStampB) {
          if (controller_DW.TimeStampB < controller_B.shi) {
            controller_B.DataStoreRead1_c = controller_DW.TimeStampB;
            lastU = &controller_DW.LastUAtTimeB;
          }
        } else if (controller_DW.TimeStampA >= controller_B.shi) {
          controller_B.DataStoreRead1_c = controller_DW.TimeStampB;
          lastU = &controller_DW.LastUAtTimeB;
        }

        controller_B.rtb_Derivative_idx_0 = (controller_B.Gain2_j[0] - (*lastU)
          [0]) / (controller_B.shi - controller_B.DataStoreRead1_c);
      }

      /* End of Derivative: '<S13>/Derivative' */

      /* Gain: '<S13>/Gain3' incorporates:
       *  Constant: '<Root>/Constant11'
       *  Sum: '<S13>/Sum1'
       */
      controller_B.Saturation = (controller_B.rtb_Derivative_idx_0 -
        controller_P.Constant11_Value) * controller_P.Gain3_Gain_i;

      /* Saturate: '<S13>/Saturation' */
      if (controller_B.Saturation > controller_P.Saturation_UpperSat_k) {
        /* Gain: '<S13>/Gain3' incorporates:
         *  Saturate: '<S13>/Saturation'
         */
        controller_B.Saturation = controller_P.Saturation_UpperSat_k;
      } else if (controller_B.Saturation < controller_P.Saturation_LowerSat_f) {
        /* Gain: '<S13>/Gain3' incorporates:
         *  Saturate: '<S13>/Saturation'
         */
        controller_B.Saturation = controller_P.Saturation_LowerSat_f;
      }

      /* End of Saturate: '<S13>/Saturation' */
      if (controller_M->Timing.TaskCounters.TID[2] == 0) {
        /* CCaller: '<S34>/C Caller3' */
        set_motor(controller_B.DataStoreRead2_m,
                  controller_B.DataTypeConversion1_c, controller_B.Saturation);
      }
    }

    /* End of Outputs for SubSystem: '<Root>/Home4' */

    /* RelationalOperator: '<S7>/Compare' incorporates:
     *  Constant: '<S7>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read6'
     */
    controller_B.Compare_a = (controller_DW.state ==
      controller_P.CompareToConstant7_const);

    /* Outputs for Triggered SubSystem: '<Root>/Exit Control' incorporates:
     *  TriggerPort: '<S9>/Trigger'
     */
    if (controller_B.Compare_a && (controller_PrevZCX.ExitControl_Trig_ZCE !=
         POS_ZCSIG)) {
      /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
       *  DataStoreRead: '<S9>/Data Store Read7'
       */
      controller_B.shi = floor(controller_DW.num_motors);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S9>/C Caller1' incorporates:
       *  DataStoreRead: '<S9>/Data Store Read1'
       *  DataTypeConversion: '<S9>/Data Type Conversion'
       */
      stop_motor(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)
                 (uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                 controller_B.shi);

      /* CCaller: '<S9>/C Caller4' */
      close_datalog();
    }

    controller_PrevZCX.ExitControl_Trig_ZCE = controller_B.Compare_a;

    /* End of Outputs for SubSystem: '<Root>/Exit Control' */
  }

  {
    real_T (*lastU)[2];

    /* Update for Enabled SubSystem: '<Root>/Home1' */
    controller_Home1_Update(controller_M, &controller_B.Home1,
      &controller_DW.Home1);

    /* End of Update for SubSystem: '<Root>/Home1' */

    /* Update for Enabled SubSystem: '<Root>/Home2' incorporates:
     *  EnablePort: '<S11>/Enable'
     */
    if (controller_DW.Home2_MODE) {
      /* Update for Delay: '<S11>/Delay' */
      controller_DW.Delay_DSTATE_h[0] = controller_B.Switch_f[0];
      controller_DW.Delay_DSTATE_h[1] = controller_B.Switch_f[1];

      /* Update for Derivative: '<S11>/Derivative' */
      if (controller_DW.TimeStampA_g == (rtInf)) {
        controller_DW.TimeStampA_g = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeA_o;
      } else if (controller_DW.TimeStampB_f == (rtInf)) {
        controller_DW.TimeStampB_f = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeB_n;
      } else if (controller_DW.TimeStampA_g < controller_DW.TimeStampB_f) {
        controller_DW.TimeStampA_g = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeA_o;
      } else {
        controller_DW.TimeStampB_f = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeB_n;
      }

      (*lastU)[0] = controller_B.Gain2_p[0];
      (*lastU)[1] = controller_B.Gain2_p[1];

      /* End of Update for Derivative: '<S11>/Derivative' */
    }

    /* End of Update for SubSystem: '<Root>/Home2' */

    /* Update for Enabled SubSystem: '<Root>/Main Control' incorporates:
     *  EnablePort: '<S15>/Enable'
     */
    if (controller_DW.MainControl_MODE) {
      /* Update for Delay: '<S15>/Delay' */
      controller_DW.Delay_DSTATE[0] = controller_B.Switch[0];
      controller_DW.Delay_DSTATE[1] = controller_B.Switch[1];
    }

    /* End of Update for SubSystem: '<Root>/Main Control' */

    /* Update for Enabled SubSystem: '<Root>/Home3' */
    controller_Home1_Update(controller_M, &controller_B.Home3,
      &controller_DW.Home3);

    /* End of Update for SubSystem: '<Root>/Home3' */

    /* Update for Enabled SubSystem: '<Root>/Home4' incorporates:
     *  EnablePort: '<S13>/Enable'
     */
    if (controller_DW.Home4_MODE) {
      /* Update for Delay: '<S13>/Delay' */
      controller_DW.Delay_DSTATE_m[0] = controller_B.Switch_j[0];
      controller_DW.Delay_DSTATE_m[1] = controller_B.Switch_j[1];

      /* Update for Derivative: '<S13>/Derivative' */
      if (controller_DW.TimeStampA == (rtInf)) {
        controller_DW.TimeStampA = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeA;
      } else if (controller_DW.TimeStampB == (rtInf)) {
        controller_DW.TimeStampB = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeB;
      } else if (controller_DW.TimeStampA < controller_DW.TimeStampB) {
        controller_DW.TimeStampA = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeA;
      } else {
        controller_DW.TimeStampB = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeB;
      }

      (*lastU)[0] = controller_B.Gain2_j[0];
      (*lastU)[1] = controller_B.Gain2_j[1];

      /* End of Update for Derivative: '<S13>/Derivative' */
    }

    /* End of Update for SubSystem: '<Root>/Home4' */
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

  /* states (dwork) */
  (void) memset((void *)&controller_DW, 0,
                sizeof(DW_controller_T));

  {
    beagleboneblue_bbblueDigitalR_T *obj;

    /* Start for Triggered SubSystem: '<Root>/E-stop' */
    /* Start for MATLABSystem: '<S8>/LED' */
    controller_DW.obj_n.matlabCodegenIsDeleted = false;
    controller_DW.objisempty = true;
    controller_DW.obj_n.isInitialized = 1;
    controller_DW.obj_n.isSetupComplete = true;

    /* End of Start for SubSystem: '<Root>/E-stop' */
    controller_AnalogInput_Start(&controller_DW.AnalogInput,
      &controller_P.AnalogInput);
    controller_AnalogInput_Start(&controller_DW.AnalogInput1,
      &controller_P.AnalogInput1);

    /* Start for MATLABSystem: '<Root>/Digital Read' */
    controller_DW.obj_b.matlabCodegenIsDeleted = false;
    controller_DW.objisempty_g = true;
    controller_DW.obj_b.SampleTime = controller_P.DigitalRead_SampleTime;
    obj = &controller_DW.obj_b;
    controller_DW.obj_b.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(113, 0);
    controller_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read1' */
    controller_DW.obj_a.matlabCodegenIsDeleted = false;
    controller_DW.objisempty_i = true;
    controller_DW.obj_a.SampleTime = controller_P.DigitalRead1_SampleTime;
    obj = &controller_DW.obj_a;
    controller_DW.obj_a.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(116, 0);
    controller_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read2' */
    controller_DW.obj_l.matlabCodegenIsDeleted = false;
    controller_DW.objisempty_f2 = true;
    controller_DW.obj_l.SampleTime = controller_P.DigitalRead2_SampleTime;
    obj = &controller_DW.obj_l;
    controller_DW.obj_l.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(49, 0);
    controller_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read3' */
    controller_DW.obj.matlabCodegenIsDeleted = false;
    controller_DW.objisempty_f = true;
    controller_DW.obj.SampleTime = controller_P.DigitalRead3_SampleTime;
    obj = &controller_DW.obj;
    controller_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(57, 0);
    controller_DW.obj.isSetupComplete = true;

    /* Start for Enabled SubSystem: '<Root>/Initialize' */
    controller_DW.Initialize_MODE = false;

    /* End of Start for SubSystem: '<Root>/Initialize' */

    /* Start for Enabled SubSystem: '<Root>/Home1' */
    controller_Home1_Start(&controller_DW.Home1);

    /* End of Start for SubSystem: '<Root>/Home1' */

    /* Start for Enabled SubSystem: '<Root>/Home2' */
    controller_DW.Home2_MODE = false;

    /* End of Start for SubSystem: '<Root>/Home2' */

    /* Start for Enabled SubSystem: '<Root>/Main Control' */
    controller_DW.MainControl_MODE = false;

    /* End of Start for SubSystem: '<Root>/Main Control' */

    /* Start for Enabled SubSystem: '<Root>/Home3' */
    controller_Home1_Start(&controller_DW.Home3);

    /* End of Start for SubSystem: '<Root>/Home3' */

    /* Start for Enabled SubSystem: '<Root>/Home4' */
    controller_DW.Home4_MODE = false;

    /* End of Start for SubSystem: '<Root>/Home4' */

    /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
    controller_DW.state = controller_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    controller_DW.LS1_R = controller_P.DataStoreMemory1_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory10' */
    controller_DW.F1 = controller_P.DataStoreMemory10_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory11' */
    controller_DW.F2 = controller_P.DataStoreMemory11_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory12' */
    controller_DW.max_speed = controller_P.DataStoreMemory12_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory13' */
    controller_DW.max_accel = controller_P.DataStoreMemory13_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory14' */
    controller_DW.GR1 = controller_P.DataStoreMemory14_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory15' */
    controller_DW.GR2 = controller_P.DataStoreMemory15_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory16' */
    controller_DW.debug = controller_P.DataStoreMemory16_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    controller_DW.q01 = controller_P.DataStoreMemory2_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
    controller_DW.LS2_R = controller_P.DataStoreMemory3_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
    controller_DW.pdo_id = controller_P.DataStoreMemory4_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
    controller_DW.q02 = controller_P.DataStoreMemory5_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
    controller_DW.cfg_id = controller_P.DataStoreMemory6_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
    controller_DW.num_motors = controller_P.DataStoreMemory7_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
    controller_DW.LS1_L = controller_P.DataStoreMemory8_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory9' */
    controller_DW.LS2_L = controller_P.DataStoreMemory9_InitialValue;
  }

  controller_PrevZCX.Estop_Trig_ZCE = UNINITIALIZED_ZCSIG;
  controller_PrevZCX.ExitControl_Trig_ZCE = POS_ZCSIG;
  controller_PrevZCX.StopMotor1_d.StopMotor1_Trig_ZCE = POS_ZCSIG;
  controller_PrevZCX.Home3.StopMotor1_Trig_ZCE_f = POS_ZCSIG;
  controller_PrevZCX.StopMotor1.StopMotor1_Trig_ZCE = POS_ZCSIG;
  controller_PrevZCX.Home1.StopMotor1_Trig_ZCE_f = POS_ZCSIG;

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home1' */
  controller_Home1_Init(&controller_DW.Home1, &controller_P.Home1);

  /* End of SystemInitialize for SubSystem: '<Root>/Home1' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home2' */
  /* InitializeConditions for Delay: '<S11>/Delay' */
  controller_DW.Delay_DSTATE_h[0] = controller_P.Delay_InitialCondition;
  controller_DW.Delay_DSTATE_h[1] = controller_P.Delay_InitialCondition;

  /* InitializeConditions for Derivative: '<S11>/Derivative' */
  controller_DW.TimeStampA_g = (rtInf);
  controller_DW.TimeStampB_f = (rtInf);

  /* SystemInitialize for Triggered SubSystem: '<S11>/Stop Motor1' */
  controller_StopMotor1_Init(&controller_B.StopMotor1, &controller_P.StopMotor1);

  /* End of SystemInitialize for SubSystem: '<S11>/Stop Motor1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Home2' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Main Control' */
  /* InitializeConditions for Delay: '<S15>/Delay' */
  controller_DW.Delay_DSTATE[0] = controller_P.Delay_InitialCondition_b;
  controller_DW.Delay_DSTATE[1] = controller_P.Delay_InitialCondition_b;

  /* End of SystemInitialize for SubSystem: '<Root>/Main Control' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home3' */
  controller_Home1_Init(&controller_DW.Home3, &controller_P.Home3);

  /* End of SystemInitialize for SubSystem: '<Root>/Home3' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home4' */
  /* InitializeConditions for Delay: '<S13>/Delay' */
  controller_DW.Delay_DSTATE_m[0] = controller_P.Delay_InitialCondition_k;
  controller_DW.Delay_DSTATE_m[1] = controller_P.Delay_InitialCondition_k;

  /* InitializeConditions for Derivative: '<S13>/Derivative' */
  controller_DW.TimeStampA = (rtInf);
  controller_DW.TimeStampB = (rtInf);

  /* SystemInitialize for Triggered SubSystem: '<S13>/Stop Motor1' */
  controller_StopMotor1_Init(&controller_B.StopMotor1_d,
    &controller_P.StopMotor1_d);

  /* End of SystemInitialize for SubSystem: '<S13>/Stop Motor1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Home4' */
}

/* Model terminate function */
void controller_terminate(void)
{
  /* Terminate for Triggered SubSystem: '<Root>/E-stop' */
  /* Terminate for MATLABSystem: '<S8>/LED' */
  if (!controller_DW.obj_n.matlabCodegenIsDeleted) {
    controller_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_n.isInitialized == 1) &&
        controller_DW.obj_n.isSetupComplete) {
      rc_led_cleanup();
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/LED' */
  /* End of Terminate for SubSystem: '<Root>/E-stop' */
  controller_AnalogInput_Term(&controller_DW.AnalogInput);
  controller_AnalogInput_Term(&controller_DW.AnalogInput1);

  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  if (!controller_DW.obj_b.matlabCodegenIsDeleted) {
    controller_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_b.isInitialized == 1) &&
        controller_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(controller_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read1' */
  if (!controller_DW.obj_a.matlabCodegenIsDeleted) {
    controller_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_a.isInitialized == 1) &&
        controller_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(controller_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read2' */
  if (!controller_DW.obj_l.matlabCodegenIsDeleted) {
    controller_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_l.isInitialized == 1) &&
        controller_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(controller_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read3' */
  if (!controller_DW.obj.matlabCodegenIsDeleted) {
    controller_DW.obj.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj.isInitialized == 1) &&
        controller_DW.obj.isSetupComplete) {
      MW_digitalIO_close(controller_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read3' */
}
