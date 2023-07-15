/*
 * controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.45
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Jul 14 19:57:27 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controller.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "controller_private.h"
#include "coder_posix_time.h"
#include <string.h>

/* Block signals (default storage) */
B_controller_T controller_B;

/* Block states (default storage) */
DW_controller_T controller_DW;

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
static creal_T controller_two_sum(real_T b_a, real_T b_b);
static creal_T controller_plus(const creal_T b_a, real_T b_b);
static creal_T controller_two_diff(real_T b_a, real_T b_b);
static creal_T controller_floor(const creal_T b_a);
static creal_T controller_minus(const creal_T b_a, const creal_T b_b);
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
  if ((controller_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [1.0s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[1] = 0;
  }

  (controller_M->Timing.TaskCounters.TID[2])++;
  if ((controller_M->Timing.TaskCounters.TID[2]) > 99999) {/* Sample time: [10000.0s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void controller_getLocalTime(real_T *t_tm_nsec, real_T *t_tm_sec, real_T *
  t_tm_min, real_T *t_tm_hour, real_T *t_tm_mday, real_T *t_tm_mon, real_T
  *t_tm_year, boolean_T *t_tm_isdst)
{
  coderTm origStructTm;
  coderLocalTime(&origStructTm);
  *t_tm_nsec = (real_T)origStructTm.tm_nsec;
  *t_tm_sec = origStructTm.tm_sec;
  *t_tm_min = origStructTm.tm_min;
  *t_tm_hour = origStructTm.tm_hour;
  *t_tm_mday = origStructTm.tm_mday;
  *t_tm_mon = origStructTm.tm_mon;
  *t_tm_year = origStructTm.tm_year;
  *t_tm_isdst = (origStructTm.tm_isdst != 0);
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static creal_T controller_two_prod(real_T b_a)
{
  creal_T c;
  real_T shi;
  real_T slo;
  int32_T trueCount;
  controller_B.da = controller_split(b_a);
  shi = b_a * 8.64E+7;
  slo = (controller_B.da.re * 8.64E+7 - shi) + controller_B.da.im * 8.64E+7;
  trueCount = 0;
  if (rtIsNaN(slo)) {
    trueCount = 1;
  }

  if (trueCount - 1 >= 0) {
    slo = 0.0;
  }

  c.re = shi;
  c.im = slo;
  return c;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static creal_T controller_times(const creal_T b_a)
{
  creal_T c;
  real_T ahi;
  real_T alo;
  real_T b_b;
  c = controller_two_prod(b_a.re);
  b_b = b_a.im * 8.64E+7;
  alo = c.im;
  ahi = c.re;
  if (b_b != 0.0) {
    alo = c.im + b_b;
    ahi = c.re + alo;
    alo -= ahi - c.re;
  }

  if (rtIsNaN(alo)) {
    alo = 0.0;
  }

  c.re = ahi;
  c.im = alo;
  return c;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static creal_T controller_two_sum(real_T b_a, real_T b_b)
{
  creal_T c;
  real_T bb;
  real_T shi;
  int32_T trueCount;
  shi = b_a + b_b;
  bb = shi - b_a;
  bb = (b_a - (shi - bb)) + (b_b - bb);
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static creal_T controller_plus(const creal_T b_a, real_T b_b)
{
  creal_T c;
  real_T ahi;
  real_T alo;
  real_T b_ahi;
  c = controller_two_sum(b_a.re, b_b);
  controller_B.t_c = controller_two_sum(b_a.im, 0.0);
  alo = c.im;
  ahi = c.re;
  if (controller_B.t_c.re != 0.0) {
    alo = c.im + controller_B.t_c.re;
    ahi = c.re + alo;
    alo -= ahi - c.re;
  }

  if (rtIsNaN(alo)) {
    alo = 0.0;
  }

  b_ahi = ahi;
  if (controller_B.t_c.im != 0.0) {
    alo += controller_B.t_c.im;
    b_ahi = ahi + alo;
    alo -= b_ahi - ahi;
  }

  if (rtIsNaN(alo)) {
    alo = 0.0;
  }

  c.re = b_ahi;
  c.im = alo;
  return c;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static creal_T controller_two_diff(real_T b_a, real_T b_b)
{
  creal_T c;
  real_T bb;
  real_T shi;
  int32_T trueCount;
  shi = b_a - b_b;
  bb = shi - b_a;
  bb = (b_a - (shi - bb)) - (b_b + bb);
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static creal_T controller_floor(const creal_T b_a)
{
  creal_T b_b;
  real_T alo;
  real_T b_ahi;
  real_T c_b;
  b_b.re = floor(b_a.re);
  b_b.im = 0.0;
  if (b_b.re == b_a.re) {
    c_b = floor(b_a.im);
    alo = 0.0;
    b_ahi = b_b.re;
    if (c_b != 0.0) {
      b_ahi = b_b.re + c_b;
      alo = c_b - (b_ahi - b_b.re);
    }

    if (rtIsNaN(alo)) {
      alo = 0.0;
    }

    b_b.re = b_ahi;
    b_b.im = alo;
  }

  return b_b;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static creal_T controller_minus(const creal_T b_a, const creal_T b_b)
{
  creal_T cout;
  real_T ahi;
  real_T alo;
  real_T b_ahi;
  controller_B.c = controller_two_diff(b_a.re, b_b.re);
  controller_B.t_m = controller_two_diff(b_a.im, b_b.im);
  alo = controller_B.c.im;
  ahi = controller_B.c.re;
  if (controller_B.t_m.re != 0.0) {
    alo = controller_B.c.im + controller_B.t_m.re;
    ahi = controller_B.c.re + alo;
    alo -= ahi - controller_B.c.re;
  }

  if (rtIsNaN(alo)) {
    alo = 0.0;
  }

  b_ahi = ahi;
  if (controller_B.t_m.im != 0.0) {
    alo += controller_B.t_m.im;
    b_ahi = ahi + alo;
    alo -= b_ahi - ahi;
  }

  if (rtIsNaN(alo)) {
    alo = 0.0;
  }

  cout.re = b_ahi;
  cout.im = alo;
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
  int32_T rtb_DataTypeConversion;
  boolean_T expl_temp;
  if (controller_M->Timing.TaskCounters.TID[2] == 0) {
    /* CCaller: '<Root>/C Caller5' */
    controller_B.CCaller5 = init_can();
  }

  if (controller_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    controller_B.d_ahi_k = floor(controller_P.Constant1_Value);
    if (rtIsNaN(controller_B.d_ahi_k) || rtIsInf(controller_B.d_ahi_k)) {
      controller_B.d_ahi_k = 0.0;
    } else {
      controller_B.d_ahi_k = fmod(controller_B.d_ahi_k, 4.294967296E+9);
    }

    /* CCaller: '<Root>/C Caller2' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion2'
     */
    print_input(controller_B.CCaller5, controller_B.d_ahi_k < 0.0 ? -(int32_T)
                (uint32_T)-controller_B.d_ahi_k : (int32_T)(uint32_T)
                controller_B.d_ahi_k);
  }

  /* MATLAB Function: '<Root>/MATLAB Function' */
  controller_getLocalTime(&controller_B.fracSecs, &controller_B.second,
    &controller_B.shi, &controller_B.b_alo, &controller_B.d_ahi_k,
    &controller_B.c_tm_mon, &controller_B.c_tm_year, &expl_temp);
  controller_B.fracSecs /= 1.0E+6;
  controller_B.check = (((((controller_B.c_tm_year + controller_B.c_tm_mon) +
    controller_B.d_ahi_k) + controller_B.b_alo) + controller_B.shi) +
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

    if ((controller_B.fracSecs < 0.0) || (controller_B.fracSecs >= 1000.0)) {
      controller_B.check = floor(controller_B.fracSecs / 1000.0);
      controller_B.second += controller_B.check;
      controller_B.fracSecs -= controller_B.check * 1000.0;
    }

    controller_B.d_data.re = ((((((365.0 * controller_B.c_tm_year + floor
      (controller_B.c_tm_year / 4.0)) - floor(controller_B.c_tm_year / 100.0)) +
      floor(controller_B.c_tm_year / 400.0)) + floor((153.0 *
      controller_B.c_tm_mon + 2.0) / 5.0)) + controller_B.d_ahi_k) + 60.0) -
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

  controller_B.c_s.re = (0.0 * controller_B.d_data.im + controller_B.c_s.re) -
    0.0 * controller_B.t.im;
  controller_B.c_s.im = (controller_B.c_s.im + controller_B.d_data.im) -
    controller_B.t.im;
  controller_B.shi = (controller_B.c_s.re + controller_B.c_s.im) / 8.64E+7;
  controller_B.b_alo = 0.0;
  controller_B.d_ahi_k = controller_B.b_c.re;
  if (controller_B.shi != 0.0) {
    controller_B.d_ahi_k = controller_B.b_c.re + controller_B.shi;
    controller_B.b_alo = controller_B.shi - (controller_B.d_ahi_k -
      controller_B.b_c.re);
  }

  if (rtIsNaN(controller_B.b_alo)) {
    controller_B.b_alo = 0.0;
  }

  controller_B.d_ahi.re = controller_B.d_ahi_k;
  controller_B.d_ahi.im = controller_B.b_alo;
  controller_B.d_data = controller_minus(controller_B.d_data, controller_times
    (controller_floor(controller_B.d_ahi)));
  controller_B.b_c.re = controller_B.d_data.re / 1000.0;
  controller_B.t = controller_split(controller_B.b_c.re);
  controller_B.shi = controller_B.b_c.re * 1000.0;
  controller_B.b_alo = (controller_B.t.re * 1000.0 - controller_B.shi) +
    controller_B.t.im * 1000.0;
  rtb_DataTypeConversion = 0;
  if (rtIsNaN(controller_B.b_alo)) {
    rtb_DataTypeConversion = 1;
  }

  if (rtb_DataTypeConversion - 1 >= 0) {
    controller_B.b_alo = 0.0;
  }

  controller_B.c_s.re = 0.0;
  controller_B.c_s.im = 0.0;
  if (controller_B.d_data.re != controller_B.shi) {
    controller_B.c_s = controller_two_diff(controller_B.d_data.re,
      controller_B.shi);
  }

  controller_B.c_s.re = (0.0 * controller_B.d_data.im + controller_B.c_s.re) -
    0.0 * controller_B.b_alo;
  controller_B.c_s.im = (controller_B.c_s.im + controller_B.d_data.im) -
    controller_B.b_alo;
  controller_B.shi = (controller_B.c_s.re + controller_B.c_s.im) / 1000.0;
  controller_B.b_alo = 0.0;
  controller_B.d_ahi_k = controller_B.b_c.re;
  if (controller_B.shi != 0.0) {
    controller_B.d_ahi_k = controller_B.b_c.re + controller_B.shi;
    controller_B.b_alo = controller_B.shi - (controller_B.d_ahi_k -
      controller_B.b_c.re);
  }

  if (rtIsNaN(controller_B.b_alo)) {
    controller_B.b_alo = 0.0;
  }

  controller_B.d_data.re = controller_B.d_ahi_k;
  controller_B.d_data.im = controller_B.b_alo;
  controller_B.t = controller_floor(controller_B.d_data);
  controller_B.b_c = controller_minus(controller_B.d_data, controller_B.t);
  controller_B.shi = controller_B.t.re + controller_B.t.im;
  if ((controller_B.shi >= 0.0) && (controller_B.shi <= 2.147483647E+9)) {
    rtb_DataTypeConversion = (int32_T)rt_roundd_snf(controller_B.shi);
    rtb_DataTypeConversion -= 3600 * div_s32(rtb_DataTypeConversion, 3600);
    controller_B.shi = rtb_DataTypeConversion - 60 * div_s32
      (rtb_DataTypeConversion, 60);
  } else {
    controller_B.shi -= floor((controller_B.shi - floor(controller_B.shi /
      3600.0) * 3600.0) / 60.0) * 60.0;
  }

  controller_B.shi += controller_B.b_c.re + controller_B.b_c.im;
  if (controller_B.shi == 60.0) {
    controller_B.shi = 59.999999999999993;
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Delay: '<Root>/Delay'
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  Sum: '<Root>/Sum'
   */
  controller_B.b_alo = (controller_B.shi - controller_DW.Delay_DSTATE) *
    controller_P.Gain_Gain;

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  controller_B.d_ahi_k = floor(controller_B.b_alo);
  if (rtIsNaN(controller_B.d_ahi_k) || rtIsInf(controller_B.d_ahi_k)) {
    controller_B.d_ahi_k = 0.0;
  } else {
    controller_B.d_ahi_k = fmod(controller_B.d_ahi_k, 4.294967296E+9);
  }

  rtb_DataTypeConversion = controller_B.d_ahi_k < 0.0 ? -(int32_T)(uint32_T)
    -controller_B.d_ahi_k : (int32_T)(uint32_T)controller_B.d_ahi_k;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* CCaller: '<Root>/C Caller1' */
  controller_B.d_ahi_k = get_encoder(controller_B.CCaller5,
    rtb_DataTypeConversion);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  controller_B.d_ahi_k = floor(controller_P.Constant2_Value);
  if (rtIsNaN(controller_B.d_ahi_k) || rtIsInf(controller_B.d_ahi_k)) {
    controller_B.d_ahi_k = 0.0;
  } else {
    controller_B.d_ahi_k = fmod(controller_B.d_ahi_k, 4.294967296E+9);
  }

  /* CCaller: '<Root>/C Caller4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  print_input(rtb_DataTypeConversion, controller_B.d_ahi_k < 0.0 ? -(int32_T)
              (uint32_T)-controller_B.d_ahi_k : (int32_T)(uint32_T)
              controller_B.d_ahi_k);

  /* Update for Delay: '<Root>/Delay' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  controller_DW.Delay_DSTATE = controller_B.shi;
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

  /* InitializeConditions for Delay: '<Root>/Delay' */
  controller_DW.Delay_DSTATE = controller_P.Delay_InitialCondition;
}

/* Model terminate function */
void controller_terminate(void)
{
  /* (no terminate code required) */
}
