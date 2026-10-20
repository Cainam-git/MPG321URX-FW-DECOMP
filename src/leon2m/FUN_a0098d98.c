/* leon2m FUN_a0098d98 @ 0xa0098d98  MATCH (-mcpu=v8 -O2 -g)
 * Calls FUN_a00a93bc(0), stores 0x2B to the word at 0xa802afec, calls FUN_a00a900c(1, 1) and FUN_a00b7530(0), then
 * sets bit 1 of DAT_a802b08e.
 */
extern int FUN_a00a93bc(int);        /* 0xa00a93bc */
extern unsigned int _DAT_a802afec;   /* 0xa802afec */
extern void FUN_a00a900c(int, int);  /* 0xa00a900c */
extern int FUN_a00b7530(int);        /* 0xa00b7530 */
extern unsigned char DAT_a802b08e;   /* 0xa802b08e */

void FUN_a0098d98(void)
{
    FUN_a00a93bc(0);
    _DAT_a802afec = 0x2b;
    FUN_a00a900c(1, 1);
    FUN_a00b7530(0);
    DAT_a802b08e = DAT_a802b08e | 2;
}
