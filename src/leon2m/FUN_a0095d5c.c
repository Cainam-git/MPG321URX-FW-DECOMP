/* FUN_a0095d5c (leon2m 0xa0095d5c-0xa0095dd8, 124 bytes), flags -mcpu=v8 -O3 -g.
 * When byte 0x15b of DAT_a802d290 differs from the byte DAT_a8025c56, copies it there and calls FUN_a00d9120();
 * then calls FUN_a00a93bc(DAT_a802afec - 0x4e), FUN_a00a9650(b, 0) and FUN_a00a813c(1, b, 1) with b =
 * DAT_a802d290[0x15b], stores 0xf to DAT_a802afec, calls FUN_a00a900c(1, 1) and FUN_a00acef4() (tail call).
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c56;
extern unsigned int DAT_a802afec;
extern void FUN_a00d9120(void);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a813c(unsigned char, unsigned char, unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00acef4(void);

void FUN_a0095d5c(void)
{
    if (DAT_a802d290[0x15b] != DAT_a8025c56) {
        DAT_a802d290[0x15b] = DAT_a8025c56;
        FUN_a00d9120();
    }
    FUN_a00a93bc(DAT_a802afec - 0x4e);
    FUN_a00a9650(DAT_a802d290[0x15b], 0);
    FUN_a00a813c(1, DAT_a802d290[0x15b], 1);
    DAT_a802afec = 0xf;
    FUN_a00a900c(1, 1);
    FUN_a00acef4();
}
