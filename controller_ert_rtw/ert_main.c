#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "controller_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "MW_bbblue_init.h"
#include "linuxinitialize.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
sem_t subrateTaskSem[1];
int taskId[1];
pthread_t schedulerThread;
pthread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
pthread_t subRateThread[1];
int subratePriority[1];
void *subrateTask(void *arg)
{
  int tid = *((int *) arg);
  int subRateId;
  subRateId = tid + 1;
  while (runModel) {
    sem_wait(&subrateTaskSem[tid]);
    if (terminatingmodel)
      break;

#ifdef MW_RTOS_DEBUG

    printf(" -subrate task %d semaphore received\n", subRateId);

#endif

    controller_step(subRateId);

    /* Get model outputs here */
  }

  pthread_exit((void *)0);
  return NULL;
}

void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(controller_M) == (NULL));
  while (runModel) {
    sem_wait(&baserateTaskSem);

#ifdef MW_RTOS_DEBUG

    printf("*base rate task semaphore received\n");
    fflush(stdout);

#endif

    if (rtmStepTask(controller_M, 1)
        ) {
      sem_post(&subrateTaskSem[0]);
    }

    controller_step(0);

    /* Get model outputs here */
    stopRequested = !((rtmGetErrorStatus(controller_M) == (NULL)));
  }

  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(controller_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    int i;

    /* Signal all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(sem_post(&subrateTaskSem[i]), 0, "sem_post");
      CHECK_STATUS(sem_destroy(&subrateTaskSem[i]), 0, "sem_destroy");
    }

    /* Wait for all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(pthread_join(subRateThread[i], &threadJoinStatus), 0,
                   "pthread_join");
    }

    runModel = 0;
  }

  MW_bbblue_terminate();

  /* Terminate model */
  controller_terminate();
  sem_post(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  subratePriority[0] = 4;
  MW_bbblue_init();
  rtmSetErrorStatus(controller_M, 0);

  /* Initialize model */
  controller_initialize();

  /* Call RTOS Initialization function */
  myRTOSInit(0.001, 1);

  /* Wait for stop semaphore */
  sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(sem_destroy(&timerTaskSem[i]), 0, "sem_destroy");
    }
  }

#endif

  return 0;
}
