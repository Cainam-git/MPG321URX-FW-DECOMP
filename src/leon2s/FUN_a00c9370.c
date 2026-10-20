/* leon2s FUN_a00c9370 @ 0xa00c9370  MATCH (-mcpu=v8 -Os -g)
 * This function calls `FUN_a0fb7fd8` with the low byte of `param_1`, zero as the second argument, and 0xf as the third. It then masks the result with 0x40 and returns whether that bit is set. The structure follows the proven byte-exact pattern from `FUN_a008f9c0`: the masked result is stored in a local variable before the comparison, which lets the compiler emit the `cmp %g0, %o0; addx %g0, 0, %i0` carry trick exactly as the target does.
 */
extern unsigned int FUN_a0fb7fd8(unsigned int param_1, unsigned int param_2, unsigned int param_3);

unsigned int FUN_a00c9370(unsigned int param_1)
{
    unsigned int x = FUN_a0fb7fd8(param_1 & 0xff, 0, 0xf) & 0x40;
    return x != 0;
}
