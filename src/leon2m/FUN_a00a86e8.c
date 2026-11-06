/* leon2m FUN_a00a86e8 @ 0xa00a86e8-0xa00a87cc (57 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Code facts: FUN_a0146b50(0x111, 0); FUN_a0146b6c(0, 0); if byte DAT_a802d290[0x1e] == DAT_a802d290[0x20]:
 * FUN_a0146a80(0x2a, 0xc, 0xb, 0x296, 0), FUN_a0146a80(0x2a, 0xe, 0xb, 0x296, 0). Then for i = 0..4 (u8):
 * FUN_a00a31a4(0, 0x2a, i*2 + 6, 1, FUN_a00a3844(table 0x1828c0, (u16)(i*29 + byte DAT_a802d290[8])), 0). void.
 * FUN_a00b31a0 family.
 * Source form: a plain for loop over i = 0..4, built with -msoft-float as its siblings FUN_a00a8654 and
 * FUN_a00b3c80 (the fw keeps only the sethi of DAT_a802d290 outside the loop, 0xa00a8704); the table is the
 * symbol DAT_001828c0.
 */
extern unsigned char DAT_a802d290[];
extern unsigned int DAT_001828c0[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);

void FUN_a00a86e8(void)
{
    unsigned char i;

    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    if (DAT_a802d290[0x1e] == DAT_a802d290[0x20]) {
        FUN_a0146a80(0x2a, 0xc, 0xb, 0x296, 0);
        FUN_a0146a80(0x2a, 0xe, 0xb, 0x296, 0);
    }
    for (i = 0; i <= 4; i++)
        FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1,
                     FUN_a00a3844(DAT_001828c0, i * 29 + DAT_a802d290[8]), 0);
}
