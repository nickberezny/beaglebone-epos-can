/*
 * controller_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.58
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Jul 14 21:53:10 2023
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
  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<Root>/Gain'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<Root>/Delay1'
   */
  0.0,

  /* Expression: 200000
   * Referenced by: '<Root>/Constant3'
   */
  200000.0,

  /* Expression: -1/20
   * Referenced by: '<Root>/Gain1'
   */
  -0.05,

  /* Expression: 500
   * Referenced by: '<Root>/Saturation'
   */
  500.0,

  /* Expression: -500
   * Referenced by: '<Root>/Saturation'
   */
  -500.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant4'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<Root>/Constant5'
   */
  3.0,

  /* Expression: 4
   * Referenced by: '<Root>/Constant2'
   */
  4.0
};
