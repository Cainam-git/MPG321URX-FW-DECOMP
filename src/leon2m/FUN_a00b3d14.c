/* leon2m FUN_a00b3d14 @ 0xa00b3d14-0xa00b3ed0 (444 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * FUN_a0146b50(0x46, 0), FUN_a0146b6c(0, 0); FUN_a0146a80(6, 0x10, 10, 0x692, 0) when FUN_a00d7d48() != 0
 * or bit 31 of DAT_a802d484 is set. second == 0: rows 0..6 with FUN_a00a31a4(0, 6, i * 2 + 6, 1, ...) of
 * FUN_a00a3844(DAT_00196dc0, byte +8 of DAT_a802d290 + i * 29); otherwise rows 7..8 at i * 2 - 8. Then
 * FUN_a0146ab0(0x792, 0) and FUN_a0146b20(1, i + 9, 0x15, 1, i + 0x28, 0) for i = 0..1.
 * The sign test is written as '(DAT_a802d484 >> 31)' (a '< 0' test gives another block order); the operand
 * order of the two index sums differs between the two loops.
 */
struct R290 { unsigned char pad[8]; unsigned char b08; };
extern struct R290 DAT_a802d290;
extern int DAT_a802d484;
extern unsigned int DAT_00196dc0[];
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern int FUN_a00d7d48(void);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146ab0(unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);

void FUN_a00b3d14(unsigned char second)
{
    unsigned char i;
    unsigned char n;

    FUN_a0146b50(0x46, 0);
    FUN_a0146b6c(0, 0);
    if (FUN_a00d7d48() != 0 || (DAT_a802d484 >> 31))
        FUN_a0146a80(6, 0x10, 10, 0x692, 0);
    if (second == 0) {
        n = 7;
        for (i = 0; i < n; i++)
            FUN_a00a31a4(0, 6, i * 2 + 6, 1, FUN_a00a3844(DAT_00196dc0, DAT_a802d290.b08 + i * 29), 0);
    } else {
        for (i = 7; i <= 8; i++)
            FUN_a00a31a4(0, 6, i * 2 - 8, 1, FUN_a00a3844(DAT_00196dc0, i * 29 + DAT_a802d290.b08), 0);
    }
    FUN_a0146ab0(0x792, 0);
    n = 2;
    for (i = 0; i < n; i++)
        FUN_a0146b20(1, i + 9, 0x15, 1, i + 0x28, 0);
}
