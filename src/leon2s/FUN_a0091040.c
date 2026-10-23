/* leon2s FUN_a0091040 @ 0xa0091040 (-mcpu=v8 -Os -g)
 * Returns the halfword at +0xa0 of the 0xb0-byte record (p & 0xff) at 0xA807D3E4.
 */
extern unsigned short ARR_a807d3e4[];

unsigned short FUN_a0091040(unsigned int param_1)
{
    return ARR_a807d3e4[(param_1 & 0xff) * 0x58 + 0x50];
}
