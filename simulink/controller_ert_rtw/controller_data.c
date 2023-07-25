/*
 * controller_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.246
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Tue Jul 25 10:06:33 2023
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
  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S2>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant3_const
   * Referenced by: '<S3>/Constant'
   */
  3.0,

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S4>/Constant'
   */
  5.0,

  /* Mask Parameter: CompareToConstant5_const
   * Referenced by: '<S5>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant6_const
   * Referenced by: '<S6>/Constant'
   */
  4.0,

  /* Mask Parameter: CompareToConstant7_const
   * Referenced by: '<S7>/Constant'
   */
  6.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S32>/Constant'
   */
  0,

  /* Mask Parameter: CompareToConstant_const_n
   * Referenced by: '<S24>/Constant'
   */
  1U,

  /* Mask Parameter: CompareToConstant_const_m
   * Referenced by: '<S28>/Constant'
   */
  1U,

  /* Expression: 0.1
   * Referenced by: '<Root>/Button'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<Root>/Button1'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Read'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Read1'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Read2'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Read3'
   */
  0.1,

  /* Expression: -1
   * Referenced by: '<S8>/Constant'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Constant1'
   */
  0.0,

  /* Computed Parameter: enc_Y0
   * Referenced by: '<S25>/enc'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S25>/Constant7'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S12>/Constant'
   */
  3.0,

  /* Expression: 2
   * Referenced by: '<S29>/Constant7'
   */
  2.0,

  /* Expression: 5
   * Referenced by: '<S13>/Constant'
   */
  5.0,

  /* Expression: 1
   * Referenced by: '<S14>/Constant'
   */
  1.0,

  /* Expression: 5000
   * Referenced by: '<S14>/Constant1'
   */
  5000.0,

  /* Expression: 1024
   * Referenced by: '<S15>/Gain'
   */
  1024.0,

  /* Expression: 1024
   * Referenced by: '<S15>/Gain1'
   */
  1024.0,

  /* Expression: 3
   * Referenced by: '<S15>/Constant2'
   */
  3.0,

  /* Expression: 1
   * Referenced by: '<S15>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S15>/Constant3'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S15>/Constant1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S15>/Constant5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory5'
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

  /* Expression: 2
   * Referenced by: '<Root>/Constant4'
   */
  2.0,

  /* Expression: 5000
   * Referenced by: '<Root>/Constant5'
   */
  5000.0,

  /* Expression: 5000
   * Referenced by: '<Root>/Constant6'
   */
  5000.0,

  /* Expression: 126
   * Referenced by: '<Root>/Constant7'
   */
  126.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant14'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 75
   * Referenced by: '<Root>/Constant1'
   */
  75.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant2'
   */
  2.0,

  /* Expression: 75
   * Referenced by: '<Root>/Constant3'
   */
  75.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant8'
   */
  1.0,

  /* Expression: -75
   * Referenced by: '<Root>/Constant9'
   */
  -75.0,

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
   * Referenced by: '<Root>/Data Store Memory10'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory11'
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
   * Referenced by: '<Root>/Data Store Memory2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory7'
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

  /* Computed Parameter: DataStoreMemory3_InitialValue
   * Referenced by: '<Root>/Data Store Memory3'
   */
  false,

  /* Computed Parameter: DataStoreMemory8_InitialValue
   * Referenced by: '<Root>/Data Store Memory8'
   */
  false,

  /* Computed Parameter: DataStoreMemory9_InitialValue
   * Referenced by: '<Root>/Data Store Memory9'
   */
  false,

  /* Computed Parameter: DataStoreMemory1_InitialValue
   * Referenced by: '<Root>/Data Store Memory1'
   */
  0U,

  /* Start of '<Root>/Home2' */
  {
    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S20>/Constant'
     */
    1U,

    /* Expression: 4
     * Referenced by: '<S11>/Constant'
     */
    4.0
  }
  ,

  /* End of '<Root>/Home2' */

  /* Start of '<Root>/Home1' */
  {
    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S16>/Constant'
     */
    1U,

    /* Expression: 2
     * Referenced by: '<S10>/Constant'
     */
    2.0
  }
  ,

  /* End of '<Root>/Home1' */

  /* Start of '<Root>/Analog Input1' */
  {
    /* Expression: 0.1
     * Referenced by: '<Root>/Analog Input1'
     */
    0.1
  }
  ,

  /* End of '<Root>/Analog Input1' */

  /* Start of '<Root>/Analog Input' */
  {
    /* Expression: 0.1
     * Referenced by: '<Root>/Analog Input'
     */
    0.1
  }
  /* End of '<Root>/Analog Input' */
};
