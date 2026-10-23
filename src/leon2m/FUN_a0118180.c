/* FUN_a0118180 (leon2m 0xa0118180-0xa011818c, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores its argument to the byte DAT_a802c98d. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a0118174 and FUN_a011818c. Source form: a direct store to the
 * extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char DAT_a802c98d;

void FUN_a0118180(unsigned char v)
{
    DAT_a802c98d = v;
}
