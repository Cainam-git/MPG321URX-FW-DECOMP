/* leon2m FUN_a00918f4 @ 0xa00918f4-0xa00919b4 (48 words).
 * Calls FUN_a00b4144(afec - 2, 2) with afec = word 0xa802afec, sets afec to 0xe, and while
 * FUN_a00aa520(afec - 0xe) does not return 1 steps it forwards through 0xe..0x14: t = ((low halfword of afec) - 13) %
 * 7, afec = t + 0xe. Then FUN_a00a900c(afec - 0xe, 1). Then FUN_a00af44c(0xe, afec - 0xe) and FUN_a00a9650(byte
 * 0xa802d412, 0). Same loop as FUN_a0091668.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a900c(unsigned char, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00b4144(unsigned char, int);
extern void FUN_a00af44c(int, unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char DAT_a802d412;

void FUN_a00918f4(void)
{
  int t;

  FUN_a00b4144(_DAT_a802afec - 2, 2);
  _DAT_a802afec = 0xe;
  for (;;) {
    if (FUN_a00aa520(_DAT_a802afec - 0xe) == 1)
      break;
    t = (unsigned short)_DAT_a802afec - 13;
    t = t % 7;
    _DAT_a802afec = t + 0xe;
  }
  FUN_a00a900c(_DAT_a802afec - 0xe, 1);
  FUN_a00af44c(0xe, _DAT_a802afec - 0xe);
  FUN_a00a9650(DAT_a802d412, 0);
}
