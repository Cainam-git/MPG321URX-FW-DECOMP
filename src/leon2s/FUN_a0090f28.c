/* leon2s FUN_a0090f28 @ 0xa0090f28 (-mcpu=v8 -Os -g)
 * Returns byte +0x8d of entry (p & 0xff) of the 0xB0-byte records at 0xA807D3E4. Source form: the array is
 * declared at the record base 0xA807D3E4 (the firmware builds that base with sethi/or), the +0x8d in the index.
 */
extern unsigned char ARR_a807d3e4[];

unsigned char FUN_a0090f28(unsigned int param_1)
{
    return ARR_a807d3e4[(param_1 & 0xff) * 0xb0 + 0x8d];
}
