/* FUN_a014f980 (leon2m 0xa014f980-0xa014f98c, 12 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores its argument to the byte DAT_a802cc86. Called by FUN_a014bac4. It lies between FUN_a014f974 and
 * FUN_a014f98c. Source form: a direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char DAT_a802cc86;

void FUN_a014f980(unsigned char v)
{
    DAT_a802cc86 = v;
}
