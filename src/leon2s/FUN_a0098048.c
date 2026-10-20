/* FUN_a0098048 (leon2s 0xa0098048-0xa00980a4, 92 bytes, leaf), flags -mcpu=v8 -Os -g.
 * rec = 0x34-byte record (port) of ARR_a807db00; r = register block at record word 2 (volatile MMIO, read
 * twice). When (r[0x20] >> 8) & ((r[0x20] >> 16) & 0xf) is non-zero, sets bit 0x19 of the bitmap at
 * record word 1 + 0x34 through FUN_a00a73ac, otherwise clears it through FUN_a00a73d4 (tail calls).
 * The two values are computed into separate locals (one expression folds the 0xf mask into the test).
 */
extern void FUN_a00a73ac(unsigned int, int);
extern void FUN_a00a73d4(unsigned int, int);
extern unsigned char ARR_a807db00[];

void FUN_a0098048(unsigned char port)
{
    unsigned int *base = (unsigned int *)(ARR_a807db00 + port * 0x34);
    volatile unsigned int *r = (volatile unsigned int *)base[2];

    unsigned int a = r[0x20] >> 8;
    unsigned int m = (r[0x20] >> 16) & 0xf;

    if (a & m)
        FUN_a00a73ac(0x19, base[1] + 0x34);
    else
        FUN_a00a73d4(0x19, base[1] + 0x34);
}
