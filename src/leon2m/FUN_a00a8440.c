/* leon2m FUN_a00a8440 @ 0xa00a8440  (-mcpu=v8 -O3 -g)
 * Calls FUN_a0146b50(0x111, 0) and FUN_a0146b6c(0, 0). Then three FUN_a00a31a4(0, 0x2A, row, 1, FUN_a00a3844(table,
 * index), 0) calls: row 6 with entry DAT_a802d290 byte +8 + 0x91 of the table at 0x18E9F8, rows 8 and 10 with entries
 * (i - 1) * 29 + byte +8 of the table at 0x193248 for i = 1, 2. sel = bit 12 of the word at +0xA8, plus 1, gives row
 * = sel * 2 + 6 (sel <= 6) or sel * 2 - 8, which is passed to FUN_a0146b20(0, 0x28, row, 1, 0xF, 0) and
 * FUN_a0146b20(0, 0x29, row, 1, 0x10, 0).
 * Callers: FUN_a0094df0, FUN_a0094e70.
 * Source form: every access names DAT_a802d290 directly (a local pointer to it moves the address load).
 */
struct R290 { unsigned char pad[8]; unsigned char b08; unsigned char pad2[0xa8 - 9]; unsigned int wa8; };
extern struct R290 DAT_a802d290;
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146b20(unsigned int, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);

void FUN_a00a8440(void)
{
    unsigned char i;
    unsigned char sel;
    unsigned char row;

    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    FUN_a00a31a4(0, 0x2a, 6, 1, FUN_a00a3844((unsigned int *)0x18e9f8, DAT_a802d290.b08 + 0x91), 0);
    for (i = 1; i <= 2; i++)
        FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844((unsigned int *)0x193248, (i - 1) * 29 + DAT_a802d290.b08), 0);
    sel = ((DAT_a802d290.wa8 >> 12) & 1) + 1;
    if (sel <= 6)
        row = sel * 2 + 6;
    else
        row = sel * 2 - 8;
    FUN_a0146b20(0, 0x28, row, 1, 0xf, 0);
    FUN_a0146b20(0, 0x29, row, 1, 0x10, 0);
}
