/* leon2m FUN_a014705c @ 0xa014705c-0xa0147064 (2 words); -mcpu=v8 -O2 -g and -O3 -g give the same code.
 * Returns 0xff. No callers were found; it directly follows FUN_a0146fdc, whose code ends in two tail calls.
 * The two words are 'retl; mov 0xff, %o0'.
 */
unsigned char FUN_a014705c(void)
{
    return 0xff;
}
