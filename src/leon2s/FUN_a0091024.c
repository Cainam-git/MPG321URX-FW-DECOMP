/* leon2s FUN_a0091024 @ 0xa0091024  MATCH (-mcpu=v8 -Os, gcc 3.4.4, near)
 * near-miss repaired mechanically (tools/nearfix.py): ARR_a807d482->ARR_a807d082; ARR_a807d082->ARR_a807d3e4
 */
extern unsigned short ARR_a807d3e4[];

unsigned short FUN_a0091024(unsigned int param_1)
{
    return ARR_a807d3e4[(param_1 & 0xff) * 0xb0 / 2 + 0x4f];
}
