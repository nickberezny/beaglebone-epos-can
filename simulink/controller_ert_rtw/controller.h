/*
 * controller.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.200
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Jul 24 09:55:24 2023
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

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* user code (top of header file) */
#include "init_can.h"
#include "get_encoder.h"
#include "set_motor.h"
#include "print_input.h"
#include "stop_motor.h"
#include "datalog.h"

/* Zero-crossing (trigger) state for system '<Root>/Home1' */
typedef struct {
  ZCSigState StopMotor_Trig_ZCE_p;     /* '<S7>/Stop Motor' */
} ZCE_Home1_controller_T;

/* Zero-crossing (trigger) state for system '<S8>/Stop Motor' */
typedef struct {
  ZCSigState StopMotor_Trig_ZCE;       /* '<S8>/Stop Motor' */
} ZCE_StopMotor_controller_T;

/* Block signals (default storage) */
typedef struct {
  real_T CCaller1[2];                  /* '<S12>/C Caller1' */
  real_T Clock;                        /* '<S12>/Clock' */
  boolean_T Compare;                   /* '<S4>/Compare' */
} B_controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  beagleboneblue_bbblueDigitalR_T obj; /* '<Root>/Digital Read1' */
  beagleboneblue_bbblueDigitalR_T obj_b;/* '<Root>/Digital Read' */
  real_T enc2;                         /* '<Root>/Data Store Memory5' */
  real_T state;                        /* '<Root>/Data Store Memory' */
  real_T enc1;                         /* '<Root>/Data Store Memory2' */
  int32_T pdo_id;                      /* '<Root>/Data Store Memory4' */
  int32_T cfg_id;                      /* '<Root>/Data Store Memory6' */
  boolean_T LS1;                       /* '<Root>/Data Store Memory1' */
  boolean_T LS2;                       /* '<Root>/Data Store Memory3' */
  boolean_T objisempty;                /* '<Root>/Digital Read1' */
  boolean_T objisempty_g;              /* '<Root>/Digital Read' */
  boolean_T MainControl_MODE;          /* '<Root>/Main Control' */
  boolean_T Initialize_MODE;           /* '<Root>/Initialize' */
} DW_controller_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_StopMotor_controller_T StopMotor_p;/* '<S10>/Stop Motor' */
  ZCE_Home1_controller_T Home3;        /* '<Root>/Home3' */
  ZCE_StopMotor_controller_T StopMotor;/* '<S8>/Stop Motor' */
  ZCE_Home1_controller_T Home1;        /* '<Root>/Home1' */
} PrevZCX_controller_T;

/* Parameters for system: '<Root>/Home1' */
struct P_Home1_controller_T_ {
  boolean_T CompareToConstant_const;  /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S13>/Constant'
                                       */
  real_T Constant_Value;               /* Expression: 2
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 4
                                        * Referenced by: '<S7>/Constant2'
                                        */
};

/* Parameters for system: '<S8>/Stop Motor' */
struct P_StopMotor_controller_T_ {
  real_T Constant7_Value;              /* Expression: 2
                                        * Referenced by: '<S18>/Constant7'
                                        */
};

