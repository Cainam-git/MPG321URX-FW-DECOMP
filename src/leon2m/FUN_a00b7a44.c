/* FUN_a00b7a44 (leon2m 0xa00b7a44-0xa00b7ae4, 160 bytes), flags -mcpu=v8 -O3 -g.
 * Calls FUN_a0146b50(0x111, 0) and FUN_a0146b6c(0, 0), then for i = 0..2 calls FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1,
 * FUN_a00a3844(DAT_001909ec, i * 29 + b), 0) with b = byte 8 of DAT_a802d290, and finally FUN_a00a813c(1, byte
 * 0x17c of DAT_a802d290, 1) as a tail call. Called by FUN_a00af44c. Source form: the loop form of FUN_a00a82c4.
 */
struct R290 { unsigned char p000[8]; unsigned char b008; unsigned char p009[0x17c - 9]; unsigned char b17c; };
extern struct R290 DAT_a802d290;
extern unsigned int DAT_001909ec[];
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(unsigned char c, unsigned char v);
extern void FUN_a00a813c(unsigned char mode, unsigned char sel, unsigned char on);

void FUN_a00b7a44(void)
{
    unsigned char i;

    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    for (i = 0; i <= 2; i++)
        FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_001909ec, i * 29 + DAT_a802d290.b008), 0);
    FUN_a00a813c(1, DAT_a802d290.b17c, 1);
}
