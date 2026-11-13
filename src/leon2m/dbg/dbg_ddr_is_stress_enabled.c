/* dbg_ddr_is_stress_enabled  (FUN_a00dd7f0)
 *
 * Return whether the memory stress test is switched on.
 * Returns: 0 or 1
 * Name basis: proven - byte at 0xA802B0AC; read by the stress test task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd7f0 @ 0xa00dd7f0, flags -mcpu=v8 -O2. A leaf routine without a register window.
 * Source form: the blank line between the header and the brace is kept.
 */
extern unsigned char dbg_ddr_stress_enabled;

/* Return the on/off byte of the memory stress test. Read by dbg_ddr_stress_task. */
unsigned char dbg_ddr_is_stress_enabled(void)

{
  return dbg_ddr_stress_enabled;
}
