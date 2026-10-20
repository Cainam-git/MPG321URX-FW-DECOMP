/* leon2s FUN_a0090f28 @ 0xa0090f28 (-mcpu=v8 -Os -g)
 * The difference was the base address: the target computes `sethi %hi(0xa807d000), %g1` then `or %g1, 0x3e4, %g1`, giving base `0xa807d3e4`. The array should be declared at that base, not at `0xa807d471` (which was Ghidra's incorrect merged base+offset). Now the index multiplication and the final `+0x8d` match the target's instruction sequence exactly.
 */
extern unsigned char ARR_a807d3e4[];

unsigned char FUN_a0090f28(unsigned int param_1)
{
    return ARR_a807d3e4[(param_1 & 0xff) * 0xb0 + 0x8d];
}
