/* leon2s FUN_a00b0438 @ 0xa00b0438 (-mcpu=v8 -Os -g)
 * Returns the word at byte offset (p & 0xff) * 300 + 0xfc of ARR_a807dc18 (300-byte records; written as word index
 * (p & 0xff) * 75 + 0x3f).
 */
extern unsigned int ARR_a807dc18[];

unsigned int FUN_a00b0438(unsigned int param_1)
{
    return ARR_a807dc18[(param_1 & 0xff) * 75 + 0x3f];
}
