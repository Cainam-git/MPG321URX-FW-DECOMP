/* FUN_a0121eac (leon2m 0xa0121eac-0xa0121eb8, 12 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores its argument to the word DAT_a802c9e0. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a0121e3c and FUN_a0121eb8. Source form: a direct store to the
 * extern symbol (the store sits in the retl delay slot).
 */
extern unsigned int DAT_a802c9e0;

void FUN_a0121eac(unsigned int v)
{
    DAT_a802c9e0 = v;
}
