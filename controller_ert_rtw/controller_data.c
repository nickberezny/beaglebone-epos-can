/*
 * controller_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.294
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Tue Aug  8 10:07:50 2023
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
  true,

  /* Mask Parameter: CompareToConstant_const_m
   * Referenced by: '<S28>/Constant'
   */
  true,

  /* Mask Parameter: CompareToConstant_const_g
   * Referenced by: '<S34>/Constant'
   */
  true,

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

  /* Expression: 3
   * Referenced by: '<S12>/Constant'
   */
  3.0,

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

  /* Expression: 6
   * Referenced by: '<S15>/Constant4'
   */
  6.0,

  /* Expression: 0
   * Referenced by: '<S35>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S15>/Delay'
   */
  0.0,

  /* Expression: 4*1024
   * Referenced by: '<S15>/Gain'
   */
  4096.0,

  /* Expression: 4*1024
   * Referenced by: '<S15>/Gain1'
   */
  4096.0,

  /* Expression: 2*pi
   * Referenced by: '<S15>/Gain2'
   */
  6.2831853071795862,

  /* Expression: 3
   * Referenced by: '<S15>/Constant2'
   */
  3.0,

  /* Expression: 1
   * Referenced by: '<S15>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S15>/Sine Wave'
   */
  2.0,

  /* Expression: 50
   * Referenced by: '<S15>/Sine Wave'
   */
  50.0,

  /* Expression: 1
   * Referenced by: '<S15>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S15>/Sine Wave'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S15>/Constant1'
   */
  2.0,

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

  /* Expression: 50
   * Referenced by: '<Root>/Constant1'
   */
  50.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant2'
   */
  2.0,

  /* Expression: 50
   * Referenced by: '<Root>/Constant3'
   */
  50.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant8'
   */
  1.0,

  /* Expression: -50
   * Referenced by: '<Root>/Constant9'
   */
  -50.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant10'
   */
  2.0,

  /* Expression: -50
   * Referenced by: '<Root>/Constant11'
   */
  -50.0,

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
   * Referenced by: '<Root>/Data Store Memory16'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory2'
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

  /* Computed Parameter: DataStoreMemory8_InitialValue
   * Referenced by: '<Root>/Data Store Memory8'
   */
  false,

  /* Computed Parameter: DataStoreMemory9_InitialValue
   * Referenced by: '<Root>/Data Store Memory9'
   */
  false,

  /* Start of '<S13>/Stop Motor' */
  {
    /* Computed Parameter: enc_Y0
     * Referenced by: '<S29>/enc'
     */
    0.0,

    /* Expression: 2
     * Referenced by: '<S29>/Constant7'
     */
    2.0
  }
  ,

  /* End of '<S13>/Stop Motor' */

  /* Start of '<S12>/Stop Motor' */
  {
    /* Computed Parameter: enc_Y0
     * Referenced by: '<S25>/enc'
     */
    0.0,

    /* Expression: 2
     * Referenced by: '<S25>/Constant7'
     */
    2.0
  }
  ,

  /* End of '<S12>/Stop Motor' */

  /* Start of '<Root>/Home2' */
  {
    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S20>/Constant'
     */
    true,

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
    true,

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
