/*
 * analog_test_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "analog_test".
 *
 * Model version              : 1.5
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Sep 22 15:09:20 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_analog_test_types_h_
#define RTW_HEADER_analog_test_types_h_
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

#ifndef typedef_beagleboneblue_bbblueADC_anal_T
#define typedef_beagleboneblue_bbblueADC_anal_T

typedef struct tag_q4re843yYTsFSUEoF6hnJH beagleboneblue_bbblueADC_anal_T;

#endif                             /* typedef_beagleboneblue_bbblueADC_anal_T */

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

/* Parameters (default storage) */
typedef struct P_analog_test_T_ P_analog_test_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_analog_test_T RT_MODEL_analog_test_T;

#endif                                 /* RTW_HEADER_analog_test_types_h_ */
