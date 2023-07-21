/*
 * controller.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.125
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Jul 21 11:19:09 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller_h_
#define RTW_HEADER_controller_h_
#ifndef controller_COMMON_INCLUDES_
#define controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_digitalIO.h"
#endif                                 /* controller_COMMON_INCLUDES_ */

#include "controller_types.h"
#include "rtGetInf.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "init_can.h"
#include "get_encoder.h"
#include "set_motor.h"
#include "print_input.h"
#include "stop_motor.h"

/* Block states (default storage) for system '<Root>' */
typedef struct {
  beagleboneblue_bbblueDigitalR_T obj; /* '<Root>/Digital Read' */
  real_T state;                        /* '<Root>/Data Store Memory' */
  real_T enc1;                         /* '<Root>/Data Store Memory2' */
  real_T pos_h;                        /* '<Root>/Data Store Memory3' */
  real_T enc2;                         /* '<Root>/Data Store Memory5' */
  int32_T pdo_id;                      /* '<Root>/Data Store Memory4' */
  boolean_T LS1;                       /* '<Root>/Data Store Memory1' */
  boolean_T objisempty;                /* '<Root>/Digital Read' */
} DW_controller_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState StopMotor_Trig_ZCE;       /* '<S3>/Stop Motor' */
} PrevZCX_controller_T;

/* Parameters (default storage) */
struct P_controller_T_ {
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S1>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S2>/Constant'
                                      */
  int32_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S9>/Constant'
                                       */
  boolean_T CompareToConstant_const_b;
                                    /* Mask Parameter: CompareToConstant_const_b
                                     * Referenced by: '<S5>/Constant'
                                     */
  real_T DigitalRead_SampleTime;       /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Read'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 5000
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant7_Value;              /* Expression: 2
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant_Value_c;             /* Expression: 2
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value_i;            /* Expression: 75
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T DataStoreMemory_InitialValue; /* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory'
                                        */
  real_T DataStoreMemory2_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory2'
                                        */
  real_T DataStoreMemory3_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory3'
                                        */
  real_T DataStoreMemory5_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory5'
                                        */
  int32_T DataStoreMemory4_InitialValue;
                            /* Computed Parameter: DataStoreMemory4_InitialValue
                             * Referenced by: '<Root>/Data Store Memory4'
                             */
  boolean_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<Root>/Data Store Memory1'
                             */
};

/* Real-time Model Data Structure */
struct tag_RTM_controller_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_T TID[4];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_controller_T controller_P;

/* Block states (default storage) */
extern DW_controller_T controller_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_controller_T controller_PrevZCX;

/* Model entry point functions */
extern void controller_initialize(void);
extern void controller_step(void);
extern void controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_controller_T *const controller_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'controller'
 * '<S1>'   : 'controller/Compare To Constant1'
 * '<S2>'   : 'controller/Compare To Constant2'
 * '<S3>'   : 'controller/Home1'
 * '<S4>'   : 'controller/Initialize'
 * '<S5>'   : 'controller/Home1/Compare To Constant'
 * '<S6>'   : 'controller/Home1/Stop Motor'
 * '<S7>'   : 'controller/Home1/Subsystem'
 * '<S8>'   : 'controller/Home1/Subsystem1'
 * '<S9>'   : 'controller/Initialize/Compare To Constant'
 * '<S10>'  : 'controller/Initialize/Subsystem'
 */
#endif                                 /* RTW_HEADER_controller_h_ */
