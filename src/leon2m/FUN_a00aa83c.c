/* leon2m FUN_a00aa83c @ 0xa00aa83c-0xa00aa9d8 (412 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Calls func_0x4008e2a4(), then for q = 5..0x14 FUN_a0146b20(0, 0x13, q, 0x13, 0, 0) and FUN_a0146a80(0x13, q,
 * 0x13, 0x792, 0), then FUN_a0146b20(0, 0x1C, 0x15, 2, 0, 0), FUN_a0146c40(5, 0, 0), FUN_a0146b50(0x92, 0) and
 * FUN_a0146b6c(0, 0) (the same start as FUN_a00ad02c). Then n = 7 rows for page 0, else 1 row: for i < n with
 * q = i * 2 + 6, FUN_a0146a80(0x14, q, 0x11, 0x292, 0) first when FUN_a00aa520(i) returns 0, then FUN_a00a31a4(0,
 * 0x14, q, 1, entry, 0) with entry (i + page * 7) * 29 + DAT_a802d290 byte +8 of the table DAT_00185e78 (looked
 * up with FUN_a00a3844). Ends with FUN_a00b32e4(1, 1, 0x792, 0x1c, 0x15, 2, 0x28).
 * Callers: FUN_a0092fd4, FUN_a0093144, FUN_a00b0034, FUN_a00b1004.
 * Source form: the row count in an unsigned int variable (n = page ? 1 : 7), the table as an extern array symbol
 * and DAT_a802d290 accessed directly.
 */
struct R290 { unsigned char pad[8]; unsigned char b08; };
extern struct R290 DAT_a802d290;
extern unsigned int DAT_00185e78[];
extern void func_0x4008e2a4(void);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);

void FUN_a00aa83c(unsigned char page)
{
    unsigned char i;

    func_0x4008e2a4();
    for (i = 5; i <= 0x14; i++) {
        FUN_a0146b20(0, 0x13, i, 0x13, 0, 0);
        FUN_a0146a80(0x13, i, 0x13, 0x792, 0);
    }
    FUN_a0146b20(0, 0x1c, 0x15, 2, 0, 0);
    FUN_a0146c40(5, 0, 0);
    FUN_a0146b50(0x92, 0);
    FUN_a0146b6c(0, 0);
    {
        unsigned int n = page ? 1 : 7;
        for (i = 0; i < n; i++) {
            if (!FUN_a00aa520(i))
                FUN_a0146a80(0x14, i * 2 + 6, 0x11, 0x292, 0);
            FUN_a00a31a4(0, 0x14, i * 2 + 6, 1, FUN_a00a3844(DAT_00185e78, (i + page * 7) * 29 + DAT_a802d290.b08), 0);
        }
    }
    FUN_a00b32e4(1, 1, 0x792, 0x1c, 0x15, 2, 0x28);
}
