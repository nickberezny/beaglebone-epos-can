#include "customcode_9FYpWq1vvG3Hr0dnFEWgeE.h"
#ifdef __cplusplus
extern "C" {
#endif


/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
DLL_EXPORT_CC extern void get_fptr_addr_9FYpWq1vvG3Hr0dnFEWgeE(struct _iobuf ***varAddr);
DLL_EXPORT_CC extern const char_T *get_dll_checksum_9FYpWq1vvG3Hr0dnFEWgeE(void);
DLL_EXPORT_CC extern void init_can_9FYpWq1vvG3Hr0dnFEWgeE(int32_T num_motors, real_T maxSpeed, real_T maxAccel, int32_T *fds);
DLL_EXPORT_CC extern void get_encoder_9FYpWq1vvG3Hr0dnFEWgeE(int32_T pdo_id, int32_T size, real_T *pos);
DLL_EXPORT_CC extern void set_motor_9FYpWq1vvG3Hr0dnFEWgeE(int32_T pdo_id, int32_T motor_id, real_T set_val);
DLL_EXPORT_CC extern void print_input_9FYpWq1vvG3Hr0dnFEWgeE(real_T a, int32_T id, int32_T debug);
DLL_EXPORT_CC extern void stop_motor_9FYpWq1vvG3Hr0dnFEWgeE(int32_T pdo_fd, int32_T num_motors);
DLL_EXPORT_CC extern void e_stop_9FYpWq1vvG3Hr0dnFEWgeE(int32_T cfg_fd, int32_T num_motors);
DLL_EXPORT_CC extern void init_datalog_9FYpWq1vvG3Hr0dnFEWgeE(void);
DLL_EXPORT_CC extern void print_data_9FYpWq1vvG3Hr0dnFEWgeE(real_T *data, int32_T size);
DLL_EXPORT_CC extern void close_datalog_9FYpWq1vvG3Hr0dnFEWgeE(void);

/* Function Definitions */
DLL_EXPORT_CC const uint8_T *get_checksum_source_info(int32_T *size);
#ifdef __cplusplus
}
#endif

