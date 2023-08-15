/*
 * test_tcp_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "test_tcp".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Aug 10 15:06:47 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test_tcp_types_h_
#define RTW_HEADER_test_tcp_types_h_
#include "rtwtypes.h"
#ifndef struct_tag_7VBpQHbNwwtaFRfgXV6MaB
#define struct_tag_7VBpQHbNwwtaFRfgXV6MaB

struct tag_7VBpQHbNwwtaFRfgXV6MaB
{
  int32_T isInitialized;
  uint16_T connStream_;
  real_T isServer_;
  uint8_T isLittleEnd_;
};

#endif                                 /* struct_tag_7VBpQHbNwwtaFRfgXV6MaB */

#ifndef typedef_beagleboneblue_bbblueTCPSend__T
#define typedef_beagleboneblue_bbblueTCPSend__T

typedef struct tag_7VBpQHbNwwtaFRfgXV6MaB beagleboneblue_bbblueTCPSend__T;

#endif                             /* typedef_beagleboneblue_bbblueTCPSend__T */

/* Parameters (default storage) */
typedef struct P_test_tcp_T_ P_test_tcp_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_test_tcp_T RT_MODEL_test_tcp_T;

#endif                                 /* RTW_HEADER_test_tcp_types_h_ */
