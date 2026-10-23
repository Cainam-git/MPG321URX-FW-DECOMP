/* FUN_a0147c5c (leon2m 0xa0147c5c-0xa0147c6c, 16 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Calls FUN_a0123744() as a tail call ('mov %o7, %g1; call; mov %g1, %o7'); the nop after it is the -g line nop.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a0147c48 and FUN_a0147c6c. Source form: a void wrapper; whatever arguments are in %o0..%o5 reach the callee
 * unchanged.
 */
extern void FUN_a0123744(void);

void FUN_a0147c5c(void)
{
    FUN_a0123744();
}
