/* leon2m FUN_a0099970 @ 0xa0099970 (-mcpu=v8 -O3 -g)
 */
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d2da;
extern int FUN_a00a93bc();
extern void FUN_a00a9650();
extern void FUN_a00a813c();
extern void FUN_a00a900c();

void FUN_a0099970(void)
{
    FUN_a00a93bc((_DAT_a802afec - 68) & 0xff);
    volatile unsigned char *pb1_ = (volatile unsigned char *)0xA802D290;
    FUN_a00a9650(((*(volatile unsigned char *)(pb1_ + 74)) + 2) & 0xff, 0);
    FUN_a00a813c(1, ((*(volatile unsigned char *)(pb1_ + 74)) + 2) & 0xff, 0);
    FUN_a00a813c(1, ((*(volatile unsigned char *)(pb1_ + 74)) + 2) & 0xff, 1);
    _DAT_a802afec = 13;
    FUN_a00a900c(2, 1);
}
