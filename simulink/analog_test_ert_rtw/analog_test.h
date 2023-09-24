/*
 * analog_test.h
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

#ifndef RTW_HEADER_analog_test_h_
#define RTW_HEADER_analog_test_h_
#ifndef analog_test_COMMON_INCLUDES_
#define analog_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_bbblue_driver.h"
#include "MW_digitalIO.h"
#endif                                 /* analog_test_COMMON_INCLUDES_ */

#include "analog_test_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T AnalogInput;                  /* '<Root>/Analog Input' */
  boolean_T DigitalRead3;              /* '<Root>/Digital Read3' */
  boolean_T DigitalRead2;              /* '<Root>/Digital Read2' */
  boolean_T DigitalRead1;              /* '<Root>/Digital Read1' */
  boolean_T DigitalRead;               /* '<Root>/Digital Read' */
} B_analog_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  beagleboneblue_bbblueADC_anal_T obj; /* '<Root>/Analog Input' */
  beagleboneblue_bbblueDigitalR_T obj_b;/* '<Root>/Digital Read3' */
  beagleboneblue_bbblueDigitalR_T obj_j;/* '<Root>/Digital Read2' */
  beagleboneblue_bbblueDigitalR_T obj_h;/* '<Root>/Digital Read1' */
  beagleboneblue_bbblueDigitalR_T obj_h5;/* '<Root>/Digital Read' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[4];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  boolean_T objisempty;                /* '<Root>/Digital Read3' */
  boolean_T objisempty_a;              /* '<Root>/Digital Read2' */
  boolean_T objisempty_g;              /* '<Root>/Digital Read1' */
  boolean_T objisempty_ga;             /* '<Root>/Digital Read' */
  boolean_T objisempty_n;              /* '<Root>/Analog Input' */
} DW_analog_test_T;

/* Parameters (default storage) */
struct P_analog_test_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: 0.001
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T DigitalRead_SampleTime;       /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Read'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Read1'
                                        */
  real_T DigitalRead2_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Read2'
                                        */
  real_T DigitalRead3_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Read3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_analog_test_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_analog_test_T analog_test_P;

/* Block signals (default storage) */
extern B_analog_test_T analog_test_B;

/* Block states (default storage) */
extern DW_analog_test_T analog_test_DW;

/* External function called from main */
extern void analog_test_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void analog_test_initialize(void);
extern void analog_test_step0(void);
extern void analog_test_step1(void);
extern void analog_test_step(int_T tid);
extern void analog_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_analog_test_T *const analog_test_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'analog_test'
 */
#endif                                 /* RTW_HEADER_analog_test_h_ */
