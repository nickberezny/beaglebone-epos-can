/*
 * controller.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.571
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Oct  2 12:25:29 2023
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
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <string.h>
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

/* Zero-crossing (trigger) state for system '<S7>/Stop Motor1' */
typedef struct {
  ZCSigState StopMotor1_Trig_ZCE;      /* '<S7>/Stop Motor1' */
} ZCE_StopMotor1_controller_T;

/* Block signals (default storage) */
typedef struct {
  real_T CCaller4[8];                  /* '<S10>/C Caller4' */
  real_T CCaller6[2];                  /* '<S10>/C Caller6' */
  real_T Delay1[2];                    /* '<S10>/Delay1' */
  real_T Switch2[2];                   /* '<S10>/Switch2' */
  real_T Gain3[2];                     /* '<S10>/Gain3' */
  real_T TmpSignalConversionAtCCal_e[2];
  real_T Switch_g[2];                  /* '<S7>/Switch' */
  real_T Switch[2];                    /* '<S8>/Switch' */
  creal_T d_data;
  creal_T b_c;
  creal_T t;
  creal_T c_s;
  creal_T d_ahi;
  creal_T c;
  creal_T t_m;
  creal_T da;
  creal_T t_c;
  real_T Add1;                         /* '<S25>/Add1' */
  real_T Add1_o;                       /* '<S26>/Add1' */
  real_T SineWave1;                    /* '<S10>/Sine Wave1' */
  real_T Divide[2];                    /* '<S10>/Divide' */
  real_T Saturation;                   /* '<S10>/Saturation' */
  real_T Saturation1;                  /* '<S10>/Saturation1' */
  real_T y;                            /* '<S30>/MATLAB Function' */
  real_T c_tm_year;
  real_T second;
  real_T fracSecs;
  real_T check;
  real_T shi;
  real_T DataStoreRead1_c;             /* '<Root>/Data Store Read1' */
  real_T DataStoreRead7;               /* '<Root>/Data Store Read7' */
  real_T DataStoreRead8;               /* '<Root>/Data Store Read8' */
  real_T Sum1;                         /* '<S30>/Sum1' */
  real_T alo;
  real_T b;
  real_T alo_k;
  real_T alo_c;
  int32_T CCaller5[2];                 /* '<S9>/C Caller5' */
  boolean_T Compare;                   /* '<S1>/Compare' */
  boolean_T Compare_m;                 /* '<S3>/Compare' */
  boolean_T Compare_j;                 /* '<S4>/Compare' */
  boolean_T LogicalOperator3[2];       /* '<S10>/Logical Operator3' */
  B_AnalogInput_controller_T AnalogInput1;/* '<Root>/Analog Input' */
  B_AnalogInput_controller_T AnalogInput;/* '<Root>/Analog Input' */
} B_controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  beagleboneblue_bbblueDigitalR_T obj; /* '<Root>/Digital Read3' */
  beagleboneblue_bbblueDigitalR_T obj_l;/* '<Root>/Digital Read2' */
  beagleboneblue_bbblueDigitalR_T obj_a;/* '<Root>/Digital Read1' */
  beagleboneblue_bbblueDigitalR_T obj_b;/* '<Root>/Digital Read' */
  real_T Delay1_DSTATE[2];             /* '<S10>/Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S30>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S30>/Unit Delay1' */
  real_T Delay_DSTATE[2];              /* '<S8>/Delay' */
  real_T Delay_DSTATE_n[2];            /* '<S7>/Delay' */
  real_T state;                        /* '<Root>/Data Store Memory' */
  real_T F1;                           /* '<Root>/Data Store Memory10' */
  real_T F2;                           /* '<Root>/Data Store Memory11' */
  real_T max_speed;                    /* '<Root>/Data Store Memory12' */
  real_T max_accel;                    /* '<Root>/Data Store Memory13' */
  real_T GR1;                          /* '<Root>/Data Store Memory14' */
  real_T GR2;                          /* '<Root>/Data Store Memory15' */
  real_T debug;                        /* '<Root>/Data Store Memory16' */
  real_T q01;                          /* '<Root>/Data Store Memory2' */
  real_T q02;                          /* '<Root>/Data Store Memory5' */
  real_T num_motors;                   /* '<Root>/Data Store Memory7' */
  real_T TimeStampA;                   /* '<S10>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S10>/Derivative' */
  real_T TimeStampB;                   /* '<S10>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S10>/Derivative' */
  int32_T pdo_id;                      /* '<Root>/Data Store Memory4' */
  int32_T cfg_id;                      /* '<Root>/Data Store Memory6' */
  boolean_T LS1_R;                     /* '<Root>/Data Store Memory1' */
  boolean_T LS2_R;                     /* '<Root>/Data Store Memory3' */
  boolean_T LS1_L;                     /* '<Root>/Data Store Memory8' */
  boolean_T LS2_L;                     /* '<Root>/Data Store Memory9' */
  boolean_T objisempty;                /* '<Root>/Digital Read3' */
  boolean_T objisempty_f;              /* '<Root>/Digital Read2' */
  boolean_T objisempty_i;              /* '<Root>/Digital Read1' */
  boolean_T objisempty_g;              /* '<Root>/Digital Read' */
  boolean_T MainControl_MODE;          /* '<Root>/Main Control' */
  boolean_T Initialize_MODE;           /* '<Root>/Initialize' */
  boolean_T Home2_MODE;                /* '<Root>/Home2' */
  boolean_T Home1_MODE;                /* '<Root>/Home1' */
  DW_AnalogInput_controller_T AnalogInput1;/* '<Root>/Analog Input' */
  DW_AnalogInput_controller_T AnalogInput;/* '<Root>/Analog Input' */
} DW_controller_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_StopMotor1_controller_T StopMotor1_n;/* '<S8>/Stop Motor1' */
  ZCE_StopMotor1_controller_T StopMotor1;/* '<S7>/Stop Motor1' */
  ZCSigState ExitControl_Trig_ZCE;     /* '<Root>/Exit Control' */
} PrevZCX_controller_T;

