/* Include files */

#include "modelInterface.h"
#include "m_ruThg8ilLzfH7h2KmGFzOE.h"
#include "mwmathutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 24,    /* lineNo */
  "bbblueADC",                         /* fcnName */
  "C:\\ProgramData\\MATLAB\\SupportPackages\\R2022b\\toolbox\\target\\supportpackages\\beagleboneblue\\+beagleboneblue\\bbblueADC.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 1,   /* lineNo */
  "System",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\System.p"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 1,   /* lineNo */
  "SystemProp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemProp.p"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 1,   /* lineNo */
  "SystemCore",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemCore.p"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 1,   /* lineNo */
  "BlockSampleTime",                   /* fcnName */
  "C:\\ProgramData\\MATLAB\\SupportPackages\\R2022b\\toolbox\\target\\shared\\svd\\+matlabshared\\+svd\\BlockSampleTime.p"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 9,   /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 19,  /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 24,  /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 26,  /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 32,  /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 40,  /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 28,  /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 22,  /* lineNo */
  "matlabCodegenHandle",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\matlabCodegenHandle.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 1,     /* lineNo */
  1,                                   /* colNo */
  "BlockSampleTime",                   /* fName */
  "C:\\ProgramData\\MATLAB\\SupportPackages\\R2022b\\toolbox\\target\\shared\\svd\\+matlabshared\\+svd\\BlockSampleTime.p"/* pName */
};

static emlrtMCInfo b_emlrtMCI = { 1,   /* lineNo */
  1,                                   /* colNo */
  "SystemCore",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemCore.p"/* pName */
};

static emlrtMCInfo c_emlrtMCI = { 1,   /* lineNo */
  1,                                   /* colNo */
  "validateSampleTime",                /* fName */
  "C:\\ProgramData\\MATLAB\\SupportPackages\\R2022b\\toolbox\\target\\shared\\svd\\+matlabshared\\+svd\\+internal\\validateSampleTime.p"/* pName */
};

static emlrtRSInfo n_emlrtRSI = { 1,   /* lineNo */
  "validateSampleTime",                /* fcnName */
  "C:\\ProgramData\\MATLAB\\SupportPackages\\R2022b\\toolbox\\target\\shared\\svd\\+matlabshared\\+svd\\+internal\\validateSampleTime.p"/* pathName */
};

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance);
static void mw__internal__system__init__fcn
  (InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *moduleInstance);
static void mw__internal__system__terminate__fcn
  (InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *moduleInstance);
static void mw__internal__call__setup(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance, const emlrtStack *sp, real_T SampleTime);
static beagleboneblue_bbblueADC *bbblueADC_bbblueADC(beagleboneblue_bbblueADC
  *obj);
static void BlockSampleTime_set_SampleTime(const emlrtStack *sp,
  beagleboneblue_bbblueADC *obj, real_T newTime);
static void SystemCore_setup(const emlrtStack *sp, beagleboneblue_bbblueADC *obj);
static void SystemCore_checkTunablePropChange(const emlrtStack *sp,
  beagleboneblue_bbblueADC *obj);
static void mw__internal__call__reset(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance, const emlrtStack *sp, real_T SampleTime);
static real_T mw__internal__call__step(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance, const emlrtStack *sp, real_T SampleTime);
static const mxArray *emlrt_marshallOut(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance);
static const mxArray *cgxe_mdl_get_sim_state
  (InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *moduleInstance);
static void emlrt_marshallIn(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance, const emlrtStack *sp, const mxArray *u);
static beagleboneblue_bbblueADC b_emlrt_marshallIn(const emlrtStack *sp, const
  mxArray *b_sysobj, const char_T *identifier);
static beagleboneblue_bbblueADC c_emlrt_marshallIn(const emlrtStack *sp, const
  mxArray *u, const emlrtMsgIdentifier *parentId);
static boolean_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static int32_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static boolean_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_sysobj_not_empty, const char_T *identifier);
static void cgxe_mdl_set_sim_state(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance, const mxArray *st);
static const mxArray *message(const emlrtStack *sp, const mxArray *m1,
  emlrtMCInfo *location);
