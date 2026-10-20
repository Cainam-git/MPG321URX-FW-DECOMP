/* leon2s FUN_a00a27f8 @ 0xa00a27f8 (-mcpu=v8 -Os -g)
 * Returns halfword 0xE of row (param_1 & 0xFF) of the halfword table at 0xA807D7E0 (200 halfwords per row). The
 * base is built as sethi %hi(0xa807d400), %g1 / or %g1, 0x3e0, %g1.
 */
extern unsigned short ARR_a807d7e0[];

unsigned short FUN_a00a27f8(unsigned int param_1)
{
    return ARR_a807d7e0[(param_1 & 0xff) * 200 + 0xe];
}
