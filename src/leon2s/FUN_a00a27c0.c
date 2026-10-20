/* leon2s FUN_a00a27c0 @ 0xa00a27c0  MATCH (-mcpu=v8 -Os -g)
 * Returns the halfword at byte offset 0x24 of the 400-byte record (param_1 & 0xFF) of the table at 0xa807d7e0,
 * written as halfword indexing (stride 0xC8, offset 0x12).
 */
extern unsigned short ARR_a807d7e0[];

unsigned short FUN_a00a27c0(unsigned int param_1)
{
    return ARR_a807d7e0[(param_1 & 0xff) * 0xc8 + 0x12];
}
