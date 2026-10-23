/* FUN_a014f950 (leon2m 0xa014f950-0xa014f95c, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores its argument to the halfword DAT_a802a4a0. Called by FUN_a014bac4. It lies between FUN_a014f944 and
 * FUN_a014f95c. Source form: a direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned short DAT_a802a4a0;

void FUN_a014f950(unsigned short v)
{
    DAT_a802a4a0 = v;
}
