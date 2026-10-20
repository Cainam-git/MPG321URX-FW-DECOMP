/* leon2m FUN_a0096230 @ 0xa0096230 (-mcpu=v8 -O2 -g)
 * The function performs a sequence of display/OSD operations: it reads a status byte, calls a trace function with it, then calls another trace with a computed value, updates a counter register, and sets a flag. The first call to FUN_a00a93bc takes only one argument (the byte at 0xa8025c56), not two as Ghidra suggested. The function returns void.
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
