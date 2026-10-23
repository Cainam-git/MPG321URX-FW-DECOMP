/* FUN_a0127980 (leon2m 0xa0127980-0xa012798c, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores its argument to the byte DAT_a802d8a4. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a0127974 and FUN_a012798c. Source form: a direct store to the
 * extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char DAT_a802d8a4;

void FUN_a0127980(unsigned char v)
{
    DAT_a802d8a4 = v;
}
