/* FUN_a014f894 (leon2m 0xa014f894-0xa014f8a0, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores its argument to the halfword DAT_a802a49c. Called by FUN_a014bac4. It lies between FUN_a014f888 and
 * FUN_a014f8a0. Source form: a direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned short DAT_a802a49c;

void FUN_a014f894(unsigned short v)
{
    DAT_a802a49c = v;
}
