/*
 * controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.670
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Wed Nov 29 14:25:05 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controller.h"
#include "rtwtypes.h"
#include "controller_types.h"
#include "controller_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "coder_posix_time.h"
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
static void controller_getLocalTime(real_T *b_t_tm_nsec, real_T *b_t_tm_sec,
  real_T *b_t_tm_min, real_T *b_t_tm_hour, real_T *b_t_tm_mday, real_T
  *b_t_tm_mon, real_T *b_t_tm_year, boolean_T *b_t_tm_isdst);
static creal_T controller_split(real_T b_a);
static creal_T controller_times(const creal_T b_a, B_MATLABFunction_controller_T
  *localB);
static creal_T controller_plus(const creal_T b_a, real_T b);
static creal_T controller_floor(const creal_T b_a);
static creal_T controller_minus(const creal_T b_a, const creal_T b);

/* Forward declaration for local functions */
static void controller_SystemCore_setup(dsp_simulink_MovingAverage_co_T *obj);
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
  (controller_M->Timing.TaskCounters.TID[1])++;
  if ((controller_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[1] = 0;
  }

  (controller_M->Timing.TaskCounters.TID[2])++;
  if ((controller_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.1s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[2] = 0;
  }

  (controller_M->Timing.TaskCounters.TID[3])++;
  if ((controller_M->Timing.TaskCounters.TID[3]) > 499) {/* Sample time: [0.5s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[3] = 0;
  }

  (controller_M->Timing.TaskCounters.TID[4])++;
  if ((controller_M->Timing.TaskCounters.TID[4]) > 999) {/* Sample time: [1.0s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[4] = 0;
  }

  (controller_M->Timing.TaskCounters.TID[5])++;
  if ((controller_M->Timing.TaskCounters.TID[5]) > 99999) {/* Sample time: [100.0s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[5] = 0;
  }

  (controller_M->Timing.TaskCounters.TID[6])++;
  if ((controller_M->Timing.TaskCounters.TID[6]) > 9999999) {/* Sample time: [10000.0s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[6] = 0;
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
 *    '<S7>/Stop Motor1'
 *    '<S8>/Stop Motor1'
 */
void controller_StopMotor1(boolean_T rtu_Trigger, const real_T *rtd_num_motors,
  const int32_T *rtd_pdo_id, ZCE_StopMotor1_controller_T *localZCE)
{
  real_T rtb_DataStoreRead7_b;
  int32_T rtb_DataStoreRead1_l;

  /* Outputs for Triggered SubSystem: '<S7>/Stop Motor1' incorporates:
   *  TriggerPort: '<S12>/Trigger'
   */
  if (rtu_Trigger && (localZCE->StopMotor1_Trig_ZCE != POS_ZCSIG)) {
    /* DataStoreRead: '<S12>/Data Store Read1' */
    rtb_DataStoreRead1_l = *rtd_pdo_id;

    /* DataStoreRead: '<S12>/Data Store Read7' */
    rtb_DataStoreRead7_b = *rtd_num_motors;

    /* DataTypeConversion: '<S12>/Data Type Conversion' */
    rtb_DataStoreRead7_b = floor(rtb_DataStoreRead7_b);
    if (rtIsNaN(rtb_DataStoreRead7_b) || rtIsInf(rtb_DataStoreRead7_b)) {
      rtb_DataStoreRead7_b = 0.0;
    } else {
      rtb_DataStoreRead7_b = fmod(rtb_DataStoreRead7_b, 4.294967296E+9);
    }

    /* CCaller: '<S12>/C Caller4' incorporates:
     *  DataTypeConversion: '<S12>/Data Type Conversion'
     */
    stop_motor(rtb_DataStoreRead1_l, rtb_DataStoreRead7_b < 0.0 ? -(int32_T)
               (uint32_T)-rtb_DataStoreRead7_b : (int32_T)(uint32_T)
               rtb_DataStoreRead7_b);
  }

  localZCE->StopMotor1_Trig_ZCE = rtu_Trigger;

  /* End of Outputs for SubSystem: '<S7>/Stop Motor1' */
}

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static void controller_getLocalTime(real_T *b_t_tm_nsec, real_T *b_t_tm_sec,
  real_T *b_t_tm_min, real_T *b_t_tm_hour, real_T *b_t_tm_mday, real_T
  *b_t_tm_mon, real_T *b_t_tm_year, boolean_T *b_t_tm_isdst)
{
  coderTm origStructTm;
  coderLocalTime(&origStructTm);
  *b_t_tm_nsec = (real_T)origStructTm.tm_nsec;
  *b_t_tm_sec = origStructTm.tm_sec;
  *b_t_tm_min = origStructTm.tm_min;
  *b_t_tm_hour = origStructTm.tm_hour;
  *b_t_tm_mday = origStructTm.tm_mday;
  *b_t_tm_mon = origStructTm.tm_mon;
  *b_t_tm_year = origStructTm.tm_year;
  *b_t_tm_isdst = (origStructTm.tm_isdst != 0);
}

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static creal_T controller_times(const creal_T b_a, B_MATLABFunction_controller_T
  *localB)
{
  creal_T c;
  real_T ahi;
  real_T alo;
  real_T shi;
  real_T slo;
  localB->da_m = controller_split(b_a.re);
  shi = b_a.re * 8.64E+7;
  slo = (localB->da_m.re * 8.64E+7 - shi) + localB->da_m.im * 8.64E+7;
  alo = slo;
  if (rtIsNaN(slo)) {
    alo = 0.0;
  }

  slo = b_a.im * 8.64E+7;
  ahi = shi;
  if (slo != 0.0) {
    alo += slo;
    ahi = shi + alo;
    alo -= ahi - shi;
  }

  if (rtIsNaN(alo)) {
    alo = 0.0;
  }

  c.re = ahi;
  c.im = alo;
  return c;
}

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static creal_T controller_plus(const creal_T b_a, real_T b)
{
  creal_T c;
  real_T ahi;
  real_T bb;
  real_T d_idx_0;
  real_T f_idx_0;
  real_T shi;
  shi = b_a.re + b;
  bb = shi - b_a.re;
  bb = (b_a.re - (shi - bb)) + (b - bb);
  d_idx_0 = bb;
  if (rtIsNaN(bb)) {
    d_idx_0 = 0.0;
  }

  bb = b_a.im - b_a.im;
  bb = (b_a.im - (b_a.im - bb)) + (0.0 - bb);
  f_idx_0 = bb;
  if (rtIsNaN(bb)) {
    f_idx_0 = 0.0;
  }

  bb = d_idx_0;
  ahi = shi;
  if (b_a.im != 0.0) {
    bb = d_idx_0 + b_a.im;
    ahi = shi + bb;
    bb -= ahi - shi;
  }

  if (rtIsNaN(bb)) {
    bb = 0.0;
  }

  shi = ahi;
  if (f_idx_0 != 0.0) {
    bb += f_idx_0;
    shi = ahi + bb;
    bb -= shi - ahi;
  }

  if (rtIsNaN(bb)) {
    bb = 0.0;
  }

  c.re = shi;
  c.im = bb;
  return c;
}

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static creal_T controller_floor(const creal_T b_a)
{
  creal_T b;
  real_T alo;
  real_T b_ahi;
  real_T b_b;
  real_T b_tmp;
  b_tmp = floor(b_a.re);
  b.re = b_tmp;
  b.im = 0.0;
  if (b_tmp == b_a.re) {
    b_b = floor(b_a.im);
    alo = 0.0;
    b_ahi = b_tmp;
    if (b_b != 0.0) {
      b_ahi = b_tmp + b_b;
      alo = b_b - (b_ahi - b_tmp);
    }

    if (rtIsNaN(alo)) {
      alo = 0.0;
    }

    b.re = b_ahi;
    b.im = alo;
  }

  return b;
}

/* Function for MATLAB Function: '<S16>/MATLAB Function' */
static creal_T controller_minus(const creal_T b_a, const creal_T b)
{
  creal_T cout;
  real_T ahi;
  real_T b_bb;
  real_T bb;
  real_T d_idx_0;
  real_T f_idx_0;
  real_T shi;
  shi = b_a.re - b.re;
  bb = shi - b_a.re;
  bb = (b_a.re - (shi - bb)) - (b.re + bb);
  d_idx_0 = bb;
  if (rtIsNaN(bb)) {
    d_idx_0 = 0.0;
  }

  bb = b_a.im - b.im;
  b_bb = bb - b_a.im;
  b_bb = (b_a.im - (bb - b_bb)) - (b.im + b_bb);
  f_idx_0 = b_bb;
  if (rtIsNaN(b_bb)) {
    f_idx_0 = 0.0;
  }

  b_bb = d_idx_0;
  ahi = shi;
  if (bb != 0.0) {
    b_bb = d_idx_0 + bb;
    ahi = shi + b_bb;
    b_bb -= ahi - shi;
  }

  if (rtIsNaN(b_bb)) {
    b_bb = 0.0;
  }

  shi = ahi;
  if (f_idx_0 != 0.0) {
    b_bb += f_idx_0;
    shi = ahi + b_bb;
    b_bb -= shi - ahi;
  }

  if (rtIsNaN(b_bb)) {
    b_bb = 0.0;
  }

  cout.re = shi;
  cout.im = b_bb;
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

/*
 * Output and update for atomic system:
 *    '<S16>/MATLAB Function'
 *    '<S24>/MATLAB Function'
 *    '<S34>/MATLAB Function'
 */
void controller_MATLABFunction(B_MATLABFunction_controller_T *localB)
{
  real_T c_s_im;
  int32_T u0;
  boolean_T expl_temp;
  controller_getLocalTime(&localB->fracSecs, &localB->second, &localB->c_tm_min,
    &localB->c_slo, &localB->c_shi, &c_s_im, &localB->c_tm_year, &expl_temp);
  localB->fracSecs /= 1.0E+6;
  localB->check = (((((localB->c_tm_year + c_s_im) + localB->c_shi) +
                     localB->c_slo) + localB->c_tm_min) + localB->second) +
    localB->fracSecs;
  if ((!rtIsInf(localB->check)) && (!rtIsNaN(localB->check))) {
    if ((c_s_im < 1.0) || (c_s_im > 12.0)) {
      localB->check = floor((c_s_im - 1.0) / 12.0);
      localB->c_tm_year += localB->check;
      c_s_im = ((c_s_im - 1.0) - localB->check * 12.0) + 1.0;
    }

    if (c_s_im < 3.0) {
      localB->c_tm_year--;
      c_s_im += 9.0;
    } else {
      c_s_im -= 3.0;
    }

    if ((localB->fracSecs < 0.0) || (localB->fracSecs >= 1000.0)) {
      localB->check = floor(localB->fracSecs / 1000.0);
      localB->second += localB->check;
      localB->fracSecs -= localB->check * 1000.0;
    }

    localB->da.re = ((((((365.0 * localB->c_tm_year + floor(localB->c_tm_year /
      4.0)) - floor(localB->c_tm_year / 100.0)) + floor(localB->c_tm_year /
      400.0)) + floor((153.0 * c_s_im + 2.0) / 5.0)) + localB->c_shi) + 60.0) -
      719529.0;
    localB->da.im = 0.0;
    localB->d_data = controller_plus(controller_plus(controller_plus
      (controller_times(localB->da, localB), (60.0 * localB->c_slo +
      localB->c_tm_min) * 60000.0), localB->second * 1000.0), localB->fracSecs);
  } else {
    localB->d_data.re = localB->check;
    localB->d_data.im = 0.0;
  }

  localB->c_tm_min = localB->d_data.re / 8.64E+7;
  localB->da = controller_split(localB->c_tm_min);
  localB->c_shi = localB->c_tm_min * 8.64E+7;
  localB->c_slo = (localB->da.re * 8.64E+7 - localB->c_shi) + localB->da.im *
    8.64E+7;
  localB->fracSecs = localB->c_slo;
  if (rtIsNaN(localB->c_slo)) {
    localB->fracSecs = 0.0;
  }

  localB->c_slo = 0.0;
  c_s_im = 0.0;
  if (localB->d_data.re != localB->c_shi) {
    localB->c_slo = localB->d_data.re - localB->c_shi;
    c_s_im = localB->c_slo - localB->d_data.re;
    localB->c_shi = (localB->d_data.re - (localB->c_slo - c_s_im)) -
      (localB->c_shi + c_s_im);
    if (rtIsNaN(localB->c_shi)) {
      localB->c_shi = 0.0;
    }

    c_s_im = localB->c_shi;
  }

  localB->c_slo = (((0.0 * localB->d_data.im + localB->c_slo) - 0.0 *
                    localB->fracSecs) + ((c_s_im + localB->d_data.im) -
    localB->fracSecs)) / 8.64E+7;
  localB->c_shi = 0.0;
  c_s_im = localB->c_tm_min;
  if (localB->c_slo != 0.0) {
    c_s_im = localB->c_tm_min + localB->c_slo;
    localB->c_shi = localB->c_slo - (c_s_im - localB->c_tm_min);
  }

  if (rtIsNaN(localB->c_shi)) {
    localB->c_shi = 0.0;
  }

  localB->d_ahi.re = c_s_im;
  localB->d_ahi.im = localB->c_shi;
  localB->d_data = controller_minus(localB->d_data, controller_times
    (controller_floor(localB->d_ahi), localB));
  localB->c_tm_min = localB->d_data.re / 1000.0;
  localB->da = controller_split(localB->c_tm_min);
  localB->c_shi = localB->c_tm_min * 1000.0;
  localB->c_slo = (localB->da.re * 1000.0 - localB->c_shi) + localB->da.im *
    1000.0;
  localB->fracSecs = localB->c_slo;
  if (rtIsNaN(localB->c_slo)) {
    localB->fracSecs = 0.0;
  }

  localB->c_slo = 0.0;
  c_s_im = 0.0;
  if (localB->d_data.re != localB->c_shi) {
    localB->c_slo = localB->d_data.re - localB->c_shi;
    c_s_im = localB->c_slo - localB->d_data.re;
    localB->c_shi = (localB->d_data.re - (localB->c_slo - c_s_im)) -
      (localB->c_shi + c_s_im);
    if (rtIsNaN(localB->c_shi)) {
      localB->c_shi = 0.0;
    }

    c_s_im = localB->c_shi;
  }

  localB->c_slo = (((0.0 * localB->d_data.im + localB->c_slo) - 0.0 *
                    localB->fracSecs) + ((c_s_im + localB->d_data.im) -
    localB->fracSecs)) / 1000.0;
  localB->c_shi = 0.0;
  c_s_im = localB->c_tm_min;
  if (localB->c_slo != 0.0) {
    c_s_im = localB->c_tm_min + localB->c_slo;
    localB->c_shi = localB->c_slo - (c_s_im - localB->c_tm_min);
  }

  if (rtIsNaN(localB->c_shi)) {
    localB->c_shi = 0.0;
  }

  localB->d_data.re = c_s_im;
  localB->d_data.im = localB->c_shi;
  localB->da = controller_floor(localB->d_data);
  localB->d_ahi = controller_minus(localB->d_data, localB->da);
  localB->c_tm_min = localB->da.re + localB->da.im;
  if ((localB->c_tm_min >= 0.0) && (localB->c_tm_min <= 2.147483647E+9)) {
    u0 = (int32_T)rt_roundd_snf(localB->c_tm_min);
    u0 -= 3600 * div_s32(u0, 3600);
    localB->c_tm_min = u0 - 60 * div_s32(u0, 60);
  } else {
    localB->c_tm_min -= floor((localB->c_tm_min - floor(localB->c_tm_min /
      3600.0) * 3600.0) / 60.0) * 60.0;
  }

  localB->y = (localB->d_ahi.re + localB->d_ahi.im) + localB->c_tm_min;
  if (localB->y == 60.0) {
    localB->y = 59.999999999999993;
  }
}

static void controller_SystemCore_setup(dsp_simulink_MovingAverage_co_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->NumChannels = 1;
  obj->FrameLength = 1;
  obj->_pobj0.isInitialized = 0;
  obj->_pobj0.isInitialized = 0;
  obj->pStatistic = &obj->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

/* System initialize for atomic system: */
void controller_MovingAverage_Init(DW_MovingAverage_controller_T *localDW)
{
  h_dsp_internal_SlidingWindowA_T *obj;
  int32_T i;

  /* InitializeConditions for MATLABSystem: '<S10>/Moving Average' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pCumSum = 0.0;
    for (i = 0; i < 7; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S10>/Moving Average' */
}

/* Start for atomic system: */
void controller_MovingAverage_Start(DW_MovingAverage_controller_T *localDW)
{
  /* Start for MATLABSystem: '<S10>/Moving Average' */
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.FrameLength = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  controller_SystemCore_setup(&localDW->obj);
}

/* Output and update for atomic system: */
void controller_MovingAverage(real_T rtu_0, B_MovingAverage_controller_T *localB,
  DW_MovingAverage_controller_T *localDW)
{
  h_dsp_internal_SlidingWindowA_T *obj;
  real_T csum;
  real_T cumRevIndex;
  real_T modValueRev;
  real_T z;
  int32_T i;

  /* MATLABSystem: '<S10>/Moving Average' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (i = 0; i < 7; i++) {
      obj->pCumSumRev[i] = 0.0;
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  for (i = 0; i < 7; i++) {
    localB->csumrev[i] = obj->pCumSumRev[i];
  }

  modValueRev = obj->pModValueRev;
  z = 0.0;

  /* MATLABSystem: '<S10>/Moving Average' */
  localB->MovingAverage = 0.0;

  /* MATLABSystem: '<S10>/Moving Average' */
  csum += rtu_0;
  if (modValueRev == 0.0) {
    z = localB->csumrev[(int32_T)cumRevIndex - 1] + csum;
  }

  localB->csumrev[(int32_T)cumRevIndex - 1] = rtu_0;
  if (cumRevIndex != 7.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    for (i = 5; i >= 0; i--) {
      localB->csumrev[i] += localB->csumrev[i + 1];
    }
  }

  if (modValueRev == 0.0) {
    /* MATLABSystem: '<S10>/Moving Average' */
    localB->MovingAverage = z / 8.0;
  }

  obj->pCumSum = csum;
  for (i = 0; i < 7; i++) {
    obj->pCumSumRev[i] = localB->csumrev[i];
  }

  obj->pCumRevIndex = cumRevIndex;
  if (modValueRev > 0.0) {
    obj->pModValueRev = modValueRev - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }
}

/* Termination for atomic system: */
void controller_MovingAverage_Term(DW_MovingAverage_controller_T *localDW)
{
  h_dsp_internal_SlidingWindowA_T *obj;

  /* Terminate for MATLABSystem: '<S10>/Moving Average' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      obj = localDW->obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
      localDW->obj.FrameLength = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S10>/Moving Average' */
}

/* Model step function */
void controller_step(void)
{
  boolean_T rtb_Compare_c;
  boolean_T rtb_Compare_f;
  boolean_T rtb_IsNaN1_n_0;
  if (controller_M->Timing.TaskCounters.TID[2] == 0) {
    controller_AnalogInput(&controller_B.AnalogInput, &controller_DW.AnalogInput,
      &controller_P.AnalogInput);

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
  if (controller_M->Timing.TaskCounters.TID[6] == 0) {
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
  controller_DW.max_speed = controller_P.Constant5_Value_i;

  /* DataStoreWrite: '<Root>/Data Store Write8' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  controller_DW.max_accel = controller_P.Constant6_Value_n;

  /* DataStoreWrite: '<Root>/Data Store Write9' incorporates:
   *  Constant: '<Root>/Constant7'
   */
  controller_DW.GR1 = controller_P.Constant7_Value;

  /* MATLABSystem: '<Root>/Digital Read' */
  if (controller_DW.obj_b.SampleTime != controller_P.DigitalRead_SampleTime) {
    controller_DW.obj_b.SampleTime = controller_P.DigitalRead_SampleTime;
  }

  /* DataStoreWrite: '<Root>/Data Store Write' incorporates:
   *  MATLABSystem: '<Root>/Digital Read'
   */
  controller_DW.LS1_L = MW_digitalIO_read
    (controller_DW.obj_b.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<Root>/Digital Read1' */
  if (controller_DW.obj_a.SampleTime != controller_P.DigitalRead1_SampleTime) {
    controller_DW.obj_a.SampleTime = controller_P.DigitalRead1_SampleTime;
  }

  /* DataStoreWrite: '<Root>/Data Store Write1' incorporates:
   *  MATLABSystem: '<Root>/Digital Read1'
   */
  controller_DW.LS1_R = MW_digitalIO_read
    (controller_DW.obj_a.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<Root>/Digital Read2' */
  if (controller_DW.obj_l.SampleTime != controller_P.DigitalRead2_SampleTime) {
    controller_DW.obj_l.SampleTime = controller_P.DigitalRead2_SampleTime;
  }

  /* DataStoreWrite: '<Root>/Data Store Write3' incorporates:
   *  MATLABSystem: '<Root>/Digital Read2'
   */
  controller_DW.LS2_L = MW_digitalIO_read
    (controller_DW.obj_l.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<Root>/Digital Read3' */
  if (controller_DW.obj.SampleTime != controller_P.DigitalRead3_SampleTime) {
    controller_DW.obj.SampleTime = controller_P.DigitalRead3_SampleTime;
  }

  /* DataStoreWrite: '<Root>/Data Store Write4' incorporates:
   *  MATLABSystem: '<Root>/Digital Read3'
   */
  controller_DW.LS2_R = MW_digitalIO_read(controller_DW.obj.MW_DIGITALIO_HANDLE);
  if (controller_M->Timing.TaskCounters.TID[4] == 0) {
    /* DataStoreRead: '<Root>/Data Store Read1' */
    controller_B.DataStoreRead1_c = controller_DW.state;

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Constant: '<Root>/Constant14'
     */
    controller_B.d = floor(controller_P.Constant14_Value);
    if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
      controller_B.d = 0.0;
    } else {
      controller_B.d = fmod(controller_B.d, 4.294967296E+9);
    }

    /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read9'
     */
    controller_B.rtb_Divide1_idx_1 = floor(controller_DW.debug);
    if (rtIsNaN(controller_B.rtb_Divide1_idx_1) || rtIsInf
        (controller_B.rtb_Divide1_idx_1)) {
      controller_B.rtb_Divide1_idx_1 = 0.0;
    } else {
      controller_B.rtb_Divide1_idx_1 = fmod(controller_B.rtb_Divide1_idx_1,
        4.294967296E+9);
    }

    /* CCaller: '<Root>/C Caller3' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read1'
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  DataTypeConversion: '<Root>/Data Type Conversion2'
     */
    print_input(controller_DW.state, controller_B.d < 0.0 ? -(int32_T)(uint32_T)
                -controller_B.d : (int32_T)(uint32_T)controller_B.d,
                controller_B.rtb_Divide1_idx_1 < 0.0 ? -(int32_T)(uint32_T)
                -controller_B.rtb_Divide1_idx_1 : (int32_T)(uint32_T)
                controller_B.rtb_Divide1_idx_1);

    /* Outputs for Enabled SubSystem: '<Root>/Initialize' incorporates:
     *  EnablePort: '<S9>/Enable'
     */
    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     */
    if (controller_B.DataStoreRead1_c == controller_P.CompareToConstant2_const)
    {
      controller_DW.Initialize_MODE = true;
      if (controller_M->Timing.TaskCounters.TID[6] == 0) {
        /* SignalConversion generated from: '<S9>/C Caller5' */
        controller_B.CCaller5_g[0] = 0;
        controller_B.CCaller5_g[1] = 0;

        /* DataTypeConversion: '<S9>/Data Type Conversion2' incorporates:
         *  DataStoreRead: '<S9>/Data Store Read7'
         */
        controller_B.d = floor(controller_DW.num_motors);
        if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
          controller_B.d = 0.0;
        } else {
          controller_B.d = fmod(controller_B.d, 4.294967296E+9);
        }

        /* CCaller: '<S9>/C Caller5' incorporates:
         *  Constant: '<S9>/Constant1'
         *  DataTypeConversion: '<S9>/Data Type Conversion2'
         */
        init_can(controller_B.d < 0.0 ? -(int32_T)(uint32_T)-controller_B.d :
                 (int32_T)(uint32_T)controller_B.d,
                 controller_P.Constant1_Value_f, controller_P.Constant1_Value_f,
                 &controller_B.CCaller5_g[0]);

        /* DataStoreWrite: '<S9>/Data Store Write' */
        controller_DW.cfg_id = controller_B.CCaller5_g[0];

        /* DataStoreWrite: '<S9>/Data Store Write2' */
        controller_DW.pdo_id = controller_B.CCaller5_g[1];

        /* RelationalOperator: '<S27>/Compare' incorporates:
         *  Constant: '<S27>/Constant'
         */
        rtb_Compare_c = (controller_B.CCaller5_g[1] !=
                         controller_P.CompareToConstant_const);

        /* Switch: '<S28>/Switch' */
        if (rtb_Compare_c) {
          /* DataStoreWrite: '<S28>/Data Store Write' incorporates:
           *  Constant: '<S9>/Constant'
           */
          controller_DW.state = controller_P.Constant_Value_d;
        }

        /* End of Switch: '<S28>/Switch' */
      }

      if (controller_M->Timing.TaskCounters.TID[5] == 0) {
        /* CCaller: '<S9>/C Caller3' */
        init_datalog();
      }
    } else {
      controller_DW.Initialize_MODE = false;
    }

    /* End of RelationalOperator: '<S2>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Initialize' */
  }

  /* Outputs for Enabled SubSystem: '<Root>/Home1' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  DataStoreRead: '<Root>/Data Store Read'
   */
  if (controller_DW.state == controller_P.CompareToConstant1_const) {
    controller_DW.Home1_MODE = true;

    /* RelationalOperator: '<S11>/Compare' incorporates:
     *  Constant: '<S11>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read10'
     */
    rtb_Compare_f = (controller_DW.LS1_L ==
                     controller_P.CompareToConstant1_const_j);

    /* Switch: '<S14>/Switch' */
    if (rtb_Compare_f) {
      /* DataStoreWrite: '<S14>/Data Store Write' incorporates:
       *  Constant: '<S7>/Constant1'
       */
      controller_DW.state = controller_P.Constant1_Value;
    }

    /* End of Switch: '<S14>/Switch' */

    /* SignalConversion generated from: '<S7>/C Caller6' */
    controller_B.Sum6_c[0] = 0.0;
    controller_B.Sum6_c[1] = 0.0;

    /* DataTypeConversion: '<S7>/Data Type Conversion11' incorporates:
     *  DataStoreRead: '<S7>/Data Store Read10'
     */
    controller_B.d = floor(controller_DW.num_motors);
    if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
      controller_B.d = 0.0;
    } else {
      controller_B.d = fmod(controller_B.d, 4.294967296E+9);
    }

    /* CCaller: '<S7>/C Caller6' incorporates:
     *  DataStoreRead: '<S7>/Data Store Read5'
     *  DataTypeConversion: '<S7>/Data Type Conversion11'
     */
    get_encoder(controller_DW.pdo_id, controller_B.d < 0.0 ? -(int32_T)(uint32_T)
                -controller_B.d : (int32_T)(uint32_T)controller_B.d,
                &controller_B.Sum6_c[0]);

    /* Switch: '<S15>/Switch2' incorporates:
     *  Sum: '<S15>/Sum6'
     */
    controller_B.DataStoreRead1_c = controller_B.Sum6_c[0];

    /* RelationalOperator: '<S17>/Compare' incorporates:
     *  Constant: '<S17>/Constant'
     */
    rtb_Compare_c = (controller_B.Sum6_c[0] != controller_P.Constant_Value);

    /* RelationalOperator: '<S15>/IsNaN1' */
    rtb_IsNaN1_n_0 = rtIsNaN(controller_B.Sum6_c[0]);

    /* Switch: '<S15>/Switch2' incorporates:
     *  Delay: '<S15>/Delay1'
     *  Logic: '<S15>/Logical Operator2'
     *  Logic: '<S15>/Logical Operator3'
     */
    if ((!rtb_Compare_c) || rtb_IsNaN1_n_0) {
      controller_B.DataStoreRead1_c = controller_DW.Delay1_DSTATE_e[0];
    }

    /* Sum: '<S15>/Sum6' */
    controller_B.Divide_e = controller_B.Sum6_c[1];

    /* RelationalOperator: '<S17>/Compare' incorporates:
     *  Constant: '<S17>/Constant'
     */
    rtb_Compare_c = (controller_B.Sum6_c[1] != controller_P.Constant_Value);

    /* RelationalOperator: '<S15>/IsNaN1' */
    rtb_IsNaN1_n_0 = rtIsNaN(controller_B.Sum6_c[1]);

    /* Switch: '<S15>/Switch2' incorporates:
     *  Delay: '<S15>/Delay1'
     *  Logic: '<S15>/Logical Operator2'
     *  Logic: '<S15>/Logical Operator3'
     */
    if ((!rtb_Compare_c) || rtb_IsNaN1_n_0) {
      controller_B.Divide_e = controller_DW.Delay1_DSTATE_e[1];
    }

    /* DataStoreWrite: '<S7>/Data Store Write1' */
    controller_DW.q01 = controller_B.DataStoreRead1_c;

    /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
     *  Constant: '<Root>/Constant'
     */
    controller_B.d = floor(controller_P.Constant_Value_c);
    if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
      controller_B.d = 0.0;
    } else {
      controller_B.d = fmod(controller_B.d, 4.294967296E+9);
    }

    /* CCaller: '<S13>/C Caller3' incorporates:
     *  Constant: '<S7>/Constant4'
     *  DataStoreRead: '<S13>/Data Store Read2'
     *  DataTypeConversion: '<S13>/Data Type Conversion1'
     */
    set_motor(controller_DW.pdo_id, controller_B.d < 0.0 ? -(int32_T)(uint32_T)
              -controller_B.d : (int32_T)(uint32_T)controller_B.d,
              controller_P.Constant4_Value);

    /* Outputs for Triggered SubSystem: '<S7>/Stop Motor1' */
    controller_StopMotor1(rtb_Compare_f, &controller_DW.num_motors,
                          &controller_DW.pdo_id, &controller_PrevZCX.StopMotor1);

    /* End of Outputs for SubSystem: '<S7>/Stop Motor1' */
    if (controller_M->Timing.TaskCounters.TID[3] == 0) {
      /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
       *  Constant: '<S7>/Constant3'
       */
      controller_B.d = floor(controller_P.Constant3_Value);
      if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
        controller_B.d = 0.0;
      } else {
        controller_B.d = fmod(controller_B.d, 4.294967296E+9);
      }

      /* DataTypeConversion: '<S7>/Data Type Conversion6' incorporates:
       *  DataStoreRead: '<S7>/Data Store Read1'
       */
      controller_B.rtb_Divide1_idx_1 = floor(controller_DW.debug);
      if (rtIsNaN(controller_B.rtb_Divide1_idx_1) || rtIsInf
          (controller_B.rtb_Divide1_idx_1)) {
        controller_B.rtb_Divide1_idx_1 = 0.0;
      } else {
        controller_B.rtb_Divide1_idx_1 = fmod(controller_B.rtb_Divide1_idx_1,
          4.294967296E+9);
      }

      /* CCaller: '<S7>/C Caller1' incorporates:
       *  DataTypeConversion: '<S7>/Data Type Conversion1'
       *  DataTypeConversion: '<S7>/Data Type Conversion6'
       */
      print_input(0.0, controller_B.d < 0.0 ? -(int32_T)(uint32_T)
                  -controller_B.d : (int32_T)(uint32_T)controller_B.d,
                  controller_B.rtb_Divide1_idx_1 < 0.0 ? -(int32_T)(uint32_T)
                  -controller_B.rtb_Divide1_idx_1 : (int32_T)(uint32_T)
                  controller_B.rtb_Divide1_idx_1);

      /* DataTypeConversion: '<S7>/Data Type Conversion7' incorporates:
       *  Constant: '<S7>/Constant5'
       */
      controller_B.d = floor(controller_P.Constant5_Value);
      if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
        controller_B.d = 0.0;
      } else {
        controller_B.d = fmod(controller_B.d, 4.294967296E+9);
      }

      /* DataTypeConversion: '<S7>/Data Type Conversion9' incorporates:
       *  DataStoreRead: '<S7>/Data Store Read2'
       */
      controller_B.rtb_Divide1_idx_1 = floor(controller_DW.debug);
      if (rtIsNaN(controller_B.rtb_Divide1_idx_1) || rtIsInf
          (controller_B.rtb_Divide1_idx_1)) {
        controller_B.rtb_Divide1_idx_1 = 0.0;
      } else {
        controller_B.rtb_Divide1_idx_1 = fmod(controller_B.rtb_Divide1_idx_1,
          4.294967296E+9);
      }

      /* CCaller: '<S7>/C Caller3' incorporates:
       *  DataTypeConversion: '<S7>/Data Type Conversion7'
       *  DataTypeConversion: '<S7>/Data Type Conversion9'
       */
      print_input(0.0, controller_B.d < 0.0 ? -(int32_T)(uint32_T)
                  -controller_B.d : (int32_T)(uint32_T)controller_B.d,
                  controller_B.rtb_Divide1_idx_1 < 0.0 ? -(int32_T)(uint32_T)
                  -controller_B.rtb_Divide1_idx_1 : (int32_T)(uint32_T)
                  controller_B.rtb_Divide1_idx_1);
    }

    /* MATLAB Function: '<S16>/MATLAB Function' */
    controller_MATLABFunction(&controller_B.sf_MATLABFunction);

    /* Update for Delay: '<S15>/Delay1' incorporates:
     *  Switch: '<S15>/Switch2'
     */
    controller_DW.Delay1_DSTATE_e[0] = controller_B.DataStoreRead1_c;
    controller_DW.Delay1_DSTATE_e[1] = controller_B.Divide_e;
  } else {
    controller_DW.Home1_MODE = false;
  }

  /* End of RelationalOperator: '<S1>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/Home1' */

  /* Outputs for Enabled SubSystem: '<Root>/Home2' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  DataStoreRead: '<Root>/Data Store Read3'
   */
  if (controller_DW.state == controller_P.CompareToConstant3_const) {
    /* RelationalOperator: '<S19>/Compare' incorporates:
     *  Constant: '<S19>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read4'
     */
    rtb_Compare_f = (controller_DW.LS2_L ==
                     controller_P.CompareToConstant1_const_p);

    /* Switch: '<S22>/Switch' */
    if (rtb_Compare_f) {
      /* DataStoreWrite: '<S22>/Data Store Write' incorporates:
       *  Constant: '<S8>/Constant1'
       */
      controller_DW.state = controller_P.Constant1_Value_g;
    }

    /* End of Switch: '<S22>/Switch' */

    /* SignalConversion generated from: '<S8>/C Caller6' */
    controller_B.Sum6_c[0] = 0.0;
    controller_B.Sum6_c[1] = 0.0;

    /* DataTypeConversion: '<S8>/Data Type Conversion11' incorporates:
     *  DataStoreRead: '<S8>/Data Store Read10'
     */
    controller_B.d = floor(controller_DW.num_motors);
    if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
      controller_B.d = 0.0;
    } else {
      controller_B.d = fmod(controller_B.d, 4.294967296E+9);
    }

    /* CCaller: '<S8>/C Caller6' incorporates:
     *  DataStoreRead: '<S8>/Data Store Read5'
     *  DataTypeConversion: '<S8>/Data Type Conversion11'
     */
    get_encoder(controller_DW.pdo_id, controller_B.d < 0.0 ? -(int32_T)(uint32_T)
                -controller_B.d : (int32_T)(uint32_T)controller_B.d,
                &controller_B.Sum6_c[0]);

    /* Switch: '<S23>/Switch2' incorporates:
     *  Sum: '<S23>/Sum6'
     */
    controller_B.DataStoreRead1_c = controller_B.Sum6_c[0];

    /* RelationalOperator: '<S25>/Compare' incorporates:
     *  Constant: '<S25>/Constant'
     */
    rtb_Compare_c = (controller_B.Sum6_c[0] != controller_P.Constant_Value_b);

    /* RelationalOperator: '<S23>/IsNaN1' */
    rtb_IsNaN1_n_0 = rtIsNaN(controller_B.Sum6_c[0]);

    /* Switch: '<S23>/Switch2' incorporates:
     *  Delay: '<S23>/Delay1'
     *  Logic: '<S23>/Logical Operator2'
     *  Logic: '<S23>/Logical Operator3'
     */
    if ((!rtb_Compare_c) || rtb_IsNaN1_n_0) {
      controller_B.DataStoreRead1_c = controller_DW.Delay1_DSTATE_i[0];
    }

    /* Sum: '<S23>/Sum6' */
    controller_B.Divide_e = controller_B.Sum6_c[1];

    /* RelationalOperator: '<S25>/Compare' incorporates:
     *  Constant: '<S25>/Constant'
     */
    rtb_Compare_c = (controller_B.Sum6_c[1] != controller_P.Constant_Value_b);

    /* RelationalOperator: '<S23>/IsNaN1' */
    rtb_IsNaN1_n_0 = rtIsNaN(controller_B.Sum6_c[1]);

    /* Switch: '<S23>/Switch2' incorporates:
     *  Delay: '<S23>/Delay1'
     *  Logic: '<S23>/Logical Operator2'
     *  Logic: '<S23>/Logical Operator3'
     */
    if ((!rtb_Compare_c) || rtb_IsNaN1_n_0) {
      controller_B.Divide_e = controller_DW.Delay1_DSTATE_i[1];
    }

    /* DataStoreWrite: '<S8>/Data Store Write1' incorporates:
     *  Switch: '<S23>/Switch2'
     */
    controller_DW.q02 = controller_B.Divide_e;

    /* DataTypeConversion: '<S21>/Data Type Conversion1' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    controller_B.d = floor(controller_P.Constant2_Value_k);
    if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
      controller_B.d = 0.0;
    } else {
      controller_B.d = fmod(controller_B.d, 4.294967296E+9);
    }

    /* CCaller: '<S21>/C Caller3' incorporates:
     *  Constant: '<S8>/Constant6'
     *  DataStoreRead: '<S21>/Data Store Read2'
     *  DataTypeConversion: '<S21>/Data Type Conversion1'
     */
    set_motor(controller_DW.pdo_id, controller_B.d < 0.0 ? -(int32_T)(uint32_T)
              -controller_B.d : (int32_T)(uint32_T)controller_B.d,
              controller_P.Constant6_Value);

    /* Outputs for Triggered SubSystem: '<S8>/Stop Motor1' */
    controller_StopMotor1(rtb_Compare_f, &controller_DW.num_motors,
                          &controller_DW.pdo_id,
                          &controller_PrevZCX.StopMotor1_a);

    /* End of Outputs for SubSystem: '<S8>/Stop Motor1' */

    /* MATLAB Function: '<S24>/MATLAB Function' */
    controller_MATLABFunction(&controller_B.sf_MATLABFunction_l);

    /* Update for Delay: '<S23>/Delay1' incorporates:
     *  Switch: '<S23>/Switch2'
     */
    controller_DW.Delay1_DSTATE_i[0] = controller_B.DataStoreRead1_c;
    controller_DW.Delay1_DSTATE_i[1] = controller_B.Divide_e;
  }

  /* End of RelationalOperator: '<S3>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/Home2' */

  /* DataStoreRead: '<Root>/Data Store Read7' */
  controller_B.DataStoreRead1_c = controller_DW.q01;

  /* DataStoreRead: '<Root>/Data Store Read8' */
  controller_B.DataStoreRead8 = controller_DW.q02;

  /* Outputs for Enabled SubSystem: '<Root>/Main Control' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   *  DataStoreRead: '<Root>/Data Store Read2'
   */
  if (controller_DW.state == controller_P.CompareToConstant4_const) {
    controller_DW.MainControl_MODE = true;

    /* Switch: '<S32>/Switch' incorporates:
     *  Constant: '<S29>/Constant'
     *  DataStoreRead: '<S10>/Data Store Read3'
     *  RelationalOperator: '<S29>/Compare'
     */
    if (controller_DW.LS1_R == controller_P.CompareToConstant_const_g) {
      /* DataStoreWrite: '<S32>/Data Store Write' incorporates:
       *  Constant: '<S10>/Constant4'
       */
      controller_DW.state = controller_P.Constant4_Value_l;
    }

    /* End of Switch: '<S32>/Switch' */

    /* MATLAB Function: '<S34>/MATLAB Function' */
    controller_MATLABFunction(&controller_B.sf_MATLABFunction_e);

    /* Sum: '<S34>/Sum' incorporates:
     *  UnitDelay: '<S34>/Unit Delay'
     */
    controller_B.Divide_e = controller_B.sf_MATLABFunction_e.y -
      controller_DW.UnitDelay_DSTATE;

    /* Switch: '<S34>/Switch' incorporates:
     *  Constant: '<S34>/Constant'
     *  Constant: '<S34>/Constant1'
     *  Constant: '<S34>/Constant2'
     *  Logic: '<S34>/Logical Operator'
     *  RelationalOperator: '<S34>/Relational Operator'
     *  RelationalOperator: '<S34>/Relational Operator1'
     */
    if ((!(controller_B.Divide_e >= controller_P.Constant_Value_m)) ||
        (!(controller_B.Divide_e <= controller_P.Constant2_Value))) {
      controller_B.Divide_e = controller_P.Constant1_Value_j;
    }

    /* End of Switch: '<S34>/Switch' */

    /* Sum: '<S34>/Sum1' incorporates:
     *  UnitDelay: '<S34>/Unit Delay1'
     */
    controller_B.Sum1 = controller_B.Divide_e + controller_DW.UnitDelay1_DSTATE;
    if (controller_M->Timing.TaskCounters.TID[1] == 0) {
      /* DataTypeConversion: '<S10>/Data Type Conversion7' incorporates:
       *  Constant: '<S10>/Constant9'
       */
      controller_B.d = floor(controller_P.Constant9_Value);
      if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
        controller_B.d = 0.0;
      } else {
        controller_B.d = fmod(controller_B.d, 4.294967296E+9);
      }

      /* DataTypeConversion: '<S10>/Data Type Conversion9' incorporates:
       *  DataStoreRead: '<S10>/Data Store Read4'
       */
      controller_B.rtb_Divide1_idx_1 = floor(controller_DW.debug);
      if (rtIsNaN(controller_B.rtb_Divide1_idx_1) || rtIsInf
          (controller_B.rtb_Divide1_idx_1)) {
        controller_B.rtb_Divide1_idx_1 = 0.0;
      } else {
        controller_B.rtb_Divide1_idx_1 = fmod(controller_B.rtb_Divide1_idx_1,
          4.294967296E+9);
      }

      /* CCaller: '<S10>/C Caller2' incorporates:
       *  DataTypeConversion: '<S10>/Data Type Conversion7'
       *  DataTypeConversion: '<S10>/Data Type Conversion9'
       */
      print_input(controller_B.Sum1, controller_B.d < 0.0 ? -(int32_T)(uint32_T)
                  -controller_B.d : (int32_T)(uint32_T)controller_B.d,
                  controller_B.rtb_Divide1_idx_1 < 0.0 ? -(int32_T)(uint32_T)
                  -controller_B.rtb_Divide1_idx_1 : (int32_T)(uint32_T)
                  controller_B.rtb_Divide1_idx_1);
    }

    /* Sum: '<S33>/Sum6' incorporates:
     *  Delay: '<S10>/Delay1'
     */
    controller_B.Sum6_c[0] = controller_DW.Delay1_DSTATE[0] -
      controller_B.DataStoreRead1_c;
    controller_B.Sum6_c[1] = controller_DW.Delay1_DSTATE[1] -
      controller_B.DataStoreRead8;

    /* RelationalOperator: '<S33>/Relational Operator' incorporates:
     *  Constant: '<S33>/Constant8'
     */
    rtb_Compare_c = (controller_B.Sum6_c[0] <= controller_P.Constant8_Value);

    /* Sum: '<S33>/Sum7' incorporates:
     *  Constant: '<S33>/Constant6'
     *  Product: '<S33>/Divide2'
     */
    controller_B.Sum6_c[0] += controller_P.Constant6_Value_c * (real_T)
      rtb_Compare_c;

    /* Switch: '<S33>/Switch2' incorporates:
     *  Constant: '<S35>/Constant'
     *  Delay: '<S10>/Delay1'
     *  Delay: '<S33>/Delay1'
     *  Logic: '<S33>/Logical Operator3'
     *  RelationalOperator: '<S33>/IsNaN1'
     *  RelationalOperator: '<S35>/Compare'
     */
    if ((!(controller_DW.Delay1_DSTATE[0] != controller_P.Constant_Value_f)) ||
        rtIsNaN(controller_DW.Delay1_DSTATE[0])) {
      controller_B.Sum6_c[0] = controller_DW.Delay1_DSTATE_j[0];
    }

    /* RelationalOperator: '<S33>/Relational Operator' incorporates:
     *  Constant: '<S33>/Constant8'
     */
    rtb_Compare_c = (controller_B.Sum6_c[1] <= controller_P.Constant8_Value);

    /* Sum: '<S33>/Sum7' incorporates:
     *  Constant: '<S33>/Constant6'
     *  Product: '<S33>/Divide2'
     */
    controller_B.Sum6_c[1] += controller_P.Constant6_Value_c * (real_T)
      rtb_Compare_c;

    /* Switch: '<S33>/Switch2' incorporates:
     *  Constant: '<S35>/Constant'
     *  Delay: '<S10>/Delay1'
     *  Delay: '<S33>/Delay1'
     *  Logic: '<S33>/Logical Operator3'
     *  RelationalOperator: '<S33>/IsNaN1'
     *  RelationalOperator: '<S35>/Compare'
     */
    if ((!(controller_DW.Delay1_DSTATE[1] != controller_P.Constant_Value_f)) ||
        rtIsNaN(controller_DW.Delay1_DSTATE[1])) {
      controller_B.Sum6_c[1] = controller_DW.Delay1_DSTATE_j[1];
    }

    /* Gain: '<S33>/Gain3' incorporates:
     *  DataStoreRead: '<S33>/Data Store Read1'
     *  DataStoreRead: '<S33>/Data Store Read6'
     *  Gain: '<S33>/Gain1'
     *  Gain: '<S33>/Gain4'
     *  Product: '<S33>/Divide1'
     */
    controller_B.DataStoreRead1_c = controller_B.Sum6_c[0] /
      (controller_P.Gain1_Gain * controller_DW.GR1) * controller_P.Gain3_Gain;
    controller_B.rtb_Divide1_idx_1 = controller_B.Sum6_c[1] /
      (controller_P.Gain4_Gain * controller_DW.GR2) * controller_P.Gain3_Gain;

    /* Product: '<S33>/Divide' incorporates:
     *  Delay: '<S33>/Delay2'
     *  Sum: '<S33>/Sum1'
     */
    controller_B.Divide[0] = (controller_B.DataStoreRead1_c -
      controller_DW.Delay2_DSTATE[0]) / controller_B.Divide_e;
    controller_B.Divide[1] = (controller_B.rtb_Divide1_idx_1 -
      controller_DW.Delay2_DSTATE[1]) / controller_B.Divide_e;
    controller_MovingAverage(controller_B.Divide[0], &controller_B.MovingAverage,
      &controller_DW.MovingAverage);
    controller_MovingAverage(controller_B.Divide[1],
      &controller_B.MovingAverage1, &controller_DW.MovingAverage1);

    /* Sum: '<S10>/Sum6' incorporates:
     *  Constant: '<S10>/Constant3'
     *  Sin: '<S10>/Sine Wave1'
     *  Sin: '<S10>/Sine Wave2'
     *  Sin: '<S10>/Sine Wave3'
     */
    controller_B.DataStoreRead8 = (((sin(controller_P.SineWave2_Freq *
      controller_B.Sum1 + controller_P.SineWave2_Phase) *
      controller_P.SineWave2_Amp + controller_P.SineWave2_Bias) + (sin
      (controller_P.SineWave1_Freq * controller_B.Sum1 +
       controller_P.SineWave1_Phase) * controller_P.SineWave1_Amp +
      controller_P.SineWave1_Bias)) + (sin(controller_P.SineWave3_Freq *
      controller_B.Sum1 + controller_P.SineWave3_Phase) *
      controller_P.SineWave3_Amp + controller_P.SineWave3_Bias)) +
      controller_P.Constant3_Value_n;

    /* Product: '<S10>/Divide' incorporates:
     *  Delay: '<S10>/Delay2'
     *  Sum: '<S10>/Sum7'
     */
    controller_B.Divide_e = (controller_B.DataStoreRead8 -
      controller_DW.Delay2_DSTATE_l) / controller_B.Divide_e;

    /* Sum: '<S10>/Sum1' incorporates:
     *  Gain: '<S10>/Gain'
     *  Gain: '<S10>/Gain2'
     *  Sum: '<S10>/Sum'
     *  Sum: '<S10>/Sum4'
     */
    controller_B.DataStoreRead7_j = (controller_B.DataStoreRead8 -
      controller_B.DataStoreRead1_c) * controller_P.Gain_Gain +
      (controller_B.Divide_e - controller_B.MovingAverage.MovingAverage) *
      controller_P.Gain2_Gain;

    /* Saturate: '<S10>/Saturation' */
    if (controller_B.DataStoreRead7_j > controller_P.Saturation_UpperSat) {
      controller_B.DataStoreRead7_j = controller_P.Saturation_UpperSat;
    } else if (controller_B.DataStoreRead7_j < controller_P.Saturation_LowerSat)
    {
      controller_B.DataStoreRead7_j = controller_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<S10>/Saturation' */

    /* Sum: '<S10>/Sum3' incorporates:
     *  Gain: '<S10>/Gain5'
     *  Gain: '<S10>/Gain6'
     *  Sum: '<S10>/Sum2'
     *  Sum: '<S10>/Sum8'
     */
    controller_B.Divide_e = (controller_B.DataStoreRead8 -
      controller_B.rtb_Divide1_idx_1) * controller_P.Gain5_Gain +
      (controller_B.Divide_e - controller_B.MovingAverage1.MovingAverage) *
      controller_P.Gain6_Gain;

    /* Saturate: '<S10>/Saturation1' */
    if (controller_B.Divide_e > controller_P.Saturation1_UpperSat) {
      controller_B.Divide_e = controller_P.Saturation1_UpperSat;
    } else if (controller_B.Divide_e < controller_P.Saturation1_LowerSat) {
      controller_B.Divide_e = controller_P.Saturation1_LowerSat;
    }

    /* End of Saturate: '<S10>/Saturation1' */

    /* CCaller: '<S10>/C Caller4' incorporates:
     *  SignalConversion generated from: '<S10>/C Caller4'
     */
    controller_B.CCaller4[0] = controller_B.Sum1;
    controller_B.CCaller4[1] = controller_B.DataStoreRead1_c;
    controller_B.CCaller4[2] = controller_B.rtb_Divide1_idx_1;
    controller_B.CCaller4[3] = controller_B.MovingAverage.MovingAverage;
    controller_B.CCaller4[4] = controller_B.MovingAverage1.MovingAverage;
    controller_B.CCaller4[5] = controller_B.DataStoreRead7_j;
    controller_B.CCaller4[6] = controller_B.Divide_e;
    controller_B.CCaller4[7] = controller_B.DataStoreRead8;

    /* DataTypeConversion: '<S10>/Data Type Conversion2' incorporates:
     *  Constant: '<S10>/Constant2'
     */
    controller_B.d = floor(controller_P.Constant2_Value_i);
    if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
      controller_B.d = 0.0;
    } else {
      controller_B.d = fmod(controller_B.d, 4.294967296E+9);
    }

    /* CCaller: '<S10>/C Caller4' incorporates:
     *  DataTypeConversion: '<S10>/Data Type Conversion2'
     */
    print_data(&controller_B.CCaller4[0], controller_B.d < 0.0 ? -(int32_T)
               (uint32_T)-controller_B.d : (int32_T)(uint32_T)controller_B.d);

    /* CCaller: '<S10>/C Caller5' incorporates:
     *  SignalConversion generated from: '<S10>/C Caller5'
     */
    controller_B.CCaller5[0] = 0.0;
    controller_B.CCaller5[1] = 0.0;
    controller_B.CCaller5[2] = controller_B.DataStoreRead7_j;
    controller_B.CCaller5[3] = controller_B.Divide_e;

    /* DataTypeConversion: '<S10>/Data Type Conversion11' incorporates:
     *  DataStoreRead: '<S10>/Data Store Read10'
     */
    controller_B.d = floor(controller_DW.num_motors);
    if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
      controller_B.d = 0.0;
    } else {
      controller_B.d = fmod(controller_B.d, 4.294967296E+9);
    }

    /* CCaller: '<S10>/C Caller5' incorporates:
     *  DataStoreRead: '<S10>/Data Store Read8'
     *  DataTypeConversion: '<S10>/Data Type Conversion11'
     */
    read_write(controller_DW.pdo_id, controller_B.d < 0.0 ? -(int32_T)(uint32_T)
               -controller_B.d : (int32_T)(uint32_T)controller_B.d,
               controller_B.Sum1, &controller_B.CCaller5[0]);

    /* Update for UnitDelay: '<S34>/Unit Delay' */
    controller_DW.UnitDelay_DSTATE = controller_B.sf_MATLABFunction_e.y;

    /* Update for UnitDelay: '<S34>/Unit Delay1' */
    controller_DW.UnitDelay1_DSTATE = controller_B.Sum1;

    /* Update for Delay: '<S10>/Delay1' */
    controller_DW.Delay1_DSTATE[0] = controller_B.CCaller5[0];
    controller_DW.Delay1_DSTATE[1] = controller_B.CCaller5[1];
    controller_DW.Delay1_DSTATE[2] = controller_B.CCaller5[2];
    controller_DW.Delay1_DSTATE[3] = controller_B.CCaller5[3];

    /* Update for Delay: '<S33>/Delay1' */
    controller_DW.Delay1_DSTATE_j[0] = controller_B.Sum6_c[0];

    /* Update for Delay: '<S33>/Delay2' */
    controller_DW.Delay2_DSTATE[0] = controller_B.DataStoreRead1_c;

    /* Update for Delay: '<S33>/Delay1' */
    controller_DW.Delay1_DSTATE_j[1] = controller_B.Sum6_c[1];

    /* Update for Delay: '<S33>/Delay2' */
    controller_DW.Delay2_DSTATE[1] = controller_B.rtb_Divide1_idx_1;

    /* Update for Delay: '<S10>/Delay2' */
    controller_DW.Delay2_DSTATE_l = controller_B.DataStoreRead8;
  } else {
    controller_DW.MainControl_MODE = false;
  }

  /* End of RelationalOperator: '<S4>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/Main Control' */

  /* RelationalOperator: '<S5>/Compare' incorporates:
   *  Constant: '<S5>/Constant'
   *  DataStoreRead: '<Root>/Data Store Read6'
   */
  rtb_Compare_c = (controller_DW.state == controller_P.CompareToConstant7_const);

  /* Outputs for Triggered SubSystem: '<Root>/Exit Control' incorporates:
   *  TriggerPort: '<S6>/Trigger'
   */
  if (rtb_Compare_c && (controller_PrevZCX.ExitControl_Trig_ZCE != POS_ZCSIG)) {
    /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
     *  DataStoreRead: '<S6>/Data Store Read7'
     */
    controller_B.d = floor(controller_DW.num_motors);
    if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
      controller_B.d = 0.0;
    } else {
      controller_B.d = fmod(controller_B.d, 4.294967296E+9);
    }

    /* CCaller: '<S6>/C Caller1' incorporates:
     *  DataStoreRead: '<S6>/Data Store Read1'
     *  DataTypeConversion: '<S6>/Data Type Conversion'
     */
    stop_motor(controller_DW.pdo_id, controller_B.d < 0.0 ? -(int32_T)(uint32_T)
               -controller_B.d : (int32_T)(uint32_T)controller_B.d);

    /* CCaller: '<S6>/C Caller4' */
    close_datalog();
  }

  controller_PrevZCX.ExitControl_Trig_ZCE = rtb_Compare_c;

  /* End of Outputs for SubSystem: '<Root>/Exit Control' */
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

  /* states (dwork) */
  (void) memset((void *)&controller_DW, 0,
                sizeof(DW_controller_T));
  controller_AnalogInput_Start(&controller_DW.AnalogInput,
    &controller_P.AnalogInput);
  controller_AnalogInput_Start(&controller_DW.AnalogInput1,
    &controller_P.AnalogInput1);

  /* Start for MATLABSystem: '<Root>/Digital Read' */
  controller_DW.obj_b.matlabCodegenIsDeleted = false;
  controller_DW.objisempty_g = true;
  controller_DW.obj_b.SampleTime = controller_P.DigitalRead_SampleTime;
  controller_DW.obj_b.isInitialized = 1;
  controller_DW.obj_b.MW_DIGITALIO_HANDLE = MW_digitalIO_open(113, 0);
  controller_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Read1' */
  controller_DW.obj_a.matlabCodegenIsDeleted = false;
  controller_DW.objisempty_i = true;
  controller_DW.obj_a.SampleTime = controller_P.DigitalRead1_SampleTime;
  controller_DW.obj_a.isInitialized = 1;
  controller_DW.obj_a.MW_DIGITALIO_HANDLE = MW_digitalIO_open(116, 0);
  controller_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Read2' */
  controller_DW.obj_l.matlabCodegenIsDeleted = false;
  controller_DW.objisempty_f = true;
  controller_DW.obj_l.SampleTime = controller_P.DigitalRead2_SampleTime;
  controller_DW.obj_l.isInitialized = 1;
  controller_DW.obj_l.MW_DIGITALIO_HANDLE = MW_digitalIO_open(49, 0);
  controller_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Read3' */
  controller_DW.obj.matlabCodegenIsDeleted = false;
  controller_DW.objisempty = true;
  controller_DW.obj.SampleTime = controller_P.DigitalRead3_SampleTime;
  controller_DW.obj.isInitialized = 1;
  controller_DW.obj.MW_DIGITALIO_HANDLE = MW_digitalIO_open(57, 0);
  controller_DW.obj.isSetupComplete = true;

  /* Start for Enabled SubSystem: '<Root>/Initialize' */
  controller_DW.Initialize_MODE = false;

  /* End of Start for SubSystem: '<Root>/Initialize' */

  /* Start for Enabled SubSystem: '<Root>/Home1' */
  controller_DW.Home1_MODE = false;

  /* End of Start for SubSystem: '<Root>/Home1' */

  /* Start for Enabled SubSystem: '<Root>/Main Control' */
  controller_DW.MainControl_MODE = false;
  controller_MovingAverage_Start(&controller_DW.MovingAverage);
  controller_MovingAverage_Start(&controller_DW.MovingAverage1);

  /* End of Start for SubSystem: '<Root>/Main Control' */

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
  controller_PrevZCX.ExitControl_Trig_ZCE = POS_ZCSIG;
  controller_PrevZCX.StopMotor1_a.StopMotor1_Trig_ZCE = POS_ZCSIG;
  controller_PrevZCX.StopMotor1.StopMotor1_Trig_ZCE = POS_ZCSIG;

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home1' */
  /* InitializeConditions for Delay: '<S15>/Delay1' */
  controller_DW.Delay1_DSTATE_e[0] = controller_P.Delay1_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<Root>/Home1' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home2' */
  /* InitializeConditions for Delay: '<S23>/Delay1' */
  controller_DW.Delay1_DSTATE_i[0] = controller_P.Delay1_InitialCondition_l;

  /* End of SystemInitialize for SubSystem: '<Root>/Home2' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home1' */
  /* InitializeConditions for Delay: '<S15>/Delay1' */
  controller_DW.Delay1_DSTATE_e[1] = controller_P.Delay1_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<Root>/Home1' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home2' */
  /* InitializeConditions for Delay: '<S23>/Delay1' */
  controller_DW.Delay1_DSTATE_i[1] = controller_P.Delay1_InitialCondition_l;

  /* End of SystemInitialize for SubSystem: '<Root>/Home2' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Main Control' */
  /* InitializeConditions for UnitDelay: '<S34>/Unit Delay' */
  controller_DW.UnitDelay_DSTATE = controller_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S34>/Unit Delay1' */
  controller_DW.UnitDelay1_DSTATE = controller_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for Delay: '<S10>/Delay1' */
  controller_DW.Delay1_DSTATE[0] = controller_P.Delay1_InitialCondition_k;
  controller_DW.Delay1_DSTATE[1] = controller_P.Delay1_InitialCondition_k;
  controller_DW.Delay1_DSTATE[2] = controller_P.Delay1_InitialCondition_k;
  controller_DW.Delay1_DSTATE[3] = controller_P.Delay1_InitialCondition_k;

  /* InitializeConditions for Delay: '<S33>/Delay1' */
  controller_DW.Delay1_DSTATE_j[0] = controller_P.Delay1_InitialCondition_k5;

  /* InitializeConditions for Delay: '<S33>/Delay2' */
  controller_DW.Delay2_DSTATE[0] = controller_P.Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<S33>/Delay1' */
  controller_DW.Delay1_DSTATE_j[1] = controller_P.Delay1_InitialCondition_k5;

  /* InitializeConditions for Delay: '<S33>/Delay2' */
  controller_DW.Delay2_DSTATE[1] = controller_P.Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<S10>/Delay2' */
  controller_DW.Delay2_DSTATE_l = controller_P.Delay2_InitialCondition_c;
  controller_MovingAverage_Init(&controller_DW.MovingAverage);
  controller_MovingAverage_Init(&controller_DW.MovingAverage1);

  /* End of SystemInitialize for SubSystem: '<Root>/Main Control' */
}

/* Model terminate function */
void controller_terminate(void)
{
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

  /* Terminate for Enabled SubSystem: '<Root>/Main Control' */
  controller_MovingAverage_Term(&controller_DW.MovingAverage);
  controller_MovingAverage_Term(&controller_DW.MovingAverage1);

  /* End of Terminate for SubSystem: '<Root>/Main Control' */
}
