/* sys_return_one  (FUN_a0110f44)
 *
 * Return 1.
 * Returns: 1
 * Name basis: descriptive - constant; unused
 *
 * Matching notes
 * --------------
 * FUN_a0110f44 (leon2m 0xa0110f44-0xa0110f4c, 8 bytes, leaf), flags -mcpu=v8 -O2 -g (section default).
 * Source form: a constant return; the value is set in the retl delay slot.
 */
/* Always returns 1. Nothing in the image calls it or holds its address. */
int sys_return_one(void)
{
    return 1;
}
