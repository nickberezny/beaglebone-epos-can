#ifndef __customcode_0dOygxPzmxkwRo3A8cJIGG_h__
#define __customcode_0dOygxPzmxkwRo3A8cJIGG_h__

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
#define customcode_0dOygxPzmxkwRo3A8cJIGG_initializer()

#define customcode_0dOygxPzmxkwRo3A8cJIGG_terminator()
#ifdef __cplusplus
}
#endif

#endif

