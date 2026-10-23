/* leon2m FUN_a0096230 @ 0xa0096230 (-mcpu=v8 -O2 -g)
 * FUN_a00a93bc(byte 0xA8025C56); FUN_a00a813c(1, byte 0xA8025C56, 0); FUN_a00a9650((word 0xA802AFEC - 100) & 0xff,
 * 0); FUN_a00a813c(1, word 0xA802D2C4 & 0xf, 1); word 0xA802AFEC = 0x17; FUN_a00a900c(2, 1); byte 0xA802B08E |= 2.
 * FUN_a00a93bc takes one argument.
 */
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern unsigned int _DAT_a802afec;
extern volatile unsigned short _DAT_a802d2c4;

extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(int, int);

void FUN_a0096230(void)
{
    FUN_a00a93bc(DAT_a8025c56);
    FUN_a00a813c(1, DAT_a8025c56, 0);
    FUN_a00a9650((_DAT_a802afec - 100U) & 0xff, 0);
    FUN_a00a813c(1, _DAT_a802d2c4 & 0xf, 1);
    _DAT_a802afec = 0x17;
    FUN_a00a900c(2, 1);
    DAT_a802b08e = DAT_a802b08e | 2;
}
