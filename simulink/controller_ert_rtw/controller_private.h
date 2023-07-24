/*
 * controller_private.h
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

extern void controller_Home1(boolean_T rtu_Enable, real_T rtu_motor_id, real_T
  rtu_homing_torque, const boolean_T *rtd_LS1, const int32_T *rtd_cfg_id, const
  int32_T *rtd_pdo_id, real_T *rtd_state, P_Home1_controller_T *localP,
  ZCE_Home1_controller_T *localZCE);
extern void controller_StopMotor(boolean_T rtu_Trigger, const int32_T
  *rtd_cfg_id, real_T *rtd_enc1, const int32_T *rtd_pdo_id,
  P_StopMotor_controller_T *localP, ZCE_StopMotor_controller_T *localZCE);

#endif                                 /* RTW_HEADER_controller_private_h_ */
