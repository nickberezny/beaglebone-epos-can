/*
 * IO_test.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "IO_test".
 *
 * Model version              : 1.3
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Jul 21 09:15:37 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "IO_test.h"
#include "IO_test_types.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include <string.h>

/* Block states (default storage) */
DW_IO_test_T IO_test_DW;

/* Real-time model */
static RT_MODEL_IO_test_T IO_test_M_;
RT_MODEL_IO_test_T *const IO_test_M = &IO_test_M_;

/* Model step function */
void IO_test_step(void)
{
  real_T tmp;
  boolean_T rtb_DigitalRead_0;

  /* MATLABSystem: '<Root>/Digital Read' */
  if (IO_test_DW.obj.SampleTime != IO_test_P.DigitalRead_SampleTime) {
    IO_test_DW.obj.SampleTime = IO_test_P.DigitalRead_SampleTime;
  }

  rtb_DigitalRead_0 = MW_digitalIO_read(IO_test_DW.obj.MW_DIGITALIO_HANDLE);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  tmp = floor(IO_test_P.Constant2_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  /* CCaller: '<Root>/C Caller4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  MATLABSystem: '<Root>/Digital Read'
   */
  print_input(rtb_DigitalRead_0, tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)
              (uint32_T)tmp);
}

/* Model initialize function */
void IO_test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(IO_test_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&IO_test_DW, 0,
                sizeof(DW_IO_test_T));

  {
    beagleboneblue_bbblueDigitalR_T *obj;

    /* Start for MATLABSystem: '<Root>/Digital Read' */
    IO_test_DW.obj.matlabCodegenIsDeleted = false;
    IO_test_DW.objisempty = true;
    IO_test_DW.obj.SampleTime = IO_test_P.DigitalRead_SampleTime;
    obj = &IO_test_DW.obj;
    IO_test_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(113, 0);
    IO_test_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void IO_test_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  if (!IO_test_DW.obj.matlabCodegenIsDeleted) {
    IO_test_DW.obj.matlabCodegenIsDeleted = true;
    if ((IO_test_DW.obj.isInitialized == 1) && IO_test_DW.obj.isSetupComplete) {
      MW_digitalIO_close(IO_test_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read' */
}
