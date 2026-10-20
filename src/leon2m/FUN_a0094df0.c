/* leon2m FUN_a0094df0 @ 0xa0094df0  MATCH (-mcpu=v8 -O2 -g)
 * Calls FUN_a00a93bc((_DAT_a802afec + 0x23) & 0xff), FUN_a00a8c88(), FUN_a00a8440(), FUN_a00a813c(1, DAT_a8025c56
 * + 1, 1) and FUN_a00a9650(DAT_a8025c56 + 1, 0); stores 0x53 to _DAT_a802afec, calls FUN_a00a9650(0, 1) and sets
 * bit 1 of DAT_a802b08e. No return value.
 */
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802b08e;

extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a8c88(void);
extern void FUN_a00a8440(void);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a0094df0(void)
{
    FUN_a00a93bc((_DAT_a802afec + 0x23U) & 0xff);
    FUN_a00a8c88();
    FUN_a00a8440();
    FUN_a00a813c(1, DAT_a8025c56 + 1, 1);
    FUN_a00a9650(DAT_a8025c56 + 1, 0);
    _DAT_a802afec = 0x53;
    FUN_a00a9650(0, 1);
    DAT_a802b08e = DAT_a802b08e | 2;
}
