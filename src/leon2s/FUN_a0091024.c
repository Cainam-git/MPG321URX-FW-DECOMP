/* leon2s FUN_a0091024 @ 0xa0091024 (-mcpu=v8 -Os)
 * Returns the halfword at +0x9e of the 0xb0-byte record (p & 0xff) at 0xA807D3E4.
 */
extern unsigned short ARR_a807d3e4[];

unsigned short FUN_a0091024(unsigned int param_1)
{
    return ARR_a807d3e4[(param_1 & 0xff) * 0xb0 / 2 + 0x4f];
}
