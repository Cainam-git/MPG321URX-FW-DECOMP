/* leon2m FUN_a00b31a0 @ 0xa00b31a0-0xa00b3238 (38 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Code facts: FUN_a00a8c88(); FUN_a0146b50(0x111, 0); FUN_a0146b6c(0, 0); for i = 0, 1, 2 (u8): FUN_a00a31a4(0,
 * 0x2a, i*2 + 6, 1, FUN_a00a3844(table 0x18f550, (u16)(i*29 + byte DAT_a802d290[8])), 0). void. Same family and
 * loop form as FUN_a00a89e4 / FUN_a00a8654.
 * Source form: the record base DAT_a802d290[8]; the table symbol DAT_0018f550 (named by address); a plain for loop
 * over i = 0..2 (with -msoft-float, as FUN_a00a89e4; at plain -O3 -g loop.c hoists the full &DAT_a802d290, while
 * the fw hoists only the sethi).
 */
extern unsigned char DAT_a802d290[];
extern unsigned int DAT_0018f550[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern void FUN_a00a8c88(void);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);

void FUN_a00b31a0(void)
{
    unsigned char i;

    FUN_a00a8c88();
    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    for (i = 0; i < 3; i++)
        FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1,
                 FUN_a00a3844(DAT_0018f550, i * 29 + DAT_a802d290[8]), 0);
}
