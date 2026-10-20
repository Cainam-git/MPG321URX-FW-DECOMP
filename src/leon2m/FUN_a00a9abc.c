/* leon2m FUN_a00a9abc @ 0xa00a9abc  (-mcpu=v8 -O3 -g -msoft-float)
 * Calls FUN_a0146b50(0x111, 0) and FUN_a0146b6c(0, 0). When DAT_a802d290 bytes +0x1E and +0x20 are equal it calls
 * FUN_a0146a80(0x2A, 0x10, 0xB, 0x296, 0) and FUN_a0146a80(0x2A, 0x12, 0xB, 0x296, 0). Then three loops call
 * FUN_a00a31a4(0, 0x2A, row, 1, FUN_a00a3844(table, i * 29 + byte +8), 0): i = 0..2 with DAT_0018e89c and
 * row i * 2 + 6; i = 0..1 with DAT_00182534 and row i * 2 + 0xC; i = 3..4 with DAT_001828c0 and row i * 2 + 10.
 * Finally FUN_a00a9650(byte +0x2F, 0), and with s = byte +0x2F, row = s * 2 + 6 (s <= 6) or s * 2 - 8:
 * FUN_a0146b20(0, 0x28, row, 1, 0xF, 0) and FUN_a0146b20(0, 0x29, row, 1, 0x10, 0).
 * Callers: FUN_a00951a8, FUN_a009530c, FUN_a00af44c.
 * Source form: the three tables are extern array symbols (cast integer constants change which addresses the
 * compiler keeps in registers across the loops); DAT_a802d290 is accessed directly.
 */
struct R290 {
    unsigned char pad[8]; unsigned char b08;
    unsigned char pad2[0x1e - 9]; unsigned char b1e;
    unsigned char pad3; unsigned char b20;
    unsigned char pad4[0x2f - 0x21]; unsigned char b2f;
};
extern struct R290 DAT_a802d290;
extern unsigned int DAT_0018e89c[];
extern unsigned int DAT_00182534[];
extern unsigned int DAT_001828c0[];
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146a80(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a0146b20(unsigned int, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a00a9abc(void)
{
    unsigned char i;
    unsigned char row;

    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    if (DAT_a802d290.b1e == DAT_a802d290.b20) {
        FUN_a0146a80(0x2a, 0x10, 0xb, 0x296, 0);
        FUN_a0146a80(0x2a, 0x12, 0xb, 0x296, 0);
    }
    for (i = 0; i <= 2; i++)
        FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_0018e89c, i * 29 + DAT_a802d290.b08), 0);
    for (i = 0; i <= 1; i++)
        FUN_a00a31a4(0, 0x2a, i * 2 + 0xc, 1, FUN_a00a3844(DAT_00182534, i * 29 + DAT_a802d290.b08), 0);
    for (i = 3; i <= 4; i++)
        FUN_a00a31a4(0, 0x2a, i * 2 + 10, 1, FUN_a00a3844(DAT_001828c0, i * 29 + DAT_a802d290.b08), 0);
    FUN_a00a9650(DAT_a802d290.b2f, 0);
    if (DAT_a802d290.b2f <= 6)
        row = DAT_a802d290.b2f * 2 + 6;
    else
        row = DAT_a802d290.b2f * 2 - 8;
    FUN_a0146b20(0, 0x28, row, 1, 0xf, 0);
    FUN_a0146b20(0, 0x29, row, 1, 0x10, 0);
}
