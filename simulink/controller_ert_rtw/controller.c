/*
 * controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.198
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Jul 21 17:05:11 2023
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
#include <stdio.h>
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
static int8_T controller_filedata(void);
static int8_T controller_cfopen(const char_T *cfilename, const char_T
  *cpermission);
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
  if ((controller_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.1s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[2] = 0;
  }

  (controller_M->Timing.TaskCounters.TID[3])++;
  if ((controller_M->Timing.TaskCounters.TID[3]) > 99999) {/* Sample time: [100.0s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[3] = 0;
  }

  (controller_M->Timing.TaskCounters.TID[4])++;
  if ((controller_M->Timing.TaskCounters.TID[4]) > 9999999) {/* Sample time: [10000.0s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[4] = 0;
  }
}

/*
 * Output and update for trigger system:
 *    '<S7>/Stop Motor'
 *    '<S9>/Stop Motor'
 */
void controller_StopMotor(boolean_T rtu_Trigger, const int32_T *rtd_cfg_id,
  ZCE_StopMotor_controller_T *localZCE)
{
  int32_T rtb_DataStoreRead1_b;

  /* Outputs for Triggered SubSystem: '<S7>/Stop Motor' incorporates:
   *  TriggerPort: '<S14>/Trigger'
   */
  if (rtu_Trigger && (localZCE->StopMotor_Trig_ZCE_p != POS_ZCSIG)) {
    /* DataStoreRead: '<S14>/Data Store Read1' */
    rtb_DataStoreRead1_b = *rtd_cfg_id;

    /* CCaller: '<S14>/C Caller4' */
    stop_motor(rtb_DataStoreRead1_b);
  }

  localZCE->StopMotor_Trig_ZCE_p = rtu_Trigger;

  /* End of Outputs for SubSystem: '<S7>/Stop Motor' */
}

/*
 * Output and update for trigger system:
 *    '<S8>/Stop Motor'
 *    '<S10>/Stop Motor'
 */
