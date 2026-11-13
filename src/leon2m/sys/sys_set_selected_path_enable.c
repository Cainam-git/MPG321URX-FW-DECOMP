/* sys_set_selected_path_enable  (FUN_a0114374)
 *
 * Switch the selected path on or off, or clear a block bit for another path.
 * Name basis: descriptive - compares the argument with the path selector
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0114374, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the parameters are declared (unsigned char enable, int path) and path is masked with 0xff in place;
 *  - the call is made three times, each followed by its own return, with the last argument as a character
 *    constant ('\0' or '\x01');
 *  - input_capture_update_bits is declared without a prototype (extern int f();).
 */
#define reg_sys_path_selector (*(volatile unsigned int *)0xcf01166c)
#define reg_sys_selected_path_enable (*(volatile unsigned int *)0xcf011670)
#define reg_sys_path_enable_2 (*(volatile unsigned int *)0xcf015a00)
extern int input_capture_update_bits();

#define CAPTURE_REG_0           0       /* register 0 of the capture block */
#define CAPTURE_BIT_0X40        0x40    /* the bit of that register that follows the path switch */

/*
 * Switch the selected signal path on or off.
 *
 *   enable  non-zero: switch on, zero: switch off
 *   path    the path (only the low 8 bits count); it is the selected path when it equals bits 0..1 of
 *           reg_sys_path_selector
 *
 * Only the selected path is switched: reg_sys_path_enable_2 and reg_sys_selected_path_enable are both set to
 * 1 or to 0, and bit 0x40 of register 0 of capture block `path` is set (on) or cleared (off). For a path that
 * is not the selected one only that bit is cleared, whatever `enable` says.
 * Called by the two one-line routines sys_api_enable_selected_path (enable = 1) and sys_api_disable_selected_path (enable = 0).
 */
void sys_set_selected_path_enable(unsigned char enable, int path)

{
  path = path & 0xff;
  if (path != (reg_sys_path_selector & 3)) {
    input_capture_update_bits(path,CAPTURE_REG_0,CAPTURE_BIT_0X40,'\0');
    return;
  }
  if (enable != '\0') {
    reg_sys_path_enable_2 = 1;
    reg_sys_selected_path_enable = 1;
    input_capture_update_bits(path,CAPTURE_REG_0,CAPTURE_BIT_0X40,'\x01');
    return;
  }
  reg_sys_path_enable_2 = 0;
  reg_sys_selected_path_enable = 0;
  input_capture_update_bits(path,CAPTURE_REG_0,CAPTURE_BIT_0X40,'\0');
  return;
}
