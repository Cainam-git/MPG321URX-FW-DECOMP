/* panel_vx1_is_locked  (FUN_a0122d40)
 *
 * Return whether the V-by-One status register reads 4.
 * Returns: 0 or 1
 * Name basis: derived - register 0xCF00EB48; polled by the application timer task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0122d40 @ 0xa0122d40 (-mcpu=v8 -O3 -g)
 * Source form: the result type is the decompiler's one-byte bool (unsigned char).
 */
#define reg_panel_vx1_lock_status (*(volatile unsigned int *)0xcf00eb48)

/*
 * Return 1 when register 0xCF00EB48 reads 4, else 0. sys_run_app_timer_task prints "Vx1 is abnormal" when this
 * returns 0 while the panel power-on steps are done and the other conditions listed there hold.
 */
unsigned char panel_vx1_is_locked(void)

{
  return reg_panel_vx1_lock_status == 4;
}
