/* sys_return_4  (FUN_a012c110)
 *
 * Return the constant 4.
 * Returns: 4
 * Name basis: descriptive - constant; unused
 *
 * Matching notes
 * --------------
 * FUN_a012c110 (leon2m 0xa012c110-0xa012c118, 8 bytes, leaf), flags -mcpu=v8 -O2 -g. Source form: a constant
 * return; the value is set in the retl delay slot.
 */
/* Return 4. Not called by name anywhere in the source. */
int sys_return_4(void)
{
    return 4;
}