/* Parameters (default storage) */
struct P_controller_T_ {
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S1>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S2>/Constant'
                                      */
  real_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S3>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S4>/Constant'
                                      */
  real_T CompareToConstant5_const;   /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S5>/Constant'
                                      */
  real_T CompareToConstant6_const;   /* Mask Parameter: CompareToConstant6_const
                                      * Referenced by: '<S6>/Constant'
                                      */
  int32_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S29>/Constant'
                                       */
  boolean_T CompareToConstant_const_f;
                                    /* Mask Parameter: CompareToConstant_const_f
                                     * Referenced by: '<S17>/Constant'
                                     */
  boolean_T CompareToConstant_const_m;
                                    /* Mask Parameter: CompareToConstant_const_m
                                     * Referenced by: '<S25>/Constant'
                                     */
  real_T DigitalRead_SampleTime;       /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Read'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Read1'
                                        */
  real_T Constant_Value;               /* Expression: 3
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 4
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T Constant_Value_a;             /* Expression: 3
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant2_Value_f;            /* Expression: 4
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Constant4_Value;              /* Expression: 2
                                        * Referenced by: '<S11>/Constant4'
                                        */
  real_T Constant1_Value;              /* Expression: 5000
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Constant2_Value_l;            /* Expression: 1
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 2
                                        * Referenced by: '<S11>/Constant3'
                                        */
  real_T Constant7_Value;              /* Expression: 2
                                        * Referenced by: '<S12>/Constant7'
                                        */
  real_T Constant4_Value_p;            /* Expression: 3.45
                                        * Referenced by: '<S12>/Constant4'
                                        */
  real_T Constant2_Value_i;            /* Expression: 2
                                        * Referenced by: '<S12>/Constant2'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: 2
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T DataStoreMemory5_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory5'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value_i;            /* Expression: 75
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value_m;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value_j;            /* Expression: -75
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant8_Value;              /* Expression: 2
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: 75
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Constant10_Value;             /* Expression: 2
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T Constant11_Value;             /* Expression: -75
                                        * Referenced by: '<Root>/Constant11'
                                        */
  real_T DataStoreMemory_InitialValue; /* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory'
                                        */
  real_T DataStoreMemory2_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory2'
                                        */
  int32_T DataStoreMemory4_InitialValue;
                            /* Computed Parameter: DataStoreMemory4_InitialValue
                             * Referenced by: '<Root>/Data Store Memory4'
                             */
  int32_T DataStoreMemory6_InitialValue;
                            /* Computed Parameter: DataStoreMemory6_InitialValue
                             * Referenced by: '<Root>/Data Store Memory6'
                             */
  boolean_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<Root>/Data Store Memory1'
                             */
  boolean_T DataStoreMemory3_InitialValue;
                            /* Computed Parameter: DataStoreMemory3_InitialValue
                             * Referenced by: '<Root>/Data Store Memory3'
                             */
  P_StopMotor_controller_T StopMotor_p;/* '<S10>/Stop Motor' */
  P_Home1_controller_T Home3;          /* '<Root>/Home3' */
  P_StopMotor_controller_T StopMotor;  /* '<S8>/Stop Motor' */
  P_Home1_controller_T Home1;          /* '<Root>/Home1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_controller_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint32_T TID[5];
    } TaskCounters;

    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[5];
  } Timing;
};

/* Block parameters (default storage) */
extern P_controller_T controller_P;

/* Block signals (default storage) */
extern B_controller_T controller_B;

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
 * Block '<S12>/Delay' : Unused code path elimination
 * Block '<S12>/Delay1' : Unused code path elimination
 * Block '<S12>/Gain' : Unused code path elimination
 * Block '<S12>/Sum' : Unused code path elimination
 * Block '<S12>/Sum1' : Unused code path elimination
 * Block '<S16>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S28>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S31>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S32>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S3>'   : 'controller/Compare To Constant3'
 * '<S4>'   : 'controller/Compare To Constant4'
 * '<S5>'   : 'controller/Compare To Constant5'
 * '<S6>'   : 'controller/Compare To Constant6'
 * '<S7>'   : 'controller/Home1'
 * '<S8>'   : 'controller/Home2'
 * '<S9>'   : 'controller/Home3'
 * '<S10>'  : 'controller/Home4'
 * '<S11>'  : 'controller/Initialize'
 * '<S12>'  : 'controller/Main Control'
 * '<S13>'  : 'controller/Home1/Compare To Constant'
 * '<S14>'  : 'controller/Home1/Stop Motor'
 * '<S15>'  : 'controller/Home1/Subsystem'
 * '<S16>'  : 'controller/Home1/Subsystem1'
 * '<S17>'  : 'controller/Home2/Compare To Constant'
 * '<S18>'  : 'controller/Home2/Stop Motor'
 * '<S19>'  : 'controller/Home2/Subsystem'
 * '<S20>'  : 'controller/Home2/Subsystem1'
 * '<S21>'  : 'controller/Home3/Compare To Constant'
 * '<S22>'  : 'controller/Home3/Stop Motor'
 * '<S23>'  : 'controller/Home3/Subsystem'
 * '<S24>'  : 'controller/Home3/Subsystem1'
 * '<S25>'  : 'controller/Home4/Compare To Constant'
 * '<S26>'  : 'controller/Home4/Stop Motor'
 * '<S27>'  : 'controller/Home4/Subsystem'
 * '<S28>'  : 'controller/Home4/Subsystem1'
 * '<S29>'  : 'controller/Initialize/Compare To Constant'
 * '<S30>'  : 'controller/Initialize/Subsystem'
 * '<S31>'  : 'controller/Main Control/Subsystem1'
 * '<S32>'  : 'controller/Main Control/Subsystem2'
 */
#endif                                 /* RTW_HEADER_controller_h_ */
