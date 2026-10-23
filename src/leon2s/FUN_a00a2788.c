/* leon2s FUN_a00a2788 @ 0xa00a2788 (-mcpu=v8 -Os)
 * Returns the halfword at +0x1a of the 400-byte record p & 0xff at 0xA807D7E0 (halfword index p * 200 + 13).
 */
extern unsigned short ARR_a807d7e0[];

unsigned short FUN_a00a2788(unsigned int param_1)
{
    return ARR_a807d7e0[(param_1 & 0xff) * 200 + 13];
}
