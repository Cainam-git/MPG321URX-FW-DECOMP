/* leon2m FUN_a009a3cc @ 0xa009a3cc-0xa009a424 (22 words), flags -mcpu=v8 -O3 -g.
 * Code facts: byte 0xa8025c55 = byte 0xa802d46f; FUN_a00a93bc((word 0xa802afec + 0x45) & 0xff);
 * FUN_a00a8c88() (no argument set); FUN_a00b7d14(1); word 0xa802afec = 0xf5; FUN_a00a9650(0, 1);
 * tail call FUN_a00aee44(0xbf, 0).
 * FUN_a00b7d14 takes ONE argument (fw sets only %o0 = 1; its asm never reads %i1); the callees have prototypes.
 * Aids: none.
 */
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a802d46f;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a8c88(void);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(int, int);
extern void FUN_a00aee44(unsigned char, unsigned char);
extern void FUN_a00b7d14(unsigned char);

void FUN_a009a3cc(void)
{
  DAT_a8025c55 = DAT_a802d46f;
  FUN_a00a93bc(_DAT_a802afec + 0x45);
  FUN_a00a8c88();
  FUN_a00b7d14(1);
  _DAT_a802afec = 0xf5;
  FUN_a00a9650(0, 1);
  FUN_a00aee44(0xbf, 0);
}
