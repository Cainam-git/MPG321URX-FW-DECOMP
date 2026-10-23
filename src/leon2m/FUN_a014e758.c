/* FUN_a014e758 (leon2m 0xa014e758-0xa014e768, 16 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Calls FUN_a013adcc() as a tail call ('mov %o7, %g1; call; mov %g1, %o7'); the nop after it is the -g line nop.
 * Called by FUN_a002ef0c. It lies between FUN_a014e4b8 and FUN_a014e768. Source form: a void wrapper; whatever
 * arguments are in %o0..%o5 reach the callee unchanged.
 */
extern void FUN_a013adcc(void);

void FUN_a014e758(void)
{
    FUN_a013adcc();
}
