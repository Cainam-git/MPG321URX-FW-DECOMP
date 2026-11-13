/* pq_api_enable_secondary_gamma_lut  (FUN_a014e170)
 *
 * Switch the secondary gamma look-up table on, or off followed by a 20-tick delay.
 * Name basis: descriptive - enable bit 0xCF00EAC8.3; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e170 @ 0xa014e170, flags -mcpu=v8 -O2 -g (section default).
 * Source form: as pq_api_enable_primary_gamma_lut (six parameters, callees without a prototype called with
 * 0x14 and pass_1..pass_5, a tail call on both paths).
 */
extern int pq_gamma_enable_secondary_lut();
extern int pq_gamma_disable_secondary_lut();
extern int timer_sleep_ticks();

#define LUT_OFF_WAIT_TICKS 0x14         /* passed to timer_sleep_ticks after switching off */

/*
 * Set (on != 0) or clear (on = 0) bit 3 of the gamma look-up table control register 0xCF00EAC8. After
 * clearing, timer_sleep_ticks(0x14) waits. pq_gamma_enable_secondary_lut takes no argument; the extra values
 * passed to it are not used. Nothing in the firmware calls this routine.
 */
void pq_api_enable_secondary_gamma_lut(unsigned char on, unsigned int pass_1, unsigned int pass_2, unsigned int pass_3,
                 unsigned int pass_4, unsigned int pass_5)
{
  if (on != 0) {
    pq_gamma_enable_secondary_lut(LUT_OFF_WAIT_TICKS, pass_1, pass_2, pass_3, pass_4, pass_5);
    return;
  }
  pq_gamma_disable_secondary_lut();
  timer_sleep_ticks(LUT_OFF_WAIT_TICKS, pass_1, pass_2, pass_3, pass_4, pass_5);
  return;
}
