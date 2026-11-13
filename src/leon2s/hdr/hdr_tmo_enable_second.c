/* hdr_tmo_enable_second  (FUN_a00d2d8c)
 *
 * Switch the second tone-mapping set on and print a line.
 * Name basis: descriptive - sibling on the flag at 0xA8078C26
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d2d8c @ 0xa00d2d8c-0xa00d2e00, flags -mcpu=v8 -Os -g.
 * Source form: the tail call takes the text as the symbol DAT_9f1c6420, so the compiler builds the address in the
 * delay slot of the final restore (a plain constant gives a separate 'or' and a bare restore). hdr_tmo_set_reg_fd0_bit
 * runs first and takes two arguments; the five callees are (unsigned char, unsigned char) as in hdr_init. The
 * unreachable ret/restore tail that the linker merges after the routine is not part of the source.
 */
extern unsigned char hdr_tmo_second_enabled_flag;
extern int hdr_tmo_set_reg_fd0_bit(unsigned char, unsigned char);
extern int hdr_tmo_set_reg_fe0_bit(unsigned char, unsigned char);
extern int hdr_tmo_set_reg_f60_f70_bit(unsigned char, unsigned char);
extern int hdr_tmo_set_reg_f50_bit(unsigned char, unsigned char);
extern int hdr_tmo_set_reg_f10_bit(unsigned char, unsigned char);
extern int dbg_print_string();
extern const char DAT_9f1c6420[];

/*
 * When hdr_tmo_second_enabled_flag is 0: set the control bits of all five registers (FD0, FE0, F60, F50 and
 * F10; hdr_tmo_enable clears the F10 bit instead), set the flag to 1 and print a text. Does nothing otherwise.
 * hdr_task calls it when hdr_check_metadata_timeout reports 1.
 */
void hdr_tmo_enable_second(void)
{
  if (hdr_tmo_second_enabled_flag == 0) {
    hdr_tmo_set_reg_fd0_bit(0, 1);
    hdr_tmo_set_reg_fe0_bit(0, 1);
    hdr_tmo_set_reg_f60_f70_bit(0, 1);
    hdr_tmo_set_reg_f50_bit(0, 1);
    hdr_tmo_set_reg_f10_bit(0, 1);
    hdr_tmo_second_enabled_flag = 1;
    dbg_print_string(DAT_9f1c6420);
  }
}
