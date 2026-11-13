/* dbg_switch_dithering  (FUN_a00dd6c8)
 *
 * Switch the twelve dithering units off (mode 1 or 2) or on; print 'Dithering disabled' / 'enabled'.
 * Name basis: proven - prints 'Dithering disabled' after switching the twelve units off and 'Dithering
 *   enabled' after switching them on; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd6c8 @ 0xa00dd6c8, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the two texts are the symbols DAT_00198c60 / DAT_00198c78 ('restore %i0, %lo, %o0' builds the address in the
 *    delay slot of the return; a constant gives a separate 'or' and a bare restore);
 *  - volatile only on the 0xcf009bb8 hardware register.
 */

extern unsigned char dbg_dithering_off_flag;
extern unsigned char dbg_dithering_off_mode2_flag;
#define UNIT_TEST_REG_CF009BB8 (*(volatile unsigned int *)0xcf009bb8)
extern int uart_put_string();
extern const char DAT_00198c60[];       /* "Dithering disabled", printed after switching off */
extern const char DAT_00198c78[];       /* "Dithering enabled", printed after switching on */
extern int sys_enable_unit_e9e8();
extern int sys_enable_unit_e9e8_with_bit4();
extern int sys_enable_unit_6800_n0();
extern int sys_enable_unit_6800_n1();
extern int sys_enable_unit_6800_n2();
extern int sys_enable_unit_6800_n3();
extern int sys_enable_unit_6800_n4();
extern int sys_enable_unit_7400_n0();
extern int sys_enable_unit_7400_n1();
extern int sys_enable_unit_7400_n2();
extern int sys_enable_unit_7400_n3();
extern int sys_enable_unit_6a80();

/*
 * Switch the twelve units off or on through the same twelve setters (in the same order) that the start-up code
 * calls with 1, then print "Dithering disabled" or "Dithering enabled".
 *
 *   mode      1 or 2: switch all twelve units off (setter argument 0), set dbg_dithering_off_flag, and with
 *             mode 2 also dbg_dithering_off_mode2_flag, then print DAT_00198c60 ("Dithering disabled").
 *             any other value: clear both flags and register 0xCF009BB8, switch all twelve units on
 *             (argument 1), then print DAT_00198c78 ("Dithering enabled").
 *   argument  passed on to uart_put_string as its second argument.
 *
 * Nothing in the firmware calls it.
 */
void dbg_switch_dithering(int mode, unsigned int argument)

{
  if (mode == 2) {
    dbg_dithering_off_mode2_flag = 1;
  }
  if (mode - 1U < 2) {
    dbg_dithering_off_flag = 1;
    sys_enable_unit_7400_n0(0);
    sys_enable_unit_7400_n1(0);
    sys_enable_unit_7400_n2(0);
    sys_enable_unit_7400_n3(0);
    sys_enable_unit_6800_n0(0);
    sys_enable_unit_6800_n1(0);
    sys_enable_unit_6800_n2(0);
    sys_enable_unit_6800_n3(0);
    sys_enable_unit_6800_n4(0);
    sys_enable_unit_e9e8(0);
    sys_enable_unit_e9e8_with_bit4(0);
    sys_enable_unit_6a80(0);
    uart_put_string(DAT_00198c60, argument);
    return;
  }
  dbg_dithering_off_mode2_flag = 0;
  dbg_dithering_off_flag = 0;
  UNIT_TEST_REG_CF009BB8 = 0;
  sys_enable_unit_7400_n0(1);
  sys_enable_unit_7400_n1(1);
  sys_enable_unit_7400_n2(1);
  sys_enable_unit_7400_n3(1);
  sys_enable_unit_6800_n0(1);
  sys_enable_unit_6800_n1(1);
  sys_enable_unit_6800_n2(1);
  sys_enable_unit_6800_n3(1);
  sys_enable_unit_6800_n4(1);
  sys_enable_unit_e9e8(1);
  sys_enable_unit_e9e8_with_bit4(1);
  sys_enable_unit_6a80(1);
  uart_put_string(DAT_00198c78, argument);
  return;
}
