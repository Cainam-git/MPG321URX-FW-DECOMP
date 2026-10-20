/* leon2m FUN_a009a480 @ 0xa009a480-0xa009a500 (32 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Calls FUN_a00a93bc(byte 0xa802d46f % 7) (0xa802d290 + 0x1df), stores byte 0xa8025c55 into byte 0xa802d46f, calls
 * FUN_a00af44c(0x34, 3), sets word 0xa802afec to 0xbf, calls FUN_a00a9650(4, 1) and clears byte 0xa8025c55.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c55;
extern unsigned int DAT_a802afec;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00af44c(int, unsigned char);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a009a480(void)
{
    FUN_a00a93bc(DAT_a802d290[0x1df] % 7);
    DAT_a802d290[0x1df] = DAT_a8025c55;
    FUN_a00af44c(0x34, 3);
    DAT_a802afec = 0xbf;
    FUN_a00a9650(4, 1);
    DAT_a8025c55 = 0;
}
