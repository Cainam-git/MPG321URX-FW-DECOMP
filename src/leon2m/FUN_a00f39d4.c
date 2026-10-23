/* FUN_a00f39d4 (leon2m 0xa00f39d4-0xa00f39e0, 12 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores its argument to the word DAT_a802b79c. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a00f39c0 and FUN_a00f39e0. Source form: a direct store to the
 * extern symbol (the store sits in the retl delay slot).
 */
extern unsigned int DAT_a802b79c;

void FUN_a00f39d4(unsigned int v)
{
    DAT_a802b79c = v;
}
