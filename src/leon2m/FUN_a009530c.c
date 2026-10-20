/* leon2m FUN_a009530c @ 0xa009530c-0xa00953d4 (50 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Sets byte 0xa802b08f to 0x10. When byte 0xa802d433 (0xa802d290 + 0x1a3) is not 0, stores byte 0xa8025c55 into
 * byte 0xa802d2b0 (+0x20) and calls FUN_a00d5938(1) when the value changed. Calls FUN_a00a8c88 and FUN_a00a9abc,
 * sets word 0xa802afec to 0x83 (byte +0x1a3 not 0) or 0x82, calls FUN_a00a9650(byte 0xa8025c54, 2),
 * FUN_a00a813c(1, byte 0xa8025c54, 1) and FUN_a00a9650(0xa802afec - 127, 1). Finally copies byte +0x1a4 into
 * byte 0xa8025c55 and clears byte +0x1a3. Exact form: the old byte +0x20 is read at the start.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c54, DAT_a8025c55;
extern unsigned char DAT_a802b08f;
extern unsigned int DAT_a802afec;
extern void FUN_a00d5938(int);
extern void FUN_a00a8c88(void);
extern void FUN_a00a9abc(void);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a813c(int, unsigned char, int);

void FUN_a009530c(void)
{
    unsigned char old = DAT_a802d290[0x20];

    DAT_a802b08f = 0x10;
    if (DAT_a802d290[0x1a3] != 0) {
        DAT_a802d290[0x20] = DAT_a8025c55;
        if (DAT_a8025c55 != old)
            FUN_a00d5938(1);
    }
    FUN_a00a8c88();
    FUN_a00a9abc();
    if (DAT_a802d290[0x1a3] == 0)
        DAT_a802afec = 0x82;
    else
        DAT_a802afec = 0x83;
    FUN_a00a9650(DAT_a8025c54, 2);
    FUN_a00a813c(1, DAT_a8025c54, 1);
    FUN_a00a9650(DAT_a802afec - 127, 1);
    DAT_a8025c55 = DAT_a802d290[0x1a4];
    DAT_a802d290[0x1a3] = 0;
}
