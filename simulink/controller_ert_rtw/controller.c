/*
 * controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.189
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Jul 21 15:36:32 2023
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
static int32_T controller_cfclose(real_T fid);
static int8_T controller_filedata_h(void);
static int8_T controller_cfopen_d(const char_T *cfilename, const char_T
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
  (controller_M->Timing.TaskCounters.TID[1])++;
  if ((controller_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[1] = 0;
  }

  (controller_M->Timing.TaskCounters.TID[2])++;
  if ((controller_M->Timing.TaskCounters.TID[2]) > 9999999) {/* Sample time: [10000.0s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * Output and update for enable system:
 *    '<Root>/Home1'
 *    '<Root>/Home3'
 */
void controller_Home1(boolean_T rtu_Enable, real_T rtu_motor_id, real_T
                      rtu_homing_torque, const boolean_T *rtd_LS1, const int32_T
                      *rtd_cfg_id, const int32_T *rtd_pdo_id, real_T *rtd_state,
                      P_Home1_controller_T *localP, ZCE_Home1_controller_T
                      *localZCE)
{
  real_T rtb_Switch_c;
  real_T tmp;
  real_T tmp_0;
  int32_T rtb_DataStoreRead1_b;
  boolean_T rtb_DataStoreRead_o;
  boolean_T tmp_1;
  boolean_T tmp_2;

  /* Outputs for Enabled SubSystem: '<Root>/Home1' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (rtu_Enable) {
    /* DataStoreRead: '<S7>/Data Store Read' */
    rtb_DataStoreRead_o = *rtd_LS1;

    /* RelationalOperator: '<S13>/Compare' incorporates:
     *  Constant: '<S13>/Constant'
     */
    rtb_DataStoreRead_o = (rtb_DataStoreRead_o ==
      localP->CompareToConstant_const);

    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S7>/Constant'
     */
    if (rtb_DataStoreRead_o) {
      rtb_Switch_c = localP->Constant_Value;
    } else {
      /* DataStoreRead: '<S15>/Data Store Read' */
      rtb_Switch_c = *rtd_state;
    }

    /* End of Switch: '<S15>/Switch' */

    /* DataStoreWrite: '<S15>/Data Store Write' */
    *rtd_state = rtb_Switch_c;

    /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
     *  DataTypeConversion: '<S16>/Data Type Conversion1'
     */
    rtb_Switch_c = floor(rtu_motor_id);
    tmp_1 = rtIsNaN(rtb_Switch_c);
    tmp_2 = rtIsInf(rtb_Switch_c);
    if (tmp_1 || tmp_2) {
      tmp = 0.0;
    } else {
      tmp = fmod(rtb_Switch_c, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
     *  Constant: '<S7>/Constant2'
     */
    tmp_0 = floor(localP->Constant2_Value);
    if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
      tmp_0 = 0.0;
    } else {
      tmp_0 = fmod(tmp_0, 4.294967296E+9);
    }

    /* CCaller: '<S7>/C Caller1' incorporates:
     *  DataTypeConversion: '<S7>/Data Type Conversion'
     *  DataTypeConversion: '<S7>/Data Type Conversion1'
     */
    print_input(tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp,
                tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 : (int32_T)(uint32_T)
                tmp_0);

    /* DataStoreRead: '<S16>/Data Store Read2' */
    rtb_DataStoreRead1_b = *rtd_pdo_id;

    /* DataTypeConversion: '<S16>/Data Type Conversion1' */
    if (tmp_1 || tmp_2) {
      rtb_Switch_c = 0.0;
    } else {
      rtb_Switch_c = fmod(rtb_Switch_c, 4.294967296E+9);
    }

    /* CCaller: '<S16>/C Caller3' incorporates:
     *  DataTypeConversion: '<S16>/Data Type Conversion1'
     */
    set_motor(rtb_DataStoreRead1_b, rtb_Switch_c < 0.0 ? -(int32_T)(uint32_T)
              -rtb_Switch_c : (int32_T)(uint32_T)rtb_Switch_c, rtu_homing_torque);

    /* Outputs for Triggered SubSystem: '<S7>/Stop Motor' incorporates:
     *  TriggerPort: '<S14>/Trigger'
     */
    if (rtb_DataStoreRead_o && (localZCE->StopMotor_Trig_ZCE_p != POS_ZCSIG)) {
      /* DataStoreRead: '<S14>/Data Store Read1' */
      rtb_DataStoreRead1_b = *rtd_cfg_id;

      /* CCaller: '<S14>/C Caller4' */
      stop_motor(rtb_DataStoreRead1_b);
    }

    localZCE->StopMotor_Trig_ZCE_p = rtb_DataStoreRead_o;

    /* End of Outputs for SubSystem: '<S7>/Stop Motor' */
  }

  /* End of Outputs for SubSystem: '<Root>/Home1' */
}

