/* leon2s FUN_a0090fb4 @ 0xa0090fb4 (-mcpu=v8 -Os -g)
 * The target computes the base address as `sethi %hi(0xa807d000); or %g1, 0x3e4` which gives 0xa807d3e4, so the array symbol must be at that full address. The stride is 0xb0 = 176 bytes = 88 halfwords, and the load offset is 0x94 = 148 bytes = 74 halfwords. So the expression is `(param_1 & 0xff) * 88 + 74` indexing into an `unsigned short` array.
 */
extern unsigned short ARR_a807d3e4[];

unsigned short FUN_a0090fb4(unsigned int param_1)
{
    return ARR_a807d3e4[(param_1 & 0xff) * 88 + 74];
}
