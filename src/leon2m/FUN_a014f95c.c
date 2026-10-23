/* FUN_a014f95c (leon2m 0xa014f95c-0xa014f968, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores its argument to the halfword DAT_a802a49e. Called by FUN_a014bac4. It lies between FUN_a014f950 and
 * FUN_a014f968. Source form: a direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned short DAT_a802a49e;

void FUN_a014f95c(unsigned short v)
{
    DAT_a802a49e = v;
}