/*
 * Output and update for enable system:
 *    '<Root>/Home2'
 *    '<Root>/Home4'
 */
void controller_Home2(boolean_T rtu_Enable, real_T rtu_motor_id, real_T
                      rtu_homing_torque, const boolean_T *rtd_LS2, const int32_T
                      *rtd_cfg_id, real_T *rtd_enc1, const int32_T *rtd_pdo_id,
                      real_T *rtd_state, P_Home2_controller_T *localP,
                      ZCE_Home2_controller_T *localZCE)
{
  real_T rtb_CCaller1_j[2];
  real_T rtb_Switch_g;
  real_T tmp;
  real_T tmp_0;
  int32_T rtb_DataStoreRead1_f;
  boolean_T rtb_DataStoreRead_jb;
  boolean_T tmp_1;
  boolean_T tmp_2;

  /* Outputs for Enabled SubSystem: '<Root>/Home2' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (rtu_Enable) {
    /* DataStoreRead: '<S8>/Data Store Read' */
    rtb_DataStoreRead_jb = *rtd_LS2;

    /* RelationalOperator: '<S17>/Compare' incorporates:
     *  Constant: '<S17>/Constant'
     */
    rtb_DataStoreRead_jb = (rtb_DataStoreRead_jb ==
      localP->CompareToConstant_const);

    /* Switch: '<S19>/Switch' incorporates:
     *  Constant: '<S8>/Constant'
     */
    if (rtb_DataStoreRead_jb) {
      rtb_Switch_g = localP->Constant_Value;
    } else {
      /* DataStoreRead: '<S19>/Data Store Read' */
      rtb_Switch_g = *rtd_state;
    }

    /* End of Switch: '<S19>/Switch' */

    /* DataStoreWrite: '<S19>/Data Store Write' */
    *rtd_state = rtb_Switch_g;

    /* DataTypeConversion: '<S8>/Data Type Conversion1' incorporates:
     *  DataTypeConversion: '<S20>/Data Type Conversion1'
     */
    rtb_Switch_g = floor(rtu_motor_id);
    tmp_1 = rtIsNaN(rtb_Switch_g);
    tmp_2 = rtIsInf(rtb_Switch_g);
    if (tmp_1 || tmp_2) {
      tmp = 0.0;
    } else {
      tmp = fmod(rtb_Switch_g, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
     *  Constant: '<S8>/Constant2'
     */
    tmp_0 = floor(localP->Constant2_Value);
    if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
      tmp_0 = 0.0;
    } else {
      tmp_0 = fmod(tmp_0, 4.294967296E+9);
    }

    /* CCaller: '<S8>/C Caller1' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion'
     *  DataTypeConversion: '<S8>/Data Type Conversion1'
     */
    print_input(tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp,
                tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 : (int32_T)(uint32_T)
                tmp_0);

    /* DataStoreRead: '<S20>/Data Store Read2' */
    rtb_DataStoreRead1_f = *rtd_pdo_id;

    /* DataTypeConversion: '<S20>/Data Type Conversion1' */
    if (tmp_1 || tmp_2) {
      rtb_Switch_g = 0.0;
    } else {
      rtb_Switch_g = fmod(rtb_Switch_g, 4.294967296E+9);
    }

    /* CCaller: '<S20>/C Caller3' incorporates:
     *  DataTypeConversion: '<S20>/Data Type Conversion1'
     */
    set_motor(rtb_DataStoreRead1_f, rtb_Switch_g < 0.0 ? -(int32_T)(uint32_T)
              -rtb_Switch_g : (int32_T)(uint32_T)rtb_Switch_g, rtu_homing_torque);

    /* Outputs for Triggered SubSystem: '<S8>/Stop Motor' incorporates:
     *  TriggerPort: '<S18>/Trigger'
     */
    if (rtb_DataStoreRead_jb && (localZCE->StopMotor_Trig_ZCE != POS_ZCSIG)) {
      /* DataStoreRead: '<S18>/Data Store Read2' */
      rtb_DataStoreRead1_f = *rtd_pdo_id;

      /* DataTypeConversion: '<S18>/Data Type Conversion7' incorporates:
       *  Constant: '<S18>/Constant7'
       */
      rtb_Switch_g = floor(localP->Constant7_Value);
      if (rtIsNaN(rtb_Switch_g) || rtIsInf(rtb_Switch_g)) {
        rtb_Switch_g = 0.0;
      } else {
        rtb_Switch_g = fmod(rtb_Switch_g, 4.294967296E+9);
      }

      /* CCaller: '<S18>/C Caller1' incorporates:
       *  DataTypeConversion: '<S18>/Data Type Conversion7'
       */
      get_encoder(rtb_DataStoreRead1_f, rtb_Switch_g < 0.0 ? -(int32_T)(uint32_T)
                  -rtb_Switch_g : (int32_T)(uint32_T)rtb_Switch_g,
                  &rtb_CCaller1_j[0]);

      /* DataStoreWrite: '<S18>/Data Store Write1' */
      *rtd_enc1 = rtb_CCaller1_j[0];

      /* DataStoreRead: '<S18>/Data Store Read1' */
      rtb_DataStoreRead1_f = *rtd_cfg_id;

      /* CCaller: '<S18>/C Caller4' */
      stop_motor(rtb_DataStoreRead1_f);
    }

    localZCE->StopMotor_Trig_ZCE = rtb_DataStoreRead_jb;

    /* End of Outputs for SubSystem: '<S8>/Stop Motor' */
  }

  /* End of Outputs for SubSystem: '<Root>/Home2' */
}

