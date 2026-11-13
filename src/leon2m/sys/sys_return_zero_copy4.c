/* sys_return_zero_copy4  (FUN_a01423a8)
 *
 * Return 0.
 * Returns: 0
 * Note: Identical copy of sys_return_zero.
 * Name basis: descriptive - constant; used as a status getter that is always 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01423a8 @ 0xa01423a8, flags -mcpu=v8 -O2 -g (the section default).
 */

/* Always returns 0. */
unsigned int sys_return_zero_copy4(void)
{
    return 0;
}
