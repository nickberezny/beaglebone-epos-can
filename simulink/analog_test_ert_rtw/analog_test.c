/*
 * analog_test.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "analog_test".
 *
 * Model version              : 1.5
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Sep 22 15:09:20 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "analog_test.h"
#include "analog_test_types.h"
#include "analog_test_private.h"
#include <string.h>
#include "analog_test_dt.h"

/* Block signals (default storage) */
B_analog_test_T analog_test_B;

/* Block states (default storage) */
DW_analog_test_T analog_test_DW;

/* Real-time model */
static RT_MODEL_analog_test_T analog_test_M_;
RT_MODEL_analog_test_T *const analog_test_M = &analog_test_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void analog_test_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(analog_test_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (analog_test_M->Timing.TaskCounters.TID[1])++;
  if ((analog_test_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    analog_test_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void analog_test_step0(void)           /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<Root>/Analog Input' */
  if (analog_test_DW.obj.SampleTime != analog_test_P.AnalogInput_SampleTime) {
    analog_test_DW.obj.SampleTime = analog_test_P.AnalogInput_SampleTime;
  }

  /* MATLABSystem: '<Root>/Analog Input' */
  analog_test_B.AnalogInput = rc_adc_read_raw(3);

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)analog_test_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(analog_test_M)!=-1) &&
        !((rtmGetTFinal(analog_test_M)-analog_test_M->Timing.taskTime0) >
          analog_test_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(analog_test_M, "Simulation finished");
    }

    if (rtmGetStopRequested(analog_test_M)) {
      rtmSetErrorStatus(analog_test_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++analog_test_M->Timing.clockTick0)) {
    ++analog_test_M->Timing.clockTickH0;
  }

  analog_test_M->Timing.taskTime0 = analog_test_M->Timing.clockTick0 *
    analog_test_M->Timing.stepSize0 + analog_test_M->Timing.clockTickH0 *
    analog_test_M->Timing.stepSize0 * 4294967296.0;
}

