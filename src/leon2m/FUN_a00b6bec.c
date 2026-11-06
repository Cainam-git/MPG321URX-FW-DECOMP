/* leon2m FUN_a00b6bec @ 0xa00b6bec  (-mcpu=v8 -O3 -g -msoft-float)
 * Calls FUN_a00a8c88(), FUN_a0146b50(0x111, 0) and FUN_a0146b6c(0, 0). n = 7 when page is 0, else 1. For i = 0..n-1:
 * when i is 5, 6 or 7 and FUN_a00d7d48() returns non-zero it calls FUN_a0146a80(0x2A, i * 2 + 6, 0xB, 0x296, 0);
 * then FUN_a00a31a4(0, 0x2A, i * 2 + 6, 1, FUN_a00a3844(DAT_001951dc, (i + page * 7) * 29 + DAT_a802d290 byte +8),
 * 0). Then FUN_a0146ab0(0x792, 0) and FUN_a0146b20(1, i + 0x2F, 0x1C, 1, i + 0x28, 0) for i = 0..2.
 * Callers: FUN_a0095fb0, FUN_a009bfb4, FUN_a009c22c, FUN_a00af44c, FUN_a00b1004.
 * Source form: the 5 / 6 tests are a static helper is_5_or_6 ('if (i == 5) return 1; return i == 6;'), the
 *   7 test is '|| i == 7' at the call (fw: cmp 5 / cmp 6 at the loop end, cmp 7 at the body top, no range test).
 *   The second loop limit reuses n (n = 3), which keeps the 'cmp 3; bcs' form. The table at 0x1951DC is an extern
 *   array symbol; with a cast integer constant the compiler keeps the whole DAT_a802d290 address in a register.
 */
struct R290 { unsigned char pad[8]; unsigned char b08; };
extern struct R290 DAT_a802d290;
extern unsigned int DAT_001951dc[];
extern void FUN_a00a8c88(void);
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern int FUN_a00d7d48(void);
extern void FUN_a0146a80(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a0146ab0(int, int);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);

static int is_5_or_6(unsigned char i)
{
    if (i == 5)
        return 1;
    return i == 6;
}

void FUN_a00b6bec(unsigned char page)
{
    unsigned char n;
    unsigned char i;

    FUN_a00a8c88();
    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    n = (page == 0) ? 7 : 1;
    for (i = 0; i < n; i++) {
        if (is_5_or_6(i) || i == 7) {
            if (FUN_a00d7d48())
                FUN_a0146a80(0x2a, i * 2 + 6, 0xb, 0x296, 0);
        }
        FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_001951dc, (i + page * 7) * 29 + DAT_a802d290.b08), 0);
    }
    FUN_a0146ab0(0x792, 0);
    n = 3;
    for (i = 0; i < n; i++)
        FUN_a0146b20(1, i + 0x2f, 0x1c, 1, i + 0x28, 0);
}
