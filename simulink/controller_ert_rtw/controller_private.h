/*
 * controller_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 6.3
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Mon Jan 29 15:11:21 2024
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
#include "rtw_continuous.h"
#include "rtw_solver.h"

extern real_T rt_roundd_snf(real_T u);
extern int32_T div_s32(int32_T numerator, int32_T denominator);
extern void controller_StopMotor1(boolean_T rtu_Trigger, const real_T
  *rtd_num_motors, const int32_T *rtd_pdo_id, ZCE_StopMotor1_controller_T
  *localZCE);
extern void controller_MATLABFunction(B_MATLABFunction_controller_T *localB);
extern void controller_MovingAverage_Init(DW_MovingAverage_controller_T *localDW);
extern void controller_MovingAverage_Start(DW_MovingAverage_controller_T
  *localDW);
extern void controller_MovingAverage(real_T rtu_0, B_MovingAverage_controller_T *
  localB, DW_MovingAverage_controller_T *localDW);
extern void controller_MovingAverage_Term(DW_MovingAverage_controller_T *localDW);

#endif                                 /* RTW_HEADER_controller_private_h_ */