static void error(const emlrtStack *sp, const mxArray *m, emlrtMCInfo *location);
static const mxArray *b_message(const emlrtStack *sp, const mxArray *m1, const
  mxArray *m2, emlrtMCInfo *location);
static const mxArray *getString(const emlrtStack *sp, const mxArray *m1,
  emlrtMCInfo *location);
static void b_error(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                    emlrtMCInfo *location);
static boolean_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static int32_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void init_simulink_io_address(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *moduleInstance)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T *SampleTime;
  init_simulink_io_address(moduleInstance);
  SampleTime = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 0);
  st.tls = moduleInstance->emlrtRootTLSGlobal;
  cgxertSetGcb(moduleInstance->S, -1, -1);
  mw__internal__system__init__fcn(moduleInstance);
  mw__internal__call__setup(moduleInstance, &st, *SampleTime);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void cgxe_mdl_initialize(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T *SampleTime;
  SampleTime = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 0);
  st.tls = moduleInstance->emlrtRootTLSGlobal;
  cgxertSetGcb(moduleInstance->S, -1, -1);
  mw__internal__call__reset(moduleInstance, &st, *SampleTime);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void cgxe_mdl_outputs(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T *SampleTime;
  SampleTime = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 0);
  st.tls = moduleInstance->emlrtRootTLSGlobal;
  cgxertSetGcb(moduleInstance->S, -1, -1);
  *moduleInstance->b_y0 = mw__internal__call__step(moduleInstance, &st,
    *SampleTime);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void cgxe_mdl_update(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance)
{
  cgxertSetGcb(moduleInstance->S, -1, -1);
  mw__internal__system__terminate__fcn(moduleInstance);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void mw__internal__system__init__fcn
  (InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *moduleInstance)
{
  moduleInstance->sysobj.matlabCodegenIsDeleted = true;
}

static void mw__internal__system__terminate__fcn
  (InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *moduleInstance)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  st.site = NULL;
  if (!moduleInstance->sysobj.matlabCodegenIsDeleted) {
    moduleInstance->sysobj.matlabCodegenIsDeleted = true;
    b_st.site = &m_emlrtRSI;
    c_st.site = &d_emlrtRSI;
    if (moduleInstance->sysobj.isInitialized == 1) {
      moduleInstance->sysobj.isInitialized = 2;
      d_st.site = &d_emlrtRSI;
    }
  }
}

static void mw__internal__call__setup(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance, const emlrtStack *sp, real_T SampleTime)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (!moduleInstance->sysobj_not_empty) {
    st.site = &f_emlrtRSI;
    bbblueADC_bbblueADC(&moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
    st.site = &g_emlrtRSI;
    BlockSampleTime_set_SampleTime(&st, &moduleInstance->sysobj, SampleTime);
  }

  st.site = &h_emlrtRSI;
  SystemCore_setup(&st, &moduleInstance->sysobj);
}

