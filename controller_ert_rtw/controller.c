/*
 * controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 4.23
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Jul 10 09:59:00 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controller.h"
#include "rtwtypes.h"
#include <string.h>

/* Block signals (default storage) */
B_controller_T controller_B;

/* Block states (default storage) */
DW_controller_T controller_DW;

/* Real-time model */
static RT_MODEL_controller_T controller_M_;
RT_MODEL_controller_T *const controller_M = &controller_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void controller_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(controller_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  controller_M->Timing.RateInteraction.TID0_1 =
    (controller_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (controller_M->Timing.TaskCounters.TID[1])++;
  if ((controller_M->Timing.TaskCounters.TID[1]) > 9999999) {/* Sample time: [10000.0s, 0.0s] */
    controller_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void controller_step0(void)            /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition generated from: '<Root>/C Caller5' */
  if (controller_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<Root>/C Caller5' */
    controller_B.TmpRTBAtCCaller5Outport1 =
      controller_DW.TmpRTBAtCCaller5Outport1_Buffer;
  }

  /* End of RateTransition generated from: '<Root>/C Caller5' */

  /* CCaller: '<Root>/C Caller1' */
  get_encoder(controller_B.TmpRTBAtCCaller5Outport1);

  /* CCaller: '<Root>/C Caller3' */
  set_motor(controller_B.TmpRTBAtCCaller5Outport1, 0.0);
}

/* Model step function for TID1 */
void controller_step1(void)            /* Sample time: [10000.0s, 0.0s] */
{
  int32_T rtb_CCaller5;

  /* CCaller: '<Root>/C Caller5' */
  rtb_CCaller5 = init_can();

  /* RateTransition generated from: '<Root>/C Caller5' */
  controller_DW.TmpRTBAtCCaller5Outport1_Buffer = rtb_CCaller5;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void controller_step(int_T tid)
{
  switch (tid) {
   case 0 :
    controller_step0();
    break;

   case 1 :
    controller_step1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void controller_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)controller_M, 0,
                sizeof(RT_MODEL_controller_T));

  /* block I/O */
  (void) memset(((void *) &controller_B), 0,
                sizeof(B_controller_T));

  /* states (dwork) */
  (void) memset((void *)&controller_DW, 0,
                sizeof(DW_controller_T));

  /* Start for RateTransition generated from: '<Root>/C Caller5' */
  controller_B.TmpRTBAtCCaller5Outport1 =
    controller_P.TmpRTBAtCCaller5Outport1_Initia;

  /* InitializeConditions for RateTransition generated from: '<Root>/C Caller5' */
  controller_DW.TmpRTBAtCCaller5Outport1_Buffer =
    controller_P.TmpRTBAtCCaller5Outport1_Initia;
}

/* Model terminate function */
void controller_terminate(void)
{
  /* (no terminate code required) */
}
