/* leon2m FUN_a00b0034 @ 0xa00b0034-0xa00b05d8 (361 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Callers: FUN_a00911a0, FUN_a00912ac, FUN_a009145c, FUN_a00919b4, FUN_a0092bb4, FUN_a0092f2c.
 * Runs seq_a() (func_0x4008e2a4(), for q = 5..0x14 FUN_a0146b20(0, 0x13, q, 0x13, 0, 0) and FUN_a0146a80(0x13, q,
 * 0x13, 0x792, 0), then FUN_a0146b20(0, 0x1c, 0x15, 2, 0, 0) and FUN_a0146c40(5, 0, 0)) and FUN_a00a8c88(), then
 * acts on id (0..8; other values return):
 *   0: seq_a() again, FUN_a0146b50(0x92, 0), FUN_a0146b6c(0, 0), rows i = 0..2 from the table 0x18a360 (third argument
 *      argument 0xd), FUN_a00a900c(0, 0), FUN_a00af44c(0xb, 0);
 *   1: FUN_a00ad02c(0, 0), FUN_a00a900c(0, 0), FUN_a00af44c(0xe, 0);
 *   2: FUN_a0146b50/FUN_a0146b6c as in 0, rows 0..2 from the table 0x188634 (0xf), FUN_a00b6d58(),
 *      FUN_a00a900c(0, 0), FUN_a00af44c(0x15, 0);
 *   3: as 2 with rows 0..5 from the table 0x18ca88 (0xd); sel = 0 when FUN_a00aa520(0) is non-zero, else 1 when
 *      FUN_a00aa520(1) == 1, else 2; FUN_a00a900c(sel, 0), FUN_a00af44c(0x18, sel);
 *   4: FUN_a00b3ba0(), FUN_a00a900c(FUN_a01445fc(byte 0xa802d290+0x1e), 0);
 *   5: FUN_a00b3c80(), FUN_a00a900c(b, 0) with b = byte 0xa802d290+0x1f; y = b * 2 + 6 for b < 7, else b * 2 - 8;
 *      FUN_a0146b20(0, 0x14, y, 1, 0x3a, 0), FUN_a0146b20(0, 0x15, y, 1, 0x3b, 0), FUN_a00af44c(0x23, b);
 *   6: FUN_a0146b50/FUN_a0146b6c, rows 0..3 from the table 0x19158c without the FUN_a00aa520 test,
 *      FUN_a00a900c(0, 0), FUN_a00af44c(0x26, 0);
 *   7: FUN_a00ad1c0(0), FUN_a00a900c(0, 0), FUN_a00af44c(0x2a, 0);
 *   8: FUN_a00aa83c(0), FUN_a00a900c(0, 0), FUN_a00af44c(0x34, 0).
 * A row i: when FUN_a00aa520(i) returns 0, FUN_a0146a80(0x14, i * 2 + 6, third argument, 0x292, 0); then FUN_a00a31a4(0, 0x14,
 * i * 2 + 6, 1, FUN_a00a3844(table, i * 29 + byte 0xa802d290+8), 0) (as in FUN_a00ad02c).
 * Source form: seq_a() is a static helper inlined twice. The id-0 rows use their own block-local counter (with the
 * shared counter the loop pre-header orders 'clr' before the address 'sethi'); the id-6 loop limit is held in a
 * variable (cmp 4; bcs). The tables are extern array symbols.
 */
struct R290 { unsigned char p000[8]; unsigned char b008; unsigned char p009[0x1e - 9]; unsigned char b01e;
              unsigned char b01f; };
extern struct R290 DAT_a802d290;
extern unsigned int DAT_0018a360[], DAT_00188634[], DAT_0018ca88[], DAT_0019158c[];
extern void func_0x4008e2a4(void);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void FUN_a00a8c88(void);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00af44c(int, unsigned char);
extern void FUN_a00aa83c(unsigned char);
extern void FUN_a00ad1c0(unsigned char);
extern void FUN_a00ad02c(unsigned char, int);
extern void FUN_a00b3c80(void);
extern void FUN_a00b3ba0(void);
extern void FUN_a00b6d58(void);
extern unsigned char FUN_a01445fc(unsigned char);

