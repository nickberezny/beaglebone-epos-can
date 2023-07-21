/*
 * controller_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.196
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Jul 21 16:47:09 2023
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

extern void controller_StopMotor(boolean_T rtu_Trigger, const int32_T
  *rtd_cfg_id, ZCE_StopMotor_controller_T *localZCE);
extern void controller_StopMotor_p(boolean_T rtu_Trigger, const int32_T
  *rtd_cfg_id, real_T *rtd_enc1, const int32_T *rtd_pdo_id,
  P_StopMotor_controller_a_T *localP, ZCE_StopMotor_controller_a_T *localZCE);

#endif                                 /* RTW_HEADER_controller_private_h_ */
