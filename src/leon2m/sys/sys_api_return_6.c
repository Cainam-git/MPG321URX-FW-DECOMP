/* sys_api_return_6  (FUN_a0144484)
 *
 * Return the constant 6.
 * Returns: 6
 * Name basis: descriptive - constant; unused
 *
 * Matching notes
 * --------------
 * FUN_a0144484 (leon2m 0xa0144484-0xa014448c, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Nothing in the image refers to this routine. Source form: a constant return; the value is set in the
 * retl delay slot.
 */

/* Always returns 6. Nothing calls this routine. */
int sys_api_return_6(void)
{
    return 6;
}
