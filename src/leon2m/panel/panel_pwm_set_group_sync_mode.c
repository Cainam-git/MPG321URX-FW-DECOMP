/* panel_pwm_set_group_sync_mode  (FUN_a011e690)
 *
 * Wait for a frame, then set the 2-bit mode at the top of register 0xCF016404.
 * Name basis: descriptive - 0x80 for argument 1, else 0x40; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011e690 @ 0xa011e690 (-mcpu=v8 -O3 -g)
 * Source form: the decompiler's form is kept. The function is declared void yet ends in a return of
 * CONCAT44(second_arg, mode) & 0xffffffff000000ff; the build depends on that expression, so it stays.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
#define reg_panel_pwm_group_sync (*(volatile unsigned int *)0xcf016404)
extern int panel_wait_sync_pulse();

/*
 * Wait for one sync pulse of the panel, then put a 2-bit value in the top bits (7..6) of 0xCF016404 and keep
 * bits 5..0: 2 (0x80) when the low byte of mode is 1, else 1 (0x40).
 * No routine in the image calls it.
 */
void panel_pwm_set_group_sync_mode(unsigned int mode, unsigned int second_arg)

{
  panel_wait_sync_pulse();
  if ((mode & 0xff) == 1) {
    reg_panel_pwm_group_sync = reg_panel_pwm_group_sync & 0x3f | 0x80;
  }
  else {
    reg_panel_pwm_group_sync = reg_panel_pwm_group_sync & 0x3f | 0x40;
  }
  return CONCAT44(second_arg,mode) & 0xffffffff000000ff;
}
