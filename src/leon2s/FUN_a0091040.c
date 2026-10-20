/* leon2s FUN_a0091040 @ 0xa0091040  MATCH (-mcpu=v8 -Os -g)
 * 
 */
extern unsigned short ARR_a807d3e4[];

unsigned short FUN_a0091040(unsigned int param_1)
{
    return ARR_a807d3e4[(param_1 & 0xff) * 0x58 + 0x50];
}
