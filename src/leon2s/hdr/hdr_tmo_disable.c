/* hdr_tmo_disable  (FUN_a00d2c38)
 *
 * Switch the tone-mapping stages off when they are on.
 * Name basis: derived - five control bits cleared; flag at 0xA8078C25
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d2c38 @ 0xa00d2c38-0xa00d2ca8, flags -mcpu=v8 -Os -g.
 * Source form: the tail call takes the text as the symbol DAT_9f1c63d8, so the compiler builds the address in the
 * delay slot of the final restore (a plain constant gives a separate 'or' and a bare restore). hdr_tmo_set_reg_fd0_bit
 * runs first and takes two arguments; the five callees are (unsigned char, unsigned char) as in hdr_init. The
 * unreachable ret/restore tail that the linker merges after the routine is not part of the source.
 */
extern unsigned char hdr_tmo_enabled_flag;
extern int hdr_tmo_set_reg_fd0_bit(unsigned char, unsigned char);
extern int hdr_tmo_set_reg_fe0_bit(unsigned char, unsigned char);
extern int hdr_tmo_set_reg_f60_f70_bit(unsigned char, unsigned char);
extern int hdr_tmo_set_reg_f50_bit(unsigned char, unsigned char);
extern int hdr_tmo_set_reg_f10_bit(unsigned char, unsigned char);
extern int dbg_print_string();
extern const char DAT_9f1c63d8[];

/*
 * When hdr_tmo_enabled_flag is 1: clear the five tone-mapping control bits (the bit setters of registers
 * FD0, FE0, F60, F50 and F10, each with which = 0 and value = 0), clear the flag and print a text. Does nothing
 * when the flag is not 1. Counterpart of hdr_tmo_enable.
 */
void hdr_tmo_disable(void)
{
  if (hdr_tmo_enabled_flag == 1) {
    hdr_tmo_set_reg_fd0_bit(0, 0);
    hdr_tmo_set_reg_fe0_bit(0, 0);
    hdr_tmo_set_reg_f60_f70_bit(0, 0);
    hdr_tmo_set_reg_f50_bit(0, 0);
    hdr_tmo_set_reg_f10_bit(0, 0);
    hdr_tmo_enabled_flag = 0;
    dbg_print_string(DAT_9f1c63d8);
  }
}
