/* leon2s FUN_a00c9370 @ 0xa00c9370-0xa00c9398 (10 words), flags -mcpu=v8 -Os -g.
 * Returns 1 when bit 6 (0x40) of FUN_a0fb7fd8(param_1 & 0xff, 0, 0xf) is set, else 0.
 * Source form: the masked result is stored in a local before the comparison (as in FUN_a008f9c0), which
 * gives the firmware's 'cmp %g0, %o0; addx %g0, 0, %i0'.
 */
extern unsigned int FUN_a0fb7fd8(unsigned int param_1, unsigned int param_2, unsigned int param_3);

unsigned int FUN_a00c9370(unsigned int param_1)
{
    unsigned int x = FUN_a0fb7fd8(param_1 & 0xff, 0, 0xf) & 0x40;
    return x != 0;
}
