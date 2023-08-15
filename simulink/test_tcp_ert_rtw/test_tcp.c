/*
 * test_tcp.c
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

#include "test_tcp.h"
#include "test_tcp_types.h"
#include "rtwtypes.h"
#include <string.h>
#include "test_tcp_private.h"
#include <stddef.h>
#include <math.h>
#include "test_tcp_dt.h"

/* Block states (default storage) */
DW_test_tcp_T test_tcp_DW;

/* Real-time model */
static RT_MODEL_test_tcp_T test_tcp_M_;
RT_MODEL_test_tcp_T *const test_tcp_M = &test_tcp_M_;

/* Forward declaration for local functions */
static void test_tcp_SystemCore_setup(beagleboneblue_bbblueTCPSend__T *obj);
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void test_tcp_SystemCore_setup(beagleboneblue_bbblueTCPSend__T *obj)
{
  real_T tmp;
  int32_T i;
  int16_T errorNo;
  uint16_T tmp_0;
  char_T ipaddr[14];
  static const char_T tmp_1[14] = "192.168.0.100";
  obj->isInitialized = 1;
  obj->isServer_ = 0.0;
  for (i = 0; i < 14; i++) {
    ipaddr[i] = tmp_1[i];
  }

  tmp = rt_roundd_snf(obj->isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint16_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  TCPStreamSetup(5000, 0, &obj->connStream_, tmp_0, 0.0, &errorNo, &ipaddr[0]);
  littleEndianCheck(&obj->isLittleEnd_);
}

/* Model step function */
void test_tcp_step(void)
{
  real_T dataIn;
  real_T tmp;
  int16_T errorNo;
  uint16_T tmp_0;
  uint8_T b_x[8];
  uint8_T xtmp;

  /* MATLABSystem: '<Root>/TCP//IP Send' incorporates:
   *  Constant: '<Root>/Constant'
   */
  dataIn = test_tcp_P.Constant_Value;
  if (test_tcp_DW.obj.isLittleEnd_ == 1) {
    memcpy((void *)&b_x[0], (void *)&test_tcp_P.Constant_Value, (size_t)8 *
           sizeof(uint8_T));
    xtmp = b_x[0];
    b_x[0] = b_x[7];
    b_x[7] = xtmp;
    xtmp = b_x[1];
    b_x[1] = b_x[6];
    b_x[6] = xtmp;
    xtmp = b_x[2];
    b_x[2] = b_x[5];
    b_x[5] = xtmp;
    xtmp = b_x[3];
    b_x[3] = b_x[4];
    b_x[4] = xtmp;
    memcpy((void *)&dataIn, (void *)&b_x[0], (size_t)1 * sizeof(real_T));
  }

  tmp = rt_roundd_snf(test_tcp_DW.obj.isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint16_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  TCPStreamStepSend(&dataIn, 8U, test_tcp_DW.obj.connStream_, tmp_0, &errorNo);

  /* End of MATLABSystem: '<Root>/TCP//IP Send' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.2s, 0.0s] */
    rtExtModeUpload(0, (real_T)test_tcp_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(test_tcp_M)!=-1) &&
        !((rtmGetTFinal(test_tcp_M)-test_tcp_M->Timing.taskTime0) >
          test_tcp_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(test_tcp_M, "Simulation finished");
    }

    if (rtmGetStopRequested(test_tcp_M)) {
      rtmSetErrorStatus(test_tcp_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++test_tcp_M->Timing.clockTick0)) {
    ++test_tcp_M->Timing.clockTickH0;
  }

  test_tcp_M->Timing.taskTime0 = test_tcp_M->Timing.clockTick0 *
    test_tcp_M->Timing.stepSize0 + test_tcp_M->Timing.clockTickH0 *
    test_tcp_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void test_tcp_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)test_tcp_M, 0,
                sizeof(RT_MODEL_test_tcp_T));
  rtmSetTFinal(test_tcp_M, 10.0);
  test_tcp_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  test_tcp_M->Sizes.checksums[0] = (408485721U);
  test_tcp_M->Sizes.checksums[1] = (954327178U);
  test_tcp_M->Sizes.checksums[2] = (3246081223U);
  test_tcp_M->Sizes.checksums[3] = (1780948930U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    test_tcp_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(test_tcp_M->extModeInfo,
      &test_tcp_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(test_tcp_M->extModeInfo, test_tcp_M->Sizes.checksums);
    rteiSetTPtr(test_tcp_M->extModeInfo, rtmGetTPtr(test_tcp_M));
  }

  /* states (dwork) */
  (void) memset((void *)&test_tcp_DW, 0,
                sizeof(DW_test_tcp_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    test_tcp_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/TCP//IP Send' */
  test_tcp_DW.obj.isInitialized = 0;
  test_tcp_DW.objisempty = true;
  test_tcp_SystemCore_setup(&test_tcp_DW.obj);
}

/* Model terminate function */
void test_tcp_terminate(void)
{
  /* (no terminate code required) */
}
