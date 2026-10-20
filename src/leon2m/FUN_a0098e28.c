/* leon2m FUN_a0098e28 @ 0xa0098e28  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, autoc)
 * Finished by hand from mechanical Ghidra C. Fixed init sequence: FUN_a00a93bc(0), word
 * 0xa802afec = 0x2c, FUN_a00a900c(2, 1), FUN_a00b7674(0), then sets bit 1 of the byte at
 * 0xa802b08e. FUN_a00a900c is void; the draft had it returning int.
 */
extern int FUN_a00a93bc(int);        /* 0xa00a93bc */
extern unsigned int DAT_a802afec;    /* 0xa802afec */
extern void FUN_a00a900c(int, int);  /* 0xa00a900c */
extern int FUN_a00b7674(int);        /* 0xa00b7674 */
extern unsigned char DAT_a802b08e;   /* 0xa802b08e */

void FUN_a0098e28(void)
{
    FUN_a00a93bc(0);
    DAT_a802afec = 0x2c;
    FUN_a00a900c(2, 1);
    FUN_a00b7674(0);
    DAT_a802b08e = DAT_a802b08e | 2;
}
