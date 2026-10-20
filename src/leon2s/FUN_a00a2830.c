/* leon2s FUN_a00a2830 @ 0xa00a2830  MATCH (-mcpu=v8 -Os, gcc 3.4.4, near)
 * near-miss repaired mechanically (tools/nearfix.py): ARR_a807d400->ARR_a807d7e0
 */
extern unsigned short ARR_a807d7e0[];

unsigned short FUN_a00a2830(unsigned int param_1)
{
    return ARR_a807d7e0[(param_1 & 0xff) * 200 + 0x13];
}
