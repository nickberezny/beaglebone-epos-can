/*
 * controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.413
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Aug 24 12:17:01 2023
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
   *  TriggerPort: '<S13>/Trigger'
   */
  if (rtu_Trigger && (localZCE->StopMotor1_Trig_ZCE != POS_ZCSIG)) {
    /* DataStoreRead: '<S13>/Data Store Read1' */
    rtb_DataStoreRead1_l = *rtd_pdo_id;

    /* DataStoreRead: '<S13>/Data Store Read7' */
    rtb_DataStoreRead7_b = *rtd_num_motors;

    /* DataTypeConversion: '<S13>/Data Type Conversion' */
    rtb_DataStoreRead7_b = floor(rtb_DataStoreRead7_b);
    if (rtIsNaN(rtb_DataStoreRead7_b) || rtIsInf(rtb_DataStoreRead7_b)) {
      rtb_DataStoreRead7_b = 0.0;
    } else {
      rtb_DataStoreRead7_b = fmod(rtb_DataStoreRead7_b, 4.294967296E+9);
    }

    /* CCaller: '<S13>/C Caller4' incorporates:
     *  DataTypeConversion: '<S13>/Data Type Conversion'
     */
    stop_motor(rtb_DataStoreRead1_l, rtb_DataStoreRead7_b < 0.0 ? -(int32_T)
               (uint32_T)-rtb_DataStoreRead7_b : (int32_T)(uint32_T)
               rtb_DataStoreRead7_b);
  }

  localZCE->StopMotor1_Trig_ZCE = rtu_Trigger;

  /* End of Outputs for SubSystem: '<S7>/Stop Motor1' */
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static creal_T controller_times(const creal_T b_a)
{
  creal_T c;
  real_T ahi;
  c = controller_two_prod(b_a.re);
  controller_B.b = b_a.im * 8.64E+7;
  controller_B.alo_k = c.im;
  ahi = c.re;
  if (controller_B.b != 0.0) {
    controller_B.alo_k = c.im + controller_B.b;
    ahi = c.re + controller_B.alo_k;
    controller_B.alo_k -= ahi - c.re;
  }

  if (rtIsNaN(controller_B.alo_k)) {
    controller_B.alo_k = 0.0;
  }

  c.re = ahi;
  c.im = controller_B.alo_k;
  return c;
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static creal_T controller_plus(const creal_T b_a, real_T b)
{
  creal_T c;
  real_T ahi;
  real_T b_ahi;
  c = controller_two_sum(b_a.re, b);
  controller_B.t_c = controller_two_sum(b_a.im, 0.0);
  controller_B.alo_c = c.im;
  ahi = c.re;
  if (controller_B.t_c.re != 0.0) {
    controller_B.alo_c = c.im + controller_B.t_c.re;
    ahi = c.re + controller_B.alo_c;
    controller_B.alo_c -= ahi - c.re;
  }

  if (rtIsNaN(controller_B.alo_c)) {
    controller_B.alo_c = 0.0;
  }

  b_ahi = ahi;
  if (controller_B.t_c.im != 0.0) {
    controller_B.alo_c += controller_B.t_c.im;
    b_ahi = ahi + controller_B.alo_c;
    controller_B.alo_c -= b_ahi - ahi;
  }

  if (rtIsNaN(controller_B.alo_c)) {
    controller_B.alo_c = 0.0;
  }

  c.re = b_ahi;
  c.im = controller_B.alo_c;
  return c;
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static creal_T controller_minus(const creal_T b_a, const creal_T b)
{
  creal_T cout;
  real_T ahi;
  real_T b_ahi;
  controller_B.c = controller_two_diff(b_a.re, b.re);
  controller_B.t_m = controller_two_diff(b_a.im, b.im);
  controller_B.alo = controller_B.c.im;
  ahi = controller_B.c.re;
  if (controller_B.t_m.re != 0.0) {
    controller_B.alo = controller_B.c.im + controller_B.t_m.re;
    ahi = controller_B.c.re + controller_B.alo;
    controller_B.alo -= ahi - controller_B.c.re;
  }

  if (rtIsNaN(controller_B.alo)) {
    controller_B.alo = 0.0;
  }

  b_ahi = ahi;
  if (controller_B.t_m.im != 0.0) {
    controller_B.alo += controller_B.t_m.im;
    b_ahi = ahi + controller_B.alo;
    controller_B.alo -= b_ahi - ahi;
  }

  if (rtIsNaN(controller_B.alo)) {
    controller_B.alo = 0.0;
  }

  cout.re = b_ahi;
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
  boolean_T rtb_Compare_m;
  boolean_T rtb_Compare_i;

  {
    real_T *lastU;
    int32_T trueCount;
    boolean_T rtb_Compare_n1;
    boolean_T rtb_IsNaN1;
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
    controller_DW.max_accel = controller_P.Constant6_Value_n;

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

      /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
       *  Constant: '<Root>/Constant14'
       */
      controller_B.Sum6 = floor(controller_P.Constant14_Value_c);
      if (rtIsNaN(controller_B.Sum6) || rtIsInf(controller_B.Sum6)) {
        controller_B.Sum6 = 0.0;
      } else {
        controller_B.Sum6 = fmod(controller_B.Sum6, 4.294967296E+9);
      }

      /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<Root>/Data Store Read9'
       */
      controller_B.DataStoreRead7 = floor(controller_DW.debug);
      if (rtIsNaN(controller_B.DataStoreRead7) || rtIsInf
          (controller_B.DataStoreRead7)) {
        controller_B.DataStoreRead7 = 0.0;
      } else {
        controller_B.DataStoreRead7 = fmod(controller_B.DataStoreRead7,
          4.294967296E+9);
      }

      /* CCaller: '<Root>/C Caller3' incorporates:
       *  DataStoreRead: '<Root>/Data Store Read1'
       *  DataTypeConversion: '<Root>/Data Type Conversion'
       *  DataTypeConversion: '<Root>/Data Type Conversion2'
       */
      print_input(controller_DW.state, controller_B.Sum6 < 0.0 ? -(int32_T)
                  (uint32_T)-controller_B.Sum6 : (int32_T)(uint32_T)
                  controller_B.Sum6, controller_B.DataStoreRead7 < 0.0 ?
                  -(int32_T)(uint32_T)-controller_B.DataStoreRead7 : (int32_T)
                  (uint32_T)controller_B.DataStoreRead7);

      /* Outputs for Enabled SubSystem: '<Root>/Initialize' incorporates:
       *  EnablePort: '<S9>/Enable'
       */
      /* RelationalOperator: '<S2>/Compare' incorporates:
       *  Constant: '<S2>/Constant'
       */
      if (controller_B.DataStoreRead1_c == controller_P.CompareToConstant2_const)
      {
        controller_DW.Initialize_MODE = true;
        if (controller_M->Timing.TaskCounters.TID[5] == 0) {
          /* DataTypeConversion: '<S9>/Data Type Conversion2' incorporates:
           *  DataStoreRead: '<S9>/Data Store Read7'
           */
          controller_B.Sum6 = floor(controller_DW.num_motors);
          if (rtIsNaN(controller_B.Sum6) || rtIsInf(controller_B.Sum6)) {
            controller_B.Sum6 = 0.0;
          } else {
            controller_B.Sum6 = fmod(controller_B.Sum6, 4.294967296E+9);
          }

          /* CCaller: '<S9>/C Caller5' incorporates:
           *  Constant: '<S9>/Constant1'
           *  DataTypeConversion: '<S9>/Data Type Conversion2'
           */
          init_can(controller_B.Sum6 < 0.0 ? -(int32_T)(uint32_T)
                   -controller_B.Sum6 : (int32_T)(uint32_T)controller_B.Sum6,
                   controller_P.Constant1_Value_f,
                   controller_P.Constant1_Value_f, &controller_B.CCaller5[0]);

          /* DataStoreWrite: '<S9>/Data Store Write' */
          controller_DW.cfg_id = controller_B.CCaller5[0];

          /* DataStoreWrite: '<S9>/Data Store Write2' */
          controller_DW.pdo_id = controller_B.CCaller5[1];

          /* RelationalOperator: '<S21>/Compare' incorporates:
           *  Constant: '<S21>/Constant'
           */
          rtb_Compare_n1 = (controller_B.CCaller5[1] !=
                            controller_P.CompareToConstant_const);

          /* Switch: '<S22>/Switch' */
          if (rtb_Compare_n1) {
            /* DataStoreWrite: '<S22>/Data Store Write' incorporates:
             *  Constant: '<S9>/Constant'
             */
            controller_DW.state = controller_P.Constant_Value_d;
          }

          /* End of Switch: '<S22>/Switch' */
        }

        if (controller_M->Timing.TaskCounters.TID[4] == 0) {
          /* CCaller: '<S9>/C Caller3' */
          init_datalog();
        }
      } else {
        controller_DW.Initialize_MODE = false;
      }

      /* End of RelationalOperator: '<S2>/Compare' */
      /* End of Outputs for SubSystem: '<Root>/Initialize' */
    }

    /* DataStoreRead: '<Root>/Data Store Read10' */
    rtb_Compare_n1 = controller_DW.LS1_R;

    /* RelationalOperator: '<S1>/Compare' incorporates:
     *  Constant: '<S1>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read'
     */
    controller_B.Compare = (controller_DW.state ==
      controller_P.CompareToConstant1_const);

    /* Outputs for Enabled SubSystem: '<Root>/Home1' incorporates:
     *  EnablePort: '<S7>/Enable'
     */
    controller_DW.Home1_MODE = controller_B.Compare;
    if (controller_DW.Home1_MODE) {
      /* DataStoreRead: '<S7>/Data Store Read7' */
      controller_B.DataStoreRead1_c = controller_DW.num_motors;

      /* DataTypeConversion: '<S7>/Data Type Conversion7' */
      controller_B.Sum6 = floor(controller_B.DataStoreRead1_c);
      if (rtIsNaN(controller_B.Sum6) || rtIsInf(controller_B.Sum6)) {
        controller_B.Sum6 = 0.0;
      } else {
        controller_B.Sum6 = fmod(controller_B.Sum6, 4.294967296E+9);
      }

      /* CCaller: '<S7>/C Caller1' incorporates:
       *  DataStoreRead: '<S7>/Data Store Read2'
       *  DataTypeConversion: '<S7>/Data Type Conversion7'
       */
      get_encoder(controller_DW.pdo_id, controller_B.Sum6 < 0.0 ? -(int32_T)
                  (uint32_T)-controller_B.Sum6 : (int32_T)(uint32_T)
                  controller_B.Sum6, &controller_B.DataStoreRead1_c);

      /* DataStoreWrite: '<S7>/Data Store Write' */
      controller_DW.q01 = controller_B.DataStoreRead1_c;

      /* RelationalOperator: '<S11>/Compare' incorporates:
       *  Constant: '<S11>/Constant'
       */
      rtb_Compare_i = (rtb_Compare_n1 == controller_P.CompareToConstant1_const_j);

      /* Switch: '<S15>/Switch' */
      if (rtb_Compare_i) {
        /* DataStoreWrite: '<S15>/Data Store Write' incorporates:
         *  Constant: '<S7>/Constant1'
         */
        controller_DW.state = controller_P.Constant1_Value;
      }

      /* End of Switch: '<S15>/Switch' */

      /* RelationalOperator: '<S12>/Compare' incorporates:
       *  Constant: '<S12>/Constant'
       */
      rtb_Compare_n1 = (controller_B.DataStoreRead1_c !=
                        controller_P.Constant_Value);

      /* Switch: '<S7>/Switch' */
      if (rtb_Compare_n1) {
        /* Switch: '<S7>/Switch' */
        controller_B.Switch_g = controller_B.DataStoreRead1_c;
      } else {
        /* Switch: '<S7>/Switch' incorporates:
         *  Delay: '<S7>/Delay'
         */
        controller_B.Switch_g = controller_DW.Delay_DSTATE_n;
      }

      /* End of Switch: '<S7>/Switch' */

      /* Gain: '<S7>/Gain2' incorporates:
       *  DataStoreRead: '<S7>/Data Store Read1'
       *  Gain: '<S7>/Gain'
       *  Product: '<S7>/Divide'
       */
      controller_B.Gain2_o = controller_B.Switch_g / (controller_P.Gain_Gain *
        controller_DW.GR1) * controller_P.Gain2_Gain;

      /* Derivative: '<S7>/Derivative' */
      controller_B.Sum6 = controller_M->Timing.t[0];
      if ((controller_DW.TimeStampA_f >= controller_B.Sum6) &&
          (controller_DW.TimeStampB_o >= controller_B.Sum6)) {
        /* Derivative: '<S7>/Derivative' */
        controller_B.Derivative_e = 0.0;
      } else {
        controller_B.DataStoreRead1_c = controller_DW.TimeStampA_f;
        lastU = &controller_DW.LastUAtTimeA_e;
        if (controller_DW.TimeStampA_f < controller_DW.TimeStampB_o) {
          if (controller_DW.TimeStampB_o < controller_B.Sum6) {
            controller_B.DataStoreRead1_c = controller_DW.TimeStampB_o;
            lastU = &controller_DW.LastUAtTimeB_h;
          }
        } else if (controller_DW.TimeStampA_f >= controller_B.Sum6) {
          controller_B.DataStoreRead1_c = controller_DW.TimeStampB_o;
          lastU = &controller_DW.LastUAtTimeB_h;
        }

        /* Derivative: '<S7>/Derivative' */
        controller_B.Derivative_e = (controller_B.Gain2_o - *lastU) /
          (controller_B.Sum6 - controller_B.DataStoreRead1_c);
      }

      /* End of Derivative: '<S7>/Derivative' */

      /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
       *  Constant: '<S7>/Constant14'
       */
      controller_B.Sum6 = floor(controller_P.Constant14_Value);
      if (rtIsNaN(controller_B.Sum6) || rtIsInf(controller_B.Sum6)) {
        controller_B.Sum6 = 0.0;
      } else {
        controller_B.Sum6 = fmod(controller_B.Sum6, 4.294967296E+9);
      }

      /* DataTypeConversion: '<S7>/Data Type Conversion2' incorporates:
       *  DataStoreRead: '<S7>/Data Store Read9'
       */
      controller_B.DataStoreRead7 = floor(controller_DW.debug);
      if (rtIsNaN(controller_B.DataStoreRead7) || rtIsInf
          (controller_B.DataStoreRead7)) {
        controller_B.DataStoreRead7 = 0.0;
      } else {
        controller_B.DataStoreRead7 = fmod(controller_B.DataStoreRead7,
          4.294967296E+9);
      }

      /* CCaller: '<S7>/C Caller3' incorporates:
       *  DataTypeConversion: '<S7>/Data Type Conversion'
       *  DataTypeConversion: '<S7>/Data Type Conversion2'
       */
      print_input(controller_B.Derivative_e, controller_B.Sum6 < 0.0 ? -(int32_T)
                  (uint32_T)-controller_B.Sum6 : (int32_T)(uint32_T)
                  controller_B.Sum6, controller_B.DataStoreRead7 < 0.0 ?
                  -(int32_T)(uint32_T)-controller_B.DataStoreRead7 : (int32_T)
                  (uint32_T)controller_B.DataStoreRead7);

      /* Sum: '<S7>/Sum2' incorporates:
       *  Constant: '<Root>/Constant1'
       *  Constant: '<S7>/Constant'
       *  Gain: '<S7>/Gain3'
       *  Sum: '<S7>/Sum1'
       */
      controller_B.Saturation_d = (controller_P.Constant1_Value_i -
        controller_B.Derivative_e) * controller_P.Gain3_Gain -
        controller_P.Constant_Value_e;

      /* Saturate: '<S7>/Saturation' */
      if (controller_B.Saturation_d > controller_P.Saturation_UpperSat) {
        /* Sum: '<S7>/Sum2' incorporates:
         *  Saturate: '<S7>/Saturation'
         */
        controller_B.Saturation_d = controller_P.Saturation_UpperSat;
      } else if (controller_B.Saturation_d < controller_P.Saturation_LowerSat) {
        /* Sum: '<S7>/Sum2' incorporates:
         *  Saturate: '<S7>/Saturation'
         */
        controller_B.Saturation_d = controller_P.Saturation_LowerSat;
      }

      /* End of Saturate: '<S7>/Saturation' */

      /* DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant'
       */
      controller_B.Sum6 = floor(controller_P.Constant_Value_c);
      if (rtIsNaN(controller_B.Sum6) || rtIsInf(controller_B.Sum6)) {
        controller_B.Sum6 = 0.0;
      } else {
        controller_B.Sum6 = fmod(controller_B.Sum6, 4.294967296E+9);
      }

      /* CCaller: '<S14>/C Caller3' incorporates:
       *  DataStoreRead: '<S14>/Data Store Read2'
       *  DataTypeConversion: '<S14>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, controller_B.Sum6 < 0.0 ? -(int32_T)
                (uint32_T)-controller_B.Sum6 : (int32_T)(uint32_T)
                controller_B.Sum6, controller_B.Saturation_d);

      /* Outputs for Triggered SubSystem: '<S7>/Stop Motor1' */
      controller_StopMotor1(rtb_Compare_i, &controller_DW.num_motors,
                            &controller_DW.pdo_id,
                            &controller_PrevZCX.StopMotor1);

      /* End of Outputs for SubSystem: '<S7>/Stop Motor1' */
    }

    /* End of Outputs for SubSystem: '<Root>/Home1' */

    /* RelationalOperator: '<S3>/Compare' incorporates:
     *  Constant: '<S3>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read3'
     */
    controller_B.Compare_m = (controller_DW.state ==
      controller_P.CompareToConstant3_const);

    /* Outputs for Enabled SubSystem: '<Root>/Home2' incorporates:
     *  EnablePort: '<S8>/Enable'
     */
    controller_DW.Home2_MODE = controller_B.Compare_m;
    if (controller_DW.Home2_MODE) {
      /* RelationalOperator: '<S16>/Compare' incorporates:
       *  Constant: '<S16>/Constant'
       *  DataStoreRead: '<Root>/Data Store Read4'
       */
      rtb_Compare_m = (controller_DW.LS1_L ==
                       controller_P.CompareToConstant1_const_k);

      /* Switch: '<S20>/Switch' incorporates:
       *  Constant: '<S8>/Constant1'
       *  DataStoreRead: '<S20>/Data Store Read'
       */
      if (rtb_Compare_m) {
        controller_B.DataStoreRead1_c = controller_P.Constant1_Value_a;
      } else {
        controller_B.DataStoreRead1_c = controller_DW.state;
      }

      /* End of Switch: '<S20>/Switch' */

      /* DataStoreWrite: '<S20>/Data Store Write' */
      controller_DW.state = controller_B.DataStoreRead1_c;

      /* DataStoreRead: '<S8>/Data Store Read7' */
      controller_B.DataStoreRead1_c = controller_DW.num_motors;

      /* DataTypeConversion: '<S8>/Data Type Conversion7' */
      controller_B.Sum6 = floor(controller_B.DataStoreRead1_c);
      if (rtIsNaN(controller_B.Sum6) || rtIsInf(controller_B.Sum6)) {
        controller_B.Sum6 = 0.0;
      } else {
        controller_B.Sum6 = fmod(controller_B.Sum6, 4.294967296E+9);
      }

      /* CCaller: '<S8>/C Caller1' incorporates:
       *  DataStoreRead: '<S8>/Data Store Read2'
       *  DataTypeConversion: '<S8>/Data Type Conversion7'
       */
      get_encoder(controller_DW.pdo_id, controller_B.Sum6 < 0.0 ? -(int32_T)
                  (uint32_T)-controller_B.Sum6 : (int32_T)(uint32_T)
                  controller_B.Sum6, &controller_B.DataStoreRead1_c);

      /* RelationalOperator: '<S17>/Compare' incorporates:
       *  Constant: '<S17>/Constant'
       */
      rtb_Compare_n1 = (controller_B.DataStoreRead1_c !=
                        controller_P.Constant_Value_f);

      /* Switch: '<S8>/Switch' */
      if (rtb_Compare_n1) {
        /* Switch: '<S8>/Switch' */
        controller_B.Switch = controller_B.DataStoreRead1_c;
      } else {
        /* Switch: '<S8>/Switch' incorporates:
         *  Delay: '<S8>/Delay'
         */
        controller_B.Switch = controller_DW.Delay_DSTATE;
      }

      /* End of Switch: '<S8>/Switch' */

      /* Gain: '<S8>/Gain2' incorporates:
       *  DataStoreRead: '<S8>/Data Store Read1'
       *  Gain: '<S8>/Gain'
       *  Product: '<S8>/Divide'
       */
      controller_B.Gain2 = controller_B.Switch / (controller_P.Gain_Gain_o *
        controller_DW.GR1) * controller_P.Gain2_Gain_p;

      /* Derivative: '<S8>/Derivative' */
      controller_B.Sum6 = controller_M->Timing.t[0];
      if ((controller_DW.TimeStampA_gc >= controller_B.Sum6) &&
          (controller_DW.TimeStampB_h >= controller_B.Sum6)) {
        /* Derivative: '<S8>/Derivative' */
        controller_B.Derivative = 0.0;
      } else {
        controller_B.DataStoreRead1_c = controller_DW.TimeStampA_gc;
        lastU = &controller_DW.LastUAtTimeA_f;
        if (controller_DW.TimeStampA_gc < controller_DW.TimeStampB_h) {
          if (controller_DW.TimeStampB_h < controller_B.Sum6) {
            controller_B.DataStoreRead1_c = controller_DW.TimeStampB_h;
            lastU = &controller_DW.LastUAtTimeB_c;
          }
        } else if (controller_DW.TimeStampA_gc >= controller_B.Sum6) {
          controller_B.DataStoreRead1_c = controller_DW.TimeStampB_h;
          lastU = &controller_DW.LastUAtTimeB_c;
        }

        /* Derivative: '<S8>/Derivative' */
        controller_B.Derivative = (controller_B.Gain2 - *lastU) /
          (controller_B.Sum6 - controller_B.DataStoreRead1_c);
      }

      /* End of Derivative: '<S8>/Derivative' */

      /* DataStoreRead: '<S8>/Data Store Read9' */
      controller_B.DataStoreRead1_c = controller_DW.debug;

      /* DataTypeConversion: '<S8>/Data Type Conversion2' */
      controller_B.Sum6 = floor(controller_B.DataStoreRead1_c);
      if (rtIsNaN(controller_B.Sum6) || rtIsInf(controller_B.Sum6)) {
        controller_B.Sum6 = 0.0;
      } else {
        controller_B.Sum6 = fmod(controller_B.Sum6, 4.294967296E+9);
      }

      /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
       *  Constant: '<S8>/Constant14'
       */
      controller_B.DataStoreRead7 = floor(controller_P.Constant14_Value_m);
      if (rtIsNaN(controller_B.DataStoreRead7) || rtIsInf
          (controller_B.DataStoreRead7)) {
        controller_B.DataStoreRead7 = 0.0;
      } else {
        controller_B.DataStoreRead7 = fmod(controller_B.DataStoreRead7,
          4.294967296E+9);
      }

      /* CCaller: '<S8>/C Caller3' incorporates:
       *  DataTypeConversion: '<S8>/Data Type Conversion'
       *  DataTypeConversion: '<S8>/Data Type Conversion2'
       */
      print_input(controller_B.Derivative, controller_B.DataStoreRead7 < 0.0 ?
                  -(int32_T)(uint32_T)-controller_B.DataStoreRead7 : (int32_T)
                  (uint32_T)controller_B.DataStoreRead7, controller_B.Sum6 < 0.0
                  ? -(int32_T)(uint32_T)-controller_B.Sum6 : (int32_T)(uint32_T)
                  controller_B.Sum6);

      /* Sum: '<S8>/Sum2' incorporates:
       *  Constant: '<Root>/Constant3'
       *  Constant: '<S8>/Constant'
       *  Gain: '<S8>/Gain3'
       *  Sum: '<S8>/Sum1'
       */
      controller_B.Saturation_b = (controller_P.Constant3_Value_c -
        controller_B.Derivative) * controller_P.Gain3_Gain_n -
        controller_P.Constant_Value_b;

      /* Saturate: '<S8>/Saturation' */
      if (controller_B.Saturation_b > controller_P.Saturation_UpperSat_n) {
        /* Sum: '<S8>/Sum2' incorporates:
         *  Saturate: '<S8>/Saturation'
         */
        controller_B.Saturation_b = controller_P.Saturation_UpperSat_n;
      } else if (controller_B.Saturation_b < controller_P.Saturation_LowerSat_h)
      {
        /* Sum: '<S8>/Sum2' incorporates:
         *  Saturate: '<S8>/Saturation'
         */
        controller_B.Saturation_b = controller_P.Saturation_LowerSat_h;
      }

      /* End of Saturate: '<S8>/Saturation' */

      /* DataTypeConversion: '<S19>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      controller_B.Sum6 = floor(controller_P.Constant2_Value_k);
      if (rtIsNaN(controller_B.Sum6) || rtIsInf(controller_B.Sum6)) {
        controller_B.Sum6 = 0.0;
      } else {
        controller_B.Sum6 = fmod(controller_B.Sum6, 4.294967296E+9);
      }

      /* CCaller: '<S19>/C Caller3' incorporates:
       *  DataStoreRead: '<S19>/Data Store Read2'
       *  DataTypeConversion: '<S19>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, controller_B.Sum6 < 0.0 ? -(int32_T)
                (uint32_T)-controller_B.Sum6 : (int32_T)(uint32_T)
                controller_B.Sum6, controller_B.Saturation_b);

      /* Outputs for Triggered SubSystem: '<S8>/Stop Motor1' */
      controller_StopMotor1(rtb_Compare_m, &controller_DW.num_motors,
                            &controller_DW.pdo_id,
                            &controller_PrevZCX.StopMotor1_n);

      /* End of Outputs for SubSystem: '<S8>/Stop Motor1' */
    }

    /* End of Outputs for SubSystem: '<Root>/Home2' */

    /* DataStoreRead: '<Root>/Data Store Read7' */
    controller_B.DataStoreRead7 = controller_DW.q01;

    /* RelationalOperator: '<S4>/Compare' incorporates:
     *  Constant: '<S4>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read2'
     */
    controller_B.Compare_j = (controller_DW.state ==
      controller_P.CompareToConstant4_const);

    /* Outputs for Enabled SubSystem: '<Root>/Main Control' incorporates:
     *  EnablePort: '<S10>/Enable'
     */
    controller_DW.MainControl_MODE = controller_B.Compare_j;
    if (controller_DW.MainControl_MODE) {
      /* Switch: '<S27>/Switch' incorporates:
       *  Constant: '<S10>/Constant4'
       *  Constant: '<S23>/Constant'
       *  DataStoreRead: '<S10>/Data Store Read3'
       *  DataStoreRead: '<S27>/Data Store Read'
       *  RelationalOperator: '<S23>/Compare'
       */
      if (controller_DW.LS1_R == controller_P.CompareToConstant_const_g) {
        controller_B.DataStoreRead1_c = controller_P.Constant4_Value;
      } else {
        controller_B.DataStoreRead1_c = controller_DW.state;
      }

      /* End of Switch: '<S27>/Switch' */

      /* DataStoreWrite: '<S27>/Data Store Write' */
      controller_DW.state = controller_B.DataStoreRead1_c;

      /* DataStoreRead: '<S10>/Data Store Read10' */
      controller_B.DataStoreRead1_c = controller_DW.num_motors;

      /* DataTypeConversion: '<S10>/Data Type Conversion11' */
      controller_B.Sum6 = floor(controller_B.DataStoreRead1_c);
      if (rtIsNaN(controller_B.Sum6) || rtIsInf(controller_B.Sum6)) {
        controller_B.Sum6 = 0.0;
      } else {
        controller_B.Sum6 = fmod(controller_B.Sum6, 4.294967296E+9);
      }

      /* CCaller: '<S10>/C Caller6' incorporates:
       *  DataStoreRead: '<S10>/Data Store Read8'
       *  DataTypeConversion: '<S10>/Data Type Conversion11'
       */
      get_encoder(controller_DW.pdo_id, controller_B.Sum6 < 0.0 ? -(int32_T)
                  (uint32_T)-controller_B.Sum6 : (int32_T)(uint32_T)
                  controller_B.Sum6, &controller_B.CCaller6);

      /* RelationalOperator: '<S24>/Compare' incorporates:
       *  Constant: '<S24>/Constant'
       */
      rtb_Compare_n1 = (controller_B.CCaller6 != controller_P.Constant_Value_fw);

      /* RelationalOperator: '<S10>/IsNaN1' */
      rtb_IsNaN1 = rtIsNaN(controller_B.CCaller6);

      /* Logic: '<S10>/Logical Operator3' incorporates:
       *  Logic: '<S10>/Logical Operator2'
       */
      controller_B.LogicalOperator3 = (rtb_Compare_n1 && (!rtb_IsNaN1));

      /* Delay: '<S10>/Delay1' */
      controller_B.Delay1 = controller_DW.Delay1_DSTATE;

      /* Switch: '<S10>/Switch2' */
      if (controller_B.LogicalOperator3) {
        /* Sum: '<S10>/Sum6' */
        controller_B.Sum6 = controller_B.CCaller6 - controller_B.DataStoreRead7;

        /* Switch: '<S10>/Switch2' incorporates:
         *  Constant: '<S10>/Constant6'
         *  Constant: '<S25>/Constant'
         *  Product: '<S10>/Divide2'
         *  RelationalOperator: '<S25>/Compare'
         *  Sum: '<S10>/Sum7'
         */
        controller_B.Switch2 = (real_T)(controller_B.Sum6 <
          controller_P.Constant_Value_a) * controller_P.Constant6_Value +
          controller_B.Sum6;
      } else {
        /* Switch: '<S10>/Switch2' */
        controller_B.Switch2 = controller_B.Delay1;
      }

      /* End of Switch: '<S10>/Switch2' */

      /* Gain: '<S10>/Gain3' incorporates:
       *  DataStoreRead: '<S10>/Data Store Read6'
       *  Gain: '<S10>/Gain1'
       *  Product: '<S10>/Divide1'
       */
      controller_B.Gain3 = controller_B.Switch2 / (controller_P.Gain1_Gain *
        controller_DW.GR1) * controller_P.Gain3_Gain_j;
      if (controller_M->Timing.TaskCounters.TID[2] == 0) {
        /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
         *  Constant: '<S10>/Constant14'
         */
        controller_B.Sum6 = floor(controller_P.Constant14_Value_g);
        if (rtIsNaN(controller_B.Sum6) || rtIsInf(controller_B.Sum6)) {
          controller_B.Sum6 = 0.0;
        } else {
          controller_B.Sum6 = fmod(controller_B.Sum6, 4.294967296E+9);
        }

        /* DataTypeConversion: '<S10>/Data Type Conversion3' incorporates:
         *  DataStoreRead: '<S10>/Data Store Read9'
         */
        controller_B.DataStoreRead7 = floor(controller_DW.debug);
        if (rtIsNaN(controller_B.DataStoreRead7) || rtIsInf
            (controller_B.DataStoreRead7)) {
          controller_B.DataStoreRead7 = 0.0;
        } else {
          controller_B.DataStoreRead7 = fmod(controller_B.DataStoreRead7,
            4.294967296E+9);
        }

        /* CCaller: '<S10>/C Caller3' incorporates:
         *  DataTypeConversion: '<S10>/Data Type Conversion'
         *  DataTypeConversion: '<S10>/Data Type Conversion3'
         */
        print_input(controller_B.Gain3, controller_B.Sum6 < 0.0 ? -(int32_T)
                    (uint32_T)-controller_B.Sum6 : (int32_T)(uint32_T)
                    controller_B.Sum6, controller_B.DataStoreRead7 < 0.0 ?
                    -(int32_T)(uint32_T)-controller_B.DataStoreRead7 : (int32_T)
                    (uint32_T)controller_B.DataStoreRead7);
      }

      /* MATLAB Function: '<S10>/MATLAB Function' */
      controller_getLocalTime(&controller_B.fracSecs, &controller_B.second,
        &controller_B.Sum6, &controller_B.DataStoreRead1_c,
        &controller_B.DataStoreRead7, &controller_B.c_tm_mon,
        &controller_B.c_tm_year, &rtb_Compare_n1);
      controller_B.fracSecs /= 1.0E+6;
      controller_B.check = (((((controller_B.c_tm_year + controller_B.c_tm_mon)
        + controller_B.DataStoreRead7) + controller_B.DataStoreRead1_c) +
        controller_B.Sum6) + controller_B.second) + controller_B.fracSecs;
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
          controller_B.c_tm_mon + 2.0) / 5.0)) + controller_B.DataStoreRead7) +
          60.0) - 719529.0;
        controller_B.d_data.im = 0.0;
        controller_B.d_data = controller_plus(controller_times
          (controller_B.d_data), (60.0 * controller_B.DataStoreRead1_c +
          controller_B.Sum6) * 60000.0);
        controller_B.d_data = controller_plus(controller_plus
          (controller_B.d_data, controller_B.second * 1000.0),
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
      controller_B.Sum6 = (controller_B.c_s.re + controller_B.c_s.im) / 8.64E+7;
      controller_B.DataStoreRead1_c = 0.0;
      controller_B.DataStoreRead7 = controller_B.b_c.re;
      if (controller_B.Sum6 != 0.0) {
        controller_B.DataStoreRead7 = controller_B.b_c.re + controller_B.Sum6;
        controller_B.DataStoreRead1_c = controller_B.Sum6 -
          (controller_B.DataStoreRead7 - controller_B.b_c.re);
      }

      if (rtIsNaN(controller_B.DataStoreRead1_c)) {
        controller_B.DataStoreRead1_c = 0.0;
      }

      controller_B.d_ahi.re = controller_B.DataStoreRead7;
      controller_B.d_ahi.im = controller_B.DataStoreRead1_c;
      controller_B.d_data = controller_minus(controller_B.d_data,
        controller_times(controller_floor(controller_B.d_ahi)));
      controller_B.b_c.re = controller_B.d_data.re / 1000.0;
      controller_B.t = controller_split(controller_B.b_c.re);
      controller_B.Sum6 = controller_B.b_c.re * 1000.0;
      controller_B.DataStoreRead1_c = (controller_B.t.re * 1000.0 -
        controller_B.Sum6) + controller_B.t.im * 1000.0;
      controller_B.DataStoreRead7 = controller_B.DataStoreRead1_c;
      trueCount = 0;
      if (rtIsNaN(controller_B.DataStoreRead1_c)) {
        trueCount = 1;
      }

      if (trueCount - 1 >= 0) {
        controller_B.DataStoreRead7 = 0.0;
      }

      controller_B.c_s.re = 0.0;
      controller_B.c_s.im = 0.0;
      if (controller_B.d_data.re != controller_B.Sum6) {
        controller_B.c_s = controller_two_diff(controller_B.d_data.re,
          controller_B.Sum6);
      }

      controller_B.c_s.re = (0.0 * controller_B.d_data.im + controller_B.c_s.re)
        - 0.0 * controller_B.DataStoreRead7;
      controller_B.c_s.im = (controller_B.c_s.im + controller_B.d_data.im) -
        controller_B.DataStoreRead7;
      controller_B.Sum6 = (controller_B.c_s.re + controller_B.c_s.im) / 1000.0;
      controller_B.DataStoreRead1_c = 0.0;
      controller_B.DataStoreRead7 = controller_B.b_c.re;
      if (controller_B.Sum6 != 0.0) {
        controller_B.DataStoreRead7 = controller_B.b_c.re + controller_B.Sum6;
        controller_B.DataStoreRead1_c = controller_B.Sum6 -
          (controller_B.DataStoreRead7 - controller_B.b_c.re);
      }

      if (rtIsNaN(controller_B.DataStoreRead1_c)) {
        controller_B.DataStoreRead1_c = 0.0;
      }

      controller_B.d_data.re = controller_B.DataStoreRead7;
      controller_B.d_data.im = controller_B.DataStoreRead1_c;
      controller_B.t = controller_floor(controller_B.d_data);
      controller_B.b_c = controller_minus(controller_B.d_data, controller_B.t);
      controller_B.Sum6 = controller_B.t.re + controller_B.t.im;
      if ((controller_B.Sum6 >= 0.0) && (controller_B.Sum6 <= 2.147483647E+9)) {
        trueCount = (int32_T)rt_roundd_snf(controller_B.Sum6);
        trueCount -= 3600 * div_s32(trueCount, 3600);
        controller_B.Sum6 = trueCount - 60 * div_s32(trueCount, 60);
      } else {
        controller_B.Sum6 -= floor((controller_B.Sum6 - floor(controller_B.Sum6 /
          3600.0) * 3600.0) / 60.0) * 60.0;
      }

      controller_B.DataStoreRead7 = (controller_B.b_c.re + controller_B.b_c.im)
        + controller_B.Sum6;
      if (controller_B.DataStoreRead7 == 60.0) {
        controller_B.DataStoreRead7 = 59.999999999999993;
      }

      /* Derivative: '<S10>/Derivative1' incorporates:
       *  Derivative: '<S10>/Derivative2'
       */
      controller_B.Sum6 = controller_M->Timing.t[0];
      if ((controller_DW.TimeStampA >= controller_B.Sum6) &&
          (controller_DW.TimeStampB >= controller_B.Sum6)) {
        /* Derivative: '<S10>/Derivative1' */
        controller_B.Derivative1 = 0.0;
      } else {
        controller_B.DataStoreRead1_c = controller_DW.TimeStampA;
        lastU = &controller_DW.LastUAtTimeA;
        if (controller_DW.TimeStampA < controller_DW.TimeStampB) {
          if (controller_DW.TimeStampB < controller_B.Sum6) {
            controller_B.DataStoreRead1_c = controller_DW.TimeStampB;
            lastU = &controller_DW.LastUAtTimeB;
          }
        } else if (controller_DW.TimeStampA >= controller_B.Sum6) {
          controller_B.DataStoreRead1_c = controller_DW.TimeStampB;
          lastU = &controller_DW.LastUAtTimeB;
        }

        /* Derivative: '<S10>/Derivative1' */
        controller_B.Derivative1 = (controller_B.Gain3 - *lastU) /
          (controller_B.Sum6 - controller_B.DataStoreRead1_c);
      }

      /* End of Derivative: '<S10>/Derivative1' */

      /* Derivative: '<S10>/Derivative2' */
      if ((controller_DW.TimeStampA_g >= controller_B.Sum6) &&
          (controller_DW.TimeStampB_j >= controller_B.Sum6)) {
        /* Derivative: '<S10>/Derivative2' */
        controller_B.Derivative2 = 0.0;
      } else {
        controller_B.DataStoreRead1_c = controller_DW.TimeStampA_g;
        lastU = &controller_DW.LastUAtTimeA_o;
        if (controller_DW.TimeStampA_g < controller_DW.TimeStampB_j) {
          if (controller_DW.TimeStampB_j < controller_B.Sum6) {
            controller_B.DataStoreRead1_c = controller_DW.TimeStampB_j;
            lastU = &controller_DW.LastUAtTimeB_o;
          }
        } else if (controller_DW.TimeStampA_g >= controller_B.Sum6) {
          controller_B.DataStoreRead1_c = controller_DW.TimeStampB_j;
          lastU = &controller_DW.LastUAtTimeB_o;
        }

        /* Derivative: '<S10>/Derivative2' */
        controller_B.Derivative2 = (controller_B.Derivative1 - *lastU) /
          (controller_B.Sum6 - controller_B.DataStoreRead1_c);
      }

      /* SignalConversion generated from: '<S10>/C Caller4' incorporates:
       *  MATLAB Function: '<S10>/MATLAB Function'
       */
      controller_B.TmpSignalConversionAtCCalle[0] = controller_B.DataStoreRead7;
      controller_B.TmpSignalConversionAtCCalle[1] = controller_B.Derivative1;
      controller_B.TmpSignalConversionAtCCalle[2] = controller_B.Derivative2;

      /* DataTypeConversion: '<S10>/Data Type Conversion2' incorporates:
       *  Constant: '<S10>/Constant2'
       */
      controller_B.Sum6 = floor(controller_P.Constant2_Value);
      if (rtIsNaN(controller_B.Sum6) || rtIsInf(controller_B.Sum6)) {
        controller_B.Sum6 = 0.0;
      } else {
        controller_B.Sum6 = fmod(controller_B.Sum6, 4.294967296E+9);
      }

      /* CCaller: '<S10>/C Caller4' incorporates:
       *  DataTypeConversion: '<S10>/Data Type Conversion2'
       */
      print_data(&controller_B.TmpSignalConversionAtCCalle[0], controller_B.Sum6
                 < 0.0 ? -(int32_T)(uint32_T)-controller_B.Sum6 : (int32_T)
                 (uint32_T)controller_B.Sum6);

      /* Sum: '<S10>/Sum1' incorporates:
       *  Constant: '<S10>/Constant3'
       *  Gain: '<S10>/Gain'
       *  Gain: '<S10>/Gain2'
       *  Sum: '<S10>/Sum'
       */
      controller_B.Saturation = (controller_P.Constant3_Value -
        controller_B.Gain3) * controller_P.Gain_Gain_k -
        controller_P.Gain2_Gain_m * controller_B.Derivative1;

      /* Saturate: '<S10>/Saturation' */
      if (controller_B.Saturation > controller_P.Saturation_UpperSat_f) {
        /* Sum: '<S10>/Sum1' incorporates:
         *  Saturate: '<S10>/Saturation'
         */
        controller_B.Saturation = controller_P.Saturation_UpperSat_f;
      } else if (controller_B.Saturation < controller_P.Saturation_LowerSat_l) {
        /* Sum: '<S10>/Sum1' incorporates:
         *  Saturate: '<S10>/Saturation'
         */
        controller_B.Saturation = controller_P.Saturation_LowerSat_l;
      }

      /* End of Saturate: '<S10>/Saturation' */

      /* DataTypeConversion: '<S28>/Data Type Conversion1' incorporates:
       *  Constant: '<S10>/Constant'
       */
      controller_B.Sum6 = floor(controller_P.Constant_Value_i);
      if (rtIsNaN(controller_B.Sum6) || rtIsInf(controller_B.Sum6)) {
        controller_B.Sum6 = 0.0;
      } else {
        controller_B.Sum6 = fmod(controller_B.Sum6, 4.294967296E+9);
      }

      /* CCaller: '<S28>/C Caller3' incorporates:
       *  DataStoreRead: '<S28>/Data Store Read2'
       *  DataTypeConversion: '<S28>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, controller_B.Sum6 < 0.0 ? -(int32_T)
                (uint32_T)-controller_B.Sum6 : (int32_T)(uint32_T)
                controller_B.Sum6, controller_B.Saturation);
    }

    /* End of Outputs for SubSystem: '<Root>/Main Control' */

    /* RelationalOperator: '<S5>/Compare' incorporates:
     *  Constant: '<S5>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read6'
     */
    rtb_Compare_n1 = (controller_DW.state ==
                      controller_P.CompareToConstant7_const);

    /* Outputs for Triggered SubSystem: '<Root>/Exit Control' incorporates:
     *  TriggerPort: '<S6>/Trigger'
     */
    if (rtb_Compare_n1 && (controller_PrevZCX.ExitControl_Trig_ZCE != POS_ZCSIG))
    {
      /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
       *  DataStoreRead: '<S6>/Data Store Read7'
       */
      controller_B.Sum6 = floor(controller_DW.num_motors);
      if (rtIsNaN(controller_B.Sum6) || rtIsInf(controller_B.Sum6)) {
        controller_B.Sum6 = 0.0;
      } else {
        controller_B.Sum6 = fmod(controller_B.Sum6, 4.294967296E+9);
      }

      /* CCaller: '<S6>/C Caller1' incorporates:
       *  DataStoreRead: '<S6>/Data Store Read1'
       *  DataTypeConversion: '<S6>/Data Type Conversion'
       */
      stop_motor(controller_DW.pdo_id, controller_B.Sum6 < 0.0 ? -(int32_T)
                 (uint32_T)-controller_B.Sum6 : (int32_T)(uint32_T)
                 controller_B.Sum6);

      /* CCaller: '<S6>/C Caller4' */
      close_datalog();
    }

    controller_PrevZCX.ExitControl_Trig_ZCE = rtb_Compare_n1;

    /* End of Outputs for SubSystem: '<Root>/Exit Control' */
  }

  {
    real_T *lastU;

    /* Update for Enabled SubSystem: '<Root>/Home1' incorporates:
     *  EnablePort: '<S7>/Enable'
     */
    if (controller_DW.Home1_MODE) {
      /* Update for Delay: '<S7>/Delay' */
      controller_DW.Delay_DSTATE_n = controller_B.Switch_g;

      /* Update for Derivative: '<S7>/Derivative' */
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

      *lastU = controller_B.Gain2_o;

      /* End of Update for Derivative: '<S7>/Derivative' */
    }

    /* End of Update for SubSystem: '<Root>/Home1' */

    /* Update for Enabled SubSystem: '<Root>/Home2' incorporates:
     *  EnablePort: '<S8>/Enable'
     */
    if (controller_DW.Home2_MODE) {
      /* Update for Delay: '<S8>/Delay' */
      controller_DW.Delay_DSTATE = controller_B.Switch;

      /* Update for Derivative: '<S8>/Derivative' */
      if (controller_DW.TimeStampA_gc == (rtInf)) {
        controller_DW.TimeStampA_gc = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeA_f;
      } else if (controller_DW.TimeStampB_h == (rtInf)) {
        controller_DW.TimeStampB_h = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeB_c;
      } else if (controller_DW.TimeStampA_gc < controller_DW.TimeStampB_h) {
        controller_DW.TimeStampA_gc = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeA_f;
      } else {
        controller_DW.TimeStampB_h = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeB_c;
      }

      *lastU = controller_B.Gain2;

      /* End of Update for Derivative: '<S8>/Derivative' */
    }

    /* End of Update for SubSystem: '<Root>/Home2' */

    /* Update for Enabled SubSystem: '<Root>/Main Control' incorporates:
     *  EnablePort: '<S10>/Enable'
     */
    if (controller_DW.MainControl_MODE) {
      /* Update for Delay: '<S10>/Delay1' */
      controller_DW.Delay1_DSTATE = controller_B.Switch2;

      /* Update for Derivative: '<S10>/Derivative1' */
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

      *lastU = controller_B.Gain3;

      /* End of Update for Derivative: '<S10>/Derivative1' */

      /* Update for Derivative: '<S10>/Derivative2' */
      if (controller_DW.TimeStampA_g == (rtInf)) {
        controller_DW.TimeStampA_g = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeA_o;
      } else if (controller_DW.TimeStampB_j == (rtInf)) {
        controller_DW.TimeStampB_j = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeB_o;
      } else if (controller_DW.TimeStampA_g < controller_DW.TimeStampB_j) {
        controller_DW.TimeStampA_g = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeA_o;
      } else {
        controller_DW.TimeStampB_j = controller_M->Timing.t[0];
        lastU = &controller_DW.LastUAtTimeB_o;
      }

      *lastU = controller_B.Derivative1;

      /* End of Update for Derivative: '<S10>/Derivative2' */
    }

    /* End of Update for SubSystem: '<Root>/Main Control' */
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
    controller_DW.objisempty_f = true;
    controller_DW.obj_l.SampleTime = controller_P.DigitalRead2_SampleTime;
    obj = &controller_DW.obj_l;
    controller_DW.obj_l.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(49, 0);
    controller_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read3' */
    controller_DW.obj.matlabCodegenIsDeleted = false;
    controller_DW.objisempty = true;
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

  controller_PrevZCX.ExitControl_Trig_ZCE = POS_ZCSIG;
  controller_PrevZCX.StopMotor1_n.StopMotor1_Trig_ZCE = POS_ZCSIG;
  controller_PrevZCX.StopMotor1.StopMotor1_Trig_ZCE = POS_ZCSIG;

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home1' */
  /* InitializeConditions for Delay: '<S7>/Delay' */
  controller_DW.Delay_DSTATE_n = controller_P.Delay_InitialCondition;

  /* InitializeConditions for Derivative: '<S7>/Derivative' */
  controller_DW.TimeStampA_f = (rtInf);
  controller_DW.TimeStampB_o = (rtInf);

  /* End of SystemInitialize for SubSystem: '<Root>/Home1' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Home2' */
  /* InitializeConditions for Delay: '<S8>/Delay' */
  controller_DW.Delay_DSTATE = controller_P.Delay_InitialCondition_k;

  /* InitializeConditions for Derivative: '<S8>/Derivative' */
  controller_DW.TimeStampA_gc = (rtInf);
  controller_DW.TimeStampB_h = (rtInf);

  /* End of SystemInitialize for SubSystem: '<Root>/Home2' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Main Control' */
  /* InitializeConditions for Delay: '<S10>/Delay1' */
  controller_DW.Delay1_DSTATE = controller_P.Delay1_InitialCondition;

  /* InitializeConditions for Derivative: '<S10>/Derivative1' */
  controller_DW.TimeStampA = (rtInf);
  controller_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<S10>/Derivative2' */
  controller_DW.TimeStampA_g = (rtInf);
  controller_DW.TimeStampB_j = (rtInf);

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
}
