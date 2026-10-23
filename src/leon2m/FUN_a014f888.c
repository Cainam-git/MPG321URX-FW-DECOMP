/* FUN_a014f888 (leon2m 0xa014f888-0xa014f894, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores its argument to the halfword DAT_a802a4b2. Called by FUN_a014bac4. It lies between FUN_a014f6f4 and
 * FUN_a014f894. Source form: a direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned short DAT_a802a4b2;

void FUN_a014f888(unsigned short v)
{
    DAT_a802a4b2 = v;
}
