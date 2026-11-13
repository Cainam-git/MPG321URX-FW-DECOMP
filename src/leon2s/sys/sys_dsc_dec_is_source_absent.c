/* sys_dsc_dec_is_source_absent  (FUN_a00a47e0)
 *
 * Return whether the compressed (DSC) source of the decoder is gone.
 *   decoder
 * Returns: 1 when absent
 * Name basis: derived - prints 'dsc interface mode change'; uses sys_dsc_dec_is_hdmi21_source / _is_dp_source
 *   / _is_hdmi21_mode_lost
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a47e0 @ 0xa00a47e0-0xa00a486c (35 words), flags -mcpu=v8 -Os -g.
 * The port code sys_dsc_dec_command_value is passed to all three calls and re-read for each call. The state
 * table is sys_dsc_dec_state_records (8-byte records).
 * Source form: int result (a u8 result adds 'and 1' twice).
 */
struct dsc_state_record { unsigned char b[8]; };   /* byte +5 is tested here */
extern struct dsc_state_record sys_dsc_dec_state_records[];
extern unsigned char sys_dsc_dec_command_value;
extern void dbg_printf(const char *fmt, ...);
extern unsigned char sys_dsc_dec_is_hdmi21_source(unsigned char);
extern unsigned char sys_dsc_dec_is_dp_source(unsigned char);
extern unsigned char sys_dsc_dec_is_hdmi21_mode_lost(unsigned char);

/* Tell whether the decoder has no compressed source. The answer is 1, except when byte +5 of the decoder's state
 * record is not 1 and the input code in sys_dsc_dec_command_value is an HDMI 2.1 source that carries DSC or a
 * DisplayPort source with a stream: then it is 0, unless that HDMI 2.1 input has lost its mode, which gives 1
 * again and prints "dsc interface mode change".
 *   decoder: index into the state records
 */
int sys_dsc_dec_is_source_absent(unsigned char decoder)
{
    int absent = 1;

    if (sys_dsc_dec_state_records[decoder].b[5] != 1) {
        if (sys_dsc_dec_is_hdmi21_source(sys_dsc_dec_command_value) != 0 || sys_dsc_dec_is_dp_source(sys_dsc_dec_command_value) != 0) {
            absent = 0;
            if (sys_dsc_dec_is_hdmi21_mode_lost(sys_dsc_dec_command_value) == 1) {
                absent = 1;
                dbg_printf("dsc interface mode change %d\r\n", 1);
            }
        }
    }
    return absent;
}
