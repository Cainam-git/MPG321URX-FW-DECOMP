/* leon2m FUN_a0095610 @ 0xa0095610-0xa00956a0 (36 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * When byte 0xa802d2dc (0xa802d290 + 0x4c) differs from byte 0xa8025c55, stores 0xa8025c55 into it and calls
 * FUN_a00d5eac(1). Then calls FUN_a00a8c88 and FUN_a00b7ae4, sets word 0xa802afec to 0x45, calls
 * FUN_a00a9650(byte 0xa8025c56 + 2, 2) and FUN_a00a9650(1, 1) and tail-calls FUN_a00a813c(1, byte 0xa8025c56 + 2, 1).
 * FUN_a0095510 is the same for byte +0x4b with 0x44 and FUN_a00a9650(0, 1) first.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c55, DAT_a8025c56;
extern unsigned int DAT_a802afec;
extern void FUN_a00d5eac(int);
extern void FUN_a00a8c88(void);
extern void FUN_a00b7ae4(void);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a813c(int, unsigned char, int);

void FUN_a0095610(void)
{
    if (DAT_a802d290[0x4c] != DAT_a8025c55) {
        DAT_a802d290[0x4c] = DAT_a8025c55;
        FUN_a00d5eac(1);
    }
    FUN_a00a8c88();
    FUN_a00b7ae4();
    DAT_a802afec = 0x45;
    FUN_a00a9650(DAT_a8025c56 + 2, 2);
    FUN_a00a9650(1, 1);
    FUN_a00a813c(1, DAT_a8025c56 + 2, 1);
}
