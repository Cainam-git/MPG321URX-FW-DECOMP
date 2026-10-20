/* leon2m FUN_a00b77b4 @ 0xa00b77b4  (-mcpu=v8 -O3 -g)
 * Calls FUN_a0146b50(0x111, 0) and FUN_a0146b6c(0, 0), then FUN_a00a31a4(0, 0x2A, 6, 1,
 * FUN_a00a3844(DAT_00193248, DAT_a802d290 byte +8), 0) and, for i = 1..3, FUN_a00a31a4(0, 0x2A, i * 2 + 6, 1,
 * FUN_a00a3844(DAT_00193330, i - 1), 0). v = 0 when bit 6 of the word at DAT_a802d290 +0xA8 is clear, else bit 5 + 1;
 * then FUN_a00a9650(v, 0) and a tail call FUN_a00a813c(1, v, 1).
 * Callers: FUN_a00af44c+0x68C.
 * Source form: the tables at 0x193248 and 0x193330 are extern array symbols.
 */
struct R290 { unsigned char pad[8]; unsigned char b08; unsigned char pad2[0xa8 - 9]; unsigned int wa8; };
extern struct R290 DAT_a802d290;
extern unsigned int DAT_00193248[];
extern unsigned int DAT_00193330[];
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a813c(unsigned char, unsigned char, unsigned char);

void FUN_a00b77b4(void)
{
    unsigned char i;
    unsigned char v;

    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    FUN_a00a31a4(0, 0x2a, 6, 1, FUN_a00a3844(DAT_00193248, DAT_a802d290.b08), 0);
    for (i = 1; i <= 3; i++)
        FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_00193330, i - 1), 0);
    v = 0;
    if (DAT_a802d290.wa8 & 0x40)
        v = ((DAT_a802d290.wa8 >> 5) & 1) + 1;
    FUN_a00a9650(v, 0);
    FUN_a00a813c(1, v, 1);
}
