/*
 * controller_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.397
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Aug 21 17:39:09 2023
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
  2.0,

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S4>/Constant'
   */
  3.0,

  /* Mask Parameter: CompareToConstant7_const
   * Referenced by: '<S5>/Constant'
   */
  6.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S21>/Constant'
   */
  0,

  /* Mask Parameter: CompareToConstant1_const_j
   * Referenced by: '<S11>/Constant'
   */
  true,

  /* Mask Parameter: CompareToConstant1_const_k
   * Referenced by: '<S16>/Constant'
   */
  true,

  /* Mask Parameter: CompareToConstant_const_g
   * Referenced by: '<S23>/Constant'
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

  /* Expression: 2
   * Referenced by: '<S7>/Constant1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S12>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Delay'
   */
  0.0,

  /* Expression: 4*1024
   * Referenced by: '<S7>/Gain'
   */
  4096.0,

  /* Expression: 4*1024
   * Referenced by: '<S7>/Gain1'
   */
  4096.0,

  /* Expression: 2*pi
   * Referenced by: '<S7>/Gain2'
   */
  6.2831853071795862,

  /* Expression: 2
   * Referenced by: '<S7>/Constant14'
   */
  2.0,

  /* Expression: 120
   * Referenced by: '<S7>/Constant'
   */
  120.0,

  /* Expression: 150
   * Referenced by: '<S7>/Gain3'
   */
  150.0,

  /* Expression: 350
   * Referenced by: '<S7>/Saturation'
   */
  350.0,

  /* Expression: -350
   * Referenced by: '<S7>/Saturation'
   */
  -350.0,

  /* Expression: 3
   * Referenced by: '<S8>/Constant1'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<S17>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Delay'
   */
  0.0,

  /* Expression: 4*1024
   * Referenced by: '<S8>/Gain'
   */
  4096.0,

  /* Expression: 4*1024
   * Referenced by: '<S8>/Gain1'
   */
  4096.0,

  /* Expression: 2*pi
   * Referenced by: '<S8>/Gain2'
   */
  6.2831853071795862,

  /* Expression: 2
   * Referenced by: '<S8>/Constant14'
   */
  2.0,

  /* Expression: -120
   * Referenced by: '<S8>/Constant'
   */
  -120.0,

  /* Expression: 200
   * Referenced by: '<S8>/Gain3'
   */
  200.0,

  /* Expression: 350
   * Referenced by: '<S8>/Saturation'
   */
  350.0,

  /* Expression: -350
   * Referenced by: '<S8>/Saturation'
   */
  -350.0,

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

  /* Expression: 0
   * Referenced by: '<S24>/Constant'
   */
  0.0,

  /* Expression: 4*1024
   * Referenced by: '<S10>/Gain'
   */
  4096.0,

  /* Expression: 2*pi
   * Referenced by: '<S10>/Gain2'
   */
  6.2831853071795862,

  /* Expression: 3
   * Referenced by: '<S10>/Constant1'
   */
  3.0,

  /* Expression: 2
   * Referenced by: '<S10>/Constant14'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S10>/Constant2'
   */
  3.0,

  /* Expression: 1
   * Referenced by: '<S10>/Constant'
   */
  1.0,

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

  /* Expression: -0.1
   * Referenced by: '<Root>/Constant1'
   */
  -0.1,

  /* Expression: 1
   * Referenced by: '<Root>/Constant2'
   */
  1.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Constant3'
   */
  0.1,

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
