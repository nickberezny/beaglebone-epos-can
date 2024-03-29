/*
 * controller_data.c
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

#include "controller.h"

/* Block parameters (default storage) */
P_controller_T controller_P = {
  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S11>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant1_const_p
   * Referenced by: '<S19>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S29>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S2>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant1_const_i
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant3_const
   * Referenced by: '<S3>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S4>/Constant'
   */
  3.0,

  /* Mask Parameter: CompareToConstant7_const
   * Referenced by: '<S5>/Constant'
   */
  6.0,

  /* Mask Parameter: CompareToConstant_const_a
   * Referenced by: '<S27>/Constant'
   */
  0,

  /* Expression: 2
   * Referenced by: '<S7>/Constant1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S17>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S15>/Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Constant4'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S7>/Constant3'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S7>/Constant5'
   */
  3.0,

  /* Expression: 3
   * Referenced by: '<S8>/Constant1'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<S25>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S23>/Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Constant6'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S9>/Constant'
   */
  1.0,

  /* Expression: 5000
   * Referenced by: '<S9>/Constant1'
   */
  5000.0,

  /* Expression: 6
   * Referenced by: '<S10>/Constant4'
   */
  6.0,

  /* Expression: 0.001
   * Referenced by: '<S34>/Constant1'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S35>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S34>/Unit Delay'
   */
  0.0,

  /* Expression: -30
   * Referenced by: '<S34>/Constant'
   */
  -30.0,

  /* Expression: 1
   * Referenced by: '<S34>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S34>/Unit Delay1'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S10>/Constant9'
   */
  3.0,

  /* Expression: 4294967295
   * Referenced by: '<S33>/Constant6'
   */
  4.294967295E+9,

  /* Expression: 0
   * Referenced by: '<S10>/Delay1'
   */
  0.0,

  /* Expression: -20000
   * Referenced by: '<S33>/Constant8'
   */
  -20000.0,

  /* Expression: 0
   * Referenced by: '<S33>/Delay1'
   */
  0.0,

  /* Expression: 4*1024
   * Referenced by: '<S33>/Gain1'
   */
  4096.0,

  /* Expression: 4*1024
   * Referenced by: '<S33>/Gain4'
   */
  4096.0,

  /* Expression: 2*pi
   * Referenced by: '<S33>/Gain3'
   */
  6.2831853071795862,

  /* Expression: 0
   * Referenced by: '<S33>/Delay2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Constant6'
   */
  0.0,

  /* Expression: 0.4
   * Referenced by: '<S10>/Sine Wave2'
   */
  0.4,

  /* Expression: 0
   * Referenced by: '<S10>/Sine Wave2'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S10>/Sine Wave2'
   */
  0.1,

  /* Expression: -pi/2
   * Referenced by: '<S10>/Sine Wave2'
   */
  -1.5707963267948966,

  /* Expression: 0.4
   * Referenced by: '<S10>/Sine Wave1'
   */
  0.4,

  /* Expression: 0
   * Referenced by: '<S10>/Sine Wave1'
   */
  0.0,

  /* Expression: 0.3
   * Referenced by: '<S10>/Sine Wave1'
   */
  0.3,

  /* Expression: -pi/2
   * Referenced by: '<S10>/Sine Wave1'
   */
  -1.5707963267948966,

  /* Expression: 0.4
   * Referenced by: '<S10>/Sine Wave3'
   */
  0.4,

  /* Expression: 0
   * Referenced by: '<S10>/Sine Wave3'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S10>/Sine Wave3'
   */
  0.5,

  /* Expression: -pi/2
   * Referenced by: '<S10>/Sine Wave3'
   */
  -1.5707963267948966,

  /* Expression: 1.21
   * Referenced by: '<S10>/Constant3'
   */
  1.21,

  /* Expression: 8
   * Referenced by: '<S10>/Constant2'
   */
  8.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory10'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory11'
   */
  0.0,

  /* Expression: 353
   * Referenced by: '<Root>/Constant12'
   */
  353.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant13'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant15'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant4'
   */
  1.0,

  /* Expression: 5000
   * Referenced by: '<Root>/Constant5'
   */
  5000.0,

  /* Expression: 5000
   * Referenced by: '<Root>/Constant6'
   */
  5000.0,

  /* Expression: 257
   * Referenced by: '<Root>/Constant7'
   */
  257.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant14'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant2'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory12'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory13'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory14'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory15'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory16'
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

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory7'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory8'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory9'
   */
  0.0,

  /* Computed Parameter: DataStoreMemory4_InitialValue
   * Referenced by: '<Root>/Data Store Memory4'
   */
  0,

  /* Computed Parameter: DataStoreMemory6_InitialValue
   * Referenced by: '<Root>/Data Store Memory6'
   */
  0
};
