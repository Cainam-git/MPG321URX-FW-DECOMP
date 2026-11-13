/* dbg_ddr_get_stress_param  (FUN_a00dd7fc)
 *
 * Return the parameter of the memory stress test.
 * Returns: value
 * Name basis: derived - word at 0xA802B0A8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd7fc @ 0xa00dd7fc, flags -mcpu=v8 -O2 -g.
 * Source form: the blank line between the header and the brace is kept.
 */
extern unsigned int dbg_ddr_stress_param;

/* Return the parameter word of the memory stress test. dbg_ddr_stress_task compares it with its counter dbg_ddr_stress_count. */
unsigned int dbg_ddr_get_stress_param(void)

{
  return dbg_ddr_stress_param;
}
