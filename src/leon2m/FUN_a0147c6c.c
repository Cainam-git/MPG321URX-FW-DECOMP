/* FUN_a0147c6c (leon2m 0xa0147c6c-0xa0147c80, 20 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Calls FUN_a01236e8(c) with its byte argument as a tail call; the nop after it is the -g line nop. Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a0147c5c and
 * FUN_a0147c80. Source form: an unsigned char parameter passed on (and 0xff before the call).
 */
extern void FUN_a01236e8(unsigned char);

void FUN_a0147c6c(unsigned char c)
{
    FUN_a01236e8(c);
}
