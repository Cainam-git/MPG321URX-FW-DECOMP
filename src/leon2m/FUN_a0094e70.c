/* leon2m FUN_a0094e70 @ 0xa0094e70 (-mcpu=v8 -O2 -g)
 * Copies DAT_a8025c55 to DAT_a802d3ce, calls FUN_a00a8c88 and FUN_a00a8440, then FUN_a00a813c(1, DAT_a8025c56 + 1,
 * 1) and FUN_a00a9650(DAT_a8025c56 + 1, 0), stores 0x53 to the word at 0xa802afec and calls FUN_a00a9650(0, 1).
 */
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d3ce;

extern void FUN_a00a8c88(void);
extern void FUN_a00a8440(void);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a0094e70(void)
{
    DAT_a802d3ce = DAT_a8025c55;
    FUN_a00a8c88();
    FUN_a00a8440();
    FUN_a00a813c(1, DAT_a8025c56 + 1, 1);
    FUN_a00a9650(DAT_a8025c56 + 1, 0);
    _DAT_a802afec = 0x53;
    FUN_a00a9650(0, 1);
}
