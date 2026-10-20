/* leon2s FUN_a00a27a4 @ 0xa00a27a4  MATCH (-mcpu=v8 -Os -g)
 * 
 */
extern unsigned short ARR_a807d7e0[];

unsigned short FUN_a00a27a4(unsigned int param_1)
{
    return ARR_a807d7e0[(param_1 & 0xff) * 200 + 0x0f];
}
