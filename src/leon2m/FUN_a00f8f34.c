/* leon2m FUN_a00f8f34 @ 0xa00f8f34  MATCH (-mcpu=v8 -O2 -g)
 * The ternary with explicit `? 0 : 1` produces the `cmp %g0, %o0; addx %g0, 0, %i0` pattern (comparing against zero and using carry), rather than the `and %o0, 1, %i0` that `!= 0` generated. The structure is the same: one call, mask with 0x40, then boolean conversion.
 */
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);

int FUN_a00f8f34(unsigned char param_1)
{
    int result = FUN_a00f1a90(param_1, 6);
    return (result & 0x40) == 0 ? 0 : 1;
}
