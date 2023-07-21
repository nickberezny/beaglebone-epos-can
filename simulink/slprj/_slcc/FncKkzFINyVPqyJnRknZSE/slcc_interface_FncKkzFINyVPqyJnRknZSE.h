#include "customcode_FncKkzFINyVPqyJnRknZSE.h"
#ifdef __cplusplus
extern "C" {
#endif


/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
DLL_EXPORT_CC extern const char_T *get_dll_checksum_FncKkzFINyVPqyJnRknZSE(void);
DLL_EXPORT_CC extern void init_can_FncKkzFINyVPqyJnRknZSE(real_T maxSpeed, real_T maxAccel, int32_T *fds);
DLL_EXPORT_CC extern void get_encoder_FncKkzFINyVPqyJnRknZSE(int32_T pdo_id, int32_T size, real_T *pos);
DLL_EXPORT_CC extern void set_motor_FncKkzFINyVPqyJnRknZSE(int32_T pdo_id, int32_T motor_id, real_T set_val);
DLL_EXPORT_CC extern void print_input_FncKkzFINyVPqyJnRknZSE(int32_T a, int32_T id);
DLL_EXPORT_CC extern void stop_motor_FncKkzFINyVPqyJnRknZSE(int32_T cfg_fd);

/* Function Definitions */
DLL_EXPORT_CC const uint8_T *get_checksum_source_info(int32_T *size);
#ifdef __cplusplus
}
#endif

