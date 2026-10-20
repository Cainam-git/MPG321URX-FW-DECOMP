/* leon2m FUN_a0094f58 @ 0xa0094f58  MATCH (-mcpu=v8 -O2 -g)
 * Copies DAT_a8025c55 to DAT_a802d3cf, then calls FUN_a00a8c88(), FUN_a00ac388(1),
 * FUN_a00a813c(1, DAT_a8025c56 + 1, 1) and FUN_a00a9650(DAT_a8025c56 + 1, 0). Writes 0x56 to _DAT_a802afec and
 * ends with FUN_a00a9650(0, 1) as a tail call (restore in the delay slot). The result of FUN_a00a8c88 is not used.
 * Returns nothing.
 */
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802d3cf;
extern unsigned int _DAT_a802afec;

extern void FUN_a00a8c88(void);
extern void FUN_a00ac388(int);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a0094f58(void)
{
    DAT_a802d3cf = DAT_a8025c55;
    FUN_a00a8c88();
    FUN_a00ac388(1);
    FUN_a00a813c(1, DAT_a8025c56 + 1, 1);
    FUN_a00a9650(DAT_a8025c56 + 1, 0);
    _DAT_a802afec = 0x56;
    FUN_a00a9650(0, 1);
}
