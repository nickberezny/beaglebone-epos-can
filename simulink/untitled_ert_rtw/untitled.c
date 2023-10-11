/*
 * untitled.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "untitled".
 *
 * Model version              : 1.0
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Oct 11 16:42:57 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "untitled_private.h"
#include "coder_posix_time.h"
#include <string.h>
#include "untitled_dt.h"

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Forward declaration for local functions */
static void untitled_getLocalTime(real_T *t_tm_nsec, real_T *t_tm_sec, real_T
  *t_tm_min, real_T *t_tm_hour, real_T *t_tm_mday, real_T *t_tm_mon, real_T
  *t_tm_year, boolean_T *t_tm_isdst);
static creal_T untitled_split(real_T a);
static creal_T untitled_two_prod(real_T a);
static creal_T untitled_times(const creal_T a);
static creal_T untitled_two_sum(real_T a, real_T b);
static creal_T untitled_plus(const creal_T a, real_T b);
static creal_T untitled_two_diff(real_T a, real_T b);
static creal_T untitled_floor(const creal_T a);
static creal_T untitled_minus(const creal_T a, const creal_T b);
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

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static void untitled_getLocalTime(real_T *t_tm_nsec, real_T *t_tm_sec, real_T
  *t_tm_min, real_T *t_tm_hour, real_T *t_tm_mday, real_T *t_tm_mon, real_T
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

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static creal_T untitled_split(real_T a)
{
  creal_T aout;
  real_T temp;
  if (fabs(a) <= 6.69692879491417E+299) {
    temp = 1.34217729E+8 * a;
    temp -= temp - a;
    aout.re = temp;
    aout.im = a - temp;
  } else if ((!rtIsInf(a)) && (!rtIsNaN(a))) {
    a *= 3.7252902984619141E-9;
    temp = 1.34217729E+8 * a;
    temp -= temp - a;
    aout.re = temp * 2.68435456E+8;
    aout.im = (a - temp) * 2.68435456E+8;
  } else {
    aout.re = a;
    aout.im = 0.0;
  }

  return aout;
}

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static creal_T untitled_two_prod(real_T a)
{
  creal_T c;
  real_T shi;
  real_T slo;
  int32_T trueCount;
  untitled_B.da = untitled_split(a);
  shi = a * 8.64E+7;
  slo = (untitled_B.da.re * 8.64E+7 - shi) + untitled_B.da.im * 8.64E+7;
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

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static creal_T untitled_times(const creal_T a)
{
  creal_T c;
  real_T ahi;
  real_T alo;
  real_T b;
  c = untitled_two_prod(a.re);
  b = a.im * 8.64E+7;
  alo = c.im;
  ahi = c.re;
  if (b != 0.0) {
    alo = c.im + b;
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

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static creal_T untitled_two_sum(real_T a, real_T b)
{
  creal_T c;
  real_T bb;
  real_T shi;
  int32_T trueCount;
  shi = a + b;
  bb = shi - a;
  bb = (a - (shi - bb)) + (b - bb);
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

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static creal_T untitled_plus(const creal_T a, real_T b)
{
  creal_T c;
  real_T ahi;
  real_T alo;
  real_T b_ahi;
  c = untitled_two_sum(a.re, b);
  untitled_B.t_c = untitled_two_sum(a.im, 0.0);
  alo = c.im;
  ahi = c.re;
  if (untitled_B.t_c.re != 0.0) {
    alo = c.im + untitled_B.t_c.re;
    ahi = c.re + alo;
    alo -= ahi - c.re;
  }

  if (rtIsNaN(alo)) {
    alo = 0.0;
  }

  b_ahi = ahi;
  if (untitled_B.t_c.im != 0.0) {
    alo += untitled_B.t_c.im;
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

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static creal_T untitled_two_diff(real_T a, real_T b)
{
  creal_T c;
  real_T bb;
  real_T shi;
  int32_T trueCount;
  shi = a - b;
  bb = shi - a;
  bb = (a - (shi - bb)) - (b + bb);
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

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static creal_T untitled_floor(const creal_T a)
{
  creal_T b;
  real_T alo;
  real_T b_ahi;
  real_T b_b;
  b.re = floor(a.re);
  b.im = 0.0;
  if (b.re == a.re) {
    b_b = floor(a.im);
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

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static creal_T untitled_minus(const creal_T a, const creal_T b)
{
  creal_T cout;
  real_T ahi;
  real_T alo;
  real_T b_ahi;
  untitled_B.c = untitled_two_diff(a.re, b.re);
  untitled_B.t_m = untitled_two_diff(a.im, b.im);
  alo = untitled_B.c.im;
  ahi = untitled_B.c.re;
  if (untitled_B.t_m.re != 0.0) {
    alo = untitled_B.c.im + untitled_B.t_m.re;
    ahi = untitled_B.c.re + alo;
    alo -= ahi - untitled_B.c.re;
  }

  if (rtIsNaN(alo)) {
    alo = 0.0;
  }

  b_ahi = ahi;
  if (untitled_B.t_m.im != 0.0) {
    alo += untitled_B.t_m.im;
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
void untitled_step(void)
{
  int32_T trueCount;
  boolean_T expl_temp;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (untitled_DW.obj.SampleTime != untitled_P.AnalogInput_SampleTime) {
    untitled_DW.obj.SampleTime = untitled_P.AnalogInput_SampleTime;
  }

  /* MATLABSystem: '<Root>/Analog Input' */
  untitled_B.AnalogInput = rc_adc_read_raw(0);

  /* MATLAB Function: '<S1>/MATLAB Function' */
  untitled_getLocalTime(&untitled_B.fracSecs, &untitled_B.second,
                        &untitled_B.shi, &untitled_B.b_alo, &untitled_B.d_ahi_k,
                        &untitled_B.c_tm_mon, &untitled_B.c_tm_year, &expl_temp);
  untitled_B.fracSecs /= 1.0E+6;
  untitled_B.check = (((((untitled_B.c_tm_year + untitled_B.c_tm_mon) +
    untitled_B.d_ahi_k) + untitled_B.b_alo) + untitled_B.shi) +
                      untitled_B.second) + untitled_B.fracSecs;
  if ((!rtIsInf(untitled_B.check)) && (!rtIsNaN(untitled_B.check))) {
    if ((untitled_B.c_tm_mon < 1.0) || (untitled_B.c_tm_mon > 12.0)) {
      untitled_B.check = floor((untitled_B.c_tm_mon - 1.0) / 12.0);
      untitled_B.c_tm_year += untitled_B.check;
      untitled_B.c_tm_mon = ((untitled_B.c_tm_mon - 1.0) - untitled_B.check *
        12.0) + 1.0;
    }

    if (untitled_B.c_tm_mon < 3.0) {
      untitled_B.c_tm_year--;
      untitled_B.c_tm_mon += 9.0;
    } else {
      untitled_B.c_tm_mon -= 3.0;
    }

    if ((untitled_B.fracSecs < 0.0) || (untitled_B.fracSecs >= 1000.0)) {
      untitled_B.check = floor(untitled_B.fracSecs / 1000.0);
      untitled_B.second += untitled_B.check;
      untitled_B.fracSecs -= untitled_B.check * 1000.0;
    }

    untitled_B.d_data.re = ((((((365.0 * untitled_B.c_tm_year + floor
      (untitled_B.c_tm_year / 4.0)) - floor(untitled_B.c_tm_year / 100.0)) +
      floor(untitled_B.c_tm_year / 400.0)) + floor((153.0 * untitled_B.c_tm_mon
      + 2.0) / 5.0)) + untitled_B.d_ahi_k) + 60.0) - 719529.0;
    untitled_B.d_data.im = 0.0;
    untitled_B.d_data = untitled_plus(untitled_plus(untitled_plus(untitled_times
      (untitled_B.d_data), (60.0 * untitled_B.b_alo + untitled_B.shi) * 60000.0),
      untitled_B.second * 1000.0), untitled_B.fracSecs);
  } else {
    untitled_B.d_data.re = untitled_B.check;
    untitled_B.d_data.im = 0.0;
  }

  untitled_B.b_c.re = untitled_B.d_data.re / 8.64E+7;
  untitled_B.t = untitled_two_prod(untitled_B.b_c.re);
  untitled_B.c_s.re = 0.0;
  untitled_B.c_s.im = 0.0;
  if (untitled_B.d_data.re != untitled_B.t.re) {
    untitled_B.c_s = untitled_two_diff(untitled_B.d_data.re, untitled_B.t.re);
  }

  untitled_B.c_s.re = (0.0 * untitled_B.d_data.im + untitled_B.c_s.re) - 0.0 *
    untitled_B.t.im;
  untitled_B.c_s.im = (untitled_B.c_s.im + untitled_B.d_data.im) -
    untitled_B.t.im;
  untitled_B.shi = (untitled_B.c_s.re + untitled_B.c_s.im) / 8.64E+7;
  untitled_B.b_alo = 0.0;
  untitled_B.d_ahi_k = untitled_B.b_c.re;
  if (untitled_B.shi != 0.0) {
    untitled_B.d_ahi_k = untitled_B.b_c.re + untitled_B.shi;
    untitled_B.b_alo = untitled_B.shi - (untitled_B.d_ahi_k - untitled_B.b_c.re);
  }

  if (rtIsNaN(untitled_B.b_alo)) {
    untitled_B.b_alo = 0.0;
  }

  untitled_B.d_ahi.re = untitled_B.d_ahi_k;
  untitled_B.d_ahi.im = untitled_B.b_alo;
  untitled_B.d_data = untitled_minus(untitled_B.d_data, untitled_times
    (untitled_floor(untitled_B.d_ahi)));
  untitled_B.b_c.re = untitled_B.d_data.re / 1000.0;
  untitled_B.t = untitled_split(untitled_B.b_c.re);
  untitled_B.shi = untitled_B.b_c.re * 1000.0;
  untitled_B.b_alo = (untitled_B.t.re * 1000.0 - untitled_B.shi) +
    untitled_B.t.im * 1000.0;
  trueCount = 0;
  if (rtIsNaN(untitled_B.b_alo)) {
    trueCount = 1;
  }

  if (trueCount - 1 >= 0) {
    untitled_B.b_alo = 0.0;
  }

  untitled_B.c_s.re = 0.0;
  untitled_B.c_s.im = 0.0;
  if (untitled_B.d_data.re != untitled_B.shi) {
    untitled_B.c_s = untitled_two_diff(untitled_B.d_data.re, untitled_B.shi);
  }

  untitled_B.c_s.re = (0.0 * untitled_B.d_data.im + untitled_B.c_s.re) - 0.0 *
    untitled_B.b_alo;
  untitled_B.c_s.im = (untitled_B.c_s.im + untitled_B.d_data.im) -
    untitled_B.b_alo;
  untitled_B.shi = (untitled_B.c_s.re + untitled_B.c_s.im) / 1000.0;
  untitled_B.b_alo = 0.0;
  untitled_B.d_ahi_k = untitled_B.b_c.re;
  if (untitled_B.shi != 0.0) {
    untitled_B.d_ahi_k = untitled_B.b_c.re + untitled_B.shi;
    untitled_B.b_alo = untitled_B.shi - (untitled_B.d_ahi_k - untitled_B.b_c.re);
  }

  if (rtIsNaN(untitled_B.b_alo)) {
    untitled_B.b_alo = 0.0;
  }

  untitled_B.d_data.re = untitled_B.d_ahi_k;
  untitled_B.d_data.im = untitled_B.b_alo;
  untitled_B.t = untitled_floor(untitled_B.d_data);
  untitled_B.b_c = untitled_minus(untitled_B.d_data, untitled_B.t);
  untitled_B.shi = untitled_B.t.re + untitled_B.t.im;
  if ((untitled_B.shi >= 0.0) && (untitled_B.shi <= 2.147483647E+9)) {
    trueCount = (int32_T)rt_roundd_snf(untitled_B.shi);
    trueCount -= 3600 * div_s32(trueCount, 3600);
    untitled_B.shi = trueCount - 60 * div_s32(trueCount, 60);
  } else {
    untitled_B.shi -= floor((untitled_B.shi - floor(untitled_B.shi / 3600.0) *
      3600.0) / 60.0) * 60.0;
  }

  untitled_B.shi += untitled_B.b_c.re + untitled_B.b_c.im;
  if (untitled_B.shi == 60.0) {
    untitled_B.shi = 59.999999999999993;
  }

  /* Sum: '<S1>/Sum' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  untitled_B.b_alo = untitled_B.shi - untitled_DW.UnitDelay_DSTATE;

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Logic: '<S1>/Logical Operator'
   *  RelationalOperator: '<S1>/Relational Operator'
   *  RelationalOperator: '<S1>/Relational Operator1'
   */
  if ((!(untitled_B.b_alo >= untitled_P.Constant_Value)) || (!(untitled_B.b_alo <=
        untitled_P.Constant2_Value))) {
    untitled_B.b_alo = untitled_P.Constant1_Value;
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  Switch: '<S1>/Switch'
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  untitled_B.Sum1 += untitled_B.b_alo;

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   */
  untitled_DW.UnitDelay_DSTATE = untitled_B.shi;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)untitled_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(untitled_M)!=-1) &&
        !((rtmGetTFinal(untitled_M)-untitled_M->Timing.taskTime0) >
          untitled_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled_M)) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }
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
  if (!(++untitled_M->Timing.clockTick0)) {
    ++untitled_M->Timing.clockTickH0;
  }

  untitled_M->Timing.taskTime0 = untitled_M->Timing.clockTick0 *
    untitled_M->Timing.stepSize0 + untitled_M->Timing.clockTickH0 *
    untitled_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled_T));
  rtmSetTFinal(untitled_M, 10.0);
  untitled_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (991386550U);
  untitled_M->Sizes.checksums[1] = (2484598149U);
  untitled_M->Sizes.checksums[2] = (855421566U);
  untitled_M->Sizes.checksums[3] = (4227439790U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* block I/O */
  (void) memset(((void *) &untitled_B), 0,
                sizeof(B_untitled_T));

  /* states (dwork) */
  (void) memset((void *)&untitled_DW, 0,
                sizeof(DW_untitled_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.objisempty = true;
  untitled_DW.obj.SampleTime = untitled_P.AnalogInput_SampleTime;
  untitled_DW.obj.isInitialized = 1;
  rc_adc_init();
  untitled_DW.obj.isSetupComplete = true;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  untitled_DW.UnitDelay_DSTATE = untitled_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay1' */
  untitled_B.Sum1 = untitled_P.UnitDelay1_InitialCondition;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj.isInitialized == 1) && untitled_DW.obj.isSetupComplete)
    {
      rc_adc_cleanup();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */
}
