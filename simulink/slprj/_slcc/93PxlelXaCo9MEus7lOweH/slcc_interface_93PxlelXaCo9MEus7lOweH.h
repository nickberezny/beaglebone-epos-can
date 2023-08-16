#include "customcode_93PxlelXaCo9MEus7lOweH.h"
#ifdef __cplusplus
extern "C" {
#endif


/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
DLL_EXPORT_CC extern void get_fptr_addr_93PxlelXaCo9MEus7lOweH(struct __FILE ***varAddr);
DLL_EXPORT_CC extern const char_T *get_dll_checksum_93PxlelXaCo9MEus7lOweH(void);
DLL_EXPORT_CC extern void init_can_93PxlelXaCo9MEus7lOweH(int32_T num_motors, real_T maxSpeed, real_T maxAccel, int32_T *fds);
DLL_EXPORT_CC extern void get_encoder_93PxlelXaCo9MEus7lOweH(int32_T pdo_id, int32_T size, real_T *pos);
DLL_EXPORT_CC extern void set_motor_93PxlelXaCo9MEus7lOweH(int32_T pdo_id, int32_T motor_id, real_T set_val);
DLL_EXPORT_CC extern void print_input_93PxlelXaCo9MEus7lOweH(int32_T a, int32_T id, int32_T debug);
DLL_EXPORT_CC extern void stop_motor_93PxlelXaCo9MEus7lOweH(int32_T pdo_fd, int32_T num_motors);
DLL_EXPORT_CC extern void e_stop_93PxlelXaCo9MEus7lOweH(int32_T cfg_fd, int32_T num_motors);
DLL_EXPORT_CC extern void init_datalog_93PxlelXaCo9MEus7lOweH(void);
DLL_EXPORT_CC extern void print_data_93PxlelXaCo9MEus7lOweH(real_T *data, int32_T size);
DLL_EXPORT_CC extern void close_datalog_93PxlelXaCo9MEus7lOweH(void);

/* Function Definitions */
DLL_EXPORT_CC const uint8_T *get_checksum_source_info(int32_T *size);
#ifdef __cplusplus
}
#endif

