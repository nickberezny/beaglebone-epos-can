/*
 * controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.326
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Aug 16 16:41:44 2023
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
 * Output and update for trigger system:
 *    '<S8>/Stop Motor1'
 *    '<S10>/Stop Motor1'
 */
void controller_StopMotor1(boolean_T rtu_Trigger, const real_T *rtd_num_motors,
  const int32_T *rtd_pdo_id, ZCE_StopMotor1_controller_T *localZCE)
{
  real_T rtb_DataStoreRead7_b;
  int32_T rtb_DataStoreRead1_pj;

  /* Outputs for Triggered SubSystem: '<S8>/Stop Motor1' incorporates:
   *  TriggerPort: '<S16>/Trigger'
   */
  if (rtu_Trigger && (localZCE->StopMotor1_Trig_ZCE_f != POS_ZCSIG)) {
    /* DataStoreRead: '<S16>/Data Store Read1' */
    rtb_DataStoreRead1_pj = *rtd_pdo_id;

    /* DataStoreRead: '<S16>/Data Store Read7' */
    rtb_DataStoreRead7_b = *rtd_num_motors;

    /* DataTypeConversion: '<S16>/Data Type Conversion' */
    rtb_DataStoreRead7_b = floor(rtb_DataStoreRead7_b);
    if (rtIsNaN(rtb_DataStoreRead7_b) || rtIsInf(rtb_DataStoreRead7_b)) {
      rtb_DataStoreRead7_b = 0.0;
    } else {
      rtb_DataStoreRead7_b = fmod(rtb_DataStoreRead7_b, 4.294967296E+9);
    }

    /* CCaller: '<S16>/C Caller4' incorporates:
     *  DataTypeConversion: '<S16>/Data Type Conversion'
     */
    stop_motor(rtb_DataStoreRead1_pj, rtb_DataStoreRead7_b < 0.0 ? -(int32_T)
               (uint32_T)-rtb_DataStoreRead7_b : (int32_T)(uint32_T)
               rtb_DataStoreRead7_b);
  }

  localZCE->StopMotor1_Trig_ZCE_f = rtu_Trigger;

  /* End of Outputs for SubSystem: '<S8>/Stop Motor1' */
}

/*
 * System initialize for trigger system:
 *    '<S9>/Stop Motor1'
 *    '<S11>/Stop Motor1'
 */
void controller_StopMotor1_m_Init(B_StopMotor1_controller_h_T *localB,
  P_StopMotor1_controller_h_T *localP)
{
  /* SystemInitialize for CCaller: '<S21>/C Caller1' incorporates:
   *  Outport: '<S21>/enc'
   */
  localB->CCaller1[0] = localP->enc_Y0;
  localB->CCaller1[1] = localP->enc_Y0;
}

/*
 * Output and update for trigger system:
 *    '<S9>/Stop Motor1'
 *    '<S11>/Stop Motor1'
 */
