/*
 * controller_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.318
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Aug 16 15:04:38 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller_private_h_
#define RTW_HEADER_controller_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "controller.h"
#include "controller_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_roundd_snf(real_T u);
extern int32_T div_s32(int32_T numerator, int32_T denominator);
extern void controller_AnalogInput_Start(DW_AnalogInput_controller_T *localDW,
  P_AnalogInput_controller_T *localP);
extern void controller_AnalogInput(B_AnalogInput_controller_T *localB,
  DW_AnalogInput_controller_T *localDW, P_AnalogInput_controller_T *localP);
extern void controller_Home1_Init(DW_Home1_controller_T *localDW,
  P_Home1_controller_T *localP);
extern void controller_Home1_Start(DW_Home1_controller_T *localDW);
extern void controller_Home1_Disable(DW_Home1_controller_T *localDW);
extern void controller_Home1_Update(RT_MODEL_controller_T * const controller_M,
  B_Home1_controller_T *localB, DW_Home1_controller_T *localDW);
extern void controller_Home1(RT_MODEL_controller_T * const controller_M,
  boolean_T rtu_Enable, real_T rtu_motor_id, real_T rtu_home_speed, boolean_T
  rtu_LS1, const real_T *rtd_GR1, const real_T *rtd_GR2, const real_T
  *rtd_num_motors, const int32_T *rtd_pdo_id, real_T *rtd_state,
  B_Home1_controller_T *localB, DW_Home1_controller_T *localDW,
  P_Home1_controller_T *localP, ZCE_Home1_controller_T *localZCE);
extern void controller_StopMotor1_Init(B_StopMotor1_controller_T *localB,
  P_StopMotor1_controller_T *localP);
extern void controller_StopMotor1(boolean_T rtu_Trigger, const real_T
  *rtd_num_motors, const int32_T *rtd_pdo_id, B_StopMotor1_controller_T *localB,
  P_StopMotor1_controller_T *localP, ZCE_StopMotor1_controller_T *localZCE);
extern void controller_AnalogInput_Term(DW_AnalogInput_controller_T *localDW);

#endif                                 /* RTW_HEADER_controller_private_h_ */
