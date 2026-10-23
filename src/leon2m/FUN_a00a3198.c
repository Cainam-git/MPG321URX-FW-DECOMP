/* FUN_a00a3198 (leon2m 0xa00a3198-0xa00a31a4, 12 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores its argument to the byte DAT_a802aff4. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a00a3024 and FUN_a00a31a4. Source form: a direct store to the
 * extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char DAT_a802aff4;

void FUN_a00a3198(unsigned char v)
{
    DAT_a802aff4 = v;
}