static void seq_a(void)
{
    unsigned char i;

    func_0x4008e2a4();
    for (i = 5; i <= 0x14; i++) {
        FUN_a0146b20(0, 0x13, i, 0x13, 0, 0);
        FUN_a0146a80(0x13, i, 0x13, 0x792, 0);
    }
    FUN_a0146b20(0, 0x1c, 0x15, 2, 0, 0);
    FUN_a0146c40(5, 0, 0);
}

void FUN_a00b0034(unsigned char id)
{
    unsigned char i, n, sel, y;

    seq_a();
    FUN_a00a8c88();
    switch (id) {
    case 0: {
        unsigned char j;

        seq_a();
        FUN_a0146b50(0x92, 0);
        FUN_a0146b6c(0, 0);
        for (j = 0; j <= 2; j++) {
            if (!FUN_a00aa520(j))
                FUN_a0146a80(0x14, j * 2 + 6, 0xd, 0x292, 0);
            FUN_a00a31a4(0, 0x14, j * 2 + 6, 1, FUN_a00a3844(DAT_0018a360, j * 29 + DAT_a802d290.b008), 0);
        }
        FUN_a00a900c(0, 0);
        FUN_a00af44c(0xb, 0);
        break;
    }
    case 1:
        FUN_a00ad02c(0, 0);
        FUN_a00a900c(0, 0);
        FUN_a00af44c(0xe, 0);
        break;
    case 2:
        FUN_a0146b50(0x92, 0);
        FUN_a0146b6c(0, 0);
        for (i = 0; i <= 2; i++) {
            if (!FUN_a00aa520(i))
                FUN_a0146a80(0x14, i * 2 + 6, 0xf, 0x292, 0);
            FUN_a00a31a4(0, 0x14, i * 2 + 6, 1, FUN_a00a3844(DAT_00188634, i * 29 + DAT_a802d290.b008), 0);
        }
        FUN_a00b6d58();
        FUN_a00a900c(0, 0);
        FUN_a00af44c(0x15, 0);
        break;
    case 3:
        FUN_a0146b50(0x92, 0);
        FUN_a0146b6c(0, 0);
        for (i = 0; i <= 5; i++) {
            if (!FUN_a00aa520(i))
                FUN_a0146a80(0x14, i * 2 + 6, 0xd, 0x292, 0);
            FUN_a00a31a4(0, 0x14, i * 2 + 6, 1, FUN_a00a3844(DAT_0018ca88, i * 29 + DAT_a802d290.b008), 0);
        }
        if (FUN_a00aa520(0))
            sel = 0;
        else if (FUN_a00aa520(1) == 1)
            sel = 1;
        else
            sel = 2;
        FUN_a00a900c(sel, 0);
        FUN_a00af44c(0x18, sel);
        break;
    case 4:
        FUN_a00b3ba0();
        FUN_a00a900c(FUN_a01445fc(DAT_a802d290.b01e), 0);
        break;
    case 5:
        FUN_a00b3c80();
        FUN_a00a900c(DAT_a802d290.b01f, 0);
        if (DAT_a802d290.b01f < 7)
            y = DAT_a802d290.b01f * 2 + 6;
        else
            y = DAT_a802d290.b01f * 2 - 8;
        FUN_a0146b20(0, 0x14, y, 1, 0x3a, 0);
        FUN_a0146b20(0, 0x15, y, 1, 0x3b, 0);
        FUN_a00af44c(0x23, DAT_a802d290.b01f);
        break;
    case 6:
        FUN_a0146b50(0x92, 0);
        FUN_a0146b6c(0, 0);
        n = 4;
        for (i = 0; i < n; i++)
            FUN_a00a31a4(0, 0x14, i * 2 + 6, 1, FUN_a00a3844(DAT_0019158c, i * 29 + DAT_a802d290.b008), 0);
        FUN_a00a900c(0, 0);
        FUN_a00af44c(0x26, 0);
        break;
    case 7:
        FUN_a00ad1c0(0);
        FUN_a00a900c(0, 0);
        FUN_a00af44c(0x2a, 0);
        break;
    case 8:
        FUN_a00aa83c(0);
        FUN_a00a900c(0, 0);
        FUN_a00af44c(0x34, 0);
        break;
    }
}
