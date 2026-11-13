/* timer_clear_flag  (FUN_a00dedbc)
 *
 * Clear the timer flag byte.
 * Name basis: descriptive - byte at 0xA802B0BD; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dedbc @ 0xa00dedbc, flags -mcpu=v8 -O2 -g (leaf routine).
 * Source form: a direct store to the extern byte.
 */
extern unsigned char timer_flag;

/* Set the byte timer_flag (see timer_get_flag) back to 0. Nothing calls this routine. */
void timer_clear_flag(void)
{
    timer_flag = 0;
}
