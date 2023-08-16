/*
 * controller_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.326
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Aug 16 16:41:44 2023
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
  5.0,

  /* Mask Parameter: CompareToConstant7_const
   * Referenced by: '<S5>/Constant'
   */
  6.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S34>/Constant'
   */
  0,

  /* Mask Parameter: CompareToConstant1_const_j
   * Referenced by: '<S14>/Constant'
   */
  true,

  /* Mask Parameter: CompareToConstant1_const_p
   * Referenced by: '<S19>/Constant'
   */
  true,

  /* Mask Parameter: CompareToConstant1_const_n
   * Referenced by: '<S24>/Constant'
   */
  true,

  /* Mask Parameter: CompareToConstant1_const_e
   * Referenced by: '<S29>/Constant'
   */
  true,

  /* Mask Parameter: CompareToConstant_const_g
   * Referenced by: '<S36>/Constant'
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
   * Referenced by: '<S6>/Constant'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S8>/Constant1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S15>/Constant'
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

  /* Expression: 10
   * Referenced by: '<S8>/Gain3'
   */
  10.0,

  /* Expression: 30
   * Referenced by: '<S8>/Saturation'
   */
  30.0,

  /* Expression: -30
   * Referenced by: '<S8>/Saturation'
   */
  -30.0,

  /* Expression: 2
   * Referenced by: '<S8>/Constant14'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S9>/Constant1'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<S20>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Delay'
   */
  0.0,

  /* Expression: 4*1024
   * Referenced by: '<S9>/Gain'
   */
  4096.0,

  /* Expression: 4*1024
   * Referenced by: '<S9>/Gain1'
   */
  4096.0,

  /* Expression: 2*pi
   * Referenced by: '<S9>/Gain2'
   */
  6.2831853071795862,

  /* Expression: 10
   * Referenced by: '<S9>/Gain3'
   */
  10.0,

  /* Expression: 30
   * Referenced by: '<S9>/Saturation'
   */
  30.0,

  /* Expression: -30
   * Referenced by: '<S9>/Saturation'
   */
  -30.0,

  /* Expression: 4
   * Referenced by: '<S10>/Constant1'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<S25>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Delay'
   */
  0.0,

  /* Expression: 4*1024
   * Referenced by: '<S10>/Gain'
   */
  4096.0,

  /* Expression: 4*1024
   * Referenced by: '<S10>/Gain1'
   */
  4096.0,

  /* Expression: 2*pi
   * Referenced by: '<S10>/Gain2'
   */
  6.2831853071795862,

  /* Expression: 10
   * Referenced by: '<S10>/Gain3'
   */
  10.0,

  /* Expression: 30
   * Referenced by: '<S10>/Saturation'
   */
  30.0,

  /* Expression: -30
   * Referenced by: '<S10>/Saturation'
   */
  -30.0,

  /* Expression: 5
   * Referenced by: '<S11>/Constant1'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S30>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S11>/Delay'
   */
  0.0,

  /* Expression: 4*1024
   * Referenced by: '<S11>/Gain'
   */
  4096.0,

  /* Expression: 4*1024
   * Referenced by: '<S11>/Gain1'
   */
  4096.0,

  /* Expression: 2*pi
   * Referenced by: '<S11>/Gain2'
   */
  6.2831853071795862,

  /* Expression: 10
   * Referenced by: '<S11>/Gain3'
   */
  10.0,

  /* Expression: 30
   * Referenced by: '<S11>/Saturation'
   */
  30.0,

  /* Expression: -30
   * Referenced by: '<S11>/Saturation'
   */
  -30.0,

  /* Expression: 1
   * Referenced by: '<S12>/Constant'
   */
  1.0,

  /* Expression: 5000
   * Referenced by: '<S12>/Constant1'
   */
  5000.0,

  /* Expression: 6
   * Referenced by: '<S13>/Constant4'
   */
  6.0,

  /* Expression: 0
   * Referenced by: '<S37>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S13>/Delay'
   */
  0.0,

  /* Expression: 4*1024
   * Referenced by: '<S13>/Gain'
   */
  4096.0,

  /* Expression: 4*1024
   * Referenced by: '<S13>/Gain1'
   */
  4096.0,

  /* Expression: 2*pi
   * Referenced by: '<S13>/Gain2'
   */
  6.2831853071795862,

  /* Expression: 3
   * Referenced by: '<S13>/Constant2'
   */
  3.0,

  /* Expression: 1
   * Referenced by: '<S13>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S13>/Sine Wave'
   */
  2.0,

  /* Expression: 50
   * Referenced by: '<S13>/Sine Wave'
   */
  50.0,

  /* Expression: 1
   * Referenced by: '<S13>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S13>/Sine Wave'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S13>/Constant1'
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

  /* Expression: 0.05
   * Referenced by: '<Root>/Constant1'
   */
  0.05,

  /* Expression: 1
   * Referenced by: '<Root>/Constant2'
   */
  1.0,

  /* Expression: -0.05
   * Referenced by: '<Root>/Constant3'
   */
  -0.05,

  /* Expression: 2
   * Referenced by: '<Root>/Constant10'
   */
  2.0,

  /* Expression: -10
   * Referenced by: '<Root>/Constant11'
   */
  -10.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant8'
   */
  2.0,

  /* Expression: 10
   * Referenced by: '<Root>/Constant9'
   */
  10.0,

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

  /* Start of '<S11>/Stop Motor1' */
  {
    /* Computed Parameter: enc_Y0
     * Referenced by: '<S31>/enc'
     */
    0.0,

    /* Expression: 2
     * Referenced by: '<S31>/Constant7'
     */
    2.0
  }
  ,

  /* End of '<S11>/Stop Motor1' */

  /* Start of '<S9>/Stop Motor1' */
  {
    /* Computed Parameter: enc_Y0
     * Referenced by: '<S21>/enc'
     */
    0.0,

    /* Expression: 2
     * Referenced by: '<S21>/Constant7'
     */
    2.0
  }
  ,

  /* End of '<S9>/Stop Motor1' */

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
