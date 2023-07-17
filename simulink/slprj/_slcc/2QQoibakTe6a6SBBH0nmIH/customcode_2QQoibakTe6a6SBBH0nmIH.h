#ifndef __customcode_2QQoibakTe6a6SBBH0nmIH_h__
#define __customcode_2QQoibakTe6a6SBBH0nmIH_h__

/* Include files */
#include "mex.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "tmwtypes.h"


/* Helper definitions for DLL support */
#if defined _WIN32 
  #define DLL_EXPORT_CC __declspec(dllexport)
#else
  #if __GNUC__ >= 4
    #define DLL_EXPORT_CC __attribute__ ((visibility ("default")))
  #else
    #define DLL_EXPORT_CC
  #endif
#endif
/* Custom Code from Simulation Target dialog */
#include "init_can.h"
#include "get_encoder.h"
#include "set_motor.h"
#include "print_input.h"

/* Function Declarations */
#ifdef __cplusplus
extern "C" {
#endif
#define customcode_2QQoibakTe6a6SBBH0nmIH_initializer()

#define customcode_2QQoibakTe6a6SBBH0nmIH_terminator()
#ifdef __cplusplus
}
#endif

#endif