/* Function for MATLAB Function: '<S11>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S11>/MATLAB Function' */
static int8_T controller_cfopen(const char_T *cfilename, const char_T
  *cpermission)
{
  int32_T tmp;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = controller_filedata();
  if (j >= 1) {
    controller_B.filestar_c = fopen(cfilename, cpermission);
    if (controller_B.filestar_c != NULL) {
      controller_DW.eml_openfiles[j - 1] = controller_B.filestar_c;
      tmp = j + 2;
      if (j + 2 > 127) {
        tmp = 127;
      }

      fileid = (int8_T)tmp;
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<S11>/MATLAB Function1' */
static int32_T controller_cfclose(real_T fid)
{
  FILE* filestar;
  int32_T cst;
  int32_T st;
  int8_T b_fileid;
  int8_T fileid;
  st = -1;
  fileid = (int8_T)fid;
  if (((int8_T)fid > 22) || ((int8_T)fid < 0) || (fid != (int8_T)fid)) {
    fileid = -1;
  }

  b_fileid = fileid;
  if (fileid < 0) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    filestar = controller_DW.eml_openfiles_o[b_fileid - 3];
  } else if (b_fileid == 0) {
    filestar = stdin;
  } else if (b_fileid == 1) {
    filestar = stdout;
  } else if (b_fileid == 2) {
    filestar = stderr;
  } else {
    filestar = NULL;
  }

  if ((filestar != NULL) && (fileid >= 3)) {
    cst = fclose(filestar);
    if (cst == 0) {
      st = 0;
      controller_DW.eml_openfiles_o[fileid - 3] = NULL;
      controller_DW.eml_autoflush[fileid - 3] = true;
    }
  }

  return st;
}

/* Function for MATLAB Function: '<S12>/MATLAB Function' */
static int8_T controller_filedata_h(void)
{
  int32_T k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (controller_DW.eml_openfiles_c[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<S12>/MATLAB Function' */
static int8_T controller_cfopen_d(const char_T *cfilename, const char_T
  *cpermission)
{
  int32_T tmp;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = controller_filedata_h();
  if (j >= 1) {
    controller_B.filestar_m = fopen(cfilename, cpermission);
    if (controller_B.filestar_m != NULL) {
      controller_DW.eml_openfiles_c[j - 1] = controller_B.filestar_m;
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
  int8_T fileid;
  int8_T fileid_0;
  boolean_T rtb_Compare_a;
  if (controller_M->Timing.TaskCounters.TID[1] == 0) {
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

    /* Outputs for Enabled SubSystem: '<Root>/Home1' */
    /* RelationalOperator: '<S1>/Compare' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant1'
     *  Constant: '<S1>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read'
     */
    controller_Home1(controller_DW.state ==
                     controller_P.CompareToConstant1_const,
                     controller_P.Constant_Value_c,
                     controller_P.Constant1_Value_i, &controller_DW.LS1,
                     &controller_DW.cfg_id, &controller_DW.pdo_id,
                     &controller_DW.state, &controller_P.Home1,
                     &controller_PrevZCX.Home1);

    /* End of Outputs for SubSystem: '<Root>/Home1' */
  }

  if (controller_M->Timing.TaskCounters.TID[2] == 0) {
    /* Outputs for Enabled SubSystem: '<Root>/Initialize' incorporates:
     *  EnablePort: '<S11>/Enable'
     */
    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read1'
     */
    if (controller_DW.state == controller_P.CompareToConstant2_const) {
      /* CCaller: '<S11>/C Caller5' incorporates:
       *  Constant: '<S11>/Constant1'
       */
      init_can(controller_P.Constant1_Value, controller_P.Constant1_Value,
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

      /* Switch: '<S32>/Switch' */
      if (rtb_Compare_a) {
        /* DataStoreWrite: '<S32>/Data Store Write' incorporates:
         *  Constant: '<S11>/Constant'
         */
        controller_DW.state = controller_P.Constant_Value;
      }

      /* End of Switch: '<S32>/Switch' */

      /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
       *  Constant: '<S11>/Constant2'
       */
      controller_B.d = floor(controller_P.Constant2_Value);
      if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
        controller_B.d = 0.0;
      } else {
        controller_B.d = fmod(controller_B.d, 4.294967296E+9);
      }

      /* CCaller: '<S11>/C Caller1' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion'
       */
      print_input(controller_B.CCaller5[0], controller_B.d < 0.0 ? -(int32_T)
                  (uint32_T)-controller_B.d : (int32_T)(uint32_T)controller_B.d);

      /* DataTypeConversion: '<S11>/Data Type Conversion1' incorporates:
       *  Constant: '<S11>/Constant3'
       */
      controller_B.d = floor(controller_P.Constant3_Value);
      if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
        controller_B.d = 0.0;
      } else {
        controller_B.d = fmod(controller_B.d, 4.294967296E+9);
      }

      /* CCaller: '<S11>/C Caller2' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion1'
       */
      print_input(controller_B.CCaller5[1], controller_B.d < 0.0 ? -(int32_T)
                  (uint32_T)-controller_B.d : (int32_T)(uint32_T)controller_B.d);

      /* MATLAB Function: '<S11>/MATLAB Function' */
      fileid = controller_cfopen("test_datalog.txt", "rb");

      /* MATLAB Function: '<S11>/MATLAB Function1' incorporates:
       *  MATLAB Function: '<S11>/MATLAB Function'
       */
      controller_B.b_NULL = NULL;
      fileid_0 = fileid;
      if ((fileid > 22) || (fileid < 0)) {
        fileid_0 = -1;
      }

      if (fileid_0 >= 3) {
        controller_B.filestar = controller_DW.eml_openfiles_o[fileid_0 - 3];
        rtb_Compare_a = controller_DW.eml_autoflush[fileid_0 - 3];
      } else if (fileid_0 == 0) {
        controller_B.filestar = stdin;
        rtb_Compare_a = true;
      } else if (fileid_0 == 1) {
        controller_B.filestar = stdout;
        rtb_Compare_a = true;
      } else if (fileid_0 == 2) {
        controller_B.filestar = stderr;
        rtb_Compare_a = true;
      } else {
        controller_B.filestar = NULL;
        rtb_Compare_a = true;
      }

      if (!(controller_B.filestar == controller_B.b_NULL)) {
        fprintf(controller_B.filestar, "Test Test Test!!!\n");
        if (rtb_Compare_a) {
          fflush(controller_B.filestar);
        }
      }

      controller_cfclose((real_T)fileid);

      /* End of MATLAB Function: '<S11>/MATLAB Function1' */
    }

    /* End of RelationalOperator: '<S2>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Initialize' */
  }

  if (controller_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Enabled SubSystem: '<Root>/Home2' */
    /* RelationalOperator: '<S3>/Compare' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Constant: '<Root>/Constant3'
     *  Constant: '<S3>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read3'
     */
    controller_Home2(controller_DW.state ==
                     controller_P.CompareToConstant3_const,
                     controller_P.Constant2_Value_m,
                     controller_P.Constant3_Value_j, &controller_DW.LS2,
                     &controller_DW.cfg_id, &controller_DW.enc1,
                     &controller_DW.pdo_id, &controller_DW.state,
                     &controller_P.Home2, &controller_PrevZCX.Home2);

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
      controller_B.d = floor(controller_P.Constant7_Value);
      if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
        controller_B.d = 0.0;
      } else {
        controller_B.d = fmod(controller_B.d, 4.294967296E+9);
      }

      /* CCaller: '<S12>/C Caller1' incorporates:
       *  DataStoreRead: '<S12>/Data Store Read2'
       *  DataTypeConversion: '<S12>/Data Type Conversion7'
       */
      get_encoder(controller_DW.pdo_id, controller_B.d < 0.0 ? -(int32_T)
                  (uint32_T)-controller_B.d : (int32_T)(uint32_T)controller_B.d,
                  &controller_B.CCaller1[0]);

      /* DataTypeConversion: '<S34>/Data Type Conversion1' incorporates:
       *  Constant: '<S12>/Constant'
       */
      controller_B.d = floor(controller_P.Constant_Value_i);
      if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
        controller_B.d = 0.0;
      } else {
        controller_B.d = fmod(controller_B.d, 4.294967296E+9);
      }

      /* CCaller: '<S34>/C Caller3' incorporates:
       *  DataStoreRead: '<S34>/Data Store Read2'
       *  DataTypeConversion: '<S34>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, controller_B.d < 0.0 ? -(int32_T)(uint32_T)
                -controller_B.d : (int32_T)(uint32_T)controller_B.d, 0.0);

      /* DataTypeConversion: '<S35>/Data Type Conversion1' incorporates:
       *  Constant: '<S12>/Constant1'
       */
      controller_B.d = floor(controller_P.Constant1_Value_m);
      if (rtIsNaN(controller_B.d) || rtIsInf(controller_B.d)) {
        controller_B.d = 0.0;
      } else {
        controller_B.d = fmod(controller_B.d, 4.294967296E+9);
      }

      /* CCaller: '<S35>/C Caller3' incorporates:
       *  DataStoreRead: '<S35>/Data Store Read2'
       *  DataTypeConversion: '<S35>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, controller_B.d < 0.0 ? -(int32_T)(uint32_T)
                -controller_B.d : (int32_T)(uint32_T)controller_B.d, 0.0);

      /* MATLAB Function: '<S12>/MATLAB Function' */
      controller_cfopen_d("test_datalog.txt", "rb");
    }

    /* End of RelationalOperator: '<S4>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Main Control' */

    /* Outputs for Enabled SubSystem: '<Root>/Home3' */
    /* RelationalOperator: '<S5>/Compare' incorporates:
     *  Constant: '<Root>/Constant8'
     *  Constant: '<Root>/Constant9'
     *  Constant: '<S5>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read4'
     */
    controller_Home1(controller_DW.state ==
                     controller_P.CompareToConstant5_const,
                     controller_P.Constant8_Value, controller_P.Constant9_Value,
                     &controller_DW.LS1, &controller_DW.cfg_id,
                     &controller_DW.pdo_id, &controller_DW.state,
                     &controller_P.Home3, &controller_PrevZCX.Home3);

    /* End of Outputs for SubSystem: '<Root>/Home3' */

    /* Outputs for Enabled SubSystem: '<Root>/Home4' */
    /* RelationalOperator: '<S6>/Compare' incorporates:
     *  Constant: '<Root>/Constant10'
     *  Constant: '<Root>/Constant11'
     *  Constant: '<S6>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read5'
     */
    controller_Home2(controller_DW.state ==
                     controller_P.CompareToConstant6_const,
                     controller_P.Constant10_Value,
                     controller_P.Constant11_Value, &controller_DW.LS2,
                     &controller_DW.cfg_id, &controller_DW.enc1,
                     &controller_DW.pdo_id, &controller_DW.state,
                     &controller_P.Home4, &controller_PrevZCX.Home4);

    /* End of Outputs for SubSystem: '<Root>/Home4' */
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

  controller_PrevZCX.Home4.StopMotor_Trig_ZCE = POS_ZCSIG;
  controller_PrevZCX.Home3.StopMotor_Trig_ZCE_p = POS_ZCSIG;
  controller_PrevZCX.Home2.StopMotor_Trig_ZCE = POS_ZCSIG;
  controller_PrevZCX.Home1.StopMotor_Trig_ZCE_p = POS_ZCSIG;

  {
    FILE* b_a;
    FILE* b_a_0;
    FILE* b_a_1;
    int32_T i;

    /* SystemInitialize for Enabled SubSystem: '<Root>/Initialize' */
    /* SystemInitialize for MATLAB Function: '<S11>/MATLAB Function' */
    b_a = NULL;

    /* SystemInitialize for MATLAB Function: '<S11>/MATLAB Function1' */
    b_a_0 = NULL;

    /* End of SystemInitialize for SubSystem: '<Root>/Initialize' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/Main Control' */
    /* SystemInitialize for MATLAB Function: '<S12>/MATLAB Function' */
    b_a_1 = NULL;

    /* SystemInitialize for Enabled SubSystem: '<Root>/Initialize' */
    for (i = 0; i < 20; i++) {
      /* SystemInitialize for MATLAB Function: '<S11>/MATLAB Function' */
      controller_DW.eml_openfiles[i] = b_a;

      /* SystemInitialize for MATLAB Function: '<S11>/MATLAB Function1' */
      controller_DW.eml_autoflush[i] = false;
      controller_DW.eml_openfiles_o[i] = b_a_0;

      /* SystemInitialize for MATLAB Function: '<S12>/MATLAB Function' */
      controller_DW.eml_openfiles_c[i] = b_a_1;
    }

    /* End of SystemInitialize for SubSystem: '<Root>/Initialize' */
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
