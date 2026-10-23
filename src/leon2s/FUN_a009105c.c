/* leon2s FUN_a009105c @ 0xa009105c (-mcpu=v8 -Os -g)
 * Returns the halfword at +0xa2 of the 0xb0-byte record p at 0xA807D3E4.
 */
extern unsigned short ARR_a807d3e4[];

unsigned short FUN_a009105c(unsigned char param_1)
{
    return ARR_a807d3e4[param_1 * 0x58 + 0x51];
}
