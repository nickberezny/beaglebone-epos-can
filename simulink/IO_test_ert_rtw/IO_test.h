/*
 * IO_test.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "IO_test".
 *
 * Model version              : 1.3
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Jul 21 09:15:37 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_IO_test_h_
#define RTW_HEADER_IO_test_h_
#ifndef IO_test_COMMON_INCLUDES_
#define IO_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_digitalIO.h"
#endif                                 /* IO_test_COMMON_INCLUDES_ */

#include "IO_test_types.h"
#include "rtGetInf.h"
#include <stddef.h>
#include <string.h>
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "print_input.h"

/* Block states (default storage) for system '<Root>' */
typedef struct {
  beagleboneblue_bbblueDigitalR_T obj; /* '<Root>/Digital Read' */
  boolean_T objisempty;                /* '<Root>/Digital Read' */
} DW_IO_test_T;

/* Parameters (default storage) */
struct P_IO_test_T_ {
  real_T DigitalRead_SampleTime;       /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Read'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_IO_test_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_IO_test_T IO_test_P;

/* Block states (default storage) */
extern DW_IO_test_T IO_test_DW;

/* Model entry point functions */
extern void IO_test_initialize(void);
extern void IO_test_step(void);
extern void IO_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_IO_test_T *const IO_test_M;
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
 * '<Root>' : 'IO_test'
 */
#endif                                 /* RTW_HEADER_IO_test_h_ */