static beagleboneblue_bbblueADC *bbblueADC_bbblueADC(beagleboneblue_bbblueADC
  *obj)
{
  beagleboneblue_bbblueADC *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  b_obj = obj;
  st.site = &emlrtRSI;
  b_st.site = &b_emlrtRSI;
  c_st.site = &c_emlrtRSI;
  b_st.site = &b_emlrtRSI;
  b_obj->TunablePropsChanged = false;
  c_st.site = &d_emlrtRSI;
  b_obj->isInitialized = 0;
  st.site = &emlrtRSI;
  b_obj->SampleTime = -1.0;
  b_st.site = &e_emlrtRSI;
  st.site = &emlrtRSI;
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static void BlockSampleTime_set_SampleTime(const emlrtStack *sp,
  beagleboneblue_bbblueADC *obj, real_T newTime)
{
  static const int32_T iv[2] = { 1, 45 };

  static const int32_T iv1[2] = { 1, 28 };

  static const int32_T iv2[2] = { 1, 35 };

  static const int32_T iv3[2] = { 1, 45 };

  static const int32_T iv4[2] = { 1, 37 };

  static const int32_T iv5[2] = { 1, 35 };

  static const int32_T iv6[2] = { 1, 8 };

  static const int32_T iv7[2] = { 1, 37 };

  static char_T c_u[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  static char_T h_u[37] = { 's', 'v', 'd', ':', 's', 'v', 'd', ':', 'I', 'n',
    'v', 'a', 'l', 'i', 'd', 'S', 'a', 'm', 'p', 'l', 'e', 'T', 'i', 'm', 'e',
    'N', 'e', 'e', 'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  static char_T g_u[35] = { 's', 'v', 'd', ':', 's', 'v', 'd', ':', 'I', 'n',
    'v', 'a', 'l', 'i', 'd', 'S', 'a', 'm', 'p', 'l', 'e', 'T', 'i', 'm', 'e',
    'N', 'e', 'e', 'd', 'S', 'c', 'a', 'l', 'a', 'r' };

  static char_T e_u[28] = { 's', 'v', 'd', ':', 's', 'v', 'd', ':', 'S', 'a',
    'm', 'p', 'l', 'e', 'T', 'i', 'm', 'e', 'N', 'o', 'n', 'T', 'u', 'n', 'a',
    'b', 'l', 'e' };

  static char_T j_u[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  emlrtStack b_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *m;
  const mxArray *y;
  int32_T i;
  char_T u[45];
  char_T f_u[37];
  char_T d_u[35];
  char_T b_u[28];
  char_T i_u[8];
  boolean_T flag;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &e_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (obj->isInitialized == 2) {
    for (i = 0; i < 45; i++) {
      u[i] = c_u[i];
    }

    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&st, 45, m, &u[0]);
    emlrtAssign(&y, m);
    for (i = 0; i < 45; i++) {
      u[i] = c_u[i];
    }

    d_y = NULL;
    m = emlrtCreateCharArray(2, &iv3[0]);
    emlrtInitCharArrayR2013a(&st, 45, m, &u[0]);
    emlrtAssign(&d_y, m);
    for (i = 0; i < 8; i++) {
      i_u[i] = j_u[i];
    }

    g_y = NULL;
    m = emlrtCreateCharArray(2, &iv6[0]);
    emlrtInitCharArrayR2013a(&st, 8, m, &i_u[0]);
    emlrtAssign(&g_y, m);
    b_st.site = &d_emlrtRSI;
    b_error(&b_st, y, getString(&b_st, b_message(&b_st, d_y, g_y, &b_emlrtMCI),
             &b_emlrtMCI), &b_emlrtMCI);
  }

  flag = (obj->isInitialized == 1);
  if (flag && (obj->SampleTime != newTime)) {
    for (i = 0; i < 28; i++) {
      b_u[i] = e_u[i];
    }

    b_y = NULL;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 28, m, &b_u[0]);
    emlrtAssign(&b_y, m);
    st.site = &e_emlrtRSI;
    error(&st, message(&st, b_y, &emlrtMCI), &emlrtMCI);
  }

  st.site = &e_emlrtRSI;
  if (((!muDoubleScalarIsInf(newTime)) && (!muDoubleScalarIsNaN(newTime))) ||
      muDoubleScalarIsInf(newTime)) {
  } else {
    for (i = 0; i < 35; i++) {
      d_u[i] = g_u[i];
    }

    c_y = NULL;
    m = emlrtCreateCharArray(2, &iv2[0]);
    emlrtInitCharArrayR2013a(&st, 35, m, &d_u[0]);
    emlrtAssign(&c_y, m);
    for (i = 0; i < 35; i++) {
      d_u[i] = g_u[i];
    }

    f_y = NULL;
    m = emlrtCreateCharArray(2, &iv5[0]);
    emlrtInitCharArrayR2013a(&st, 35, m, &d_u[0]);
    emlrtAssign(&f_y, m);
    b_st.site = &n_emlrtRSI;
    b_error(&b_st, c_y, getString(&b_st, message(&b_st, f_y, &c_emlrtMCI),
             &c_emlrtMCI), &c_emlrtMCI);
  }

  if ((newTime < 0.0) && (newTime != -1.0)) {
    for (i = 0; i < 37; i++) {
      f_u[i] = h_u[i];
    }

    e_y = NULL;
    m = emlrtCreateCharArray(2, &iv4[0]);
    emlrtInitCharArrayR2013a(&st, 37, m, &f_u[0]);
    emlrtAssign(&e_y, m);
    for (i = 0; i < 37; i++) {
      f_u[i] = h_u[i];
    }

    h_y = NULL;
    m = emlrtCreateCharArray(2, &iv7[0]);
    emlrtInitCharArrayR2013a(&st, 37, m, &f_u[0]);
    emlrtAssign(&h_y, m);
    b_st.site = &n_emlrtRSI;
    b_error(&b_st, e_y, getString(&b_st, message(&b_st, h_y, &c_emlrtMCI),
             &c_emlrtMCI), &c_emlrtMCI);
  }

  obj->SampleTime = newTime;
}

static void SystemCore_setup(const emlrtStack *sp, beagleboneblue_bbblueADC *obj)
{
  static const int32_T iv[2] = { 1, 51 };

  static const int32_T iv1[2] = { 1, 51 };

  static const int32_T iv2[2] = { 1, 5 };

  static char_T b_u[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  static char_T d_u[5] = { 's', 'e', 't', 'u', 'p' };

  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  int32_T i;
  char_T u[51];
  char_T c_u[5];
  st.prev = sp;
  st.tls = sp->tls;
  obj->isSetupComplete = false;
  if (obj->isInitialized != 0) {
    for (i = 0; i < 51; i++) {
      u[i] = b_u[i];
    }

    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 51, m, &u[0]);
    emlrtAssign(&y, m);
    for (i = 0; i < 51; i++) {
      u[i] = b_u[i];
    }

    b_y = NULL;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 51, m, &u[0]);
    emlrtAssign(&b_y, m);
    for (i = 0; i < 5; i++) {
      c_u[i] = d_u[i];
    }

    c_y = NULL;
    m = emlrtCreateCharArray(2, &iv2[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 5, m, &c_u[0]);
    emlrtAssign(&c_y, m);
    st.site = &d_emlrtRSI;
    b_error(&st, y, getString(&st, b_message(&st, b_y, c_y, &b_emlrtMCI),
             &b_emlrtMCI), &b_emlrtMCI);
  }

  obj->isInitialized = 1;
  obj->isSetupComplete = true;
  st.site = &d_emlrtRSI;
  SystemCore_checkTunablePropChange(&st, obj);
  obj->TunablePropsChanged = false;
}

static void SystemCore_checkTunablePropChange(const emlrtStack *sp,
  beagleboneblue_bbblueADC *obj)
{
  static const int32_T iv[2] = { 1, 44 };

  static const int32_T iv1[2] = { 1, 44 };

  static char_T b_u[44] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'T', 'u', 'n', 'a',
    'b', 'l', 'e', 'M', 'o', 'd', 'A', 'c', 'c', 'e', 's', 's', 'C', 'o', 'd',
    'e', 'g', 'e', 'n' };

  emlrtStack st;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  int32_T i;
  char_T u[44];
  st.prev = sp;
  st.tls = sp->tls;
  if (obj->TunablePropsChanged) {
    for (i = 0; i < 44; i++) {
      u[i] = b_u[i];
    }

    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 44, m, &u[0]);
    emlrtAssign(&y, m);
    for (i = 0; i < 44; i++) {
      u[i] = b_u[i];
    }

    b_y = NULL;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 44, m, &u[0]);
    emlrtAssign(&b_y, m);
    st.site = &d_emlrtRSI;
    b_error(&st, y, getString(&st, message(&st, b_y, &b_emlrtMCI), &b_emlrtMCI),
            &b_emlrtMCI);
  }
}

