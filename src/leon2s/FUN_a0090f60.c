/* leon2s FUN_a0090f60 @ 0xa0090f60 (-mcpu=v8 -Os -g)
 * Returns byte +0x8F of record p1 & 0xff of the 0xB0-byte records at 0xA807D3E4. Same code as FUN_a008f9e4 with
 * other constants.
 */
extern unsigned char ARR_a807d3e4[];

unsigned char FUN_a0090f60(unsigned int param_1)
{
    return ARR_a807d3e4[(param_1 & 0xff) * 0xb0 + 0x8f];
}
