/* sys_return_one_copy2  (FUN_a0147c40)
 *
 * Return 1.
 * Returns: 1
 * Note: Identical copy of sys_return_one.
 * Name basis: descriptive - constant; unused
 *
 * Matching notes
 * --------------
 * FUN_a0147c40 (leon2m 0xa0147c40-0xa0147c48, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Nothing in the image refers to this routine. Source form: a constant return; the value is set in the
 * retl delay slot.
 */

/* Always returns 1. Nothing calls this routine. */
int sys_return_one_copy2(void)
{
    return 1;
}
