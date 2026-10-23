/* FUN_a00f39e0 (leon2m 0xa00f39e0-0xa00f39ec, 12 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores its argument to the word DAT_a802b7a0. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a00f39d4 and FUN_a00f39ec. Source form: a direct store to the
 * extern symbol (the store sits in the retl delay slot).
 */
extern unsigned int DAT_a802b7a0;

void FUN_a00f39e0(unsigned int v)
{
    DAT_a802b7a0 = v;
}
