/* FUN_a0147c48 (leon2m 0xa0147c48-0xa0147c5c, 20 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Calls FUN_a0133dc8(c) with its byte argument as a tail call; the nop after it is the -g line nop. Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a0147c40 and
 * FUN_a0147c5c. Source form: an unsigned char parameter passed on (and 0xff before the call).
 */
extern void FUN_a0133dc8(unsigned char);

void FUN_a0147c48(unsigned char c)
{
    FUN_a0133dc8(c);
}
