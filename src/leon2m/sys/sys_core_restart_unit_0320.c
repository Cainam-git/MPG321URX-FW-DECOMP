/* sys_core_restart_unit_0320  (FUN_a00de6a8)
 *
 * Write 0, wait a tick and write 5 to core register 0x9F020320.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de6a8 @ 0xa00de6a8, flags -mcpu=v8 -O2 -g.
 * Source form: reg_write32 and timer_sleep_ticks are declared without a prototype. The routine has six
 * parameters, of which the last four are passed on to the second reg_write32 call (the firmware passes the
 * incoming argument registers on).
 */
#define CORE_REG_0320 0x9f020320

extern void reg_write32();
extern int timer_sleep_ticks();

/* Write 0 to the core register 0x9F020320, wait 1 tick, then write 5 to it. Nothing calls it. */
void sys_core_restart_unit_0320(unsigned int unused_1, unsigned int unused_2, unsigned int arg_3, unsigned int arg_4,
                 unsigned int arg_5, unsigned int arg_6)

{
  reg_write32(CORE_REG_0320, 0);
  timer_sleep_ticks(1);
  reg_write32(CORE_REG_0320, 5, arg_3, arg_4, arg_5, arg_6);
  return;
}
