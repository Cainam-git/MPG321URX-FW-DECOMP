/* sys_return_one_copy  (FUN_a0124eac)
 *
 * Return 1.
 * Returns: 1
 * Note: Identical copy of sys_return_one.
 * Name basis: descriptive - constant; unused
 *
 * Matching notes
 * --------------
 * FUN_a0124eac (leon2m 0xa0124eac-0xa0124eb4, 8 bytes, leaf), flags -mcpu=v8 -O2 -g. Source form: a constant
 * return; the value is set in the retl delay slot.
 */
/* Return 1. An identical copy of sys_return_one; nothing calls it. */
int sys_return_one_copy(void)
{
    return 1;
}
