/* sys_return_one_copy3  (FUN_a0148804)
 *
 * Return 1.
 * Returns: 1
 * Note: Identical copy of sys_return_one.
 * Name basis: descriptive - constant; unused
 *
 * Matching notes
 * --------------
 * FUN_a0148804 (leon2m, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Nothing in the image refers to this routine. Source form: a constant return; the value is set in the
 * retl delay slot.
 */

/* Always returns 1. Nothing calls this routine. */
int sys_return_one_copy3(void)
{
    return 1;
}
