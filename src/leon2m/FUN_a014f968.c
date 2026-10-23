/* FUN_a014f968 (leon2m 0xa014f968-0xa014f974, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores its argument to the byte DAT_a802a49a. Called by FUN_a014bac4. It lies between FUN_a014f95c and
 * FUN_a014f974. Source form: a direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char DAT_a802a49a;

void FUN_a014f968(unsigned char v)
{
    DAT_a802a49a = v;
}