static void mw__internal__call__reset(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance, const emlrtStack *sp, real_T SampleTime)
{
  static const int32_T iv[2] = { 1, 45 };

  static const int32_T iv1[2] = { 1, 44 };

  static const int32_T iv2[2] = { 1, 45 };

  static const int32_T iv3[2] = { 1, 44 };

  static const int32_T iv4[2] = { 1, 5 };

  static char_T c_u[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  static char_T d_u[44] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'T', 'u', 'n', 'a',
    'b', 'l', 'e', 'M', 'o', 'd', 'A', 'c', 'c', 'e', 's', 's', 'C', 'o', 'd',
    'e', 'g', 'e', 'n' };

  static char_T f_u[5] = { 'r', 'e', 's', 'e', 't' };

  emlrtStack b_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *m;
  const mxArray *y;
  int32_T i;
  char_T u[45];
  char_T b_u[44];
  char_T e_u[5];
  boolean_T tunablePropChangedBeforeResetImpl;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (!moduleInstance->sysobj_not_empty) {
    st.site = &f_emlrtRSI;
    bbblueADC_bbblueADC(&moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
    st.site = &g_emlrtRSI;
    BlockSampleTime_set_SampleTime(&st, &moduleInstance->sysobj, SampleTime);
  }

  st.site = &i_emlrtRSI;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i = 0; i < 45; i++) {
      u[i] = c_u[i];
    }

    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&st, 45, m, &u[0]);
    emlrtAssign(&y, m);
    for (i = 0; i < 45; i++) {
      u[i] = c_u[i];
    }

    c_y = NULL;
    m = emlrtCreateCharArray(2, &iv2[0]);
    emlrtInitCharArrayR2013a(&st, 45, m, &u[0]);
    emlrtAssign(&c_y, m);
    for (i = 0; i < 5; i++) {
      e_u[i] = f_u[i];
    }

    e_y = NULL;
    m = emlrtCreateCharArray(2, &iv4[0]);
    emlrtInitCharArrayR2013a(&st, 5, m, &e_u[0]);
    emlrtAssign(&e_y, m);
    b_st.site = &d_emlrtRSI;
    b_error(&b_st, y, getString(&b_st, b_message(&b_st, c_y, e_y, &b_emlrtMCI),
             &b_emlrtMCI), &b_emlrtMCI);
  }

  tunablePropChangedBeforeResetImpl = moduleInstance->sysobj.TunablePropsChanged;
  if ((int32_T)tunablePropChangedBeforeResetImpl != (int32_T)
      moduleInstance->sysobj.TunablePropsChanged) {
    for (i = 0; i < 44; i++) {
      b_u[i] = d_u[i];
    }

    b_y = NULL;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a(&st, 44, m, &b_u[0]);
    emlrtAssign(&b_y, m);
    for (i = 0; i < 44; i++) {
      b_u[i] = d_u[i];
    }

    d_y = NULL;
    m = emlrtCreateCharArray(2, &iv3[0]);
    emlrtInitCharArrayR2013a(&st, 44, m, &b_u[0]);
    emlrtAssign(&d_y, m);
    b_st.site = &d_emlrtRSI;
    b_error(&b_st, b_y, getString(&b_st, message(&b_st, d_y, &b_emlrtMCI),
             &b_emlrtMCI), &b_emlrtMCI);
  }
}