/* Model step function for TID1 */
void analog_test_step1(void)           /* Sample time: [0.1s, 0.0s] */
{
  /* MATLABSystem: '<Root>/Digital Read' */
  if (analog_test_DW.obj_h5.SampleTime != analog_test_P.DigitalRead_SampleTime)
  {
    analog_test_DW.obj_h5.SampleTime = analog_test_P.DigitalRead_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Read' */
  analog_test_B.DigitalRead = MW_digitalIO_read
    (analog_test_DW.obj_h5.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<Root>/Digital Read1' */
  if (analog_test_DW.obj_h.SampleTime != analog_test_P.DigitalRead1_SampleTime)
  {
    analog_test_DW.obj_h.SampleTime = analog_test_P.DigitalRead1_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Read1' */
  analog_test_B.DigitalRead1 = MW_digitalIO_read
    (analog_test_DW.obj_h.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<Root>/Digital Read2' */
  if (analog_test_DW.obj_j.SampleTime != analog_test_P.DigitalRead2_SampleTime)
  {
    analog_test_DW.obj_j.SampleTime = analog_test_P.DigitalRead2_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Read2' */
  analog_test_B.DigitalRead2 = MW_digitalIO_read
    (analog_test_DW.obj_j.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<Root>/Digital Read3' */
  if (analog_test_DW.obj_b.SampleTime != analog_test_P.DigitalRead3_SampleTime)
  {
    analog_test_DW.obj_b.SampleTime = analog_test_P.DigitalRead3_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Read3' */
  analog_test_B.DigitalRead3 = MW_digitalIO_read
    (analog_test_DW.obj_b.MW_DIGITALIO_HANDLE);
  rtExtModeUpload(1, (real_T)(((analog_test_M->Timing.clockTick1+
    analog_test_M->Timing.clockTickH1* 4294967296.0)) * 0.1));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  analog_test_M->Timing.clockTick1++;
  if (!analog_test_M->Timing.clockTick1) {
    analog_test_M->Timing.clockTickH1++;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void analog_test_step(int_T tid)
{
  switch (tid) {
   case 0 :
    analog_test_step0();
    break;

   case 1 :
    analog_test_step1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void analog_test_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)analog_test_M, 0,
                sizeof(RT_MODEL_analog_test_T));
  rtmSetTFinal(analog_test_M, 100.0);
  analog_test_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  analog_test_M->Sizes.checksums[0] = (3709035521U);
  analog_test_M->Sizes.checksums[1] = (1152763018U);
  analog_test_M->Sizes.checksums[2] = (1596638172U);
  analog_test_M->Sizes.checksums[3] = (2578979973U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    analog_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(analog_test_M->extModeInfo,
      &analog_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(analog_test_M->extModeInfo,
                        analog_test_M->Sizes.checksums);
    rteiSetTPtr(analog_test_M->extModeInfo, rtmGetTPtr(analog_test_M));
  }

  /* block I/O */
  (void) memset(((void *) &analog_test_B), 0,
                sizeof(B_analog_test_T));

  /* states (dwork) */
  (void) memset((void *)&analog_test_DW, 0,
                sizeof(DW_analog_test_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    analog_test_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    beagleboneblue_bbblueDigitalR_T *obj;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    analog_test_DW.obj.matlabCodegenIsDeleted = false;
    analog_test_DW.objisempty_n = true;
    analog_test_DW.obj.SampleTime = analog_test_P.AnalogInput_SampleTime;
    analog_test_DW.obj.isInitialized = 1;
    rc_adc_init();
    analog_test_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read' */
    analog_test_DW.obj_h5.matlabCodegenIsDeleted = false;
    analog_test_DW.objisempty_ga = true;
    analog_test_DW.obj_h5.SampleTime = analog_test_P.DigitalRead_SampleTime;
    obj = &analog_test_DW.obj_h5;
    analog_test_DW.obj_h5.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(49, 0);
    analog_test_DW.obj_h5.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read1' */
    analog_test_DW.obj_h.matlabCodegenIsDeleted = false;
    analog_test_DW.objisempty_g = true;
    analog_test_DW.obj_h.SampleTime = analog_test_P.DigitalRead1_SampleTime;
    obj = &analog_test_DW.obj_h;
    analog_test_DW.obj_h.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(57, 0);
    analog_test_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read2' */
    analog_test_DW.obj_j.matlabCodegenIsDeleted = false;
    analog_test_DW.objisempty_a = true;
    analog_test_DW.obj_j.SampleTime = analog_test_P.DigitalRead2_SampleTime;
    obj = &analog_test_DW.obj_j;
    analog_test_DW.obj_j.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(113, 0);
    analog_test_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read3' */
    analog_test_DW.obj_b.matlabCodegenIsDeleted = false;
    analog_test_DW.objisempty = true;
    analog_test_DW.obj_b.SampleTime = analog_test_P.DigitalRead3_SampleTime;
    obj = &analog_test_DW.obj_b;
    analog_test_DW.obj_b.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(116, 0);
    analog_test_DW.obj_b.isSetupComplete = true;
  }
}

/* Model terminate function */
void analog_test_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!analog_test_DW.obj.matlabCodegenIsDeleted) {
    analog_test_DW.obj.matlabCodegenIsDeleted = true;
    if ((analog_test_DW.obj.isInitialized == 1) &&
        analog_test_DW.obj.isSetupComplete) {
      rc_adc_cleanup();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  if (!analog_test_DW.obj_h5.matlabCodegenIsDeleted) {
    analog_test_DW.obj_h5.matlabCodegenIsDeleted = true;
    if ((analog_test_DW.obj_h5.isInitialized == 1) &&
        analog_test_DW.obj_h5.isSetupComplete) {
      MW_digitalIO_close(analog_test_DW.obj_h5.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read1' */
  if (!analog_test_DW.obj_h.matlabCodegenIsDeleted) {
    analog_test_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((analog_test_DW.obj_h.isInitialized == 1) &&
        analog_test_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(analog_test_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read2' */
  if (!analog_test_DW.obj_j.matlabCodegenIsDeleted) {
    analog_test_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((analog_test_DW.obj_j.isInitialized == 1) &&
        analog_test_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(analog_test_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read3' */
  if (!analog_test_DW.obj_b.matlabCodegenIsDeleted) {
    analog_test_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((analog_test_DW.obj_b.isInitialized == 1) &&
        analog_test_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(analog_test_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read3' */
}
