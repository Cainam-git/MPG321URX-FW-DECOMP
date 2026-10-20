/* leon2s FUN_a0090f7c @ 0xa0090f7c (-mcpu=v8 -Os -g)
 * Twin of FUN_a008f9e4: same code, other constants.
 */
extern unsigned char ARR_a807d3e4[];

unsigned char FUN_a0090f7c(unsigned int param_1)
{
    return ARR_a807d3e4[(param_1 & 0xff) * 0xb0 + 0x90];
}
