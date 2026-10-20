/* leon2s FUN_a0091388 @ 0xa0091388  MATCH (-mcpu=v8 -Os -g)
 * Reads two 20-bit values through FUN_a00a6668(param_1 & 0xFF, 0x106) and FUN_a00a6668(param_1 & 0xFF, 0x10C).
 * When both are non-zero it returns (u16)((u16)FUN_a00911bc(param_1) * v106 / v10C * 10000 >> 7); otherwise 0.
 */
extern unsigned int FUN_a00a6668(unsigned int param_1, unsigned int param_2);
extern unsigned short FUN_a00911bc(unsigned int param_1);

unsigned short FUN_a0091388(unsigned int param_1)
{
    unsigned int val1, val2;
    unsigned short result = 0;

    param_1 &= 0xff;
    val1 = FUN_a00a6668(param_1, 0x106) & 0xfffff;
    val2 = FUN_a00a6668(param_1, 0x10c) & 0xfffff;

    if (val1 != 0 && val2 != 0) {
        unsigned int t = FUN_a00911bc(param_1);
        t = ((unsigned short)t) * val1 / val2 * 10000 >> 7;
        result = (unsigned short)t;
    }

    return result;
}
