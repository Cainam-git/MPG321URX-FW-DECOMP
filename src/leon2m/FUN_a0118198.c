/* FUN_a0118198 (leon2m 0xa0118198-0xa01181a4, 12 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores its argument to the byte DAT_a802c98c. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a011818c and FUN_a01181a4. Source form: a direct store to the
 * extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char DAT_a802c98c;

void FUN_a0118198(unsigned char v)
{
    DAT_a802c98c = v;
}