void controller_StopMotor_p(boolean_T rtu_Trigger, const int32_T *rtd_cfg_id,
  real_T *rtd_enc1, const int32_T *rtd_pdo_id, P_StopMotor_controller_a_T
  *localP, ZCE_StopMotor_controller_a_T *localZCE)
{
  real_T rtb_CCaller1_j[2];
  real_T tmp;
  int32_T rtb_DataStoreRead2_j;

  /* Outputs for Triggered SubSystem: '<S8>/Stop Motor' incorporates:
   *  TriggerPort: '<S18>/Trigger'
   */
  if (rtu_Trigger && (localZCE->StopMotor_Trig_ZCE != POS_ZCSIG)) {
    /* DataStoreRead: '<S18>/Data Store Read2' */
    rtb_DataStoreRead2_j = *rtd_pdo_id;

    /* DataTypeConversion: '<S18>/Data Type Conversion7' incorporates:
     *  Constant: '<S18>/Constant7'
     */
    tmp = floor(localP->Constant7_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    /* CCaller: '<S18>/C Caller1' incorporates:
     *  DataTypeConversion: '<S18>/Data Type Conversion7'
     */
    get_encoder(rtb_DataStoreRead2_j, tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
                (int32_T)(uint32_T)tmp, &rtb_CCaller1_j[0]);

    /* DataStoreWrite: '<S18>/Data Store Write1' */
    *rtd_enc1 = rtb_CCaller1_j[0];

    /* DataStoreRead: '<S18>/Data Store Read1' */
    rtb_DataStoreRead2_j = *rtd_cfg_id;

    /* CCaller: '<S18>/C Caller4' */
    stop_motor(rtb_DataStoreRead2_j);
  }

  localZCE->StopMotor_Trig_ZCE = rtu_Trigger;

  /* End of Outputs for SubSystem: '<S8>/Stop Motor' */
}

/* Function for MATLAB Function: '<S12>/MATLAB Function' */
static int8_T controller_filedata(void)
{
  int32_T k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (controller_DW.eml_openfiles[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<S12>/MATLAB Function' */
static int8_T controller_cfopen(const char_T *cfilename, const char_T
  *cpermission)
{
  FILE* filestar;
  int32_T tmp;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = controller_filedata();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      controller_DW.eml_openfiles[j - 1] = filestar;
      tmp = j + 2;
      if (j + 2 > 127) {
        tmp = 127;
      }

      fileid = (int8_T)tmp;
    }
  }

  return fileid;
}

/* Model step function */
void controller_step(void)
{
  /* local block i/o variables */
  boolean_T rtb_Compare_ne;
  boolean_T rtb_Compare_br;
  boolean_T rtb_Compare_d;
  boolean_T rtb_Compare_h;
  real_T tmp;
  boolean_T rtb_Compare_a;
  if (controller_M->Timing.TaskCounters.TID[2] == 0) {
    /* MATLABSystem: '<Root>/Digital Read' */
    if (controller_DW.obj_b.SampleTime != controller_P.DigitalRead_SampleTime) {
      controller_DW.obj_b.SampleTime = controller_P.DigitalRead_SampleTime;
    }

    /* DataStoreWrite: '<Root>/Data Store Write' incorporates:
     *  MATLABSystem: '<Root>/Digital Read'
     */
    controller_DW.LS1 = MW_digitalIO_read
      (controller_DW.obj_b.MW_DIGITALIO_HANDLE);

    /* MATLABSystem: '<Root>/Digital Read1' */
    if (controller_DW.obj.SampleTime != controller_P.DigitalRead1_SampleTime) {
      controller_DW.obj.SampleTime = controller_P.DigitalRead1_SampleTime;
    }

    /* DataStoreWrite: '<Root>/Data Store Write1' incorporates:
     *  MATLABSystem: '<Root>/Digital Read1'
     */
    controller_DW.LS2 = MW_digitalIO_read(controller_DW.obj.MW_DIGITALIO_HANDLE);
  }

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
    /* RelationalOperator: '<S13>/Compare' incorporates:
     *  Constant: '<S13>/Constant'
     *  DataStoreRead: '<S7>/Data Store Read'
     */
    rtb_Compare_ne = (controller_DW.LS1 ==
                      controller_P.CompareToConstant_const_b);

    /* Switch: '<S15>/Switch' */
    if (rtb_Compare_ne) {
      /* DataStoreWrite: '<S15>/Data Store Write' incorporates:
       *  Constant: '<S7>/Constant'
       */
      controller_DW.state = controller_P.Constant_Value;
    }

    /* End of Switch: '<S15>/Switch' */
    if (controller_M->Timing.TaskCounters.TID[2] == 0) {
      /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant'
       */
      tmp = floor(controller_P.Constant_Value_c);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
       *  Constant: '<S7>/Constant2'
       */
      controller_B.d = floor(controller_P.Constant2_Value);
      if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
        controller_B.d = 0.0;
      } else {
        controller_B.d = fmod(controller_B.d, 4.294967296E+9);
      }

      /* CCaller: '<S7>/C Caller1' incorporates:
       *  DataTypeConversion: '<S7>/Data Type Conversion'
       *  DataTypeConversion: '<S7>/Data Type Conversion1'
       */
      print_input(tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp,
                  controller_B.d < 0.0 ? -(int32_T)(uint32_T)-controller_B.d :
                  (int32_T)(uint32_T)controller_B.d);

      /* DataTypeConversion: '<S16>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant'
       */
      tmp = floor(controller_P.Constant_Value_c);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      /* CCaller: '<S16>/C Caller3' incorporates:
       *  Constant: '<Root>/Constant1'
       *  DataStoreRead: '<S16>/Data Store Read2'
       *  DataTypeConversion: '<S16>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
                (int32_T)(uint32_T)tmp, controller_P.Constant1_Value_i);
    }

    /* Clock: '<S7>/Clock' */
    controller_B.Clock = controller_M->Timing.t[0];
    if (controller_M->Timing.TaskCounters.TID[2] == 0) {
      /* SignalConversion generated from: '<S7>/C Caller4' incorporates:
       *  Constant: '<S7>/Constant4'
       */
      controller_B.TmpSignalConversionAtCCalle[0] = controller_B.Clock;
      controller_B.TmpSignalConversionAtCCalle[1] = controller_P.Constant4_Value;

      /* DataTypeConversion: '<S7>/Data Type Conversion2' incorporates:
       *  Constant: '<S7>/Constant1'
       */
      tmp = floor(controller_P.Constant1_Value);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      /* CCaller: '<S7>/C Caller4' incorporates:
       *  DataTypeConversion: '<S7>/Data Type Conversion2'
       */
      print_data(&controller_B.TmpSignalConversionAtCCalle[0], tmp < 0.0 ?
                 -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp);
    }

    /* Outputs for Triggered SubSystem: '<S7>/Stop Motor' */
    controller_StopMotor(rtb_Compare_ne, &controller_DW.cfg_id,
                         &controller_PrevZCX.StopMotor);

    /* End of Outputs for SubSystem: '<S7>/Stop Motor' */
  }

  /* End of Outputs for SubSystem: '<Root>/Home1' */
  if (controller_M->Timing.TaskCounters.TID[3] == 0) {
    /* Outputs for Enabled SubSystem: '<Root>/Initialize' incorporates:
     *  EnablePort: '<S11>/Enable'
     */
    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read1'
     */
    if (controller_DW.state == controller_P.CompareToConstant2_const) {
      controller_DW.Initialize_MODE = true;
      if (controller_M->Timing.TaskCounters.TID[4] == 0) {
        /* CCaller: '<S11>/C Caller5' incorporates:
         *  Constant: '<S11>/Constant1'
         */
        init_can(controller_P.Constant1_Value_f, controller_P.Constant1_Value_f,
                 &controller_B.CCaller5[0]);

        /* DataStoreWrite: '<S11>/Data Store Write' */
        controller_DW.cfg_id = controller_B.CCaller5[0];

        /* DataStoreWrite: '<S11>/Data Store Write2' */
        controller_DW.pdo_id = controller_B.CCaller5[1];

        /* RelationalOperator: '<S29>/Compare' incorporates:
         *  Constant: '<S29>/Constant'
         */
        rtb_Compare_a = (controller_B.CCaller5[1] !=
                         controller_P.CompareToConstant_const);

        /* Switch: '<S30>/Switch' */
        if (rtb_Compare_a) {
          /* DataStoreWrite: '<S30>/Data Store Write' incorporates:
           *  Constant: '<S11>/Constant'
           */
          controller_DW.state = controller_P.Constant_Value_d;
        }

        /* End of Switch: '<S30>/Switch' */

        /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
         *  Constant: '<S11>/Constant2'
         */
        tmp = floor(controller_P.Constant2_Value_l);
        if (rtIsNaN(tmp) || rtIsInf(tmp)) {
          tmp = 0.0;
        } else {
          tmp = fmod(tmp, 4.294967296E+9);
        }

        /* CCaller: '<S11>/C Caller1' incorporates:
         *  DataTypeConversion: '<S11>/Data Type Conversion'
         */
        print_input(controller_B.CCaller5[0], tmp < 0.0 ? -(int32_T)(uint32_T)
                    -tmp : (int32_T)(uint32_T)tmp);

        /* DataTypeConversion: '<S11>/Data Type Conversion1' incorporates:
         *  Constant: '<S11>/Constant3'
         */
        tmp = floor(controller_P.Constant3_Value);
        if (rtIsNaN(tmp) || rtIsInf(tmp)) {
          tmp = 0.0;
        } else {
          tmp = fmod(tmp, 4.294967296E+9);
        }

        /* CCaller: '<S11>/C Caller2' incorporates:
         *  DataTypeConversion: '<S11>/Data Type Conversion1'
         */
        print_input(controller_B.CCaller5[1], tmp < 0.0 ? -(int32_T)(uint32_T)
                    -tmp : (int32_T)(uint32_T)tmp);
      }

      if (controller_M->Timing.TaskCounters.TID[3] == 0) {
        /* CCaller: '<S11>/C Caller3' */
        init_datalog();
      }
    } else {
      controller_DW.Initialize_MODE = false;
    }

    /* End of RelationalOperator: '<S2>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Initialize' */
  }

  if (controller_M->Timing.TaskCounters.TID[2] == 0) {
    /* Outputs for Enabled SubSystem: '<Root>/Home2' incorporates:
     *  EnablePort: '<S8>/Enable'
     */
    /* RelationalOperator: '<S3>/Compare' incorporates:
     *  Constant: '<S3>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read3'
     */
    if (controller_DW.state == controller_P.CompareToConstant3_const) {
      /* RelationalOperator: '<S17>/Compare' incorporates:
       *  Constant: '<S17>/Constant'
       *  DataStoreRead: '<S8>/Data Store Read'
       */
      rtb_Compare_h = (controller_DW.LS2 ==
                       controller_P.CompareToConstant_const_f);

      /* Switch: '<S19>/Switch' */
      if (rtb_Compare_h) {
        /* DataStoreWrite: '<S19>/Data Store Write' incorporates:
         *  Constant: '<S8>/Constant'
         */
        controller_DW.state = controller_P.Constant_Value_i;
      }

      /* End of Switch: '<S19>/Switch' */

      /* DataTypeConversion: '<S8>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      tmp = floor(controller_P.Constant2_Value_m);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
       *  Constant: '<S8>/Constant2'
       */
      controller_B.d = floor(controller_P.Constant2_Value_c);
      if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
        controller_B.d = 0.0;
      } else {
        controller_B.d = fmod(controller_B.d, 4.294967296E+9);
      }

      /* CCaller: '<S8>/C Caller1' incorporates:
       *  DataTypeConversion: '<S8>/Data Type Conversion'
       *  DataTypeConversion: '<S8>/Data Type Conversion1'
       */
      print_input(tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp,
                  controller_B.d < 0.0 ? -(int32_T)(uint32_T)-controller_B.d :
                  (int32_T)(uint32_T)controller_B.d);

      /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      tmp = floor(controller_P.Constant2_Value_m);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      /* CCaller: '<S20>/C Caller3' incorporates:
       *  Constant: '<Root>/Constant3'
       *  DataStoreRead: '<S20>/Data Store Read2'
       *  DataTypeConversion: '<S20>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
                (int32_T)(uint32_T)tmp, controller_P.Constant3_Value_j);

      /* Outputs for Triggered SubSystem: '<S8>/Stop Motor' */
      controller_StopMotor_p(rtb_Compare_h, &controller_DW.cfg_id,
        &controller_DW.enc1, &controller_DW.pdo_id, &controller_P.StopMotor_p,
        &controller_PrevZCX.StopMotor_p);

      /* End of Outputs for SubSystem: '<S8>/Stop Motor' */

      /* CCaller: '<S8>/C Caller4' */
      close_datalog();
    }

    /* End of RelationalOperator: '<S3>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Home2' */

    /* Outputs for Enabled SubSystem: '<Root>/Main Control' incorporates:
     *  EnablePort: '<S12>/Enable'
     */
    /* RelationalOperator: '<S4>/Compare' incorporates:
     *  Constant: '<S4>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read2'
     */
    if (controller_DW.state == controller_P.CompareToConstant4_const) {
      /* DataTypeConversion: '<S12>/Data Type Conversion7' incorporates:
       *  Constant: '<S12>/Constant7'
       */
      tmp = floor(controller_P.Constant7_Value);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      /* CCaller: '<S12>/C Caller1' incorporates:
       *  DataStoreRead: '<S12>/Data Store Read2'
       *  DataTypeConversion: '<S12>/Data Type Conversion7'
       */
      get_encoder(controller_DW.pdo_id, tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
                  (int32_T)(uint32_T)tmp, &controller_B.CCaller1[0]);

      /* DataTypeConversion: '<S32>/Data Type Conversion1' incorporates:
       *  Constant: '<S12>/Constant'
       */
      tmp = floor(controller_P.Constant_Value_iy);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      /* CCaller: '<S32>/C Caller3' incorporates:
       *  DataStoreRead: '<S32>/Data Store Read2'
       *  DataTypeConversion: '<S32>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
                (int32_T)(uint32_T)tmp, 0.0);

      /* DataTypeConversion: '<S33>/Data Type Conversion1' incorporates:
       *  Constant: '<S12>/Constant1'
       */
      tmp = floor(controller_P.Constant1_Value_m);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      /* CCaller: '<S33>/C Caller3' incorporates:
       *  DataStoreRead: '<S33>/Data Store Read2'
       *  DataTypeConversion: '<S33>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
                (int32_T)(uint32_T)tmp, 0.0);

      /* MATLAB Function: '<S12>/MATLAB Function' */
      controller_cfopen("test_datalog.txt", "rb");
    }

    /* End of RelationalOperator: '<S4>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Main Control' */

    /* Outputs for Enabled SubSystem: '<Root>/Home3' incorporates:
     *  EnablePort: '<S9>/Enable'
     */
    /* RelationalOperator: '<S5>/Compare' incorporates:
     *  Constant: '<S5>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read4'
     */
    if (controller_DW.state == controller_P.CompareToConstant5_const) {
      /* RelationalOperator: '<S21>/Compare' incorporates:
       *  Constant: '<S21>/Constant'
       *  DataStoreRead: '<S9>/Data Store Read'
       */
      rtb_Compare_d = (controller_DW.LS1 ==
                       controller_P.CompareToConstant_const_n);

      /* Switch: '<S23>/Switch' */
      if (rtb_Compare_d) {
        /* DataStoreWrite: '<S23>/Data Store Write' incorporates:
         *  Constant: '<S9>/Constant'
         */
        controller_DW.state = controller_P.Constant_Value_o;
      }

      /* End of Switch: '<S23>/Switch' */

      /* DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant8'
       */
      tmp = floor(controller_P.Constant8_Value);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
       *  Constant: '<S9>/Constant2'
       */
      controller_B.d = floor(controller_P.Constant2_Value_b);
      if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
        controller_B.d = 0.0;
      } else {
        controller_B.d = fmod(controller_B.d, 4.294967296E+9);
      }

      /* CCaller: '<S9>/C Caller1' incorporates:
       *  DataTypeConversion: '<S9>/Data Type Conversion'
       *  DataTypeConversion: '<S9>/Data Type Conversion1'
       */
      print_input(tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp,
                  controller_B.d < 0.0 ? -(int32_T)(uint32_T)-controller_B.d :
                  (int32_T)(uint32_T)controller_B.d);

      /* DataTypeConversion: '<S24>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant8'
       */
      tmp = floor(controller_P.Constant8_Value);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      /* CCaller: '<S24>/C Caller3' incorporates:
       *  Constant: '<Root>/Constant9'
       *  DataStoreRead: '<S24>/Data Store Read2'
       *  DataTypeConversion: '<S24>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
                (int32_T)(uint32_T)tmp, controller_P.Constant9_Value);

      /* Outputs for Triggered SubSystem: '<S9>/Stop Motor' */
      controller_StopMotor(rtb_Compare_d, &controller_DW.cfg_id,
                           &controller_PrevZCX.StopMotor_d);

      /* End of Outputs for SubSystem: '<S9>/Stop Motor' */
    }

    /* End of RelationalOperator: '<S5>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Home3' */

    /* Outputs for Enabled SubSystem: '<Root>/Home4' incorporates:
     *  EnablePort: '<S10>/Enable'
     */
    /* RelationalOperator: '<S6>/Compare' incorporates:
     *  Constant: '<S6>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read5'
     */
    if (controller_DW.state == controller_P.CompareToConstant6_const) {
      /* RelationalOperator: '<S25>/Compare' incorporates:
       *  Constant: '<S25>/Constant'
       *  DataStoreRead: '<S10>/Data Store Read'
       */
      rtb_Compare_br = (controller_DW.LS2 ==
                        controller_P.CompareToConstant_const_m);

      /* Switch: '<S27>/Switch' */
      if (rtb_Compare_br) {
        /* DataStoreWrite: '<S27>/Data Store Write' incorporates:
         *  Constant: '<S10>/Constant'
         */
        controller_DW.state = controller_P.Constant_Value_a;
      }

      /* End of Switch: '<S27>/Switch' */

      /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant10'
       */
      tmp = floor(controller_P.Constant10_Value);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
       *  Constant: '<S10>/Constant2'
       */
      controller_B.d = floor(controller_P.Constant2_Value_f);
      if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
        controller_B.d = 0.0;
      } else {
        controller_B.d = fmod(controller_B.d, 4.294967296E+9);
      }

      /* CCaller: '<S10>/C Caller1' incorporates:
       *  DataTypeConversion: '<S10>/Data Type Conversion'
       *  DataTypeConversion: '<S10>/Data Type Conversion1'
       */
      print_input(tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp,
                  controller_B.d < 0.0 ? -(int32_T)(uint32_T)-controller_B.d :
                  (int32_T)(uint32_T)controller_B.d);

      /* DataTypeConversion: '<S28>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant10'
       */
      tmp = floor(controller_P.Constant10_Value);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      /* CCaller: '<S28>/C Caller3' incorporates:
       *  Constant: '<Root>/Constant11'
       *  DataStoreRead: '<S28>/Data Store Read2'
       *  DataTypeConversion: '<S28>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
                (int32_T)(uint32_T)tmp, controller_P.Constant11_Value);

      /* Outputs for Triggered SubSystem: '<S10>/Stop Motor' */
      controller_StopMotor_p(rtb_Compare_br, &controller_DW.cfg_id,
        &controller_DW.enc1, &controller_DW.pdo_id, &controller_P.StopMotor_p0,
        &controller_PrevZCX.StopMotor_p0);

      /* End of Outputs for SubSystem: '<S10>/Stop Motor' */
    }

    /* End of RelationalOperator: '<S6>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Home4' */
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

    /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
    controller_DW.enc2 = controller_P.DataStoreMemory5_InitialValue;

    /* Start for MATLABSystem: '<Root>/Digital Read' */
    controller_DW.obj_b.matlabCodegenIsDeleted = false;
    controller_DW.objisempty_g = true;
    controller_DW.obj_b.SampleTime = controller_P.DigitalRead_SampleTime;
    obj = &controller_DW.obj_b;
    controller_DW.obj_b.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(113, 0);
    controller_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read1' */
    controller_DW.obj.matlabCodegenIsDeleted = false;
    controller_DW.objisempty = true;
    controller_DW.obj.SampleTime = controller_P.DigitalRead1_SampleTime;
    obj = &controller_DW.obj;
    controller_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(116, 0);
    controller_DW.obj.isSetupComplete = true;

    /* Start for Enabled SubSystem: '<Root>/Home1' */
    controller_DW.Home1_MODE = false;

    /* End of Start for SubSystem: '<Root>/Home1' */

    /* Start for Enabled SubSystem: '<Root>/Initialize' */
    controller_DW.Initialize_MODE = false;

    /* End of Start for SubSystem: '<Root>/Initialize' */

    /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
    controller_DW.state = controller_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    controller_DW.LS1 = controller_P.DataStoreMemory1_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    controller_DW.enc1 = controller_P.DataStoreMemory2_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
    controller_DW.LS2 = controller_P.DataStoreMemory3_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
    controller_DW.pdo_id = controller_P.DataStoreMemory4_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
    controller_DW.cfg_id = controller_P.DataStoreMemory6_InitialValue;
  }

  controller_PrevZCX.StopMotor_p0.StopMotor_Trig_ZCE = POS_ZCSIG;
  controller_PrevZCX.StopMotor_d.StopMotor_Trig_ZCE_p = POS_ZCSIG;
  controller_PrevZCX.StopMotor_p.StopMotor_Trig_ZCE = POS_ZCSIG;
  controller_PrevZCX.StopMotor.StopMotor_Trig_ZCE_p = POS_ZCSIG;

  {
    FILE* b_a;
    int32_T i;

    /* SystemInitialize for Enabled SubSystem: '<Root>/Main Control' */
    /* SystemInitialize for MATLAB Function: '<S12>/MATLAB Function' */
    b_a = NULL;
    for (i = 0; i < 20; i++) {
      controller_DW.eml_openfiles[i] = b_a;
    }

    /* End of SystemInitialize for MATLAB Function: '<S12>/MATLAB Function' */
    /* End of SystemInitialize for SubSystem: '<Root>/Main Control' */
  }
}

/* Model terminate function */
void controller_terminate(void)
{
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
  if (!controller_DW.obj.matlabCodegenIsDeleted) {
    controller_DW.obj.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj.isInitialized == 1) &&
        controller_DW.obj.isSetupComplete) {
      MW_digitalIO_close(controller_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read1' */
}
