/* leon2s FUN_a008f9e4 @ 0xa008f9e4 (-mcpu=v8 -Os -g)
 * Returns byte +0xa6 of the 0xb0-byte record (p & 0xff) at 0xA807D3E4.
 */
extern unsigned char ARR_a807d3e4[];

unsigned char FUN_a008f9e4(unsigned int param_1)
{
    return ARR_a807d3e4[(param_1 & 0xff) * 0xb0 + 0xa6];
}
