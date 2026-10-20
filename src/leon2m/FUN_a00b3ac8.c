/* leon2m FUN_a00b3ac8 @ 0xa00b3ac8-0xa00b3b5c (37 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a0146b50(0x111, 0); FUN_a0146b6c(0, 0); for i = 0, 1, 2 (u8):
 * FUN_a00a31a4(0, 0x2a, i*2 + 6, 1, FUN_a00a3844(table 0x18e54c, (u16)(i*29 + byte
 * DAT_a802d290[8])), 0). void. Same family and loop form as FUN_a00b31a0 / FUN_a00a89e4.
 * Fixes vs the autoc draft (81.08): real base DAT_a802d290[8], table DAT_0018e54c (named by
 * address: sethi 0x18e400 | 0x14c), goto loop (do/while hoists the full &DAT_a802d290).
 * Aids: none.
 */
extern unsigned char DAT_a802d290[];
extern unsigned int DAT_0018e54c[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);

void FUN_a00b3ac8(void)
{
    unsigned char i;

    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    i = 0;
top:
    FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1,
                 FUN_a00a3844(DAT_0018e54c, i * 29 + DAT_a802d290[8]), 0);
    i++;
    if (i <= 2)
        goto top;
}
