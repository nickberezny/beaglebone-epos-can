/*
 * controller.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.269
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Tue Jul 25 15:18:52 2023
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
#include "MW_bbblue_driver.h"
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

/* Block signals for system '<Root>/Analog Input' */
typedef struct {
  real_T AnalogInput;                  /* '<Root>/Analog Input' */
} B_AnalogInput_controller_T;

/* Block states (default storage) for system '<Root>/Analog Input' */
typedef struct {
  beagleboneblue_bbblueADC_cont_T obj; /* '<Root>/Analog Input' */
  boolean_T objisempty;                /* '<Root>/Analog Input' */
} DW_AnalogInput_controller_T;

/* Block signals for system '<S12>/Stop Motor' */
typedef struct {
  real_T CCaller1[2];                  /* '<S23>/C Caller1' */
} B_StopMotor_controller_T;

/* Zero-crossing (trigger) state for system '<S12>/Stop Motor' */
typedef struct {
  ZCSigState StopMotor_Trig_ZCE;       /* '<S12>/Stop Motor' */
} ZCE_StopMotor_controller_T;

/* Block signals (default storage) */
typedef struct {
  real_T TmpSignalConversionAtCCalle[3];
  real_T CCaller1[2];                  /* '<S15>/C Caller1' */
  real_T Gain2[2];                     /* '<S15>/Gain2' */
  creal_T d_data;
  creal_T b_c;
  creal_T t;
  creal_T c_s;
  creal_T d_ahi;
  creal_T c;
  creal_T t_m;
  creal_T da;
  creal_T t_c;
  real_T c_tm_mon;
  real_T c_tm_year;
  real_T second;
  real_T fracSecs;
  real_T check;
  real_T shi;
  real_T b_alo;
  real_T d_ahi_k;
  real_T DataStoreRead1_c;             /* '<Root>/Data Store Read1' */
  real_T DataStoreRead7;               /* '<Root>/Data Store Read7' */
  real_T alo;
  real_T b;
  real_T alo_c;
  real_T alo_b;
  int32_T CCaller5[2];                 /* '<S14>/C Caller5' */
  boolean_T Compare;                   /* '<S4>/Compare' */
  B_StopMotor_controller_T StopMotor_p;/* '<S13>/Stop Motor' */
  B_StopMotor_controller_T StopMotor;  /* '<S12>/Stop Motor' */
  B_AnalogInput_controller_T AnalogInput1;/* '<Root>/Analog Input' */
  B_AnalogInput_controller_T AnalogInput;/* '<Root>/Analog Input' */
} B_controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  beagleboneblue_bbblueButton_c_T obj; /* '<Root>/Button1' */
  beagleboneblue_bbblueButton_c_T obj_j;/* '<Root>/Button' */
  beagleboneblue_bbblueDigitalR_T obj_o;/* '<Root>/Digital Read3' */
  beagleboneblue_bbblueDigitalR_T obj_l;/* '<Root>/Digital Read2' */
  beagleboneblue_bbblueDigitalR_T obj_a;/* '<Root>/Digital Read1' */
  beagleboneblue_bbblueDigitalR_T obj_b;/* '<Root>/Digital Read' */
  beagleboneblue_bbblueLED_cont_T obj_n;/* '<S8>/LED' */
  real_T state;                        /* '<Root>/Data Store Memory' */
  real_T F1;                           /* '<Root>/Data Store Memory10' */
  real_T F2;                           /* '<Root>/Data Store Memory11' */
  real_T max_speed;                    /* '<Root>/Data Store Memory12' */
  real_T max_accel;                    /* '<Root>/Data Store Memory13' */
  real_T GR1;                          /* '<Root>/Data Store Memory14' */
  real_T GR2;                          /* '<Root>/Data Store Memory15' */
  real_T q01;                          /* '<Root>/Data Store Memory2' */
  real_T q02;                          /* '<Root>/Data Store Memory5' */
  real_T num_motors;                   /* '<Root>/Data Store Memory7' */
  int32_T pdo_id;                      /* '<Root>/Data Store Memory4' */
  int32_T cfg_id;                      /* '<Root>/Data Store Memory6' */
  uint8_T LS1_R;                       /* '<Root>/Data Store Memory1' */
  uint8_T LS1_L;                       /* '<Root>/Data Store Memory8' */
  boolean_T LS2_R;                     /* '<Root>/Data Store Memory3' */
  boolean_T LS2_L;                     /* '<Root>/Data Store Memory9' */
  boolean_T objisempty;                /* '<S8>/LED' */
  boolean_T objisempty_f;              /* '<Root>/Digital Read3' */
  boolean_T objisempty_f2;             /* '<Root>/Digital Read2' */
  boolean_T objisempty_i;              /* '<Root>/Digital Read1' */
  boolean_T objisempty_g;              /* '<Root>/Digital Read' */
  boolean_T objisempty_g4;             /* '<Root>/Button1' */
  boolean_T objisempty_d;              /* '<Root>/Button' */
  boolean_T MainControl_MODE;          /* '<Root>/Main Control' */
  boolean_T Initialize_MODE;           /* '<Root>/Initialize' */
  DW_AnalogInput_controller_T AnalogInput1;/* '<Root>/Analog Input' */
  DW_AnalogInput_controller_T AnalogInput;/* '<Root>/Analog Input' */
} DW_controller_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_StopMotor_controller_T StopMotor_p;/* '<S13>/Stop Motor' */
  ZCE_StopMotor_controller_T StopMotor;/* '<S12>/Stop Motor' */
  ZCSigState ExitControl_Trig_ZCE;     /* '<Root>/Exit Control' */
  ZCSigState Estop_Trig_ZCE;           /* '<Root>/E-stop' */
} PrevZCX_controller_T;

