/* FUN_a014f944 (leon2m 0xa014f944-0xa014f950, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores its argument to the halfword DAT_a802a4a2. Called by FUN_a014bac4. It lies between FUN_a014f938 and
 * FUN_a014f950. Source form: a direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned short DAT_a802a4a2;

void FUN_a014f944(unsigned short v)
{
    DAT_a802a4a2 = v;
}
