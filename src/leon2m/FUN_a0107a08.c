/* FUN_a0107a08 (leon2m 0xa0107a08-0xa0107a14, 12 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores its argument to the byte DAT_a8027a84. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a01079f4 and FUN_a0107a14. Source form: a direct store to the
 * extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char DAT_a8027a84;

void FUN_a0107a08(unsigned char v)
{
    DAT_a8027a84 = v;
}
