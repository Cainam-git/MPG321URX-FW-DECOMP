/* sys_return_constant_9  (FUN_a01547c8)
 *
 * Return the constant 9.
 * Returns: 9
 * Name basis: descriptive - returns 9; no caller
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01547c8, flags -mcpu=v8 -g (no optimisation level): the constant is first set in %g1 and then
 * copied to %i0 before the return.
 */
/* Return 9. No direct caller was found. */
int sys_return_constant_9(void)
{
    return 9;
}
