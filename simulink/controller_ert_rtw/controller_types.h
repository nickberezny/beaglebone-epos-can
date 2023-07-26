/*
 * controller_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.271
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Jul 26 13:21:24 2023
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

#ifndef struct_tag_iXzQ7EANXGiUsqKDQTF8rH
#define struct_tag_iXzQ7EANXGiUsqKDQTF8rH

struct tag_iXzQ7EANXGiUsqKDQTF8rH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
};

#endif                                 /* struct_tag_iXzQ7EANXGiUsqKDQTF8rH */

#ifndef typedef_beagleboneblue_bbblueButton_c_T
#define typedef_beagleboneblue_bbblueButton_c_T

typedef struct tag_iXzQ7EANXGiUsqKDQTF8rH beagleboneblue_bbblueButton_c_T;

#endif                             /* typedef_beagleboneblue_bbblueButton_c_T */

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

#ifndef struct_tag_fYOEcv5C5Uqf6zenXgF1HG
#define struct_tag_fYOEcv5C5Uqf6zenXgF1HG

struct tag_fYOEcv5C5Uqf6zenXgF1HG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /* struct_tag_fYOEcv5C5Uqf6zenXgF1HG */

#ifndef typedef_beagleboneblue_bbblueLED_cont_T
#define typedef_beagleboneblue_bbblueLED_cont_T

typedef struct tag_fYOEcv5C5Uqf6zenXgF1HG beagleboneblue_bbblueLED_cont_T;

#endif                             /* typedef_beagleboneblue_bbblueLED_cont_T */

/* Custom Type definition for MATLAB Function: '<S15>/MATLAB Function' */
#include "coder_posix_time.h"

/* Parameters for system: '<Root>/Analog Input' */
typedef struct P_AnalogInput_controller_T_ P_AnalogInput_controller_T;

/* Parameters for system: '<Root>/Home1' */
typedef struct P_Home1_controller_T_ P_Home1_controller_T;

/* Parameters for system: '<S12>/Stop Motor' */
typedef struct P_StopMotor_controller_T_ P_StopMotor_controller_T;

/* Parameters (default storage) */
typedef struct P_controller_T_ P_controller_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_controller_T RT_MODEL_controller_T;

#endif                                 /* RTW_HEADER_controller_types_h_ */