/* Parameters for system: '<Root>/Analog Input' */
struct P_AnalogInput_controller_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: 0.1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
};

/* Parameters for system: '<Root>/Home1' */
struct P_Home1_controller_T_ {
  uint8_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S16>/Constant'
                                       */
  real_T Constant_Value;               /* Expression: 2
                                        * Referenced by: '<S10>/Constant'
                                        */
};

/* Parameters for system: '<S12>/Stop Motor' */
struct P_StopMotor_controller_T_ {
  real_T enc_Y0;                       /* Computed Parameter: enc_Y0
                                        * Referenced by: '<S23>/enc'
                                        */
  real_T Constant7_Value;              /* Expression: 2
                                        * Referenced by: '<S23>/Constant7'
                                        */
};

/* Parameters (default storage) */
struct P_controller_T_ {
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S2>/Constant'
                                      */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S1>/Constant'
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
  real_T CompareToConstant7_const;   /* Mask Parameter: CompareToConstant7_const
                                      * Referenced by: '<S7>/Constant'
                                      */
  int32_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S30>/Constant'
                                       */
  uint8_T CompareToConstant_const_n;/* Mask Parameter: CompareToConstant_const_n
                                     * Referenced by: '<S22>/Constant'
                                     */
  uint8_T CompareToConstant_const_m;/* Mask Parameter: CompareToConstant_const_m
                                     * Referenced by: '<S26>/Constant'
                                     */
  uint8_T CompareToConstant_const_g;/* Mask Parameter: CompareToConstant_const_g
                                     * Referenced by: '<S32>/Constant'
                                     */
  real_T Button_SampleTime;            /* Expression: 0.1
                                        * Referenced by: '<Root>/Button'
                                        */
  real_T Button1_SampleTime;           /* Expression: 0.1
                                        * Referenced by: '<Root>/Button1'
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
  real_T Constant_Value;               /* Expression: -1
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Constant_Value_o;             /* Expression: 3
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: 5
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Constant1_Value_f;            /* Expression: 5000
                                        * Referenced by: '<S14>/Constant1'
                                        */
  real_T Constant4_Value;              /* Expression: 6
                                        * Referenced by: '<S15>/Constant4'
                                        */
  real_T Gain_Gain;                    /* Expression: 4*1024
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 4*1024
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 2*pi
                                        * Referenced by: '<S15>/Gain2'
                                        */
  real_T Constant2_Value;              /* Expression: 3
                                        * Referenced by: '<S15>/Constant2'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S15>/Constant3'
                                        */
  real_T Constant1_Value_m;            /* Expression: 2
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S15>/Constant5'
                                        */
  real_T Constant12_Value;             /* Expression: 353
                                        * Referenced by: '<Root>/Constant12'
                                        */
  real_T Constant13_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant13'
                                        */
  real_T Constant4_Value_g;            /* Expression: 2
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant5_Value_i;            /* Expression: 5000
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 5000
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 126
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant14_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant14'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value_i;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value_m;            /* Expression: 2
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value_j;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Constant10_Value;             /* Expression: 2
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T Constant11_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant11'
                                        */
  real_T DataStoreMemory_InitialValue; /* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory'
                                        */
  real_T DataStoreMemory10_InitialValue;/* Expression: 0
                                         * Referenced by: '<Root>/Data Store Memory10'
                                         */
  real_T DataStoreMemory11_InitialValue;/* Expression: 0
                                         * Referenced by: '<Root>/Data Store Memory11'
                                         */
  real_T DataStoreMemory12_InitialValue;/* Expression: 0
                                         * Referenced by: '<Root>/Data Store Memory12'
                                         */
  real_T DataStoreMemory13_InitialValue;/* Expression: 0
                                         * Referenced by: '<Root>/Data Store Memory13'
                                         */
  real_T DataStoreMemory14_InitialValue;/* Expression: 0
                                         * Referenced by: '<Root>/Data Store Memory14'
                                         */
  real_T DataStoreMemory15_InitialValue;/* Expression: 0
                                         * Referenced by: '<Root>/Data Store Memory15'
                                         */
  real_T DataStoreMemory2_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory2'
                                        */
  real_T DataStoreMemory5_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory5'
                                        */
  real_T DataStoreMemory7_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory7'
                                        */
  int32_T DataStoreMemory4_InitialValue;
                            /* Computed Parameter: DataStoreMemory4_InitialValue
                             * Referenced by: '<Root>/Data Store Memory4'
                             */
  int32_T DataStoreMemory6_InitialValue;
                            /* Computed Parameter: DataStoreMemory6_InitialValue
                             * Referenced by: '<Root>/Data Store Memory6'
                             */
  boolean_T DataStoreMemory3_InitialValue;
                            /* Computed Parameter: DataStoreMemory3_InitialValue
                             * Referenced by: '<Root>/Data Store Memory3'
                             */
  boolean_T DataStoreMemory9_InitialValue;
                            /* Computed Parameter: DataStoreMemory9_InitialValue
                             * Referenced by: '<Root>/Data Store Memory9'
                             */
  uint8_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<Root>/Data Store Memory1'
                             */
  uint8_T DataStoreMemory8_InitialValue;
                            /* Computed Parameter: DataStoreMemory8_InitialValue
                             * Referenced by: '<Root>/Data Store Memory8'
                             */
  P_StopMotor_controller_T StopMotor_p;/* '<S13>/Stop Motor' */
  P_StopMotor_controller_T StopMotor;  /* '<S12>/Stop Motor' */
  P_Home1_controller_T Home2;          /* '<Root>/Home2' */
  P_Home1_controller_T Home1;          /* '<Root>/Home1' */
  P_AnalogInput_controller_T AnalogInput1;/* '<Root>/Analog Input' */
  P_AnalogInput_controller_T AnalogInput;/* '<Root>/Analog Input' */
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
 * Block '<S15>/Derivative' : Unused code path elimination
 * Block '<S18>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S25>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S29>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S35>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S36>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S7>'   : 'controller/Compare To Constant7'
 * '<S8>'   : 'controller/E-stop'
 * '<S9>'   : 'controller/Exit Control'
 * '<S10>'  : 'controller/Home1'
 * '<S11>'  : 'controller/Home2'
 * '<S12>'  : 'controller/Home3'
 * '<S13>'  : 'controller/Home4'
 * '<S14>'  : 'controller/Initialize'
 * '<S15>'  : 'controller/Main Control'
 * '<S16>'  : 'controller/Home1/Compare To Constant'
 * '<S17>'  : 'controller/Home1/Subsystem'
 * '<S18>'  : 'controller/Home1/Subsystem1'
 * '<S19>'  : 'controller/Home2/Compare To Constant'
 * '<S20>'  : 'controller/Home2/Subsystem'
 * '<S21>'  : 'controller/Home2/Subsystem1'
 * '<S22>'  : 'controller/Home3/Compare To Constant'
 * '<S23>'  : 'controller/Home3/Stop Motor'
 * '<S24>'  : 'controller/Home3/Subsystem'
 * '<S25>'  : 'controller/Home3/Subsystem1'
 * '<S26>'  : 'controller/Home4/Compare To Constant'
 * '<S27>'  : 'controller/Home4/Stop Motor'
 * '<S28>'  : 'controller/Home4/Subsystem'
 * '<S29>'  : 'controller/Home4/Subsystem1'
 * '<S30>'  : 'controller/Initialize/Compare To Constant'
 * '<S31>'  : 'controller/Initialize/Subsystem'
 * '<S32>'  : 'controller/Main Control/Compare To Constant'
 * '<S33>'  : 'controller/Main Control/MATLAB Function'
 * '<S34>'  : 'controller/Main Control/Subsystem'
 * '<S35>'  : 'controller/Main Control/Subsystem1'
 * '<S36>'  : 'controller/Main Control/Subsystem2'
 */
#endif                                 /* RTW_HEADER_controller_h_ */
