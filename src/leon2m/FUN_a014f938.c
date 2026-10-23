/* FUN_a014f938 (leon2m 0xa014f938-0xa014f944, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores its argument to the byte DAT_a802cc85. Called by FUN_a014bac4. It lies between FUN_a014f92c and
 * FUN_a014f944. Source form: a direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char DAT_a802cc85;

void FUN_a014f938(unsigned char v)
{
    DAT_a802cc85 = v;
}
