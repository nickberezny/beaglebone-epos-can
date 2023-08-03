/*
 * controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.286
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Aug  3 10:59:50 2023
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
 * System initialize for trigger system:
 *    '<S12>/Stop Motor'
 *    '<S13>/Stop Motor'
 */
void controller_StopMotor_Init(B_StopMotor_controller_T *localB,
  P_StopMotor_controller_T *localP)
{
  /* SystemInitialize for CCaller: '<S24>/C Caller1' incorporates:
   *  Outport: '<S24>/enc'
   */
  localB->CCaller1[0] = localP->enc_Y0;
  localB->CCaller1[1] = localP->enc_Y0;
}

/*
 * Output and update for trigger system:
 *    '<S12>/Stop Motor'
 *    '<S13>/Stop Motor'
 */
void controller_StopMotor(boolean_T rtu_Trigger, const int32_T *rtd_pdo_id,
  B_StopMotor_controller_T *localB, P_StopMotor_controller_T *localP,
  ZCE_StopMotor_controller_T *localZCE)
{
  real_T tmp;
  int32_T rtb_DataStoreRead2_j;

  /* Outputs for Triggered SubSystem: '<S12>/Stop Motor' incorporates:
   *  TriggerPort: '<S24>/Trigger'
   */
  if (rtu_Trigger && (localZCE->StopMotor_Trig_ZCE != POS_ZCSIG)) {
    /* DataStoreRead: '<S24>/Data Store Read2' */
    rtb_DataStoreRead2_j = *rtd_pdo_id;

    /* DataTypeConversion: '<S24>/Data Type Conversion7' incorporates:
     *  Constant: '<S24>/Constant7'
     */
    tmp = floor(localP->Constant7_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    /* CCaller: '<S24>/C Caller1' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion7'
     */
    get_encoder(rtb_DataStoreRead2_j, tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
                (int32_T)(uint32_T)tmp, &localB->CCaller1[0]);
  }

  localZCE->StopMotor_Trig_ZCE = rtu_Trigger;

  /* End of Outputs for SubSystem: '<S12>/Stop Motor' */
}

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
static creal_T controller_times(const creal_T b_a)
{
  creal_T c;
  real_T ahi;
  real_T alo;
  c = controller_two_prod(b_a.re);
  controller_B.b = b_a.im * 8.64E+7;
  alo = c.im;
  ahi = c.re;
  if (controller_B.b != 0.0) {
    alo = c.im + controller_B.b;
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

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
static creal_T controller_plus(const creal_T b_a, real_T b)
{
  creal_T c;
  real_T ahi;
  real_T alo;
  real_T b_ahi;
  c = controller_two_sum(b_a.re, b);
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

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S15>/MATLAB Function' */
static creal_T controller_minus(const creal_T b_a, const creal_T b)
{
  creal_T cout;
  real_T ahi;
  real_T alo;
  real_T b_ahi;
  controller_B.c = controller_two_diff(b_a.re, b.re);
  controller_B.t_m = controller_two_diff(b_a.im, b.im);
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
  /* local block i/o variables */
  boolean_T rtb_Compare_br;
  boolean_T rtb_Compare_d;
  int32_T trueCount;
  boolean_T rtb_Compare_a;
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
  if (controller_M->Timing.TaskCounters.TID[5] == 0) {
    /* DataStoreWrite: '<Root>/Data Store Write11' incorporates:
     *  Constant: '<Root>/Constant13'
     */
    controller_DW.state = controller_P.Constant13_Value;
  }

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
    if (controller_DW.obj_b.SampleTime != controller_P.DigitalRead_SampleTime) {
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
    if (controller_DW.obj.SampleTime != controller_P.DigitalRead3_SampleTime) {
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
    controller_B.DataStoreRead8 = floor(controller_P.Constant14_Value);
    if (rtIsNaN(controller_B.DataStoreRead8) || rtIsInf
        (controller_B.DataStoreRead8)) {
      controller_B.DataStoreRead8 = 0.0;
    } else {
      controller_B.DataStoreRead8 = fmod(controller_B.DataStoreRead8,
        4.294967296E+9);
    }

    /* CCaller: '<Root>/C Caller3' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  DataTypeConversion: '<Root>/Data Type Conversion1'
     */
    print_input(controller_B.shi < 0.0 ? -(int32_T)(uint32_T)-controller_B.shi :
                (int32_T)(uint32_T)controller_B.shi, controller_B.DataStoreRead8
                < 0.0 ? -(int32_T)(uint32_T)-controller_B.DataStoreRead8 :
                (int32_T)(uint32_T)controller_B.DataStoreRead8);

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
        init_can(controller_B.shi < 0.0 ? -(int32_T)(uint32_T)-controller_B.shi :
                 (int32_T)(uint32_T)controller_B.shi,
                 controller_P.Constant1_Value_f, controller_P.Constant1_Value_f,
                 &controller_B.CCaller5[0]);

        /* DataStoreWrite: '<S14>/Data Store Write' */
        controller_DW.cfg_id = controller_B.CCaller5[0];

        /* DataStoreWrite: '<S14>/Data Store Write2' */
        controller_DW.pdo_id = controller_B.CCaller5[1];

        /* RelationalOperator: '<S31>/Compare' incorporates:
         *  Constant: '<S31>/Constant'
         */
        rtb_Compare_a = (controller_B.CCaller5[1] !=
                         controller_P.CompareToConstant_const);

        /* Switch: '<S32>/Switch' */
        if (rtb_Compare_a) {
          /* DataStoreWrite: '<S32>/Data Store Write' incorporates:
           *  Constant: '<S14>/Constant'
           */
          controller_DW.state = controller_P.Constant_Value_d;
        }

        /* End of Switch: '<S32>/Switch' */
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

  if (controller_M->Timing.TaskCounters.TID[2] == 0) {
    /* Outputs for Enabled SubSystem: '<Root>/Home1' incorporates:
     *  EnablePort: '<S10>/Enable'
     */
    /* RelationalOperator: '<S1>/Compare' incorporates:
     *  Constant: '<S1>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read'
     */
    if (controller_DW.state == controller_P.CompareToConstant1_const) {
      /* RelationalOperator: '<S16>/Compare' incorporates:
       *  Constant: '<S16>/Constant'
       *  DataStoreRead: '<S10>/Data Store Read'
       */
      rtb_Compare_a = (controller_DW.LS1_R ==
                       controller_P.CompareToConstant_const_b);

      /* Switch: '<S18>/Switch' */
      if (rtb_Compare_a) {
        /* DataStoreWrite: '<S18>/Data Store Write' incorporates:
         *  Constant: '<S10>/Constant'
         */
        controller_DW.state = controller_P.Constant_Value_a;
      }

      /* End of Switch: '<S18>/Switch' */

      /* DataTypeConversion: '<S19>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant'
       */
      controller_B.shi = floor(controller_P.Constant_Value_c);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S19>/C Caller3' incorporates:
       *  Constant: '<Root>/Constant1'
       *  DataStoreRead: '<S19>/Data Store Read2'
       *  DataTypeConversion: '<S19>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)
                (uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                controller_B.shi, controller_P.Constant1_Value_i);

      /* Outputs for Triggered SubSystem: '<S10>/Stop Motor' incorporates:
       *  TriggerPort: '<S17>/Trigger'
       */
      if (rtb_Compare_a && (controller_PrevZCX.StopMotor_Trig_ZCE_p != POS_ZCSIG))
      {
        /* DataTypeConversion: '<S17>/Data Type Conversion' incorporates:
         *  DataStoreRead: '<S17>/Data Store Read7'
         */
        controller_B.shi = floor(controller_DW.num_motors);
        if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
          controller_B.shi = 0.0;
        } else {
          controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
        }

        /* CCaller: '<S17>/C Caller4' incorporates:
         *  DataStoreRead: '<S17>/Data Store Read1'
         *  DataTypeConversion: '<S17>/Data Type Conversion'
         */
        stop_motor(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)
                   (uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                   controller_B.shi);
      }

      controller_PrevZCX.StopMotor_Trig_ZCE_p = rtb_Compare_a;

      /* End of Outputs for SubSystem: '<S10>/Stop Motor' */
    }

    /* End of RelationalOperator: '<S1>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Home1' */

    /* Outputs for Enabled SubSystem: '<Root>/Home2' incorporates:
     *  EnablePort: '<S11>/Enable'
     */
    /* RelationalOperator: '<S3>/Compare' incorporates:
     *  Constant: '<S3>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read3'
     */
    if (controller_DW.state == controller_P.CompareToConstant3_const) {
      /* Switch: '<S21>/Switch' incorporates:
       *  Constant: '<S20>/Constant'
       *  DataStoreRead: '<S11>/Data Store Read'
       *  RelationalOperator: '<S20>/Compare'
       */
      if (controller_DW.LS1_R == controller_P.CompareToConstant_const_f) {
        /* DataStoreWrite: '<S21>/Data Store Write' incorporates:
         *  Constant: '<S11>/Constant'
         */
        controller_DW.state = controller_P.Constant_Value_i;
      }

      /* End of Switch: '<S21>/Switch' */

      /* DataTypeConversion: '<S22>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      controller_B.shi = floor(controller_P.Constant2_Value_m);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S22>/C Caller3' incorporates:
       *  Constant: '<Root>/Constant3'
       *  DataStoreRead: '<S22>/Data Store Read2'
       *  DataTypeConversion: '<S22>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)
                (uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                controller_B.shi, controller_P.Constant3_Value);
    }

    /* End of RelationalOperator: '<S3>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Home2' */
  }

  /* DataStoreRead: '<Root>/Data Store Read7' */
  controller_B.DataStoreRead1_c = controller_DW.q01;

  /* DataStoreRead: '<Root>/Data Store Read8' */
  controller_B.DataStoreRead8 = controller_DW.q02;

  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   *  DataStoreRead: '<Root>/Data Store Read2'
   */
  controller_B.Compare = (controller_DW.state ==
    controller_P.CompareToConstant4_const);

  /* Outputs for Enabled SubSystem: '<Root>/Main Control' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  controller_DW.MainControl_MODE = controller_B.Compare;
  if (controller_DW.MainControl_MODE) {
    /* Switch: '<S36>/Switch' incorporates:
     *  Constant: '<S33>/Constant'
     *  DataStoreRead: '<S15>/Data Store Read3'
     *  RelationalOperator: '<S33>/Compare'
     */
    if (controller_DW.LS1_R == controller_P.CompareToConstant_const_g) {
      /* DataStoreWrite: '<S36>/Data Store Write' incorporates:
       *  Constant: '<S15>/Constant4'
       */
      controller_DW.state = controller_P.Constant4_Value;
    }

    /* End of Switch: '<S36>/Switch' */

    /* MATLAB Function: '<S15>/MATLAB Function' */
    controller_getLocalTime(&controller_B.fracSecs, &controller_B.second,
      &controller_B.shi, &controller_B.b_alo, &controller_B.d_ahi_k,
      &controller_B.c_tm_mon, &controller_B.c_tm_year, &rtb_Compare_a);
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
        (controller_B.c_tm_year / 4.0)) - floor(controller_B.c_tm_year / 100.0))
        + floor(controller_B.c_tm_year / 400.0)) + floor((153.0 *
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

    /* Sum: '<S15>/Sum' incorporates:
     *  Product: '<S15>/Divide'
     */
    controller_B.Switch[0] = controller_B.CCaller1[0] -
      controller_B.DataStoreRead1_c;
    controller_B.Switch[1] = controller_B.CCaller1[1] -
      controller_B.DataStoreRead8;

    /* RelationalOperator: '<S34>/Compare' incorporates:
     *  Constant: '<S34>/Constant'
     */
    controller_B.Compare_e[0] = (controller_B.CCaller1[0] !=
      controller_P.Constant_Value_p);
    controller_B.Compare_e[1] = (controller_B.CCaller1[1] !=
      controller_P.Constant_Value_p);

    /* Delay: '<S15>/Delay' */
    controller_B.Delay[0] = controller_DW.Delay_DSTATE[0];

    /* Switch: '<S15>/Switch' */
    if (!controller_B.Compare_e[0]) {
      /* Switch: '<S15>/Switch' incorporates:
       *  Product: '<S15>/Divide'
       */
      controller_B.Switch[0] = controller_B.Delay[0];
    }

    /* Delay: '<S15>/Delay' */
    controller_B.Delay[1] = controller_DW.Delay_DSTATE[1];

    /* Switch: '<S15>/Switch' */
    if (!controller_B.Compare_e[1]) {
      /* Switch: '<S15>/Switch' incorporates:
       *  Product: '<S15>/Divide'
       */
      controller_B.Switch[1] = controller_B.Delay[1];
    }

    /* Gain: '<S15>/Gain2' incorporates:
     *  DataStoreRead: '<S15>/Data Store Read1'
     *  DataStoreRead: '<S15>/Data Store Read8'
     *  Gain: '<S15>/Gain'
     *  Gain: '<S15>/Gain1'
     *  Product: '<S15>/Divide'
     */
    controller_B.Gain2[0] = controller_B.Switch[0] / (controller_P.Gain_Gain *
      controller_DW.GR1) * controller_P.Gain2_Gain;
    controller_B.Gain2[1] = controller_B.Switch[1] / (controller_P.Gain1_Gain *
      controller_DW.GR2) * controller_P.Gain2_Gain;

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
               0.0 ? -(int32_T)(uint32_T)-controller_B.shi : (int32_T)(uint32_T)
               controller_B.shi);

    /* Sin: '<S15>/Sine Wave' */
    controller_B.SineWave = sin(controller_P.SineWave_Freq *
      controller_M->Timing.t[0] + controller_P.SineWave_Phase) *
      controller_P.SineWave_Amp + controller_P.SineWave_Bias;

    /* DataTypeConversion: '<S37>/Data Type Conversion1' incorporates:
     *  Constant: '<S15>/Constant'
     */
    controller_B.shi = floor(controller_P.Constant_Value_iy);
    if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
      controller_B.shi = 0.0;
    } else {
      controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
    }

    /* CCaller: '<S37>/C Caller3' incorporates:
     *  DataStoreRead: '<S37>/Data Store Read2'
     *  DataTypeConversion: '<S37>/Data Type Conversion1'
     */
    set_motor(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)(uint32_T)
              -controller_B.shi : (int32_T)(uint32_T)controller_B.shi,
              controller_B.SineWave);

    /* DataTypeConversion: '<S38>/Data Type Conversion1' incorporates:
     *  Constant: '<S15>/Constant1'
     */
    controller_B.shi = floor(controller_P.Constant1_Value_m);
    if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
      controller_B.shi = 0.0;
    } else {
      controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
    }

    /* CCaller: '<S38>/C Caller3' incorporates:
     *  DataStoreRead: '<S38>/Data Store Read2'
     *  DataTypeConversion: '<S38>/Data Type Conversion1'
     */
    set_motor(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)(uint32_T)
              -controller_B.shi : (int32_T)(uint32_T)controller_B.shi,
              controller_B.SineWave);
  }

  /* End of Outputs for SubSystem: '<Root>/Main Control' */
  if (controller_M->Timing.TaskCounters.TID[2] == 0) {
    /* Outputs for Enabled SubSystem: '<Root>/Home3' incorporates:
     *  EnablePort: '<S12>/Enable'
     */
    /* RelationalOperator: '<S5>/Compare' incorporates:
     *  Constant: '<S5>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read4'
     */
    if (controller_DW.state == controller_P.CompareToConstant5_const) {
      /* RelationalOperator: '<S23>/Compare' incorporates:
       *  Constant: '<S23>/Constant'
       *  DataStoreRead: '<S12>/Data Store Read1'
       */
      rtb_Compare_d = (controller_DW.LS1_L ==
                       controller_P.CompareToConstant_const_n);

      /* Outputs for Triggered SubSystem: '<S12>/Stop Motor' */
      controller_StopMotor(rtb_Compare_d, &controller_DW.pdo_id,
                           &controller_B.StopMotor_d, &controller_P.StopMotor_d,
                           &controller_PrevZCX.StopMotor_d);

      /* End of Outputs for SubSystem: '<S12>/Stop Motor' */

      /* DataStoreWrite: '<S12>/Data Store Write' */
      controller_DW.q01 = controller_B.StopMotor_d.CCaller1[0];

      /* Switch: '<S25>/Switch' */
      if (rtb_Compare_d) {
        /* DataStoreWrite: '<S25>/Data Store Write' incorporates:
         *  Constant: '<S12>/Constant'
         */
        controller_DW.state = controller_P.Constant_Value_o;
      }

      /* End of Switch: '<S25>/Switch' */

      /* DataTypeConversion: '<S26>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant8'
       */
      controller_B.shi = floor(controller_P.Constant8_Value);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S26>/C Caller3' incorporates:
       *  Constant: '<Root>/Constant9'
       *  DataStoreRead: '<S26>/Data Store Read2'
       *  DataTypeConversion: '<S26>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)
                (uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                controller_B.shi, controller_P.Constant9_Value);
    }

    /* End of RelationalOperator: '<S5>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Home3' */

    /* Outputs for Enabled SubSystem: '<Root>/Home4' incorporates:
     *  EnablePort: '<S13>/Enable'
     */
    /* RelationalOperator: '<S6>/Compare' incorporates:
     *  Constant: '<S6>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read5'
     */
    if (controller_DW.state == controller_P.CompareToConstant6_const) {
      /* RelationalOperator: '<S27>/Compare' incorporates:
       *  Constant: '<S27>/Constant'
       *  DataStoreRead: '<S13>/Data Store Read1'
       */
      rtb_Compare_br = (controller_DW.LS1_L ==
                        controller_P.CompareToConstant_const_m);

      /* Outputs for Triggered SubSystem: '<S13>/Stop Motor' */
      controller_StopMotor(rtb_Compare_br, &controller_DW.pdo_id,
                           &controller_B.StopMotor_p, &controller_P.StopMotor_p,
                           &controller_PrevZCX.StopMotor_p);

      /* End of Outputs for SubSystem: '<S13>/Stop Motor' */

      /* DataStoreWrite: '<S13>/Data Store Write' */
      controller_DW.q02 = controller_B.StopMotor_p.CCaller1[1];

      /* Switch: '<S29>/Switch' */
      if (rtb_Compare_br) {
        /* DataStoreWrite: '<S29>/Data Store Write' incorporates:
         *  Constant: '<S13>/Constant'
         */
        controller_DW.state = controller_P.Constant_Value_a5;
      }

      /* End of Switch: '<S29>/Switch' */

      /* DataTypeConversion: '<S30>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant10'
       */
      controller_B.shi = floor(controller_P.Constant10_Value);
      if (rtIsNaN(controller_B.shi) || rtIsInf(controller_B.shi)) {
        controller_B.shi = 0.0;
      } else {
        controller_B.shi = fmod(controller_B.shi, 4.294967296E+9);
      }

      /* CCaller: '<S30>/C Caller3' incorporates:
       *  Constant: '<Root>/Constant11'
       *  DataStoreRead: '<S30>/Data Store Read2'
       *  DataTypeConversion: '<S30>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, controller_B.shi < 0.0 ? -(int32_T)
                (uint32_T)-controller_B.shi : (int32_T)(uint32_T)
                controller_B.shi, controller_P.Constant11_Value);
    }

    /* End of RelationalOperator: '<S6>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Home4' */
  }

  /* RelationalOperator: '<S7>/Compare' incorporates:
   *  Constant: '<S7>/Constant'
   *  DataStoreRead: '<Root>/Data Store Read6'
   */
  rtb_Compare_a = (controller_DW.state == controller_P.CompareToConstant7_const);

  /* Outputs for Triggered SubSystem: '<Root>/Exit Control' incorporates:
   *  TriggerPort: '<S9>/Trigger'
   */
  if (rtb_Compare_a && (controller_PrevZCX.ExitControl_Trig_ZCE != POS_ZCSIG)) {
    /* CCaller: '<S9>/C Caller4' */
    close_datalog();
  }

  controller_PrevZCX.ExitControl_Trig_ZCE = rtb_Compare_a;

  /* End of Outputs for SubSystem: '<Root>/Exit Control' */

  /* Update for Enabled SubSystem: '<Root>/Main Control' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  if (controller_DW.MainControl_MODE) {
    /* Update for Delay: '<S15>/Delay' */
    controller_DW.Delay_DSTATE[0] = controller_B.Switch[0];
    controller_DW.Delay_DSTATE[1] = controller_B.Switch[1];
  }

  /* End of Update for SubSystem: '<Root>/Main Control' */

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

    /* Start for Enabled SubSystem: '<Root>/Main Control' */
    controller_DW.MainControl_MODE = false;

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
  controller_PrevZCX.StopMotor_Trig_ZCE_p = POS_ZCSIG;
  controller_PrevZCX.StopMotor_p.StopMotor_Trig_ZCE = POS_ZCSIG;
  controller_PrevZCX.StopMotor_d.StopMotor_Trig_ZCE = POS_ZCSIG;

  /* SystemInitialize for Enabled SubSystem: '<Root>/Main Control' */
  /* InitializeConditions for Delay: '<S15>/Delay' */
  controller_DW.Delay_DSTATE[0] = controller_P.Delay_InitialCondition;
  controller_DW.Delay_DSTATE[1] = controller_P.Delay_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<Root>/Main Control' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home3' */
  /* SystemInitialize for Triggered SubSystem: '<S12>/Stop Motor' */
  controller_StopMotor_Init(&controller_B.StopMotor_d, &controller_P.StopMotor_d);

  /* End of SystemInitialize for SubSystem: '<S12>/Stop Motor' */
  /* End of SystemInitialize for SubSystem: '<Root>/Home3' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home4' */
  /* SystemInitialize for Triggered SubSystem: '<S13>/Stop Motor' */
  controller_StopMotor_Init(&controller_B.StopMotor_p, &controller_P.StopMotor_p);

  /* End of SystemInitialize for SubSystem: '<S13>/Stop Motor' */
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
