/* sys_api_return_5  (FUN_a0144684)
 *
 * Return the constant 5.
 * Returns: 5
 * Name basis: descriptive - constant; unused
 *
 * Matching notes
 * --------------
 * FUN_a0144684 (leon2m 0xa0144684-0xa014468c, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Nothing in the image refers to this routine. Source form: a constant return; the value is set in the
 * retl delay slot.
 */

/* Always returns 5. Nothing calls this routine. */
int sys_api_return_5(void)
{
    return 5;
}
