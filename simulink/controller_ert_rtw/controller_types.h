/*
 * controller_types.h
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

#ifndef RTW_HEADER_controller_types_h_
#define RTW_HEADER_controller_types_h_
#include "rtwtypes.h"

/* Custom Type definition for MATLAB Function: '<S16>/MATLAB Function' */
#include "coder_posix_time.h"
#ifndef struct_tag_HqLxw8B3uXAAHBsMPHlV3B
#define struct_tag_HqLxw8B3uXAAHBsMPHlV3B

struct tag_HqLxw8B3uXAAHBsMPHlV3B
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[7];
  real_T pCumRevIndex;
  real_T pModValueRev;
};

#endif                                 /* struct_tag_HqLxw8B3uXAAHBsMPHlV3B */

#ifndef typedef_h_dsp_internal_SlidingWindowA_T
#define typedef_h_dsp_internal_SlidingWindowA_T

typedef struct tag_HqLxw8B3uXAAHBsMPHlV3B h_dsp_internal_SlidingWindowA_T;

#endif                             /* typedef_h_dsp_internal_SlidingWindowA_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_controller_T
#define typedef_cell_wrap_controller_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_controller_T;

#endif                                 /* typedef_cell_wrap_controller_T */

#ifndef struct_tag_DlZBprYKBkC1pNUuVqWkcH
#define struct_tag_DlZBprYKBkC1pNUuVqWkcH

struct tag_DlZBprYKBkC1pNUuVqWkcH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_controller_T inputVarSize;
  h_dsp_internal_SlidingWindowA_T *pStatistic;
  int32_T NumChannels;
  int32_T FrameLength;
  h_dsp_internal_SlidingWindowA_T _pobj0;
};

#endif                                 /* struct_tag_DlZBprYKBkC1pNUuVqWkcH */

#ifndef typedef_dsp_simulink_MovingAverage_co_T
#define typedef_dsp_simulink_MovingAverage_co_T

typedef struct tag_DlZBprYKBkC1pNUuVqWkcH dsp_simulink_MovingAverage_co_T;

#endif                             /* typedef_dsp_simulink_MovingAverage_co_T */

/* Parameters (default storage) */
typedef struct P_controller_T_ P_controller_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_controller_T RT_MODEL_controller_T;

#endif                                 /* RTW_HEADER_controller_types_h_ */
