/* leon2m FUN_a00955a0 @ 0xa00955a0 (-mcpu=v8 -O2 -g)
 * Calls FUN_a00a8c88 and FUN_a00b7ae4, sets _DAT_a802afec = 0x45, calls FUN_a00a9650 and FUN_a00a813c with the byte
 * DAT_a8025c56 + 2, and sets bit 1 of DAT_a802b08e. The (unsigned char) casts produce the 'and %oX, 0xff'
 * instructions.
 */
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern unsigned int _DAT_a802afec;

extern void FUN_a00a8c88(void);
extern void FUN_a00b7ae4(void);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a813c(int, unsigned char, int);

void FUN_a00955a0(void)
{
    FUN_a00a8c88();
    FUN_a00b7ae4();
    _DAT_a802afec = 0x45;
    FUN_a00a9650((unsigned char)(DAT_a8025c56 + 2), 2);
    FUN_a00a9650(1, 1);
    FUN_a00a813c(1, (unsigned char)(DAT_a8025c56 + 2), 1);
    DAT_a802b08e = DAT_a802b08e | 2;
}
