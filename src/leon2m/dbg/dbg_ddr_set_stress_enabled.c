/* dbg_ddr_set_stress_enabled  (FUN_a00dd808)
 *
 * Switch the memory stress test on or off.
 * Name basis: proven - byte at 0xA802B0AC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd808 @ 0xa00dd808, flags -mcpu=v8 -O2 -g.
 * Source form: the blank line between the header and the brace and the closing 'return;' are kept.
 */
extern unsigned char dbg_ddr_stress_enabled;

/* Store the on/off byte of the memory stress test. dbg_ddr_stress_task calls it with 0 to stop the test. */
void dbg_ddr_set_stress_enabled(unsigned char enabled)

{
  dbg_ddr_stress_enabled = enabled;
  return;
}