static real_T mw__internal__call__step(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance, const emlrtStack *sp, real_T SampleTime)
{
  static const int32_T iv[2] = { 1, 45 };

  static const int32_T iv1[2] = { 1, 45 };

  static const int32_T iv2[2] = { 1, 4 };

  static char_T b_u[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  static char_T d_u[4] = { 's', 't', 'e', 'p' };

  beagleboneblue_bbblueADC *obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  int32_T i;
  char_T u[45];
  char_T c_u[4];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (!moduleInstance->sysobj_not_empty) {
    st.site = &f_emlrtRSI;
    bbblueADC_bbblueADC(&moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
    st.site = &g_emlrtRSI;
    BlockSampleTime_set_SampleTime(&st, &moduleInstance->sysobj, SampleTime);
  }

  if (moduleInstance->sysobj.SampleTime != SampleTime) {
    st.site = &j_emlrtRSI;
    BlockSampleTime_set_SampleTime(&st, &moduleInstance->sysobj, SampleTime);
  }

  st.site = &k_emlrtRSI;
  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i = 0; i < 45; i++) {
      u[i] = b_u[i];
    }

    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&st, 45, m, &u[0]);
    emlrtAssign(&y, m);
    for (i = 0; i < 45; i++) {
      u[i] = b_u[i];
    }

    b_y = NULL;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a(&st, 45, m, &u[0]);
    emlrtAssign(&b_y, m);
    for (i = 0; i < 4; i++) {
      c_u[i] = d_u[i];
    }

    c_y = NULL;
    m = emlrtCreateCharArray(2, &iv2[0]);
    emlrtInitCharArrayR2013a(&st, 4, m, &c_u[0]);
    emlrtAssign(&c_y, m);
    b_st.site = &d_emlrtRSI;
    b_error(&b_st, y, getString(&b_st, b_message(&b_st, b_y, c_y, &b_emlrtMCI),
             &b_emlrtMCI), &b_emlrtMCI);
  }

  if (moduleInstance->sysobj.isInitialized != 1) {
    b_st.site = &d_emlrtRSI;
    c_st.site = &d_emlrtRSI;
    SystemCore_setup(&c_st, obj);
  }

  b_st.site = &d_emlrtRSI;
  if (moduleInstance->sysobj.TunablePropsChanged) {
    moduleInstance->sysobj.TunablePropsChanged = false;
  }

  b_st.site = &d_emlrtRSI;
  SystemCore_checkTunablePropChange(&b_st, obj);
  return 0.0;
}

