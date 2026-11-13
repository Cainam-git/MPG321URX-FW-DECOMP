/* sys_api_get_three_status_words  (FUN_a0148c84)
 *
 * Fetch the three stored status words into the caller's variables.
 * Name basis: descriptive - forwards to the getter of the words at 0xA802B7BC..C4; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148c84 @ 0xa0148c84-0xa0148c94 (4 words), flags -mcpu=v8 -O2 -g.
 * The call is a tail call: the caller's return address is handed on, so the callee returns straight to this
 * routine's caller. The last word is the nop the compiler places behind such a call sequence.
 * Nothing in the firmware calls this routine and no stored address points at it.
 */
extern void sys_get_three_status_words(unsigned int *, unsigned int *, unsigned int *);

/* Pass the three output pointers on to sys_get_three_status_words. */
void sys_api_get_three_status_words(unsigned int * first, unsigned int * second, unsigned int * third)
{
    sys_get_three_status_words(first, second, third);
}
