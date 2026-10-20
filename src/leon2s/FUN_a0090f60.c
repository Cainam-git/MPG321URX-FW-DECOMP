/* leon2s FUN_a0090f60 @ 0xa0090f60  MATCH (-mcpu=v8 -Os -g, twin)
 * Twin of FUN_a008f9e4: same code, constants swapped; byte-exact.
 */
extern unsigned char ARR_a807d3e4[];

unsigned char FUN_a0090f60(unsigned int param_1)
{
    return ARR_a807d3e4[(param_1 & 0xff) * 0xb0 + 0x8f];
}
