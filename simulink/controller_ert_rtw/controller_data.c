/*
 * controller_data.c
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

#include "controller.h"

/* Block parameters (default storage) */
P_controller_T controller_P = {
  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S2>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S9>/Constant'
   */
  0,

  /* Mask Parameter: CompareToConstant_const_b
   * Referenced by: '<S5>/Constant'
   */
  true,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Read'
   */
  0.1,

  /* Expression: 1
   * Referenced by: '<S3>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S4>/Constant'
   */
  1.0,

  /* Expression: 5000
   * Referenced by: '<S4>/Constant1'
   */
  5000.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant7'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant'
   */
  2.0,

  /* Expression: 75
   * Referenced by: '<Root>/Constant1'
   */
  75.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory5'
   */
  0.0,

  /* Computed Parameter: DataStoreMemory4_InitialValue
   * Referenced by: '<Root>/Data Store Memory4'
   */
  0,

  /* Computed Parameter: DataStoreMemory1_InitialValue
   * Referenced by: '<Root>/Data Store Memory1'
   */
  false
};
