/* FUN_a014f92c (leon2m 0xa014f92c-0xa014f938, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores its argument to the halfword DAT_a802a4b0. Called by FUN_a014bac4. It lies between FUN_a014f8a0 and
 * FUN_a014f938. Source form: a direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned short DAT_a802a4b0;

void FUN_a014f92c(unsigned short v)
{
    DAT_a802a4b0 = v;
}
