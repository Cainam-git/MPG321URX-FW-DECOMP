/* sys_api_return_6_copy  (FUN_a01547b4)
 *
 * Return the constant 6.
 * Returns: 6
 * Note: Identical copy of sys_api_return_6.
 * Name basis: descriptive - constant; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01547b4, flags -mcpu=v8 -g (no optimisation level): the constant is first set in %g1 and then
 * copied to %i0 before the return.
 */
/* Return 6. Identical to sys_api_return_6. No direct caller was found. */
int sys_api_return_6_copy(void)
{
    return 6;
}
