/* leon2m FUN_a00b3ac8 @ 0xa00b3ac8-0xa00b3b5c (37 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Code facts: FUN_a0146b50(0x111, 0); FUN_a0146b6c(0, 0); for i = 0, 1, 2 (u8): FUN_a00a31a4(0, 0x2a, i*2 + 6, 1,
 * FUN_a00a3844(table 0x18e54c, (u16)(i*29 + byte DAT_a802d290[8])), 0). void. Same family and loop form as
 * FUN_a00b31a0 / FUN_a00a89e4 / FUN_a00a8654. The table address is 0x18e54c (fw sethi 0x18e400 | 0x14c).
 * Source form: the record base DAT_a802d290[8]; the table symbol DAT_0018e54c (named by address); a plain for loop
 * over i = 0..2, built with -msoft-float as FUN_a00b31a0 / FUN_a00a8654 (at plain -O3 -g loop.c hoists the full
 * &DAT_a802d290, while the fw keeps only the sethi outside the loop).
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
    for (i = 0; i <= 2; i++)
        FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1,
                     FUN_a00a3844(DAT_0018e54c, i * 29 + DAT_a802d290[8]), 0);
}
