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
 * C source code generated on : Wed Oct 11 14:02:28 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "untitled_private.h"
#include <string.h>
#include "untitled_dt.h"

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model step function */
void untitled_step(void)
{
  real_T rtb_PulseGenerator;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (untitled_DW.obj.SampleTime != untitled_P.AnalogInput_SampleTime) {
    untitled_DW.obj.SampleTime = untitled_P.AnalogInput_SampleTime;
  }

  /* MATLABSystem: '<Root>/Analog Input' */
  untitled_B.AnalogInput = rc_adc_read_raw(0);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (untitled_DW.clockTickCounter <
                        untitled_P.PulseGenerator_Duty) &&
    (untitled_DW.clockTickCounter >= 0) ? untitled_P.PulseGenerator_Amp : 0.0;
  if (untitled_DW.clockTickCounter >= untitled_P.PulseGenerator_Period - 1.0) {
    untitled_DW.clockTickCounter = 0;
  } else {
    untitled_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  rtb_PulseGenerator = floor(rtb_PulseGenerator);
  if (rtIsNaN(rtb_PulseGenerator) || rtIsInf(rtb_PulseGenerator)) {
    rtb_PulseGenerator = 0.0;
  } else {
    rtb_PulseGenerator = fmod(rtb_PulseGenerator, 256.0);
  }

  /* MATLABSystem: '<Root>/LED' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  rc_led_set(1, (uint8_T)(rtb_PulseGenerator < 0.0 ? (int32_T)(uint8_T)-(int8_T)
              (uint8_T)-rtb_PulseGenerator : (int32_T)(uint8_T)
              rtb_PulseGenerator));

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, (real_T)untitled_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
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
  untitled_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (3293388813U);
  untitled_M->Sizes.checksums[1] = (72023117U);
  untitled_M->Sizes.checksums[2] = (3919101003U);
  untitled_M->Sizes.checksums[3] = (3546987473U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
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
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.objisempty_g = true;
  untitled_DW.obj.SampleTime = untitled_P.AnalogInput_SampleTime;
  untitled_DW.obj.isInitialized = 1;
  rc_adc_init();
  untitled_DW.obj.isSetupComplete = true;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  untitled_DW.clockTickCounter = 0;

  /* Start for MATLABSystem: '<Root>/LED' */
  untitled_DW.obj_p.matlabCodegenIsDeleted = false;
  untitled_DW.objisempty = true;
  untitled_DW.obj_p.isInitialized = 1;
  untitled_DW.obj_p.isSetupComplete = true;
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

  /* Terminate for MATLABSystem: '<Root>/LED' */
  if (!untitled_DW.obj_p.matlabCodegenIsDeleted) {
    untitled_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_p.isInitialized == 1) &&
        untitled_DW.obj_p.isSetupComplete) {
      rc_led_cleanup();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED' */
}
