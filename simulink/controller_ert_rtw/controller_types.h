/*
 * controller_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.656
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Oct 11 15:50:46 2023
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
#include "MW_SVD.h"
#ifndef struct_tag_q4re843yYTsFSUEoF6hnJH
#define struct_tag_q4re843yYTsFSUEoF6hnJH

struct tag_q4re843yYTsFSUEoF6hnJH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
};

#endif                                 /* struct_tag_q4re843yYTsFSUEoF6hnJH */

#ifndef typedef_beagleboneblue_bbblueADC_cont_T
#define typedef_beagleboneblue_bbblueADC_cont_T

typedef struct tag_q4re843yYTsFSUEoF6hnJH beagleboneblue_bbblueADC_cont_T;

#endif                             /* typedef_beagleboneblue_bbblueADC_cont_T */

/* Custom Type definition for MATLAB Function: '<S16>/MATLAB Function' */
#include "coder_posix_time.h"
#ifndef struct_tag_BomwZnYtwoEoC4SP7CGNiB
#define struct_tag_BomwZnYtwoEoC4SP7CGNiB

struct tag_BomwZnYtwoEoC4SP7CGNiB
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[14];
  real_T pCumRevIndex;
  real_T pModValueRev;
};

#endif                                 /* struct_tag_BomwZnYtwoEoC4SP7CGNiB */

#ifndef typedef_g_dsp_internal_SlidingWindowA_T
#define typedef_g_dsp_internal_SlidingWindowA_T

typedef struct tag_BomwZnYtwoEoC4SP7CGNiB g_dsp_internal_SlidingWindowA_T;

#endif                             /* typedef_g_dsp_internal_SlidingWindowA_T */

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

#ifndef struct_tag_FA92MfKCCbJl11xXJLsLGF
#define struct_tag_FA92MfKCCbJl11xXJLsLGF

struct tag_FA92MfKCCbJl11xXJLsLGF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_controller_T inputVarSize;
  g_dsp_internal_SlidingWindowA_T *pStatistic;
  int32_T NumChannels;
  int32_T FrameLength;
  g_dsp_internal_SlidingWindowA_T _pobj0;
};

#endif                                 /* struct_tag_FA92MfKCCbJl11xXJLsLGF */

#ifndef typedef_dsp_simulink_MovingAverage_co_T
#define typedef_dsp_simulink_MovingAverage_co_T

typedef struct tag_FA92MfKCCbJl11xXJLsLGF dsp_simulink_MovingAverage_co_T;

#endif                             /* typedef_dsp_simulink_MovingAverage_co_T */

/* Custom Type definition for MATLABSystem: '<Root>/Digital Read3' */
#include "MW_SVD.h"
#ifndef struct_tag_1EBWQ6hhKs9Y37qjpZj8aH
#define struct_tag_1EBWQ6hhKs9Y37qjpZj8aH

struct tag_1EBWQ6hhKs9Y37qjpZj8aH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_1EBWQ6hhKs9Y37qjpZj8aH */

#ifndef typedef_beagleboneblue_bbblueDigitalR_T
#define typedef_beagleboneblue_bbblueDigitalR_T

typedef struct tag_1EBWQ6hhKs9Y37qjpZj8aH beagleboneblue_bbblueDigitalR_T;

#endif                             /* typedef_beagleboneblue_bbblueDigitalR_T */

/* Parameters for system: '<Root>/Analog Input' */
typedef struct P_AnalogInput_controller_T_ P_AnalogInput_controller_T;

/* Parameters (default storage) */
typedef struct P_controller_T_ P_controller_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_controller_T RT_MODEL_controller_T;

#endif                                 /* RTW_HEADER_controller_types_h_ */
