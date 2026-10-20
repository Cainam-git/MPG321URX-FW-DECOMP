/* leon2m FUN_a00954a0 @ 0xa00954a0 (-mcpu=v8 -O2 -g)
 * Calls FUN_a00a8c88 and FUN_a00b7ae4, stores 0x44 to the word at 0xa802afec, calls FUN_a00a9650(0, 1),
 * FUN_a00a9650(DAT_a8025c56 + 2, 2) and FUN_a00a813c(1, DAT_a8025c56 + 2, 1), then sets bit 1 of DAT_a802b08e. No
 * return value (%i0 is not set before ret; restore).
 */
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802b08e;

extern void FUN_a00a8c88(void);
extern void FUN_a00b7ae4(void);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a813c(int, unsigned char, int);

void FUN_a00954a0(void)
{
    FUN_a00a8c88();
    FUN_a00b7ae4();
    _DAT_a802afec = 0x44;
    FUN_a00a9650(0, 1);
    FUN_a00a9650(DAT_a8025c56 + 2, 2);
    FUN_a00a813c(1, DAT_a8025c56 + 2, 1);
    DAT_a802b08e = DAT_a802b08e | 2;
}
