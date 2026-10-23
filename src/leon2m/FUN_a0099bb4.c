/* leon2m FUN_a0099bb4 @ 0xa0099bb4 (-mcpu=v8 -O2 -g)
 * FUN_a00a93bc(byte 0xA802D290[0xac]); 0xA802D290[0xac] = byte 0xA8025C55; FUN_a00af44c(0x2a, 3); word 0xA802AFEC =
 * 0xb3; FUN_a00a9650(2, 1); FUN_a00da754(0xA802D290[0xac]); byte 0xA8025C55 = 0.
 */
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern int FUN_a00a93bc();
extern void FUN_a00af44c(unsigned int, unsigned int);
extern void FUN_a00a9650(unsigned int, unsigned int);
extern void FUN_a00da754(unsigned char);

void FUN_a0099bb4(void)
{
    FUN_a00a93bc(DAT_a802d290[0xac]);
    DAT_a802d290[0xac] = DAT_a8025c55;
    FUN_a00af44c(0x2a, 3);
    _DAT_a802afec = 0xb3;
    FUN_a00a9650(2, 1);
    FUN_a00da754(DAT_a802d290[0xac]);
    DAT_a8025c55 = 0;
}