static const mxArray *emlrt_marshallOut(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance)
{
  static const char_T *sv[5] = { "matlabCodegenIsDeleted", "isInitialized",
    "isSetupComplete", "TunablePropsChanged", "SampleTime" };

  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *m;
  const mxArray *y;
  real_T c_u;
  int32_T b_u;
  boolean_T u;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellMatrix(2, 1));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 5, (const char_T **)&sv[0]));
  u = moduleInstance->sysobj.matlabCodegenIsDeleted;
  c_y = NULL;
  m = emlrtCreateLogicalScalar(u);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(b_y, 0, "matlabCodegenIsDeleted", c_y, 0);
  b_u = moduleInstance->sysobj.isInitialized;
  d_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = b_u;
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(b_y, 0, "isInitialized", d_y, 1);
  u = moduleInstance->sysobj.isSetupComplete;
  e_y = NULL;
  m = emlrtCreateLogicalScalar(u);
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(b_y, 0, "isSetupComplete", e_y, 2);
  u = moduleInstance->sysobj.TunablePropsChanged;
  f_y = NULL;
  m = emlrtCreateLogicalScalar(u);
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(b_y, 0, "TunablePropsChanged", f_y, 3);
  c_u = moduleInstance->sysobj.SampleTime;
  g_y = NULL;
  m = emlrtCreateDoubleScalar(c_u);
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(b_y, 0, "SampleTime", g_y, 4);
  emlrtSetCell(y, 0, b_y);
  h_y = NULL;
  m = emlrtCreateLogicalScalar(moduleInstance->sysobj_not_empty);
  emlrtAssign(&h_y, m);
  emlrtSetCell(y, 1, h_y);
  return y;
}

static const mxArray *cgxe_mdl_get_sim_state
  (InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *moduleInstance)
{
  const mxArray *st;
  st = NULL;
  emlrtAssign(&st, emlrt_marshallOut(moduleInstance));
  return st;
}

static void emlrt_marshallIn(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance, const emlrtStack *sp, const mxArray *u)
{
  emlrtMsgIdentifier thisId;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  thisId.fIdentifier = "sysobj";
  moduleInstance->sysobj = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((void *)
    sp, &thisId, u, 0)), "sysobj");
  thisId.fIdentifier = "sysobj_not_empty";
  moduleInstance->sysobj_not_empty = g_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetCell((void *)sp, &thisId, u, 1)), "sysobj_not_empty");
  emlrtDestroyArray(&u);
}

