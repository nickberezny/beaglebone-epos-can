/*
 * controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.135
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Jul 21 12:08:35 2023
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
#include <string.h>

/* Block states (default storage) */
DW_controller_T controller_DW;

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
  if ((controller_M->Timing.TaskCounters.TID[2]) > 999999) {/* Sample time: [1000.0s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[2] = 0;
  }

  (controller_M->Timing.TaskCounters.TID[3])++;
  if ((controller_M->Timing.TaskCounters.TID[3]) > 9999999) {/* Sample time: [10000.0s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/* Model step function */
void controller_step(void)
{
  real_T tmp;
  int32_T rtb_CCaller5[2];
  boolean_T rtb_Compare_a;
  if (controller_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/Digital Read' */
    if (controller_DW.obj.SampleTime != controller_P.DigitalRead_SampleTime) {
      controller_DW.obj.SampleTime = controller_P.DigitalRead_SampleTime;
    }

    /* DataStoreWrite: '<Root>/Data Store Write' incorporates:
     *  MATLABSystem: '<Root>/Digital Read'
     */
    controller_DW.LS1 = MW_digitalIO_read(controller_DW.obj.MW_DIGITALIO_HANDLE);

    /* Outputs for Enabled SubSystem: '<Root>/Home1' incorporates:
     *  EnablePort: '<S4>/Enable'
     */
    /* RelationalOperator: '<S1>/Compare' incorporates:
     *  Constant: '<S1>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read'
     */
    if (controller_DW.state == controller_P.CompareToConstant1_const) {
      /* Switch: '<S8>/Switch' incorporates:
       *  Constant: '<S7>/Constant'
       *  DataStoreRead: '<S4>/Data Store Read'
       *  RelationalOperator: '<S7>/Compare'
       */
      if (controller_DW.LS1 == controller_P.CompareToConstant_const_b) {
        /* DataStoreWrite: '<S8>/Data Store Write' incorporates:
         *  Constant: '<S4>/Constant'
         */
        controller_DW.state = controller_P.Constant_Value;
      }

      /* End of Switch: '<S8>/Switch' */

      /* DataStoreWrite: '<S4>/Data Store Write' incorporates:
       *  DataStoreRead: '<S4>/Data Store Read1'
       */
      controller_DW.pos_h = controller_DW.enc1;

      /* DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
       *  Constant: '<Root>/Constant'
       */
      tmp = floor(controller_P.Constant_Value_c);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      /* CCaller: '<S9>/C Caller3' incorporates:
       *  Constant: '<Root>/Constant1'
       *  DataStoreRead: '<S9>/Data Store Read2'
       *  DataTypeConversion: '<S9>/Data Type Conversion1'
       */
      set_motor(controller_DW.pdo_id, tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
                (int32_T)(uint32_T)tmp, controller_P.Constant1_Value_i);
    }

    /* End of RelationalOperator: '<S1>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Home1' */
  }

  if (controller_M->Timing.TaskCounters.TID[3] == 0) {
    /* Outputs for Enabled SubSystem: '<Root>/Initialize' incorporates:
     *  EnablePort: '<S6>/Enable'
     */
    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read1'
     */
    if (controller_DW.state == controller_P.CompareToConstant2_const) {
      /* CCaller: '<S6>/C Caller5' incorporates:
       *  Constant: '<S6>/Constant1'
       */
      init_can(controller_P.Constant1_Value, controller_P.Constant1_Value,
               &rtb_CCaller5[0]);

      /* DataStoreWrite: '<S6>/Data Store Write' */
      controller_DW.cfg_id = rtb_CCaller5[0];

      /* DataStoreWrite: '<S6>/Data Store Write2' */
      controller_DW.pdo_id = rtb_CCaller5[1];

      /* RelationalOperator: '<S11>/Compare' incorporates:
       *  Constant: '<S11>/Constant'
       */
      rtb_Compare_a = (rtb_CCaller5[1] != controller_P.CompareToConstant_const);

      /* Switch: '<S12>/Switch' */
      if (rtb_Compare_a) {
        /* DataStoreWrite: '<S12>/Data Store Write' incorporates:
         *  Constant: '<S6>/Constant'
         */
        controller_DW.state = controller_P.Constant_Value_d;
      }

      /* End of Switch: '<S12>/Switch' */
    }

    /* End of RelationalOperator: '<S2>/Compare' */
    /* End of Outputs for SubSystem: '<Root>/Initialize' */
  }

  if (controller_M->Timing.TaskCounters.TID[2] == 0) {
    /* Outputs for Enabled SubSystem: '<Root>/Home2' incorporates:
     *  EnablePort: '<S5>/Enable'
     */
    /* RelationalOperator: '<S3>/Compare' incorporates:
     *  Constant: '<S3>/Constant'
     *  DataStoreRead: '<Root>/Data Store Read3'
     */
    if (controller_DW.state == controller_P.CompareToConstant3_const) {
      /* Switch: '<S10>/Switch' */
      if (controller_P.Switch_Threshold < 0.0) {
        /* DataStoreWrite: '<S10>/Data Store Write' incorporates:
         *  Constant: '<S5>/Constant'
         */
        controller_DW.state = controller_P.Constant_Value_h;
      }

      /* End of Switch: '<S10>/Switch' */

      /* CCaller: '<S5>/C Caller4' incorporates:
       *  DataStoreRead: '<S5>/Data Store Read'
       */
      stop_motor(controller_DW.cfg_id);
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

    /* Start for MATLABSystem: '<Root>/Digital Read' */
    controller_DW.obj.matlabCodegenIsDeleted = false;
    controller_DW.objisempty = true;
    controller_DW.obj.SampleTime = controller_P.DigitalRead_SampleTime;
    obj = &controller_DW.obj;
    controller_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(113, 0);
    controller_DW.obj.isSetupComplete = true;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
    controller_DW.state = controller_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    controller_DW.LS1 = controller_P.DataStoreMemory1_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    controller_DW.enc1 = controller_P.DataStoreMemory2_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
    controller_DW.pos_h = controller_P.DataStoreMemory3_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
    controller_DW.pdo_id = controller_P.DataStoreMemory4_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
    controller_DW.cfg_id = controller_P.DataStoreMemory6_InitialValue;
  }
}

/* Model terminate function */
void controller_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  if (!controller_DW.obj.matlabCodegenIsDeleted) {
    controller_DW.obj.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj.isInitialized == 1) &&
        controller_DW.obj.isSetupComplete) {
      MW_digitalIO_close(controller_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read' */
}
