#ifndef __ruThg8ilLzfH7h2KmGFzOE_h__
#define __ruThg8ilLzfH7h2KmGFzOE_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef struct_tag_xTNOutq2KgNovgiUrNXK1F
#define struct_tag_xTNOutq2KgNovgiUrNXK1F

struct tag_xTNOutq2KgNovgiUrNXK1F
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  real_T SampleTime;
};

#endif                                 /* struct_tag_xTNOutq2KgNovgiUrNXK1F */

#ifndef typedef_beagleboneblue_bbblueADC
#define typedef_beagleboneblue_bbblueADC

typedef struct tag_xTNOutq2KgNovgiUrNXK1F beagleboneblue_bbblueADC;

#endif                                 /* typedef_beagleboneblue_bbblueADC */

#ifndef struct_tag_Hm6EPE5ncyWd4RGCxxctzF
#define struct_tag_Hm6EPE5ncyWd4RGCxxctzF

struct tag_Hm6EPE5ncyWd4RGCxxctzF
{
  char_T f1[30];
  char_T f2[29];
  char_T f3[30];
  char_T f4[30];
  char_T f5[39];
};

#endif                                 /* struct_tag_Hm6EPE5ncyWd4RGCxxctzF */

#ifndef typedef_cell
#define typedef_cell

typedef struct tag_Hm6EPE5ncyWd4RGCxxctzF cell;

#endif                                 /* typedef_cell */

#ifndef struct_tag_n5V6NPhGd1s3l2q7z9eOR
#define struct_tag_n5V6NPhGd1s3l2q7z9eOR

struct tag_n5V6NPhGd1s3l2q7z9eOR
{
  char_T f1[27];
  char_T f2[21];
  char_T f3[26];
};

#endif                                 /* struct_tag_n5V6NPhGd1s3l2q7z9eOR */

#ifndef typedef_b_cell
#define typedef_b_cell

typedef struct tag_n5V6NPhGd1s3l2q7z9eOR b_cell;

#endif                                 /* typedef_b_cell */

#ifndef struct_tag_VqK0uXiUXuliBvHmvcLR0F
#define struct_tag_VqK0uXiUXuliBvHmvcLR0F

struct tag_VqK0uXiUXuliBvHmvcLR0F
{
  char_T f1[28];
  char_T f2[22];
  char_T f3[35];
  char_T f4[26];
  char_T f5[36];
  char_T f6[39];
};

#endif                                 /* struct_tag_VqK0uXiUXuliBvHmvcLR0F */

#ifndef typedef_c_cell
#define typedef_c_cell

typedef struct tag_VqK0uXiUXuliBvHmvcLR0F c_cell;

#endif                                 /* typedef_c_cell */

#ifndef struct_tag_TnEayzHWuHj1hMPKnEr7h
#define struct_tag_TnEayzHWuHj1hMPKnEr7h

struct tag_TnEayzHWuHj1hMPKnEr7h
{
  cell _data;
};

#endif                                 /* struct_tag_TnEayzHWuHj1hMPKnEr7h */

#ifndef typedef_s_TnEayzHWuHj1hMPKnEr7h
#define typedef_s_TnEayzHWuHj1hMPKnEr7h

typedef struct tag_TnEayzHWuHj1hMPKnEr7h s_TnEayzHWuHj1hMPKnEr7h;

#endif                                 /* typedef_s_TnEayzHWuHj1hMPKnEr7h */

#ifndef struct_tag_rLqvsRnn1YgNlP4UZHEHjG
#define struct_tag_rLqvsRnn1YgNlP4UZHEHjG

struct tag_rLqvsRnn1YgNlP4UZHEHjG
{
  b_cell _data;
};

#endif                                 /* struct_tag_rLqvsRnn1YgNlP4UZHEHjG */

#ifndef typedef_s_rLqvsRnn1YgNlP4UZHEHjG
#define typedef_s_rLqvsRnn1YgNlP4UZHEHjG

typedef struct tag_rLqvsRnn1YgNlP4UZHEHjG s_rLqvsRnn1YgNlP4UZHEHjG;

#endif                                 /* typedef_s_rLqvsRnn1YgNlP4UZHEHjG */

#ifndef struct_tag_HNEgOhGwwuu4IndkThqyM
#define struct_tag_HNEgOhGwwuu4IndkThqyM

struct tag_HNEgOhGwwuu4IndkThqyM
{
  c_cell _data;
};

#endif                                 /* struct_tag_HNEgOhGwwuu4IndkThqyM */

#ifndef typedef_s_HNEgOhGwwuu4IndkThqyM
#define typedef_s_HNEgOhGwwuu4IndkThqyM

typedef struct tag_HNEgOhGwwuu4IndkThqyM s_HNEgOhGwwuu4IndkThqyM;

#endif                                 /* typedef_s_HNEgOhGwwuu4IndkThqyM */

#ifndef typedef_InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
#define typedef_InstanceStruct_ruThg8ilLzfH7h2KmGFzOE

typedef struct {
  SimStruct *S;
  beagleboneblue_bbblueADC sysobj;
  boolean_T sysobj_not_empty;
  void *emlrtRootTLSGlobal;
  real_T *b_y0;
} InstanceStruct_ruThg8ilLzfH7h2KmGFzOE;

#endif                                 /* typedef_InstanceStruct_ruThg8ilLzfH7h2KmGFzOE */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_ruThg8ilLzfH7h2KmGFzOE(SimStruct *S, int_T method,
  void* data);

#endif
