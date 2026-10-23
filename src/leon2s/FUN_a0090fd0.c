/* leon2s FUN_a0090fd0 @ 0xa0090fd0 (-mcpu=v8 -Os -g)
 * Returns the halfword at +0x96 of the 0xb0-byte record p at 0xA807D3E4 (written as halfword index p * 0x58 + 0x4b).
 */
extern unsigned short ARR_a807d3e4[];

unsigned short FUN_a0090fd0(unsigned char param_1)
{
    return ARR_a807d3e4[param_1 * 0x58 + 0x4b];
}
