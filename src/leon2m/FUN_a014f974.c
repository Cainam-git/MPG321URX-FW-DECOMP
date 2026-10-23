/* FUN_a014f974 (leon2m 0xa014f974-0xa014f980, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores its argument to the byte DAT_a802cc87. Called by FUN_a014bac4. It lies between FUN_a014f968 and
 * FUN_a014f980. Source form: a direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char DAT_a802cc87;

void FUN_a014f974(unsigned char v)
{
    DAT_a802cc87 = v;
}
