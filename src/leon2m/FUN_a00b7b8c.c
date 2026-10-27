/* leon2m FUN_a00b7b8c @ 0xa00b7b8c-0xa00b7d14 (98 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Callers: FUN_a0098618, FUN_a009cd74, FUN_a009cfd4, FUN_a00af44c.
 * FUN_a0146b50(0x111, 0), FUN_a0146b6c(0, 0), FUN_a0146a80(0x2d, 0x14, 2, 0x692, 0). mode 0: for i = 0..6 passes
 * entry i * 29 + byte DAT_a802d290+8 of the table DAT_001935bc (FUN_a00a3844) to FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1,
 * entry, 0); other modes do the same for i = 7..11 with row i * 2 - 8. Then FUN_a0146ab0(0x792, 0) and for i = 0, 1
 * FUN_a0146b20(1, i + 0x2d, 0x15, 1, i + 0x28, 0).
 * Source form: built like FUN_a00ad970; the last loop compares with a limit variable n = 2 (cmp 2; bcs).
 */
struct St {
    unsigned char pad[8];
    unsigned char b08;
};
extern struct St DAT_a802d290;
extern unsigned int DAT_001935bc[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146ab0(int, int);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned short, int, unsigned int, int);

void FUN_a00b7b8c(unsigned char mode)
{
    unsigned char i, n;

    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    FUN_a0146a80(0x2d, 0x14, 2, 0x692, 0);
    if (mode == 0) {
        for (i = 0; i <= 6; i++)
            FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_001935bc, i * 29 + DAT_a802d290.b08), 0);
    } else {
        for (i = 7; i <= 11; i++)
            FUN_a00a31a4(0, 0x2a, i * 2 - 8, 1, FUN_a00a3844(DAT_001935bc, i * 29 + DAT_a802d290.b08), 0);
    }
    FUN_a0146ab0(0x792, 0);
    n = 2;
    for (i = 0; i < n; i++)
        FUN_a0146b20(1, i + 0x2d, 0x15, 1, i + 0x28, 0);
}
