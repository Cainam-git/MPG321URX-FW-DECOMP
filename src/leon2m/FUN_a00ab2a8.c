/* leon2m FUN_a00ab2a8 @ 0xa00ab2a8 (-mcpu=v8 -O3 -g)
 * Calls FUN_a00a8c88(), FUN_a0146b50(0x111, 0) and FUN_a0146b6c(0, 0), then for i = 0 .. 2 FUN_a00a31a4(0, 0x2a, i
 * * 2 + 6, 1, FUN_a00a3844(0x18F550, i * 29 + byte 0xA802D298), 0). Same code as FUN_a00b31a0.
 * See FUN_a00b31a0 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_a802d290[];
extern unsigned int DAT_0018f550[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern void FUN_a00a8c88(void);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);

void FUN_a00ab2a8(void)
{
    unsigned char i;

    FUN_a00a8c88();
    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    i = 0;
top:
    FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1,
                 FUN_a00a3844(DAT_0018f550, i * 29 + DAT_a802d290[8]), 0);
    i++;
    if (i <= 2)
        goto top;
}
