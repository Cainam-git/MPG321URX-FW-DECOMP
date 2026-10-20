/*
 * FUN_a00ab884 (leon2s, 0xa00ab884-0xa00ab8b8, 52 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Code facts: sets (param_2 != 0) or clears (param_2 == 0) bit param_1 of the flag byte 0xa8079314
 * (ldub / or or andn / stb, the stb in the retl delay slot). Both params are u8 (fw 'and 0xff' on o0,
 * 'btst 0xff' on o1). The bit expression '1 << param_1' is written in each arm (a shared mask local
 * is computed in another order: 69.23).
 * Aids: none.
 */
extern unsigned char DAT_a8079314;

void FUN_a00ab884(unsigned char param_1, unsigned char param_2)
{
    if (param_2)
        DAT_a8079314 |= 1 << param_1;
    else
        DAT_a8079314 &= ~(1 << param_1);
}
