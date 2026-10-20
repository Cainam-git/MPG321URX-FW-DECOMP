/* leon2m FUN_a0096e14 @ 0xa0096e14  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: base 0xa802d290 kept in a register: pointer local (basefix)
 */
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern unsigned int _DAT_a802d33c;
extern int FUN_a00a813c();
extern int FUN_a00a900c();
extern int FUN_a00a93bc();
extern int FUN_a00a9650();

void FUN_a0096e14(void)
{
    volatile unsigned char *pb1_ = (volatile unsigned char *)0xA802D290;
  (*(volatile unsigned int *)(pb1_ + 172)) = ((*(volatile unsigned int *)(pb1_ + 172)) & 0xfff3ffff) | ((DAT_a8025c56 & 3) << 0x12);
  FUN_a00a93bc(_DAT_a802afec - 0x77U & 0xff);
  FUN_a00a9650((*(volatile unsigned int *)(pb1_ + 172)) >> 0x12 & 3, 0);
  FUN_a00a813c(1, (*(volatile unsigned int *)(pb1_ + 172)) >> 0x12 & 3, 1);
  _DAT_a802afec = 0x1d;
  FUN_a00a900c(5, 1);
  return;
}