static beagleboneblue_bbblueADC b_emlrt_marshallIn(const emlrtStack *sp, const
  mxArray *b_sysobj, const char_T *identifier)
{
  beagleboneblue_bbblueADC y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(sp, emlrtAlias(b_sysobj), &thisId);
  emlrtDestroyArray(&b_sysobj);
  return y;
}

static beagleboneblue_bbblueADC c_emlrt_marshallIn(const emlrtStack *sp, const
  mxArray *u, const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[5] = { "matlabCodegenIsDeleted",
    "isInitialized", "isSetupComplete", "TunablePropsChanged", "SampleTime" };

  beagleboneblue_bbblueADC y;
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 5, (const char_T **)
    &fieldNames[0], 0U, (const void *)&dims);
  thisId.fIdentifier = "matlabCodegenIsDeleted";
  y.matlabCodegenIsDeleted = d_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "matlabCodegenIsDeleted")),
    &thisId);
  thisId.fIdentifier = "isInitialized";
  y.isInitialized = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b
    ((emlrtConstCTX)sp, u, 0, 1, "isInitialized")), &thisId);
  thisId.fIdentifier = "isSetupComplete";
  y.isSetupComplete = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b
    ((emlrtConstCTX)sp, u, 0, 2, "isSetupComplete")), &thisId);
  thisId.fIdentifier = "TunablePropsChanged";
  y.TunablePropsChanged = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b
    ((emlrtConstCTX)sp, u, 0, 3, "TunablePropsChanged")), &thisId);
  thisId.fIdentifier = "SampleTime";
  y.SampleTime = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b
    ((emlrtConstCTX)sp, u, 0, 4, "SampleTime")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static boolean_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static int32_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  int32_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = j_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static boolean_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_sysobj_not_empty, const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  boolean_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(b_sysobj_not_empty), &thisId);
  emlrtDestroyArray(&b_sysobj_not_empty);
  return y;
}

static void cgxe_mdl_set_sim_state(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance, const mxArray *st)
{
  emlrtStack b_st = { NULL,            /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  b_st.tls = moduleInstance->emlrtRootTLSGlobal;
  emlrt_marshallIn(moduleInstance, &b_st, emlrtAlias(st));
  emlrtDestroyArray(&st);
}

static const mxArray *message(const emlrtStack *sp, const mxArray *m1,
  emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 1, &pArray, "message",
    true, location);
}

static void error(const emlrtStack *sp, const mxArray *m, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = m;
  emlrtCallMATLABR2012b((emlrtConstCTX)sp, 0, NULL, 1, &pArray, "error", true,
                        location);
}

static const mxArray *b_message(const emlrtStack *sp, const mxArray *m1, const
  mxArray *m2, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 2, &pArrays[0],
    "message", true, location);
}

static const mxArray *getString(const emlrtStack *sp, const mxArray *m1,
  emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 1, &pArray, "getString",
    true, location);
}

static void b_error(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = m;
  pArrays[1] = m1;
  emlrtCallMATLABR2012b((emlrtConstCTX)sp, 0, NULL, 2, &pArrays[0], "error",
                        true, location);
}