void controller_StopMotor1_g(boolean_T rtu_Trigger, const real_T *rtd_num_motors,
  const int32_T *rtd_pdo_id, B_StopMotor1_controller_h_T *localB,
  P_StopMotor1_controller_h_T *localP, ZCE_StopMotor1_controller_f_T *localZCE)
{
  real_T rtb_DataStoreRead7_f;
  int32_T rtb_DataTypeConversion_j;

  /* Outputs for Triggered SubSystem: '<S9>/Stop Motor1' incorporates:
   *  TriggerPort: '<S21>/Trigger'
   */
  if (rtu_Trigger && (localZCE->StopMotor1_Trig_ZCE != POS_ZCSIG)) {
    /* DataStoreRead: '<S21>/Data Store Read2' */
    rtb_DataTypeConversion_j = *rtd_pdo_id;

    /* DataTypeConversion: '<S21>/Data Type Conversion7' incorporates:
     *  Constant: '<S21>/Constant7'
     */
    rtb_DataStoreRead7_f = floor(localP->Constant7_Value);
    if (rtIsNaN(rtb_DataStoreRead7_f) || rtIsInf(rtb_DataStoreRead7_f)) {
      rtb_DataStoreRead7_f = 0.0;
    } else {
      rtb_DataStoreRead7_f = fmod(rtb_DataStoreRead7_f, 4.294967296E+9);
    }

    /* CCaller: '<S21>/C Caller1' incorporates:
     *  DataTypeConversion: '<S21>/Data Type Conversion7'
     */
    get_encoder(rtb_DataTypeConversion_j, rtb_DataStoreRead7_f < 0.0 ? -(int32_T)
                (uint32_T)-rtb_DataStoreRead7_f : (int32_T)(uint32_T)
                rtb_DataStoreRead7_f, &localB->CCaller1[0]);

    /* DataStoreRead: '<S21>/Data Store Read1' */
    rtb_DataTypeConversion_j = *rtd_pdo_id;

    /* DataStoreRead: '<S21>/Data Store Read7' */
    rtb_DataStoreRead7_f = *rtd_num_motors;

    /* DataTypeConversion: '<S21>/Data Type Conversion' */
    rtb_DataStoreRead7_f = floor(rtb_DataStoreRead7_f);
    if (rtIsNaN(rtb_DataStoreRead7_f) || rtIsInf(rtb_DataStoreRead7_f)) {
      rtb_DataStoreRead7_f = 0.0;
    } else {
      rtb_DataStoreRead7_f = fmod(rtb_DataStoreRead7_f, 4.294967296E+9);
    }

    /* CCaller: '<S21>/C Caller4' incorporates:
     *  DataTypeConversion: '<S21>/Data Type Conversion'
     */
    stop_motor(rtb_DataTypeConversion_j, rtb_DataStoreRead7_f < 0.0 ? -(int32_T)
               (uint32_T)-rtb_DataStoreRead7_f : (int32_T)(uint32_T)
               rtb_DataStoreRead7_f);
  }

  localZCE->StopMotor1_Trig_ZCE = rtu_Trigger;

  /* End of Outputs for SubSystem: '<S9>/Stop Motor1' */
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static creal_T controller_split(real_T b_a)
{
  creal_T aout;
  real_T temp;
  if (fabs(b_a) <= 6.69692879491417E+299) {
    temp = 1.34217729E+8 * b_a;
    temp -= temp - b_a;
    aout.re = temp;
    aout.im = b_a - temp;
  } else if ((!rtIsInf(b_a)) && (!rtIsNaN(b_a))) {
    b_a *= 3.7252902984619141E-9;
    temp = 1.34217729E+8 * b_a;
    temp -= temp - b_a;
    aout.re = temp * 2.68435456E+8;
    aout.im = (b_a - temp) * 2.68435456E+8;
  } else {
    aout.re = b_a;
    aout.im = 0.0;
  }

  return aout;
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static creal_T controller_two_prod(real_T b_a)
{
  creal_T c;
  real_T slo;
  int32_T trueCount;
  controller_B.da = controller_split(b_a);
  controller_B.shi_c = b_a * 8.64E+7;
  slo = (controller_B.da.re * 8.64E+7 - controller_B.shi_c) + controller_B.da.im
    * 8.64E+7;
  trueCount = 0;
  if (rtIsNaN(slo)) {
    trueCount = 1;
  }

  if (trueCount - 1 >= 0) {
    slo = 0.0;
  }

  c.re = controller_B.shi_c;
  c.im = slo;
  return c;
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static creal_T controller_times(const creal_T b_a)
{
  creal_T c;
  c = controller_two_prod(b_a.re);
  controller_B.b = b_a.im * 8.64E+7;
  controller_B.alo_b = c.im;
  controller_B.ahi_p = c.re;
  if (controller_B.b != 0.0) {
    controller_B.alo_b = c.im + controller_B.b;
    controller_B.ahi_p = c.re + controller_B.alo_b;
    controller_B.alo_b -= controller_B.ahi_p - c.re;
  }

  if (rtIsNaN(controller_B.alo_b)) {
    controller_B.alo_b = 0.0;
  }

  c.re = controller_B.ahi_p;
  c.im = controller_B.alo_b;
  return c;
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static creal_T controller_two_sum(real_T b_a, real_T b)
{
  creal_T c;
  real_T bb;
  real_T shi;
  int32_T trueCount;
  shi = b_a + b;
  bb = shi - b_a;
  bb = (b_a - (shi - bb)) + (b - bb);
  trueCount = 0;
  if (rtIsNaN(bb)) {
    trueCount = 1;
  }

  if (trueCount - 1 >= 0) {
    bb = 0.0;
  }

  c.re = shi;
  c.im = bb;
  return c;
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static creal_T controller_plus(const creal_T b_a, real_T b)
{
  creal_T c;
  c = controller_two_sum(b_a.re, b);
  controller_B.t_c = controller_two_sum(b_a.im, 0.0);
  controller_B.alo_f = c.im;
  controller_B.ahi_g = c.re;
  if (controller_B.t_c.re != 0.0) {
    controller_B.alo_f = c.im + controller_B.t_c.re;
    controller_B.ahi_g = c.re + controller_B.alo_f;
    controller_B.alo_f -= controller_B.ahi_g - c.re;
  }

  if (rtIsNaN(controller_B.alo_f)) {
    controller_B.alo_f = 0.0;
  }

  controller_B.b_ahi_g = controller_B.ahi_g;
  if (controller_B.t_c.im != 0.0) {
    controller_B.alo_f += controller_B.t_c.im;
    controller_B.b_ahi_g = controller_B.ahi_g + controller_B.alo_f;
    controller_B.alo_f -= controller_B.b_ahi_g - controller_B.ahi_g;
  }

  if (rtIsNaN(controller_B.alo_f)) {
    controller_B.alo_f = 0.0;
  }

  c.re = controller_B.b_ahi_g;
  c.im = controller_B.alo_f;
  return c;
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static creal_T controller_two_diff(real_T b_a, real_T b)
{
  creal_T c;
  real_T bb;
  real_T shi;
  int32_T trueCount;
  shi = b_a - b;
  bb = shi - b_a;
  bb = (b_a - (shi - bb)) - (b + bb);
  trueCount = 0;
  if (rtIsNaN(bb)) {
    trueCount = 1;
  }

  if (trueCount - 1 >= 0) {
    bb = 0.0;
  }

  c.re = shi;
  c.im = bb;
  return c;
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
static creal_T controller_floor(const creal_T b_a)
{
  creal_T b;
  real_T alo;
  real_T b_ahi;
  real_T b_b;
  b.re = floor(b_a.re);
  b.im = 0.0;
  if (b.re == b_a.re) {
    b_b = floor(b_a.im);
    alo = 0.0;
    b_ahi = b.re;
    if (b_b != 0.0) {
      b_ahi = b.re + b_b;
      alo = b_b - (b_ahi - b.re);
    }

    if (rtIsNaN(alo)) {
      alo = 0.0;
    }

    b.re = b_ahi;
    b.im = alo;
  }

  return b;
}

/* Function for MATLAB Function: '<S13>/MATLAB Function' */
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
  boolean_T rtb_Compare_bt;
  boolean_T rtb_Compare_bf;
  boolean_T rtb_Compare_i;

  {
    real_T (*lastU)[2];
    int32_T rtb_DataStoreRead2_p;
    int32_T rtb_DataTypeConversion1_l;
    int32_T trueCount;
    boolean_T rtb_Compare_a;
    boolean_T rtb_Compare_p_idx_1;
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
      controller_B.rtb_Derivative_idx_0 = floor(controller_P.Constant14_Value_c);
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
       *  EnablePort: '<S12>/Enable'
       */
      /* RelationalOperator: '<S2>/Compare' incorporates:
       *  Constant: '<S2>/Constant'
       */
      if (controller_B.DataStoreRead1_c == controller_P.CompareToConstant2_const)
      {
        controller_DW.Initialize_MODE = true;
        if (controller_M->Timing.TaskCounters.TID[5] == 0) {
          /* DataTypeConversion: '<S12>/Data Type Conversion2' incorporates:
           *  DataStoreRead: '<S12>/Data Store Read7'
           */
          controller_B.shi = floor(controller_DW.num_motors);
          if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
            controller_B.shi = 0.0;
          } else {
            controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
          }

          /* CCaller: '<S12>/C Caller5' incorporates:
           *  Constant: '<S12>/Constant1'
           *  DataTypeConversion: '<S12>/Data Type Conversion2'
           */
          init_can(controller_B.shi < 0.0 ? -(int32_T)(uint32_T)
                   -controller_B.shi : (int32_T)(uint32_T)controller_B.shi,
                   controller_P.Constant1_Value_fu,
                   controller_P.Constant1_Value_fu, &controller_B.CCaller5[0]);

          /* DataStoreWrite: '<S12>/Data Store Write' */
          controller_DW.cfg_id = controller_B.CCaller5[0];

          /* DataStoreWrite: '<S12>/Data Store Write2' */
          controller_DW.pdo_id = controller_B.CCaller5[1];

          /* RelationalOperator: '<S34>/Compare' incorporates:
           *  Constant: '<S34>/Constant'
           */
          rtb_Compare_a = (controller_B.CCaller5[1] !=
                           controller_P.CompareToConstant_const);

          /* Switch: '<S35>/Switch' */
          if (rtb_Compare_a) {
            /* DataStoreWrite: '<S35>/Data Store Write' incorporates:
             *  Constant: '<S12>/Constant'
             */
            controller_DW.state = controller_P.Constant_Value_d;
          }

          /* End of Switch: '<S35>/Switch' */
        }

        if (controller_M->Timing.TaskCounters.TID[4] == 0) {
          /* CCaller: '<S12>/C Caller3' */
          init_datalog();
        }
      } else {
        controller_DW.Initialize_MODE = false;
      }

      /* End of RelationalOperator: '<S2>/Compare' */
      /* End of Outputs for SubSystem: '<Root>/Initialize' */
    }

    /* RelationalOperator: '<S1>/Compare' incorporates:
     *  Constant: '<S1>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read'
     */
    controller_B.Compare = (controller_DW.state ==
      controller_P.CompareToConstant1_const);

    /* Outputs for Enabled SubSystem: '<Root>/Home1' incorporates:
     *  EnablePort: '<S8>/Enable'
     */
    controller_DW.Home1_MODE = controller_B.Compare;
    if (controller_DW.Home1_MODE) {
      /* RelationalOperator: '<S14>/Compare' incorporates:
       *  Constant: '<S14>/Constant'
       *  DataStoreRead: '<Root>/Data Store Read10'
       */
      rtb_Compare_i = (controller_DW.LS1_L ==
                       controller_P.CompareToConstant1_const_j);

      /* Switch: '<S18>/Switch' */
      if (rtb_Compare_i) {
        /* DataStoreWrite: '<S18>/Data Store Write' incorporates:
         *  Constant: '<S8>/Constant1'
         */
        controller_DW.state = controller_P.Constant1_Value_f;
      }

      /* End of Switch: '<S18>/Switch' */

      /* DataTypeConversion: '<S8>/Data Type Conversion7' incorporates:
       *  DataStoreRead: '<S8>/Data Store Read7'
       */
      controller_B.shi = floor(controller_DW.num_motors);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S8>/C Caller1' incorporates:
       *  DataStoreRead: '<S8>/Data Store Read2'
       *  DataTypeConversion: '<S8>/Data Type Conversion7'
       */
      get_encoder(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)
                  (uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                  controller_B.shi, &controller_B.CCaller1_k[0]);

      /* RelationalOperator: '<S15>/Compare' incorporates:
       *  Constant: '<S15>/Constant'
       */
      rtb_Compare_a = (controller_B.CCaller1_k[0] !=
                       controller_P.Constant_Value_e);
      rtb_Compare_p_idx_1 = (controller_B.CCaller1_k[1] !=
        controller_P.Constant_Value_e);

      /* Switch: '<S8>/Switch' */
      if (rtb_Compare_a) {
        /* Switch: '<S8>/Switch' */
        controller_B.Switch_g[0] = controller_B.CCaller1_k[0];
      } else {
        /* Switch: '<S8>/Switch' incorporates:
         *  Delay: '<S8>/Delay'
         */
        controller_B.Switch_g[0] = controller_DW.Delay_DSTATE_n[0];
      }

      if (rtb_Compare_p_idx_1) {
        /* Switch: '<S8>/Switch' */
        controller_B.Switch_g[1] = controller_B.CCaller1_k[1];
      } else {
        /* Switch: '<S8>/Switch' incorporates:
         *  Delay: '<S8>/Delay'
         */
        controller_B.Switch_g[1] = controller_DW.Delay_DSTATE_n[1];
      }

      /* End of Switch: '<S8>/Switch' */

      /* Gain: '<S8>/Gain2' incorporates:
       *  DataStoreRead: '<S8>/Data Store Read1'
       *  DataStoreRead: '<S8>/Data Store Read8'
       *  Gain: '<S8>/Gain'
       *  Gain: '<S8>/Gain1'
       *  Product: '<S8>/Divide'
       */
      controller_B.Gain2_o[0] = controller_B.Switch_g[0] /
        (controller_P.Gain_Gain * controller_DW.GR1) * controller_P.Gain2_Gain;
      controller_B.Gain2_o[1] = controller_B.Switch_g[1] /
        (controller_P.Gain1_Gain * controller_DW.GR2) * controller_P.Gain2_Gain;

      /* Derivative: '<S8>/Derivative' */
      controller_B.shi = controller_M->Timing.t[0];
      if ((controller_DW.TimeStampA_f >= controller_B.shi) &&
          (controller_DW.TimeStampB_o >= controller_B.shi)) {
        controller_B.rtb_Derivative_idx_0 = 0.0;
      } else {
        controller_B.DataStoreRead1_c = controller_DW.TimeStampA_f;
        lastU = &controller_DW.LastUAtTimeA_e;
        if (controller_DW.TimeStampA_f < controller_DW.TimeStampB_o) {
          if (controller_DW.TimeStampB_o < controller_B.shi) {
            controller_B.DataStoreRead1_c = controller_DW.TimeStampB_o;
            lastU = &controller_DW.LastUAtTimeB_h;
          }
        } else if (controller_DW.TimeStampA_f >= controller_B.shi) {
          controller_B.DataStoreRead1_c = controller_DW.TimeStampB_o;
          lastU = &controller_DW.LastUAtTimeB_h;
        }

        controller_B.rtb_Derivative_idx_0 = (controller_B.Gain2_o[0] - (*lastU)
          [0]) / (controller_B.shi - controller_B.DataStoreRead1_c);
      }

      /* End of Derivative: '<S8>/Derivative' */

      /* Gain: '<S8>/Gain3' incorporates:
       *  Constant: '<Root>/Constant1'
       *  Sum: '<S8>/Sum1'
       */
      controller_B.Saturation_d = (controller_B.rtb_Derivative_idx_0 -
        controller_P.Constant1_Value_iv) * controller_P.Gain3_Gain;

      /* Saturate: '<S8>/Saturation' */
      if (controller_B.Saturation_d > controller_P.Saturation_UpperSat) {
        /* Gain: '<S8>/Gain3' incorporates:
         *  Saturate: '<S8>/Saturation'
         */
        controller_B.Saturation_d = controller_P.Saturation_UpperSat;
      } else if (controller_B.Saturation_d < controller_P.Saturation_LowerSat) {
        /* Gain: '<S8>/Gain3' incorporates:
         *  Saturate: '<S8>/Saturation'
         */
        controller_B.Saturation_d = controller_P.Saturation_LowerSat;
      }

      /* End of Saturate: '<S8>/Saturation' */

      /* DataTypeConversion: '<S8>/Data Type Conversion1' */
      controller_B.shi = floor(controller_B.Saturation_d);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* DataTypeConversion: '<S8>/Data Type Conversion1' */
      controller_B.DataTypeConversion1 = controller_B.shi < 0.0 ? -(int32_T)
        (uint32_T)-controller_B.shi : (int32_T)(uint32_T)controller_B.shi;
      if (controller_M->Timing.TaskCounters.TID[3] == 0) {
        /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
         *  Constant: '<S8>/Constant14'
         */
        controller_B.shi = floor(controller_P.Constant14_Value);
        if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
          controller_B.shi = 0.0;
        } else {
          controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
        }

        /* DataTypeConversion: '<S8>/Data Type Conversion2' incorporates:
         *  DataStoreRead: '<S8>/Data Store Read9'
         */
        controller_B.rtb_Derivative_idx_0 = floor(controller_DW.debug);
        if (rtIsNaN(controller_B.rtb_Derivative_idx_0) || rtIsInf
            (controller_B.rtb_Derivative_idx_0)) {
          controller_B.rtb_Derivative_idx_0 = 0.0;
        } else {
          controller_B.rtb_Derivative_idx_0 = fmod
            (controller_B.rtb_Derivative_idx_0, 4.294967296E+9);
        }

        /* CCaller: '<S8>/C Caller3' incorporates:
         *  DataTypeConversion: '<S8>/Data Type Conversion'
         *  DataTypeConversion: '<S8>/Data Type Conversion2'
         */
        print_input(controller_B.DataTypeConversion1, controller_B.shi < 0.0 ?
                    -(int32_T)(uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                    controller_B.shi, controller_B.rtb_Derivative_idx_0 < 0.0 ?
                    -(int32_T)(uint32_T)-controller_B.rtb_Derivative_idx_0 :
                    (int32_T)(uint32_T)controller_B.rtb_Derivative_idx_0);
      }

      if (controller_M->Timing.TaskCounters.TID[2] == 0) {
        /* DataStoreRead: '<S17>/Data Store Read2' */
        rtb_DataStoreRead2_p = controller_DW.pdo_id;

        /* DataTypeConversion: '<S17>/Data Type Conversion1' incorporates:
         *  Constant: '<Root>/Constant'
         */
        controller_B.shi = floor(controller_P.Constant_Value_c);
        if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
          controller_B.shi = 0.0;
        } else {
          controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
        }

        rtb_DataTypeConversion1_l = controller_B.shi < 0.0 ? -(int32_T)(uint32_T)
          -controller_B.shi : (int32_T)(uint32_T)controller_B.shi;

        /* End of DataTypeConversion: '<S17>/Data Type Conversion1' */

        /* CCaller: '<S17>/C Caller3' incorporates:
         *  DataStoreRead: '<S17>/Data Store Read2'
         */
        set_motor(controller_DW.pdo_id, rtb_DataTypeConversion1_l,
                  controller_B.Saturation_d);
      }

      /* Outputs for Triggered SubSystem: '<S8>/Stop Motor1' */
      controller_StopMotor1(rtb_Compare_i, &controller_DW.num_motors,
                            &controller_DW.pdo_id,
                            &controller_PrevZCX.StopMotor1);

      /* End of Outputs for SubSystem: '<S8>/Stop Motor1' */
    }

    /* End of Outputs for SubSystem: '<Root>/Home1' */

    /* RelationalOperator: '<S3>/Compare' incorporates:
     *  Constant: '<S3>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read3'
     */
    controller_B.Compare_p = (controller_DW.state ==
      controller_P.CompareToConstant3_const);

    /* Outputs for Enabled SubSystem: '<Root>/Home2' incorporates:
     *  EnablePort: '<S9>/Enable'
     */
    controller_DW.Home2_MODE = controller_B.Compare_p;
    if (controller_DW.Home2_MODE) {
      /* RelationalOperator: '<S19>/Compare' incorporates:
       *  Constant: '<S19>/Constant'
       *  DataStoreRead: '<Root>/Data Store Read4'
       */
      rtb_Compare_bf = (controller_DW.LS1_R ==
                        controller_P.CompareToConstant1_const_p);

      /* Outputs for Triggered SubSystem: '<S9>/Stop Motor1' */
      controller_StopMotor1_g(rtb_Compare_bf, &controller_DW.num_motors,
        &controller_DW.pdo_id, &controller_B.StopMotor1_g,
        &controller_P.StopMotor1_g, &controller_PrevZCX.StopMotor1_g);

      /* End of Outputs for SubSystem: '<S9>/Stop Motor1' */

      /* DataStoreWrite: '<S9>/Data Store Write' */
      controller_DW.q01 = controller_B.StopMotor1_g.CCaller1[0];

      /* Switch: '<S23>/Switch' */
      if (rtb_Compare_bf) {
        /* DataStoreWrite: '<S23>/Data Store Write' incorporates:
         *  Constant: '<S9>/Constant1'
         */
        controller_DW.state = controller_P.Constant1_Value_i;
      }

      /* End of Switch: '<S23>/Switch' */
      if (controller_M->Timing.TaskCounters.TID[2] == 0) {
        /* DataStoreRead: '<S22>/Data Store Read2' */
        rtb_DataStoreRead2_p = controller_DW.pdo_id;

        /* DataTypeConversion: '<S22>/Data Type Conversion1' incorporates:
         *  Constant: '<Root>/Constant2'
         */
        controller_B.shi = floor(controller_P.Constant2_Value_h);
        if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
          controller_B.shi = 0.0;
        } else {
          controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
        }

        rtb_DataTypeConversion1_l = controller_B.shi < 0.0 ? -(int32_T)(uint32_T)
          -controller_B.shi : (int32_T)(uint32_T)controller_B.shi;

        /* End of DataTypeConversion: '<S22>/Data Type Conversion1' */
      }

      /* DataTypeConversion: '<S9>/Data Type Conversion7' incorporates:
       *  DataStoreRead: '<S9>/Data Store Read7'
       */
      controller_B.shi = floor(controller_DW.num_motors);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S9>/C Caller1' incorporates:
       *  DataStoreRead: '<S9>/Data Store Read2'
       *  DataTypeConversion: '<S9>/Data Type Conversion7'
       */
      get_encoder(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)
                  (uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                  controller_B.shi, &controller_B.CCaller1_k[0]);

      /* RelationalOperator: '<S20>/Compare' incorporates:
       *  Constant: '<S20>/Constant'
       */
      rtb_Compare_a = (controller_B.CCaller1_k[0] !=
                       controller_P.Constant_Value_ep);
      rtb_Compare_p_idx_1 = (controller_B.CCaller1_k[1] !=
        controller_P.Constant_Value_ep);

      /* Switch: '<S9>/Switch' */
      if (rtb_Compare_a) {
        /* Switch: '<S9>/Switch' */
        controller_B.Switch_f[0] = controller_B.CCaller1_k[0];
      } else {
        /* Switch: '<S9>/Switch' incorporates:
         *  Delay: '<S9>/Delay'
         */
        controller_B.Switch_f[0] = controller_DW.Delay_DSTATE_h[0];
      }

      if (rtb_Compare_p_idx_1) {
        /* Switch: '<S9>/Switch' */
        controller_B.Switch_f[1] = controller_B.CCaller1_k[1];
      } else {
        /* Switch: '<S9>/Switch' incorporates:
         *  Delay: '<S9>/Delay'
         */
        controller_B.Switch_f[1] = controller_DW.Delay_DSTATE_h[1];
      }

      /* End of Switch: '<S9>/Switch' */

      /* Gain: '<S9>/Gain2' incorporates:
       *  DataStoreRead: '<S9>/Data Store Read1'
       *  DataStoreRead: '<S9>/Data Store Read8'
       *  Gain: '<S9>/Gain'
       *  Gain: '<S9>/Gain1'
       *  Product: '<S9>/Divide'
       */
      controller_B.Gain2_p[0] = controller_B.Switch_f[0] /
        (controller_P.Gain_Gain_f * controller_DW.GR1) *
        controller_P.Gain2_Gain_a;
      controller_B.Gain2_p[1] = controller_B.Switch_f[1] /
        (controller_P.Gain1_Gain_f * controller_DW.GR2) *
        controller_P.Gain2_Gain_a;

      /* Derivative: '<S9>/Derivative' */
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
            lastU = &controller_DW.LastUAtTimeB_nm;
          }
        } else if (controller_DW.TimeStampA_g >= controller_B.shi) {
          controller_B.DataStoreRead1_c = controller_DW.TimeStampB_f;
          lastU = &controller_DW.LastUAtTimeB_nm;
        }

        controller_B.rtb_Derivative_idx_0 = (controller_B.Gain2_p[0] - (*lastU)
          [0]) / (controller_B.shi - controller_B.DataStoreRead1_c);
      }

      /* End of Derivative: '<S9>/Derivative' */

      /* Gain: '<S9>/Gain3' incorporates:
       *  Constant: '<Root>/Constant3'
       *  Sum: '<S9>/Sum1'
       */
      controller_B.Saturation_n = (controller_B.rtb_Derivative_idx_0 -
        controller_P.Constant3_Value) * controller_P.Gain3_Gain_o;

      /* Saturate: '<S9>/Saturation' */
      if (controller_B.Saturation_n > controller_P.Saturation_UpperSat_a) {
        /* Gain: '<S9>/Gain3' incorporates:
         *  Saturate: '<S9>/Saturation'
         */
        controller_B.Saturation_n = controller_P.Saturation_UpperSat_a;
      } else if (controller_B.Saturation_n < controller_P.Saturation_LowerSat_n)
      {
        /* Gain: '<S9>/Gain3' incorporates:
         *  Saturate: '<S9>/Saturation'
         */
        controller_B.Saturation_n = controller_P.Saturation_LowerSat_n;
      }

      /* End of Saturate: '<S9>/Saturation' */
      if (controller_M->Timing.TaskCounters.TID[2] == 0) {
        /* CCaller: '<S22>/C Caller3' */
        set_motor(rtb_DataStoreRead2_p, rtb_DataTypeConversion1_l,
                  controller_B.Saturation_n);
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
     *  EnablePort: '<S13>/Enable'
     */
    controller_DW.MainControl_MODE = controller_B.Compare_j;
    if (controller_DW.MainControl_MODE) {
      /* Switch: '<S39>/Switch' incorporates:
       *  Constant: '<S36>/Constant'
       *  DataStoreRead: '<S13>/Data Store Read3'
       *  RelationalOperator: '<S36>/Compare'
       */
      if (controller_DW.LS1_R == controller_P.CompareToConstant_const_g) {
        /* DataStoreWrite: '<S39>/Data Store Write' incorporates:
         *  Constant: '<S13>/Constant4'
         */
        controller_DW.state = controller_P.Constant4_Value;
      }

      /* End of Switch: '<S39>/Switch' */

      /* MATLAB Function: '<S13>/MATLAB Function' */
      controller_getLocalTime(&controller_B.fracSecs, &controller_B.second,
        &controller_B.shi, &controller_B.b_alo, &controller_B.d_ahi_c,
        &controller_B.c_tm_mon, &controller_B.c_tm_year, &rtb_Compare_a);
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
      trueCount = 0;
      if (rtIsNaN(controller_B.b_alo)) {
        trueCount = 1;
      }

      if (trueCount - 1 >= 0) {
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
        trueCount = (int32_T)rt_roundd_snf(controller_B.shi);
        trueCount -= 3600 * div_s32(trueCount, 3600);
        controller_B.shi = trueCount - 60 * div_s32(trueCount, 60);
      } else {
        controller_B.shi -= floor((controller_B.shi - floor(controller_B.shi /
          3600.0) * 3600.0) / 60.0) * 60.0;
      }

      controller_B.b_alo = (controller_B.b_c.re + controller_B.b_c.im) +
        controller_B.shi;
      if (controller_B.b_alo == 60.0) {
        controller_B.b_alo = 59.999999999999993;
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
                  controller_B.shi, &controller_B.CCaller1[0]);

      /* Sum: '<S13>/Sum' */
      controller_B.rtb_Derivative_idx_0 = controller_B.CCaller1[0] -
        controller_B.rtb_Derivative_idx_0;
      controller_B.DataStoreRead1_c = controller_B.CCaller1[1] -
        controller_B.DataStoreRead1_c;

      /* RelationalOperator: '<S37>/Compare' incorporates:
       *  Constant: '<S37>/Constant'
       */
      controller_B.Compare_e[0] = (controller_B.CCaller1[0] !=
        controller_P.Constant_Value_p);
      controller_B.Compare_e[1] = (controller_B.CCaller1[1] !=
        controller_P.Constant_Value_p);

      /* Delay: '<S13>/Delay' */
      controller_B.Delay[0] = controller_DW.Delay_DSTATE[0];

      /* Switch: '<S13>/Switch' */
      if (controller_B.Compare_e[0]) {
        /* Switch: '<S13>/Switch' */
        controller_B.Switch[0] = controller_B.rtb_Derivative_idx_0;
      } else {
        /* Switch: '<S13>/Switch' */
        controller_B.Switch[0] = controller_B.Delay[0];
      }

      /* Delay: '<S13>/Delay' */
      controller_B.Delay[1] = controller_DW.Delay_DSTATE[1];

      /* Switch: '<S13>/Switch' */
      if (controller_B.Compare_e[1]) {
        /* Switch: '<S13>/Switch' */
        controller_B.Switch[1] = controller_B.DataStoreRead1_c;
      } else {
        /* Switch: '<S13>/Switch' */
        controller_B.Switch[1] = controller_B.Delay[1];
      }

      /* Gain: '<S13>/Gain2' incorporates:
       *  DataStoreRead: '<S13>/Data Store Read1'
       *  DataStoreRead: '<S13>/Data Store Read8'
       *  Gain: '<S13>/Gain'
       *  Gain: '<S13>/Gain1'
       *  Product: '<S13>/Divide'
       */
      controller_B.Gain2[0] = controller_B.Switch[0] / (controller_P.Gain_Gain_m
        * controller_DW.GR1) * controller_P.Gain2_Gain_b1;
      controller_B.Gain2[1] = controller_B.Switch[1] /
        (controller_P.Gain1_Gain_g * controller_DW.GR2) *
        controller_P.Gain2_Gain_b1;

      /* SignalConversion generated from: '<S13>/C Caller4' incorporates:
       *  MATLAB Function: '<S13>/MATLAB Function'
       */
      controller_B.TmpSignalConversionAtCCalle[0] = controller_B.b_alo;
      controller_B.TmpSignalConversionAtCCalle[1] = controller_B.Gain2[0];
      controller_B.TmpSignalConversionAtCCalle[2] = controller_B.Gain2[1];

      /* DataTypeConversion: '<S13>/Data Type Conversion2' incorporates:
       *  Constant: '<S13>/Constant2'
       */
      controller_B.shi = floor(controller_P.Constant2_Value);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S13>/C Caller4' incorporates:
       *  DataTypeConversion: '<S13>/Data Type Conversion2'
       */
      print_data(&controller_B.TmpSignalConversionAtCCalle[0], controller_B.shi <
                 0.0 ? -(int32_T)(uint32_T)-controller_B.shi : (int32_T)
                 (uint32_T)controller_B.shi);

      /* Sin: '<S13>/Sine Wave' */
      controller_B.SineWave = sin(controller_P.SineWave_Freq *
        controller_M->Timing.t[0] + controller_P.SineWave_Phase) *
        controller_P.SineWave_Amp + controller_P.SineWave_Bias;

      /* DataTypeConversion: '<S40>/Data Type Conversion1' incorporates:
       *  Constant: '<S13>/Constant'
       */
      controller_B.shi = floor(controller_P.Constant_Value_iy);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S40>/C Caller3' incorporates:
       *  DataStoreRead: '<S40>/Data Store Read2'
       *  DataTypeConversion: '<S40>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)
                (uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                controller_B.shi, controller_B.SineWave);

      /* DataTypeConversion: '<S41>/Data Type Conversion1' incorporates:
       *  Constant: '<S13>/Constant1'
       */
      controller_B.shi = floor(controller_P.Constant1_Value_m);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S41>/C Caller3' incorporates:
       *  DataStoreRead: '<S41>/Data Store Read2'
       *  DataTypeConversion: '<S41>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)
                (uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                controller_B.shi, controller_B.SineWave);
    }

    /* End of Outputs for SubSystem: '<Root>/Main Control' */

    /* RelationalOperator: '<S5>/Compare' incorporates:
     *  Constant: '<S5>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read6'
     */
    rtb_Compare_a = (controller_DW.state ==
                     controller_P.CompareToConstant7_const);

    /* Outputs for Triggered SubSystem: '<Root>/Exit Control' incorporates:
     *  TriggerPort: '<S7>/Trigger'
     */
    if (rtb_Compare_a && (controller_PrevZCX.ExitControl_Trig_ZCE != POS_ZCSIG))
    {
      /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
       *  DataStoreRead: '<S7>/Data Store Read7'
       */
      controller_B.shi = floor(controller_DW.num_motors);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S7>/C Caller1' incorporates:
       *  DataStoreRead: '<S7>/Data Store Read1'
       *  DataTypeConversion: '<S7>/Data Type Conversion'
       */
      stop_motor(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)
                 (uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                 controller_B.shi);

      /* CCaller: '<S7>/C Caller4' */
      close_datalog();
    }

    controller_PrevZCX.ExitControl_Trig_ZCE = rtb_Compare_a;

    /* End of Outputs for SubSystem: '<Root>/Exit Control' */

    /* DataStoreRead: '<Root>/Data Store Read12' */
    controller_B.DataStoreRead12 = controller_DW.state;

    /* Outputs for Enabled SubSystem: '<Root>/Home4' incorporates:
     *  EnablePort: '<S11>/Enable'
     */
    controller_DW.Home4_MODE = (controller_B.DataStoreRead12 > 0.0);
    if (controller_DW.Home4_MODE) {
      /* RelationalOperator: '<S29>/Compare' incorporates:
       *  Constant: '<S29>/Constant'
       *  DataStoreRead: '<Root>/Data Store Read13'
       */
      rtb_Compare_b = (controller_DW.LS2_R ==
                       controller_P.CompareToConstant1_const_e);

      /* Outputs for Triggered SubSystem: '<S11>/Stop Motor1' */
      controller_StopMotor1_g(rtb_Compare_b, &controller_DW.num_motors,
        &controller_DW.pdo_id, &controller_B.StopMotor1_d,
        &controller_P.StopMotor1_d, &controller_PrevZCX.StopMotor1_d);

      /* End of Outputs for SubSystem: '<S11>/Stop Motor1' */

      /* DataStoreWrite: '<S11>/Data Store Write' */
      controller_DW.q02 = controller_B.StopMotor1_d.CCaller1[0];

      /* Switch: '<S33>/Switch' */
      if (rtb_Compare_b) {
        /* DataStoreWrite: '<S33>/Data Store Write' incorporates:
         *  Constant: '<S11>/Constant1'
         */
        controller_DW.state = controller_P.Constant1_Value_ih;
      }

      /* End of Switch: '<S33>/Switch' */
      if (controller_M->Timing.TaskCounters.TID[2] == 0) {
        /* DataStoreRead: '<S32>/Data Store Read2' */
        rtb_DataTypeConversion1_l = controller_DW.pdo_id;

        /* DataTypeConversion: '<S32>/Data Type Conversion1' incorporates:
         *  Constant: '<Root>/Constant10'
         */
        controller_B.shi = floor(controller_P.Constant10_Value);
        if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
          controller_B.shi = 0.0;
        } else {
          controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
        }

        rtb_DataStoreRead2_p = controller_B.shi < 0.0 ? -(int32_T)(uint32_T)
          -controller_B.shi : (int32_T)(uint32_T)controller_B.shi;

        /* End of DataTypeConversion: '<S32>/Data Type Conversion1' */
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

      /* RelationalOperator: '<S30>/Compare' incorporates:
       *  Constant: '<S30>/Constant'
       */
      rtb_Compare_a = (controller_B.CCaller1_k[0] !=
                       controller_P.Constant_Value_i);
      rtb_Compare_p_idx_1 = (controller_B.CCaller1_k[1] !=
        controller_P.Constant_Value_i);

      /* Switch: '<S11>/Switch' */
      if (rtb_Compare_a) {
        /* Switch: '<S11>/Switch' */
        controller_B.Switch_j[0] = controller_B.CCaller1_k[0];
      } else {
        /* Switch: '<S11>/Switch' incorporates:
         *  Delay: '<S11>/Delay'
         */
        controller_B.Switch_j[0] = controller_DW.Delay_DSTATE_m[0];
      }

      if (rtb_Compare_p_idx_1) {
        /* Switch: '<S11>/Switch' */
        controller_B.Switch_j[1] = controller_B.CCaller1_k[1];
      } else {
        /* Switch: '<S11>/Switch' incorporates:
         *  Delay: '<S11>/Delay'
         */
        controller_B.Switch_j[1] = controller_DW.Delay_DSTATE_m[1];
      }

      /* End of Switch: '<S11>/Switch' */

      /* Gain: '<S11>/Gain2' incorporates:
       *  DataStoreRead: '<S11>/Data Store Read1'
       *  DataStoreRead: '<S11>/Data Store Read8'
       *  Gain: '<S11>/Gain'
       *  Gain: '<S11>/Gain1'
       *  Product: '<S11>/Divide'
       */
      controller_B.Gain2_j[0] = controller_B.Switch_j[0] /
        (controller_P.Gain_Gain_b * controller_DW.GR1) *
        controller_P.Gain2_Gain_b;
      controller_B.Gain2_j[1] = controller_B.Switch_j[1] /
        (controller_P.Gain1_Gain_d * controller_DW.GR2) *
        controller_P.Gain2_Gain_b;

      /* Derivative: '<S11>/Derivative' */
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

      /* End of Derivative: '<S11>/Derivative' */

      /* Gain: '<S11>/Gain3' incorporates:
       *  Constant: '<Root>/Constant11'
       *  Sum: '<S11>/Sum1'
       */
      controller_B.Saturation = (controller_B.rtb_Derivative_idx_0 -
        controller_P.Constant11_Value) * controller_P.Gain3_Gain_i;

      /* Saturate: '<S11>/Saturation' */
      if (controller_B.Saturation > controller_P.Saturation_UpperSat_k) {
        /* Gain: '<S11>/Gain3' incorporates:
         *  Saturate: '<S11>/Saturation'
         */
        controller_B.Saturation = controller_P.Saturation_UpperSat_k;
      } else if (controller_B.Saturation < controller_P.Saturation_LowerSat_f) {
        /* Gain: '<S11>/Gain3' incorporates:
         *  Saturate: '<S11>/Saturation'
         */
        controller_B.Saturation = controller_P.Saturation_LowerSat_f;
      }

      /* End of Saturate: '<S11>/Saturation' */
      if (controller_M->Timing.TaskCounters.TID[2] == 0) {
        /* CCaller: '<S32>/C Caller3' */
        set_motor(rtb_DataTypeConversion1_l, rtb_DataStoreRead2_p,
                  controller_B.Saturation);
      }
    }

    /* End of Outputs for SubSystem: '<Root>/Home4' */

    /* DataStoreRead: '<Root>/Data Store Read5' */
    controller_B.DataStoreRead5 = controller_DW.state;

    /* Outputs for Enabled SubSystem: '<Root>/Home3' incorporates:
     *  EnablePort: '<S10>/Enable'
     */
    controller_DW.Home3_MODE = (controller_B.DataStoreRead5 > 0.0);
    if (controller_DW.Home3_MODE) {
      /* RelationalOperator: '<S24>/Compare' incorporates:
       *  Constant: '<S24>/Constant'
       *  DataStoreRead: '<Root>/Data Store Read11'
       */
      rtb_Compare_bt = (controller_DW.LS2_L ==
                        controller_P.CompareToConstant1_const_n);

      /* Switch: '<S28>/Switch' */
      if (rtb_Compare_bt) {
        /* DataStoreWrite: '<S28>/Data Store Write' incorporates:
         *  Constant: '<S10>/Constant1'
         */
        controller_DW.state = controller_P.Constant1_Value_h;
      }

      /* End of Switch: '<S28>/Switch' */
      if (controller_M->Timing.TaskCounters.TID[2] == 0) {
        /* DataStoreRead: '<S27>/Data Store Read2' */
        rtb_DataStoreRead2_p = controller_DW.pdo_id;

        /* DataTypeConversion: '<S27>/Data Type Conversion1' incorporates:
         *  Constant: '<Root>/Constant8'
         */
        controller_B.shi = floor(controller_P.Constant8_Value);
        if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
          controller_B.shi = 0.0;
        } else {
          controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
        }

        rtb_DataTypeConversion1_l = controller_B.shi < 0.0 ? -(int32_T)(uint32_T)
          -controller_B.shi : (int32_T)(uint32_T)controller_B.shi;

        /* End of DataTypeConversion: '<S27>/Data Type Conversion1' */
      }

      /* DataTypeConversion: '<S10>/Data Type Conversion7' incorporates:
       *  DataStoreRead: '<S10>/Data Store Read7'
       */
      controller_B.shi = floor(controller_DW.num_motors);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S10>/C Caller1' incorporates:
       *  DataStoreRead: '<S10>/Data Store Read2'
       *  DataTypeConversion: '<S10>/Data Type Conversion7'
       */
      get_encoder(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)
                  (uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                  controller_B.shi, &controller_B.CCaller1_k[0]);

      /* RelationalOperator: '<S25>/Compare' incorporates:
       *  Constant: '<S25>/Constant'
       */
      rtb_Compare_a = (controller_B.CCaller1_k[0] !=
                       controller_P.Constant_Value_b);
      rtb_Compare_p_idx_1 = (controller_B.CCaller1_k[1] !=
        controller_P.Constant_Value_b);

      /* Switch: '<S10>/Switch' */
      if (rtb_Compare_a) {
        /* Switch: '<S10>/Switch' */
        controller_B.Switch_n[0] = controller_B.CCaller1_k[0];
      } else {
        /* Switch: '<S10>/Switch' incorporates:
         *  Delay: '<S10>/Delay'
         */
        controller_B.Switch_n[0] = controller_DW.Delay_DSTATE_a[0];
      }

      if (rtb_Compare_p_idx_1) {
        /* Switch: '<S10>/Switch' */
        controller_B.Switch_n[1] = controller_B.CCaller1_k[1];
      } else {
        /* Switch: '<S10>/Switch' incorporates:
         *  Delay: '<S10>/Delay'
         */
        controller_B.Switch_n[1] = controller_DW.Delay_DSTATE_a[1];
      }

      /* End of Switch: '<S10>/Switch' */

      /* Gain: '<S10>/Gain2' incorporates:
       *  DataStoreRead: '<S10>/Data Store Read1'
       *  DataStoreRead: '<S10>/Data Store Read8'
       *  Gain: '<S10>/Gain'
       *  Gain: '<S10>/Gain1'
       *  Product: '<S10>/Divide'
       */
      controller_B.Gain2_e[0] = controller_B.Switch_n[0] /
        (controller_P.Gain_Gain_n * controller_DW.GR1) *
        controller_P.Gain2_Gain_az;
      controller_B.Gain2_e[1] = controller_B.Switch_n[1] /
        (controller_P.Gain1_Gain_f3 * controller_DW.GR2) *
        controller_P.Gain2_Gain_az;

      /* Derivative: '<S10>/Derivative' */
      controller_B.shi = controller_M->Timing.t[0];
      if ((controller_DW.TimeStampA_k >= controller_B.shi) &&
          (controller_DW.TimeStampB_n >= controller_B.shi)) {
        controller_B.rtb_Derivative_idx_0 = 0.0;
      } else {
        controller_B.DataStoreRead1_c = controller_DW.TimeStampA_k;
        lastU = &controller_DW.LastUAtTimeA_n;
        if (controller_DW.TimeStampA_k < controller_DW.TimeStampB_n) {
          if (controller_DW.TimeStampB_n < controller_B.shi) {
            controller_B.DataStoreRead1_c = controller_DW.TimeStampB_n;
            lastU = &controller_DW.LastUAtTimeB_n;
          }
        } else if (controller_DW.TimeStampA_k >= controller_B.shi) {
          controller_B.DataStoreRead1_c = controller_DW.TimeStampB_n;
          lastU = &controller_DW.LastUAtTimeB_n;
        }

        controller_B.rtb_Derivative_idx_0 = (controller_B.Gain2_e[0] - (*lastU)
          [0]) / (controller_B.shi - controller_B.DataStoreRead1_c);
      }

      /* End of Derivative: '<S10>/Derivative' */

      /* Gain: '<S10>/Gain3' incorporates:
       *  Constant: '<Root>/Constant9'
       *  Sum: '<S10>/Sum1'
       */
      controller_B.Saturation_b = (controller_B.rtb_Derivative_idx_0 -
        controller_P.Constant9_Value) * controller_P.Gain3_Gain_h;

      /* Saturate: '<S10>/Saturation' */
      if (controller_B.Saturation_b > controller_P.Saturation_UpperSat_n) {
        /* Gain: '<S10>/Gain3' incorporates:
         *  Saturate: '<S10>/Saturation'
         */
        controller_B.Saturation_b = controller_P.Saturation_UpperSat_n;
      } else if (controller_B.Saturation_b < controller_P.Saturation_LowerSat_c)
      {
        /* Gain: '<S10>/Gain3' incorporates:
         *  Saturate: '<S10>/Saturation'
         */
        controller_B.Saturation_b = controller_P.Saturation_LowerSat_c;
      }

      /* End of Saturate: '<S10>/Saturation' */
      if (controller_M->Timing.TaskCounters.TID[2] == 0) {
        /* CCaller: '<S27>/C Caller3' */
        set_motor(rtb_DataStoreRead2_p, rtb_DataTypeConversion1_l,
                  controller_B.Saturation_b);
      }

      /* Outputs for Triggered SubSystem: '<S10>/Stop Motor1' */
      controller_StopMotor1(rtb_Compare_bt, &controller_DW.num_motors,
                            &controller_DW.pdo_id,
                            &controller_PrevZCX.StopMotor1_b);

      /* End of Outputs for SubSystem: '<S10>/Stop Motor1' */
    }

    /* End of Outputs for SubSystem: '<Root>/Home3' */
  }

  {
    real_T (*lastU)[2];

    /* Update for Enabled SubSystem: '<Root>/Home1' incorporates:
     *  EnablePort: '<S8>/Enable'
     */
    if (controller_DW.Home1_MODE) {
      /* Update for Delay: '<S8>/Delay' */
      controller_DW.Delay_DSTATE_n[0] = controller_B.Switch_g[0];
      controller_DW.Delay_DSTATE_n[1] = controller_B.Switch_g[1];

      /* Update for Derivative: '<S8>/Derivative' */
      if (controller_DW.TimeStampA_f == (rtInf)) {
        controller_DW.TimeStampA_f = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeA_e;
      } else if (controller_DW.TimeStampB_o == (rtInf)) {
        controller_DW.TimeStampB_o = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeB_h;
      } else if (controller_DW.TimeStampA_f < controller_DW.TimeStampB_o) {
        controller_DW.TimeStampA_f = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeA_e;
      } else {
        controller_DW.TimeStampB_o = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeB_h;
      }

      (*lastU)[0] = controller_B.Gain2_o[0];
      (*lastU)[1] = controller_B.Gain2_o[1];

      /* End of Update for Derivative: '<S8>/Derivative' */
    }

    /* End of Update for SubSystem: '<Root>/Home1' */

    /* Update for Enabled SubSystem: '<Root>/Home2' incorporates:
     *  EnablePort: '<S9>/Enable'
     */
    if (controller_DW.Home2_MODE) {
      /* Update for Delay: '<S9>/Delay' */
      controller_DW.Delay_DSTATE_h[0] = controller_B.Switch_f[0];
      controller_DW.Delay_DSTATE_h[1] = controller_B.Switch_f[1];

      /* Update for Derivative: '<S9>/Derivative' */
      if (controller_DW.TimeStampA_g == (rtInf)) {
        controller_DW.TimeStampA_g = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeA_o;
      } else if (controller_DW.TimeStampB_f == (rtInf)) {
        controller_DW.TimeStampB_f = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeB_nm;
      } else if (controller_DW.TimeStampA_g < controller_DW.TimeStampB_f) {
        controller_DW.TimeStampA_g = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeA_o;
      } else {
        controller_DW.TimeStampB_f = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeB_nm;
      }

      (*lastU)[0] = controller_B.Gain2_p[0];
      (*lastU)[1] = controller_B.Gain2_p[1];

      /* End of Update for Derivative: '<S9>/Derivative' */
    }

    /* End of Update for SubSystem: '<Root>/Home2' */

    /* Update for Enabled SubSystem: '<Root>/Main Control' incorporates:
     *  EnablePort: '<S13>/Enable'
     */
    if (controller_DW.MainControl_MODE) {
      /* Update for Delay: '<S13>/Delay' */
      controller_DW.Delay_DSTATE[0] = controller_B.Switch[0];
      controller_DW.Delay_DSTATE[1] = controller_B.Switch[1];
    }

    /* End of Update for SubSystem: '<Root>/Main Control' */

    /* Update for Enabled SubSystem: '<Root>/Home4' incorporates:
     *  EnablePort: '<S11>/Enable'
     */
    if (controller_DW.Home4_MODE) {
      /* Update for Delay: '<S11>/Delay' */
      controller_DW.Delay_DSTATE_m[0] = controller_B.Switch_j[0];
      controller_DW.Delay_DSTATE_m[1] = controller_B.Switch_j[1];

      /* Update for Derivative: '<S11>/Derivative' */
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

      /* End of Update for Derivative: '<S11>/Derivative' */
    }

    /* End of Update for SubSystem: '<Root>/Home4' */

    /* Update for Enabled SubSystem: '<Root>/Home3' incorporates:
     *  EnablePort: '<S10>/Enable'
     */
    if (controller_DW.Home3_MODE) {
      /* Update for Delay: '<S10>/Delay' */
      controller_DW.Delay_DSTATE_a[0] = controller_B.Switch_n[0];
      controller_DW.Delay_DSTATE_a[1] = controller_B.Switch_n[1];

      /* Update for Derivative: '<S10>/Derivative' */
      if (controller_DW.TimeStampA_k == (rtInf)) {
        controller_DW.TimeStampA_k = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeA_n;
      } else if (controller_DW.TimeStampB_n == (rtInf)) {
        controller_DW.TimeStampB_n = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeB_n;
      } else if (controller_DW.TimeStampA_k < controller_DW.TimeStampB_n) {
        controller_DW.TimeStampA_k = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeA_n;
      } else {
        controller_DW.TimeStampB_n = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeB_n;
      }

      (*lastU)[0] = controller_B.Gain2_e[0];
      (*lastU)[1] = controller_B.Gain2_e[1];

      /* End of Update for Derivative: '<S10>/Derivative' */
    }

    /* End of Update for SubSystem: '<Root>/Home3' */
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
    /* Start for MATLABSystem: '<S6>/LED' */
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
    controller_DW.Home1_MODE = false;

    /* End of Start for SubSystem: '<Root>/Home1' */

    /* Start for Enabled SubSystem: '<Root>/Home2' */
    controller_DW.Home2_MODE = false;

    /* End of Start for SubSystem: '<Root>/Home2' */

    /* Start for Enabled SubSystem: '<Root>/Main Control' */
    controller_DW.MainControl_MODE = false;

    /* End of Start for SubSystem: '<Root>/Main Control' */

    /* Start for Enabled SubSystem: '<Root>/Home4' */
    controller_DW.Home4_MODE = false;

    /* End of Start for SubSystem: '<Root>/Home4' */

    /* Start for Enabled SubSystem: '<Root>/Home3' */
    controller_DW.Home3_MODE = false;

    /* End of Start for SubSystem: '<Root>/Home3' */

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
  controller_PrevZCX.StopMotor1_b.StopMotor1_Trig_ZCE_f = POS_ZCSIG;
  controller_PrevZCX.StopMotor1_g.StopMotor1_Trig_ZCE = POS_ZCSIG;
  controller_PrevZCX.StopMotor1.StopMotor1_Trig_ZCE_f = POS_ZCSIG;

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home1' */
  /* InitializeConditions for Derivative: '<S8>/Derivative' */
  controller_DW.TimeStampA_f = (rtInf);
  controller_DW.TimeStampB_o = (rtInf);

  /* InitializeConditions for Delay: '<S8>/Delay' */
  controller_DW.Delay_DSTATE_n[0] = controller_P.Delay_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<Root>/Home1' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home2' */
  /* InitializeConditions for Delay: '<S9>/Delay' */
  controller_DW.Delay_DSTATE_h[0] = controller_P.Delay_InitialCondition_o;

  /* End of SystemInitialize for SubSystem: '<Root>/Home2' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home1' */
  /* InitializeConditions for Delay: '<S8>/Delay' */
  controller_DW.Delay_DSTATE_n[1] = controller_P.Delay_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<Root>/Home1' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home2' */
  /* InitializeConditions for Delay: '<S9>/Delay' */
  controller_DW.Delay_DSTATE_h[1] = controller_P.Delay_InitialCondition_o;

  /* InitializeConditions for Derivative: '<S9>/Derivative' */
  controller_DW.TimeStampA_g = (rtInf);
  controller_DW.TimeStampB_f = (rtInf);

  /* SystemInitialize for Triggered SubSystem: '<S9>/Stop Motor1' */
  controller_StopMotor1_m_Init(&controller_B.StopMotor1_g,
    &controller_P.StopMotor1_g);

  /* End of SystemInitialize for SubSystem: '<S9>/Stop Motor1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Home2' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Main Control' */
  /* InitializeConditions for Delay: '<S13>/Delay' */
  controller_DW.Delay_DSTATE[0] = controller_P.Delay_InitialCondition_b;

  /* End of SystemInitialize for SubSystem: '<Root>/Main Control' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home4' */
  /* InitializeConditions for Delay: '<S11>/Delay' */
  controller_DW.Delay_DSTATE_m[0] = controller_P.Delay_InitialCondition_k;

  /* End of SystemInitialize for SubSystem: '<Root>/Home4' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Main Control' */
  /* InitializeConditions for Delay: '<S13>/Delay' */
  controller_DW.Delay_DSTATE[1] = controller_P.Delay_InitialCondition_b;

  /* End of SystemInitialize for SubSystem: '<Root>/Main Control' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home4' */
  /* InitializeConditions for Delay: '<S11>/Delay' */
  controller_DW.Delay_DSTATE_m[1] = controller_P.Delay_InitialCondition_k;

  /* InitializeConditions for Derivative: '<S11>/Derivative' */
  controller_DW.TimeStampA = (rtInf);
  controller_DW.TimeStampB = (rtInf);

  /* SystemInitialize for Triggered SubSystem: '<S11>/Stop Motor1' */
  controller_StopMotor1_m_Init(&controller_B.StopMotor1_d,
    &controller_P.StopMotor1_d);

  /* End of SystemInitialize for SubSystem: '<S11>/Stop Motor1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Home4' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home3' */
  /* InitializeConditions for Delay: '<S10>/Delay' */
  controller_DW.Delay_DSTATE_a[0] = controller_P.Delay_InitialCondition_c;
  controller_DW.Delay_DSTATE_a[1] = controller_P.Delay_InitialCondition_c;

  /* InitializeConditions for Derivative: '<S10>/Derivative' */
  controller_DW.TimeStampA_k = (rtInf);
  controller_DW.TimeStampB_n = (rtInf);

  /* End of SystemInitialize for SubSystem: '<Root>/Home3' */
}

/* Model terminate function */
void controller_terminate(void)
{
  /* Terminate for Triggered SubSystem: '<Root>/E-stop' */
  /* Terminate for MATLABSystem: '<S6>/LED' */
  if (!controller_DW.obj_n.matlabCodegenIsDeleted) {
    controller_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_n.isInitialized == 1) &&
        controller_DW.obj_n.isSetupComplete) {
      rc_led_cleanup();
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/LED' */
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
