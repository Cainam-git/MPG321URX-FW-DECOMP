/* sys_otp_load_shared_data  (FUN_a008d690)
 *
 * Load factory data records 12..16 into shared memory and report it.
 * Name basis: descriptive - buffer 0x9F1B0600; sets 0xA8078C00 and calls ipc_publish_status_flags
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008d690 @ 0xa008d690-0xa008d70c (31 words), flags -mcpu=v8 -Os -g.
 * The final call is a tail call and takes no argument.
 */
/* One entry of the ROM table of factory data records. */
struct otp_record { unsigned short start; unsigned short length; };    /* store address, byte count */
extern const struct otp_record ARR_a00b4036[];
extern unsigned char sys_otp_shared_loaded_flag;
extern void ipc_publish_status_flags(void);
extern void sys_otp_read_bytes(unsigned short, unsigned short, unsigned int);
extern void sys_otp_check_records(unsigned int, unsigned char, unsigned char);

#define OTP_SHARED_BUFFER 0x9f1b0600    /* shared memory buffer that receives records 12..16 */
#define OTP_SHARED_FIRST  0xc
#define OTP_SHARED_LAST   0x10
#define OTP_SHARED_END    0x11          /* one past the last record */

/* Read the factory data records 12..16 as one block from the data store into the shared buffer, check them with
 * sys_otp_check_records, set sys_otp_shared_loaded_flag and call ipc_publish_status_flags.
 */
void sys_otp_load_shared_data(void)
{
    unsigned short total_length = 0;
    unsigned char i;

    for (i = OTP_SHARED_FIRST; i <= OTP_SHARED_LAST; i++)
        total_length += ARR_a00b4036[i].length;
    sys_otp_read_bytes(ARR_a00b4036[OTP_SHARED_FIRST].start, total_length, OTP_SHARED_BUFFER);
    sys_otp_check_records(OTP_SHARED_BUFFER, OTP_SHARED_FIRST, OTP_SHARED_END);
    sys_otp_shared_loaded_flag = 1;
    ipc_publish_status_flags();
}