static boolean_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  boolean_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "logical", false, 0U, (
    const void *)&dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static int32_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  int32_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "int32", false, 0U, (
    const void *)&dims);
  ret = *(int32_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U, (
    const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void init_simulink_io_address(InstanceStruct_ruThg8ilLzfH7h2KmGFzOE
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->b_y0 = (real_T *)cgxertGetOutputPortSignal(moduleInstance->S,
    0);
}

/* CGXE Glue Code */
static void mdlOutputs_ruThg8ilLzfH7h2KmGFzOE(SimStruct *S, int_T tid)
{
  InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *moduleInstance =
    (InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_ruThg8ilLzfH7h2KmGFzOE(SimStruct *S)
{
  InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *moduleInstance =
    (InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_ruThg8ilLzfH7h2KmGFzOE(SimStruct *S, int_T tid)
{
  InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *moduleInstance =
    (InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static mxArray* getSimState_ruThg8ilLzfH7h2KmGFzOE(SimStruct *S)
{
  mxArray* mxSS;
  InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *moduleInstance =
    (InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *)cgxertGetRuntimeInstance(S);
  mxSS = (mxArray *) cgxe_mdl_get_sim_state(moduleInstance);
  return mxSS;
}

static void setSimState_ruThg8ilLzfH7h2KmGFzOE(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *moduleInstance =
    (InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_set_sim_state(moduleInstance, emlrtAlias(ss));
}

static void mdlTerminate_ruThg8ilLzfH7h2KmGFzOE(SimStruct *S)
{
  InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *moduleInstance =
    (InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_ruThg8ilLzfH7h2KmGFzOE(SimStruct *S)
{
  InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *moduleInstance =
    (InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_ruThg8ilLzfH7h2KmGFzOE(SimStruct *S)
{
  InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *moduleInstance =
    (InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_ruThg8ilLzfH7h2KmGFzOE(SimStruct *S)
{
  InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *moduleInstance =
    (InstanceStruct_ruThg8ilLzfH7h2KmGFzOE *)calloc(1, sizeof
    (InstanceStruct_ruThg8ilLzfH7h2KmGFzOE));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_ruThg8ilLzfH7h2KmGFzOE);
  ssSetmdlInitializeConditions(S, mdlInitialize_ruThg8ilLzfH7h2KmGFzOE);
  ssSetmdlUpdate(S, mdlUpdate_ruThg8ilLzfH7h2KmGFzOE);
  ssSetmdlTerminate(S, mdlTerminate_ruThg8ilLzfH7h2KmGFzOE);
  ssSetmdlEnable(S, mdlEnable_ruThg8ilLzfH7h2KmGFzOE);
  ssSetmdlDisable(S, mdlDisable_ruThg8ilLzfH7h2KmGFzOE);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_ruThg8ilLzfH7h2KmGFzOE(SimStruct *S)
{
}

void method_dispatcher_ruThg8ilLzfH7h2KmGFzOE(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_ruThg8ilLzfH7h2KmGFzOE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_ruThg8ilLzfH7h2KmGFzOE(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_ruThg8ilLzfH7h2KmGFzOE(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_ruThg8ilLzfH7h2KmGFzOE(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: ruThg8ilLzfH7h2KmGFzOE.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_ruThg8ilLzfH7h2KmGFzOE_BuildInfoUpdate(void)
{
  mxArray * mxBIArgs;
  mxArray * elem_1;
  mxArray * elem_2;
  mxArray * elem_3;
  mxArray * elem_4;
  mxArray * elem_5;
  mxArray * elem_6;
  mxArray * elem_7;
  mxArray * elem_8;
  mxArray * elem_9;
  mxArray * elem_10;
  mxBIArgs = mxCreateCellMatrix(1,3);
  elem_1 = mxCreateCellMatrix(1,6);
  elem_2 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,0,elem_2);
  elem_3 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,1,elem_3);
  elem_4 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,2,elem_4);
  elem_5 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,3,elem_5);
  elem_6 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,4,elem_6);
  elem_7 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,5,elem_7);
  mxSetCell(mxBIArgs,0,elem_1);
  elem_8 = mxCreateCellMatrix(1,1);
  elem_9 = mxCreateString("beagleboneblue.bbblueADC");
  mxSetCell(elem_8,0,elem_9);
  mxSetCell(mxBIArgs,1,elem_8);
  elem_10 = mxCreateCellMatrix(1,0);
  mxSetCell(mxBIArgs,2,elem_10);
  return mxBIArgs;
}

mxArray *cgxe_ruThg8ilLzfH7h2KmGFzOE_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("thirdPartyLibs");
  mxArray* incompatibleSymbol = mxCreateString("beagleboneblue.bbblueADC");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
