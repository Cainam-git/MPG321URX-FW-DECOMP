/* leon2s FUN_a00b0454 @ 0xa00b0454 (-mcpu=v8 -Os -g)
 * Stores p2 in byte +0x125 of the 300-byte record (p1 & 0xff) at 0xA807DC18.
 */
extern unsigned char ARR_a807dc18[];

void FUN_a00b0454(unsigned int param_1, unsigned char param_2)
{
    ARR_a807dc18[(param_1 & 0xff) * 300 + 0x125] = param_2;
}
