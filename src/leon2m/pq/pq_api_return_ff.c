/* pq_api_return_ff  (FUN_a014705c)
 *
 * Return 0xFF.
 * Returns: 0xFF
 * Name basis: descriptive - constant; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014705c @ 0xa014705c-0xa0147064 (2 words: retl; mov 0xff, %o0), flags -mcpu=v8 -O2 -g (section
 * default).
 */

/* Return 0xFF. Nothing in the firmware calls this routine. */
unsigned char pq_api_return_ff(void)
{
    return 0xff;
}
