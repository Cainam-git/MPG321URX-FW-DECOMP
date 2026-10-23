/* leon2s FUN_a0090f7c @ 0xa0090f7c (-mcpu=v8 -Os -g)
 * Returns byte +0x90 of record p1 & 0xff of the 0xB0-byte records at 0xA807D3E4. Same code as FUN_a008f9e4 with
 * other constants.
 */
extern unsigned char ARR_a807d3e4[];

unsigned char FUN_a0090f7c(unsigned int param_1)
{
    return ARR_a807d3e4[(param_1 & 0xff) * 0xb0 + 0x90];
}
