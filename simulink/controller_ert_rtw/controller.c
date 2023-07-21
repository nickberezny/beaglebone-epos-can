/*
 * controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.173
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Jul 21 15:01:27 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controller.h"
#include "controller_types.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include <string.h>

/* Block states (default storage) */
DW_controller_T controller_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_controller_T controller_PrevZCX;

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
  if ((controller_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
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
  real_T rtb_CCaller1[2];
  real_T rtb_Switch_k;
  real_T tmp;
  real_T tmp_0;
  int32_T rtb_CCaller5[2];
  boolean_T rtb_Compare_a;
  if (controller_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/Digital Read1' */
    if (controller_DW.obj.SampleTime != controller_P.DigitalRead1_SampleTime) {
      controller_DW.obj.SampleTime = controller_P.DigitalRead1_SampleTime;
    }

    rtb_Compare_a = MW_digitalIO_read(controller_DW.obj.MW_DIGITALIO_HANDLE);

    /* DataStoreWrite: '<Root>/Data Store Write1' incorporates:
     *  MATLABSystem: '<Root>/Digital Read1'
     */
    controller_DW.LS2 = rtb_Compare_a;

    /* MATLABSystem: '<Root>/Digital Read' */
    if (controller_DW.obj_b.SampleTime != controller_P.DigitalRead_SampleTime) {
      controller_DW.obj_b.SampleTime = controller_P.DigitalRead_SampleTime;
    }

    /* DataStoreWrite: '<Root>/Data Store Write' incorporates:
     *  MATLABSystem: '<Root>/Digital Read'
     */
    controller_DW.LS1 = MW_digitalIO_read
      (controller_DW.obj_b.MW_DIGITALIO_HANDLE);

    /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    tmp_0 = floor(controller_P.Constant5_Value);
    if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
      tmp_0 = 0.0;
    } else {
      tmp_0 = fmod(tmp_0, 4.294967296E+9);
    }

    /* CCaller: '<Root>/C Caller1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion2'
     *  DataTypeConversion: '<Root>/Data Type Conversion3'
     *  MATLABSystem: '<Root>/Digital Read1'
     */
    print_input(rtb_Compare_a, tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 :
                (int32_T)(uint32_T)tmp_0);

    /* DataStoreRead: '<Root>/Data Store Read1' */
    rtb_Switch_k = controller_DW.state;

    /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read1'
     */
    tmp_0 = floor(controller_DW.state);
    if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
      tmp_0 = 0.0;
    } else {
      tmp_0 = fmod(tmp_0, 4.294967296E+9);
    }

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Constant: '<Root>/Constant4'
     */
    tmp = floor(controller_P.Constant4_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    /* CCaller: '<Root>/C Caller2' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  DataTypeConversion: '<Root>/Data Type Conversion1'
     */
    print_input(tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 : (int32_T)(uint32_T)
                tmp_0, tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)
                tmp);

    /* Outputs for Enabled SubSystem: '<Root>/Initialize' incorporates:
     *  EnablePort: '<S6>/Enable'
     */
    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     */
    if (rtb_Switch_k == controller_P.CompareToConstant2_const) {
      controller_DW.Initialize_MODE = true;
      if (controller_M->Timing.TaskCounters.TID[2] == 0) {
        /* CCaller: '<S6>/C Caller5' incorporates:
         *  Constant: '<S6>/Constant1'
         */
        init_can(controller_P.Constant1_Value, controller_P.Constant1_Value,
                 &rtb_CCaller5[0]);

        /* DataStoreWrite: '<S6>/Data Store Write' */
        controller_DW.cfg_id = rtb_CCaller5[0];

        /* DataStoreWrite: '<S6>/Data Store Write2' */
        controller_DW.pdo_id = rtb_CCaller5[1];

        /* RelationalOperator: '<S15>/Compare' incorporates:
         *  Constant: '<S15>/Constant'
         */
        rtb_Compare_a = (rtb_CCaller5[1] != controller_P.CompareToConstant_const);

        /* Switch: '<S16>/Switch' */
        if (rtb_Compare_a) {
          /* DataStoreWrite: '<S16>/Data Store Write' incorporates:
           *  Constant: '<S6>/Constant'
           */
          controller_DW.state = controller_P.Constant_Value_d;
        }

        /* End of Switch: '<S16>/Switch' */

        /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
         *  Constant: '<S6>/Constant2'
         */
        tmp_0 = floor(controller_P.Constant2_Value_l);
        if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
          tmp_0 = 0.0;
        } else {
          tmp_0 = fmod(tmp_0, 4.294967296E+9);
        }

        /* CCaller: '<S6>/C Caller1' incorporates:
         *  DataTypeConversion: '<S6>/Data Type Conversion'
         */
        print_input(rtb_CCaller5[0], tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 :
                    (int32_T)(uint32_T)tmp_0);

        /* DataTypeConversion: '<S6>/Data Type Conversion1' incorporates:
         *  Constant: '<S6>/Constant3'
         */
        tmp_0 = floor(controller_P.Constant3_Value);
        if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
          tmp_0 = 0.0;
        } else {
          tmp_0 = fmod(tmp_0, 4.294967296E+9);
        }

        /* CCaller: '<S6>/C Caller2' incorporates:
         *  DataTypeConversion: '<S6>/Data Type Conversion1'
         */
        print_input(rtb_CCaller5[1], tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 :
                    (int32_T)(uint32_T)tmp_0);
      }
    } else {
      controller_DW.Initialize_MODE = false;
    }

    /* End of RelationalOperator: '<S2>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Initialize' */

    /* Outputs for Enabled SubSystem: '<Root>/Home1' incorporates:
     *  EnablePort: '<S4>/Enable'
     */
    /* RelationalOperator: '<S1>/Compare' incorporates:
     *  Constant: '<S1>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read'
     */
    if (controller_DW.state == controller_P.CompareToConstant1_const) {
      /* RelationalOperator: '<S7>/Compare' incorporates:
       *  Constant: '<S7>/Constant'
       *  DataStoreRead: '<S4>/Data Store Read'
       */
      rtb_Compare_a = (controller_DW.LS1 ==
                       controller_P.CompareToConstant_const_b);

      /* Switch: '<S9>/Switch' */
      if (rtb_Compare_a) {
        /* DataStoreWrite: '<S9>/Data Store Write' incorporates:
         *  Constant: '<S4>/Constant'
         */
        controller_DW.state = controller_P.Constant_Value;
      }

      /* End of Switch: '<S9>/Switch' */

      /* DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant'
       */
      tmp_0 = floor(controller_P.Constant_Value_c);
      if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
        tmp_0 = 0.0;
      } else {
        tmp_0 = fmod(tmp_0, 4.294967296E+9);
      }

      /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
       *  Constant: '<S4>/Constant2'
       */
      tmp = floor(controller_P.Constant2_Value);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      /* CCaller: '<S4>/C Caller1' incorporates:
       *  DataTypeConversion: '<S4>/Data Type Conversion'
       *  DataTypeConversion: '<S4>/Data Type Conversion1'
       */
      print_input(tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 : (int32_T)(uint32_T)
                  tmp_0, tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)
                  (uint32_T)tmp);

      /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant'
       */
      tmp_0 = floor(controller_P.Constant_Value_c);
      if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
        tmp_0 = 0.0;
      } else {
        tmp_0 = fmod(tmp_0, 4.294967296E+9);
      }

      /* CCaller: '<S10>/C Caller3' incorporates:
       *  Constant: '<Root>/Constant1'
       *  DataStoreRead: '<S10>/Data Store Read2'
       *  DataTypeConversion: '<S10>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 :
                (int32_T)(uint32_T)tmp_0, controller_P.Constant1_Value_i);

      /* Outputs for Triggered SubSystem: '<S4>/Stop Motor' incorporates:
       *  TriggerPort: '<S8>/Trigger'
       */
      if (rtb_Compare_a && (controller_PrevZCX.StopMotor_Trig_ZCE_p != POS_ZCSIG))
      {
        /* CCaller: '<S8>/C Caller4' incorporates:
         *  DataStoreRead: '<S8>/Data Store Read1'
         */
        stop_motor(controller_DW.cfg_id);
      }

      controller_PrevZCX.StopMotor_Trig_ZCE_p = rtb_Compare_a;

      /* End of Outputs for SubSystem: '<S4>/Stop Motor' */
    }

    /* End of RelationalOperator: '<S1>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Home1' */

    /* Outputs for Enabled SubSystem: '<Root>/Home2' incorporates:
     *  EnablePort: '<S5>/Enable'
     */
    /* RelationalOperator: '<S3>/Compare' incorporates:
     *  Constant: '<S3>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read3'
     */
    if (controller_DW.state == controller_P.CompareToConstant3_const) {
      /* RelationalOperator: '<S11>/Compare' incorporates:
       *  Constant: '<S11>/Constant'
       *  DataStoreRead: '<S5>/Data Store Read'
       */
      rtb_Compare_a = (controller_DW.LS2 ==
                       controller_P.CompareToConstant_const_f);

      /* Switch: '<S13>/Switch' */
      if (rtb_Compare_a) {
        /* DataStoreWrite: '<S13>/Data Store Write' incorporates:
         *  Constant: '<S5>/Constant'
         */
        controller_DW.state = controller_P.Constant_Value_i;
      }

      /* End of Switch: '<S13>/Switch' */

      /* DataTypeConversion: '<S5>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      tmp_0 = floor(controller_P.Constant2_Value_m);
      if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
        tmp_0 = 0.0;
      } else {
        tmp_0 = fmod(tmp_0, 4.294967296E+9);
      }

      /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
       *  Constant: '<S5>/Constant2'
       */
      tmp = floor(controller_P.Constant2_Value_c);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      /* CCaller: '<S5>/C Caller1' incorporates:
       *  DataTypeConversion: '<S5>/Data Type Conversion'
       *  DataTypeConversion: '<S5>/Data Type Conversion1'
       */
      print_input(tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 : (int32_T)(uint32_T)
                  tmp_0, tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)
                  (uint32_T)tmp);

      /* DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      tmp_0 = floor(controller_P.Constant2_Value_m);
      if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
        tmp_0 = 0.0;
      } else {
        tmp_0 = fmod(tmp_0, 4.294967296E+9);
      }

      /* CCaller: '<S14>/C Caller3' incorporates:
       *  Constant: '<Root>/Constant3'
       *  DataStoreRead: '<S14>/Data Store Read2'
       *  DataTypeConversion: '<S14>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 :
                (int32_T)(uint32_T)tmp_0, controller_P.Constant3_Value_j);

      /* Outputs for Triggered SubSystem: '<S5>/Stop Motor' incorporates:
       *  TriggerPort: '<S12>/Trigger'
       */
      if (rtb_Compare_a && (controller_PrevZCX.StopMotor_Trig_ZCE != POS_ZCSIG))
      {
        /* DataTypeConversion: '<S12>/Data Type Conversion7' incorporates:
         *  Constant: '<S12>/Constant7'
         */
        tmp_0 = floor(controller_P.Constant7_Value);
        if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
          tmp_0 = 0.0;
        } else {
          tmp_0 = fmod(tmp_0, 4.294967296E+9);
        }

        /* CCaller: '<S12>/C Caller1' incorporates:
         *  DataStoreRead: '<S12>/Data Store Read2'
         *  DataTypeConversion: '<S12>/Data Type Conversion7'
         */
        get_encoder(controller_DW.pdo_id, tmp_0 < 0.0 ? -(int32_T)(uint32_T)
                    -tmp_0 : (int32_T)(uint32_T)tmp_0, &rtb_CCaller1[0]);

        /* DataStoreWrite: '<S12>/Data Store Write1' */
        controller_DW.enc1 = rtb_CCaller1[0];

        /* CCaller: '<S12>/C Caller4' incorporates:
         *  DataStoreRead: '<S12>/Data Store Read1'
         */
        stop_motor(controller_DW.cfg_id);
      }

      controller_PrevZCX.StopMotor_Trig_ZCE = rtb_Compare_a;

      /* End of Outputs for SubSystem: '<S5>/Stop Motor' */
    }

    /* End of RelationalOperator: '<S3>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Home2' */
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

    /* Start for MATLABSystem: '<Root>/Digital Read1' */
    controller_DW.obj.matlabCodegenIsDeleted = false;
    controller_DW.objisempty = true;
    controller_DW.obj.SampleTime = controller_P.DigitalRead1_SampleTime;
    obj = &controller_DW.obj;
    controller_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(116, 0);
    controller_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read' */
    controller_DW.obj_b.matlabCodegenIsDeleted = false;
    controller_DW.objisempty_g = true;
    controller_DW.obj_b.SampleTime = controller_P.DigitalRead_SampleTime;
    obj = &controller_DW.obj_b;
    controller_DW.obj_b.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(113, 0);
    controller_DW.obj_b.isSetupComplete = true;

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

  controller_PrevZCX.StopMotor_Trig_ZCE_p = POS_ZCSIG;
  controller_PrevZCX.StopMotor_Trig_ZCE = POS_ZCSIG;
}

/* Model terminate function */
void controller_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Read1' */
  if (!controller_DW.obj.matlabCodegenIsDeleted) {
    controller_DW.obj.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj.isInitialized == 1) &&
        controller_DW.obj.isSetupComplete) {
      MW_digitalIO_close(controller_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  if (!controller_DW.obj_b.matlabCodegenIsDeleted) {
    controller_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_b.isInitialized == 1) &&
        controller_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(controller_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read' */
}
