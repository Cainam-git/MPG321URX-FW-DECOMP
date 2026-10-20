/* leon2m FUN_a0095510 @ 0xa0095510-0xa00955a0 (36 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * When byte 0xa802d2db (0xa802d290 + 0x4b) differs from byte 0xa8025c55, stores 0xa8025c55 into it and calls
 * FUN_a00d5eac(1). Then calls FUN_a00a8c88 and FUN_a00b7ae4, sets word 0xa802afec to 0x44, calls
 * FUN_a00a9650(0, 1) and FUN_a00a9650(byte 0xa8025c56 + 2, 2) and tail-calls FUN_a00a813c(1, byte 0xa8025c56 + 2, 1).
 * FUN_a0095610 is the same for byte +0x4c with 0x45 and the two FUN_a00a9650 calls swapped.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c55, DAT_a8025c56;
extern unsigned int DAT_a802afec;
extern void FUN_a00d5eac(int);
extern void FUN_a00a8c88(void);
extern void FUN_a00b7ae4(void);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a813c(int, unsigned char, int);

void FUN_a0095510(void)
{
    if (DAT_a802d290[0x4b] != DAT_a8025c55) {
        DAT_a802d290[0x4b] = DAT_a8025c55;
        FUN_a00d5eac(1);
    }
    FUN_a00a8c88();
    FUN_a00b7ae4();
    DAT_a802afec = 0x44;
    FUN_a00a9650(0, 1);
    FUN_a00a9650(DAT_a8025c56 + 2, 2);
    FUN_a00a813c(1, DAT_a8025c56 + 2, 1);
}
