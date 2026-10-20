/* leon2m FUN_a009a0d4 @ 0xa009a0d4-0xa009a198 (49 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a00db1ac.
 * Sets byte 0xa802d47e (0xa802d290 + 0x1ee) to 0 when word 0xa802afec is 0xc3, else to 1. Then calls
 * FUN_a00a93bc(byte 0xa8025c56 + 0x3d), FUN_a00a813c(1, byte 0xa8025c56, 0), sets 0xa802afec to 0x36, calls
 * FUN_a00a9650(byte +0x1ee, 0), FUN_a00a813c(1, byte +0x1ee, 1), FUN_a00a900c(0xa802afec - 52, 1),
 * FUN_a00a9468(1, 2) and FUN_a00b34d4(0, 1), and sets bit 1 (0x02) of byte 0xa802b08e.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c56;
extern unsigned int DAT_a802afec;
extern unsigned char DAT_a802b08e;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00b34d4(unsigned int, unsigned int);

void FUN_a009a0d4(void)
{
    if (DAT_a802afec == 0xc3)
        DAT_a802d290[0x1ee] = 0;
    else
        DAT_a802d290[0x1ee] = 1;
    FUN_a00a93bc(DAT_a8025c56 + 0x3d);
    FUN_a00a813c(1, DAT_a8025c56, 0);
    DAT_a802afec = 0x36;
    FUN_a00a9650(DAT_a802d290[0x1ee], 0);
    FUN_a00a813c(1, DAT_a802d290[0x1ee], 1);
    FUN_a00a900c(DAT_a802afec - 52, 1);
    FUN_a00a9468(1, 2);
    FUN_a00b34d4(0, 1);
    DAT_a802b08e |= 2;
}
