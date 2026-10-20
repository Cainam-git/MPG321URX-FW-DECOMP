/* leon2s FUN_a0091008 @ 0xa0091008  MATCH (-mcpu=v8 -Os -g)
 * Returns the halfword at byte offset 0x9C of record p (p = the parameter byte) in the 0xB0-byte record array
 * based at 0xA807D3E4, written as ARR_a807d3e4[p * 0x58 + 0x4e] on an unsigned short array (lduh).
 */
extern unsigned short ARR_a807d3e4[];

unsigned short FUN_a0091008(unsigned char param_1)
{
    return ARR_a807d3e4[param_1 * 0x58 + 0x4e];
}