/* Parameters for system: '<Root>/Analog Input' */
struct P_AnalogInput_controller_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: 0.1
                                        * Referenced by: '<Root>/Analog Input'
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
  real_T CompareToConstant7_const;   /* Mask Parameter: CompareToConstant7_const
                                      * Referenced by: '<S5>/Constant'
                                      */
  int32_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S21>/Constant'
                                       */
  boolean_T CompareToConstant1_const_j;
                                   /* Mask Parameter: CompareToConstant1_const_j
                                    * Referenced by: '<S11>/Constant'
                                    */
  boolean_T CompareToConstant1_const_k;
                                   /* Mask Parameter: CompareToConstant1_const_k
                                    * Referenced by: '<S16>/Constant'
                                    */
  boolean_T CompareToConstant_const_g;
                                    /* Mask Parameter: CompareToConstant_const_g
                                     * Referenced by: '<S23>/Constant'
                                     */
  real_T DigitalRead_SampleTime;       /* Expression: 0.001
                                        * Referenced by: '<Root>/Digital Read'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: 0.001
                                        * Referenced by: '<Root>/Digital Read1'
                                        */
  real_T DigitalRead2_SampleTime;      /* Expression: 0.001
                                        * Referenced by: '<Root>/Digital Read2'
                                        */
  real_T DigitalRead3_SampleTime;      /* Expression: 0.001
                                        * Referenced by: '<Root>/Digital Read3'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S7>/Delay'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S7>/Constant4'
                                        */
  real_T Constant2_Value;              /* Expression: 3
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T Constant1_Value_a;            /* Expression: 3
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Constant_Value_f;             /* Expression: 0
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Delay_InitialCondition_k;     /* Expression: 0
                                        * Referenced by: '<S8>/Delay'
                                        */
  real_T Constant2_Value_a;            /* Expression: 0
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T Constant14_Value;             /* Expression: 2
                                        * Referenced by: '<S8>/Constant14'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant1_Value_f;            /* Expression: 5000
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T Constant4_Value_l;            /* Expression: 6
                                        * Referenced by: '<S10>/Constant4'
                                        */
  real_T Constant1_Value_j;            /* Expression: 0.001
                                        * Referenced by: '<S30>/Constant1'
                                        */
  real_T Constant_Value_fw;            /* Expression: 0
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Constant6_Value;              /* Expression: 4294967295
                                        * Referenced by: '<S10>/Constant6'
                                        */
  real_T Constant8_Value;              /* Expression: -20000
                                        * Referenced by: '<S10>/Constant8'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S10>/Delay1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 4*1024
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Gain4_Gain;                   /* Expression: 4*1024
                                        * Referenced by: '<S10>/Gain4'
                                        */
  real_T Gain3_Gain;                   /* Expression: 2*pi
                                        * Referenced by: '<S10>/Gain3'
                                        */
  real_T Constant1_Value_fp;           /* Expression: 4
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T l2_Value;                     /* Expression: 0.28
                                        * Referenced by: '<S10>/l2'
                                        */
  real_T Constant_Value_k;             /* Expression: 2*pi
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T Constant7_Value;              /* Expression: pi*44/180
                                        * Referenced by: '<S10>/Constant7'
                                        */
  real_T Constant10_Value;             /* Expression: pi*98/180
                                        * Referenced by: '<S10>/Constant10'
                                        */
  real_T Constant1_Value_i;            /* Expression: pi
                                        * Referenced by: '<S25>/Constant1'
                                        */
  real_T l1_Value;                     /* Expression: 0.37
                                        * Referenced by: '<S10>/l1'
                                        */
  real_T Constant9_Value;              /* Expression: 3
                                        * Referenced by: '<S10>/Constant9'
                                        */
  real_T Constant_Value_c;             /* Expression: 2*pi
                                        * Referenced by: '<S26>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: pi
                                        * Referenced by: '<S26>/Constant1'
                                        */
  real_T Constant14_Value_g;           /* Expression: 2
                                        * Referenced by: '<S10>/Constant14'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S30>/Unit Delay'
                                        */
  real_T Constant_Value_m;             /* Expression: -30
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T Constant2_Value_c;            /* Expression: 1
                                        * Referenced by: '<S30>/Constant2'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S30>/Unit Delay1'
                                        */
  real_T SineWave1_Amp;                /* Expression: 0.3
                                        * Referenced by: '<S10>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0.3
                                        * Referenced by: '<S10>/Sine Wave1'
                                        */
  real_T SineWave1_Freq;               /* Expression: 1.5
                                        * Referenced by: '<S10>/Sine Wave1'
                                        */
  real_T SineWave1_Phase;              /* Expression: -pi/2
                                        * Referenced by: '<S10>/Sine Wave1'
                                        */
  real_T Gain_Gain;                    /* Expression: 5000/1.4
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: 200*0.001
                                        * Referenced by: '<S10>/Gain2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 400
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -400
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Constant5_Value;              /* Expression: 2
                                        * Referenced by: '<S10>/Constant5'
                                        */
  real_T Gain5_Gain;                   /* Expression: 5000/1.4
                                        * Referenced by: '<S10>/Gain5'
                                        */
  real_T Gain6_Gain;                   /* Expression: 200*0.001
                                        * Referenced by: '<S10>/Gain6'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 400
                                        * Referenced by: '<S10>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -400
                                        * Referenced by: '<S10>/Saturation1'
                                        */
  real_T Constant2_Value_i;            /* Expression: 8
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Constant12_Value;             /* Expression: 353
                                        * Referenced by: '<Root>/Constant12'
                                        */
  real_T Constant13_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant13'
                                        */
  real_T Constant15_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant15'
                                        */
  real_T Constant4_Value_g;            /* Expression: 2
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant5_Value_i;            /* Expression: 5000
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant6_Value_n;            /* Expression: 5000
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant7_Value_p;            /* Expression: 257
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant14_Value_c;           /* Expression: 1
                                        * Referenced by: '<Root>/Constant14'
                                        */
  real_T Constant_Value_c3;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant2_Value_k;            /* Expression: 2
                                        * Referenced by: '<Root>/Constant2'
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
  real_T DataStoreMemory16_InitialValue;/* Expression: 0
                                         * Referenced by: '<Root>/Data Store Memory16'
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
  boolean_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<Root>/Data Store Memory1'
                             */
  boolean_T DataStoreMemory3_InitialValue;
                            /* Computed Parameter: DataStoreMemory3_InitialValue
                             * Referenced by: '<Root>/Data Store Memory3'
                             */
  boolean_T DataStoreMemory8_InitialValue;
                            /* Computed Parameter: DataStoreMemory8_InitialValue
                             * Referenced by: '<Root>/Data Store Memory8'
                             */
  boolean_T DataStoreMemory9_InitialValue;
                            /* Computed Parameter: DataStoreMemory9_InitialValue
                             * Referenced by: '<Root>/Data Store Memory9'
                             */
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
      uint32_T TID[7];
    } TaskCounters;

    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[7];
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
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<Root>/Constant3' : Unused code path elimination
 * Block '<S7>/Derivative' : Unused code path elimination
 * Block '<S7>/Divide' : Unused code path elimination
 * Block '<S7>/Gain' : Unused code path elimination
 * Block '<S7>/Gain1' : Unused code path elimination
 * Block '<S7>/Gain2' : Unused code path elimination
 * Block '<S8>/Derivative' : Unused code path elimination
 * Block '<S8>/Divide' : Unused code path elimination
 * Block '<S8>/Gain' : Unused code path elimination
 * Block '<S8>/Gain1' : Unused code path elimination
 * Block '<S8>/Gain2' : Unused code path elimination
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S7>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S14>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion10' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S28>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S29>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S5>'   : 'controller/Compare To Constant7'
 * '<S6>'   : 'controller/Exit Control'
 * '<S7>'   : 'controller/Home1'
 * '<S8>'   : 'controller/Home2'
 * '<S9>'   : 'controller/Initialize'
 * '<S10>'  : 'controller/Main Control'
 * '<S11>'  : 'controller/Home1/Compare To Constant1'
 * '<S12>'  : 'controller/Home1/Compare To Zero'
 * '<S13>'  : 'controller/Home1/Stop Motor1'
 * '<S14>'  : 'controller/Home1/Subsystem1'
 * '<S15>'  : 'controller/Home1/Subsystem2'
 * '<S16>'  : 'controller/Home2/Compare To Constant1'
 * '<S17>'  : 'controller/Home2/Compare To Zero'
 * '<S18>'  : 'controller/Home2/Stop Motor1'
 * '<S19>'  : 'controller/Home2/Subsystem1'
 * '<S20>'  : 'controller/Home2/Subsystem2'
 * '<S21>'  : 'controller/Initialize/Compare To Constant'
 * '<S22>'  : 'controller/Initialize/Subsystem'
 * '<S23>'  : 'controller/Main Control/Compare To Constant'
 * '<S24>'  : 'controller/Main Control/Compare To Zero2'
 * '<S25>'  : 'controller/Main Control/Kin X'
 * '<S26>'  : 'controller/Main Control/Kin X1'
 * '<S27>'  : 'controller/Main Control/Subsystem'
 * '<S28>'  : 'controller/Main Control/Subsystem1'
 * '<S29>'  : 'controller/Main Control/Subsystem2'
 * '<S30>'  : 'controller/Main Control/Sys Time'
 * '<S31>'  : 'controller/Main Control/Sys Time/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_controller_h_ */
