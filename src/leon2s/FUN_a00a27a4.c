/* leon2s FUN_a00a27a4 @ 0xa00a27a4 (-mcpu=v8 -Os -g)
 * Returns the halfword at +0x1e of the 400-byte record p & 0xff at 0xA807D7E0 (halfword index p * 200 + 0xf).
 */
extern unsigned short ARR_a807d7e0[];

unsigned short FUN_a00a27a4(unsigned int param_1)
{
    return ARR_a807d7e0[(param_1 & 0xff) * 200 + 0x0f];
}
