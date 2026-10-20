/* leon2m FUN_a0091cc0 @ 0xa0091cc0-0xa0091d74 (45 words).
 * Calls FUN_a00b4144(afec - 2, 2) with afec = word 0xa802afec, sets afec to 0x15, and while
 * FUN_a00aa520(afec - 0x15) does not return 1 steps it forwards through 0x15..0x17: t = ((low halfword of afec) - 20)
 * % 3, afec = t + 0x15. Then FUN_a00a900c(afec - 0x15, 1). When afec is 0x16, FUN_a00aa258(1, 0) is called.
 * Same loop as FUN_a0091668.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a900c(unsigned char, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00b4144(unsigned char, int);
extern void FUN_a00aa258(int, int);

void FUN_a0091cc0(void)
{
  int t;

  FUN_a00b4144(_DAT_a802afec - 2, 2);
  _DAT_a802afec = 0x15;
  for (;;) {
    if (FUN_a00aa520(_DAT_a802afec - 0x15) == 1)
      break;
    t = (unsigned short)_DAT_a802afec - 20;
    t = t % 3;
    _DAT_a802afec = t + 0x15;
  }
  FUN_a00a900c(_DAT_a802afec - 0x15, 1);
  if (_DAT_a802afec == 0x16)
    FUN_a00aa258(1, 0);
}
