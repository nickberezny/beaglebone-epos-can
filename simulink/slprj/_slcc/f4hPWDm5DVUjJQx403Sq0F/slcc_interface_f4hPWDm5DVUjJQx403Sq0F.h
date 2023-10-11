#include "customcode_f4hPWDm5DVUjJQx403Sq0F.h"
#ifdef __cplusplus
extern "C" {
#endif


/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
DLL_EXPORT_CC extern void get_fptr_addr_f4hPWDm5DVUjJQx403Sq0F(struct __FILE ***varAddr);
DLL_EXPORT_CC extern const char_T *get_dll_checksum_f4hPWDm5DVUjJQx403Sq0F(void);
DLL_EXPORT_CC extern void init_can_f4hPWDm5DVUjJQx403Sq0F(int32_T num_motors, real_T maxSpeed, real_T maxAccel, int32_T *fds);
DLL_EXPORT_CC extern void get_encoder_f4hPWDm5DVUjJQx403Sq0F(int32_T pdo_id, int32_T size, real_T *pos);
DLL_EXPORT_CC extern void set_motor_f4hPWDm5DVUjJQx403Sq0F(int32_T pdo_id, int32_T motor_id, real_T set_val);
DLL_EXPORT_CC extern void print_input_f4hPWDm5DVUjJQx403Sq0F(real_T a, int32_T id, int32_T debug);
DLL_EXPORT_CC extern void stop_motor_f4hPWDm5DVUjJQx403Sq0F(int32_T pdo_fd, int32_T num_motors);
DLL_EXPORT_CC extern void e_stop_f4hPWDm5DVUjJQx403Sq0F(int32_T cfg_fd, int32_T num_motors);
DLL_EXPORT_CC extern void init_datalog_f4hPWDm5DVUjJQx403Sq0F(void);
DLL_EXPORT_CC extern void print_data_f4hPWDm5DVUjJQx403Sq0F(real_T *data, int32_T size);
DLL_EXPORT_CC extern void close_datalog_f4hPWDm5DVUjJQx403Sq0F(void);
DLL_EXPORT_CC extern void read_write_f4hPWDm5DVUjJQx403Sq0F(int32_T pdo_id, int32_T num_motor, real_T *val);

/* Function Definitions */
DLL_EXPORT_CC const uint8_T *get_checksum_source_info(int32_T *size);
#ifdef __cplusplus
}
#endif

