/* hdr_tmo_disable_and_print  (FUN_a00d2d1c)
 *
 * Switch the tone-mapping stages off and print a line when the second set is on.
 * Note: Works on hdr_tmo_second_enabled_flag (0xA8078C26) and does nothing when that flag is not 1;
 *   hdr_tmo_disable / hdr_tmo_enable use the flag at 0xA8078C25.
 * Name basis: derived - counterpart of hdr_tmo_enable_second on the flag at 0xA8078C26; prints '[HDR] disable
 *   HDR'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d2d1c @ 0xa00d2d1c-0xa00d2d8c, flags -mcpu=v8 -Os -g.
 * Source form: the text is passed to dbg_print_string as the only argument of a tail call; the five callees are
 * (unsigned char, unsigned char) as in hdr_init. The unreachable ret/restore pair after the routine is not part
 * of the source.
 */
extern unsigned char hdr_tmo_second_enabled_flag;
extern int hdr_tmo_set_reg_fd0_bit(unsigned char, unsigned char);
extern int hdr_tmo_set_reg_fe0_bit(unsigned char, unsigned char);
extern int hdr_tmo_set_reg_f50_bit(unsigned char, unsigned char);
extern int hdr_tmo_set_reg_f60_f70_bit(unsigned char, unsigned char);
extern int hdr_tmo_set_reg_f10_bit(unsigned char, unsigned char);
extern void dbg_print_string(const char *);

/*
 * When hdr_tmo_second_enabled_flag is 1: clear the five tone-mapping control bits (registers FD0, FE0, F60,
 * F50 and F10), clear the flag and print "[HDR] disable HDR". Does nothing otherwise. Counterpart of
 * hdr_tmo_enable_second, which sets the same flag (not the one of hdr_tmo_enable / hdr_tmo_disable).
 */
void hdr_tmo_disable_and_print(void)
{
    if (hdr_tmo_second_enabled_flag != 1)
        return;
    hdr_tmo_set_reg_fd0_bit(0, 0);
    hdr_tmo_set_reg_fe0_bit(0, 0);
    hdr_tmo_set_reg_f60_f70_bit(0, 0);
    hdr_tmo_set_reg_f50_bit(0, 0);
    hdr_tmo_set_reg_f10_bit(0, 0);
    hdr_tmo_second_enabled_flag = 0;
    dbg_print_string("[HDR] disable HDR\r");
}
