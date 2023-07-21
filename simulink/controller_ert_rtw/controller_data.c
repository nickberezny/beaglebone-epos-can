/*
 * controller_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.193
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Jul 21 16:06:12 2023
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

  /* Mask Parameter: CompareToConstant3_const
   * Referenced by: '<S3>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S4>/Constant'
   */
  5.0,

  /* Mask Parameter: CompareToConstant5_const
   * Referenced by: '<S5>/Constant'
   */
  3.0,

  /* Mask Parameter: CompareToConstant6_const
   * Referenced by: '<S6>/Constant'
   */
  4.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S29>/Constant'
   */
  0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Read'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Read1'
   */
  0.1,

  /* Expression: 1
   * Referenced by: '<S11>/Constant'
   */
  1.0,

  /* Expression: 5000
   * Referenced by: '<S11>/Constant1'
   */
  5000.0,

  /* Expression: 1
   * Referenced by: '<S11>/Constant2'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S11>/Constant3'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<S12>/Constant7'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<S12>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S12>/Constant1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory5'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 75
   * Referenced by: '<Root>/Constant1'
   */
  75.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant2'
   */
  1.0,

  /* Expression: -75
   * Referenced by: '<Root>/Constant3'
   */
  -75.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant8'
   */
  2.0,

  /* Expression: 75
   * Referenced by: '<Root>/Constant9'
   */
  75.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant10'
   */
  2.0,

  /* Expression: -75
   * Referenced by: '<Root>/Constant11'
   */
  -75.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory2'
   */
  0.0,

  /* Computed Parameter: DataStoreMemory4_InitialValue
   * Referenced by: '<Root>/Data Store Memory4'
   */
  0,

  /* Computed Parameter: DataStoreMemory6_InitialValue
   * Referenced by: '<Root>/Data Store Memory6'
   */
  0,

  /* Computed Parameter: DataStoreMemory1_InitialValue
   * Referenced by: '<Root>/Data Store Memory1'
   */
  false,

  /* Computed Parameter: DataStoreMemory3_InitialValue
   * Referenced by: '<Root>/Data Store Memory3'
   */
  false,

  /* Start of '<Root>/Home4' */
  {
    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S25>/Constant'
     */
    true,

    /* Expression: 2
     * Referenced by: '<S26>/Constant7'
     */
    2.0,

    /* Expression: 3
     * Referenced by: '<S10>/Constant'
     */
    3.0,

    /* Expression: 4
     * Referenced by: '<S10>/Constant2'
     */
    4.0
  }
  ,

  /* End of '<Root>/Home4' */

  /* Start of '<Root>/Home3' */
  {
    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S21>/Constant'
     */
    true,

    /* Expression: 2
     * Referenced by: '<S9>/Constant'
     */
    2.0,

    /* Expression: 4
     * Referenced by: '<S9>/Constant2'
     */
    4.0
  }
  ,

  /* End of '<Root>/Home3' */

  /* Start of '<Root>/Home2' */
  {
    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S17>/Constant'
     */
    true,

    /* Expression: 2
     * Referenced by: '<S18>/Constant7'
     */
    2.0,

    /* Expression: 3
     * Referenced by: '<S8>/Constant'
     */
    3.0,

    /* Expression: 4
     * Referenced by: '<S8>/Constant2'
     */
    4.0
  }
  ,

  /* End of '<Root>/Home2' */

  /* Start of '<Root>/Home1' */
  {
    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S13>/Constant'
     */
    true,

    /* Expression: 2
     * Referenced by: '<S7>/Constant'
     */
    2.0,

    /* Expression: 4
     * Referenced by: '<S7>/Constant2'
     */
    4.0
  }
  /* End of '<Root>/Home1' */
};
