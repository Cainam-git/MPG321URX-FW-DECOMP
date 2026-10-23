/* FUN_a0127908 (leon2m 0xa0127908-0xa0127914, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores its argument to the byte DAT_a802d8a1. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a01278fc and FUN_a0127914. Source form: a direct store to the
 * extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char DAT_a802d8a1;

void FUN_a0127908(unsigned char v)
{
    DAT_a802d8a1 = v;
}
