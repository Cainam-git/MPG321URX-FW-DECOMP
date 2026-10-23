/* leon2s FUN_a00b03c8 @ 0xa00b03c8 (-mcpu=v8 -Os -g)
 * Returns byte +0xF5 of record p1 & 0xff of the 300-byte records at 0xA807DC18. Same code as FUN_a00b0264 with
 * other constants.
 */
extern unsigned char ARR_a807dc18[];

unsigned char FUN_a00b03c8(unsigned int param_1)
{
    return ARR_a807dc18[(param_1 & 0xff) * 300 + 0xf5];
}
