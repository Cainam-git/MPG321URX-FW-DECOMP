/* sys_return_zero_copy3  (FUN_a012b394)
 *
 * Return 0.
 * Returns: 0
 * Note: Identical copy of sys_return_zero.
 * Name basis: descriptive - constant; used as a status getter that is always 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012b394 @ 0xa012b394 (-mcpu=v8 -O2 -g)
 */

/* Return 0. Called by input_power_on_ports_by_mask, which passes it one argument that is not used. */
unsigned int sys_return_zero_copy3(void)
{
  return 0;
}
