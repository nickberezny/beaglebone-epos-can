/*
 * controller_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.97
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Jul 20 15:36:39 2023
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
  /* Expression: 5000
   * Referenced by: '<Root>/Constant1'
   */
  5000.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant7'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant10'
   */
  2.0,

  /* Expression: 10
   * Referenced by: '<Root>/Step'
   */
  10.0,

  /* Expression: 75
   * Referenced by: '<Root>/Step'
   */
  75.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<Root>/Saturation'
   */
  100.0,

  /* Expression: -100
   * Referenced by: '<Root>/Saturation'
   */
  -100.0,

  /* Expression: 0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Expression: 100000
   * Referenced by: '<Root>/Gain'
   */
  100000.0,

  /* Expression: 4
   * Referenced by: '<Root>/Constant2'
   */
  4.0
};
