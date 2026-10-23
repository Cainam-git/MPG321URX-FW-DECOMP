/* FUN_a0147c80 (leon2m 0xa0147c80-0xa0147c94, 20 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Calls FUN_a011337c(c) with its byte argument as a tail call; the nop after it is the -g line nop. Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a0147c6c and
 * FUN_a0147c94. Source form: an unsigned char parameter passed on (and 0xff before the call).
 */
extern void FUN_a011337c(unsigned char);

void FUN_a0147c80(unsigned char c)
{
    FUN_a011337c(c);
}
