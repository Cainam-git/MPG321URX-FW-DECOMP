/* leon2m FUN_a0092ea8 @ 0xa0092ea8-0xa0092f2c (33 words).
 * Calls FUN_a00b4144(afec - 2, 2) with afec = word 0xa802afec, sets afec to 0x34, and while
 * FUN_a00aa520(afec - 0x34) does not return 1 steps it forwards through 0x34..0x3b: t = ((low halfword of afec) - 51)
 * % 8, afec = t + 0x34. Then FUN_a00a900c(afec - 0x34, 1). Same loop as FUN_a0091668.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a900c(unsigned char, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00b4144(unsigned char, int);

void FUN_a0092ea8(void)
{
  int t;

  FUN_a00b4144(_DAT_a802afec - 2, 2);
  _DAT_a802afec = 0x34;
  for (;;) {
    if (FUN_a00aa520(_DAT_a802afec - 0x34) == 1)
      break;
    t = (unsigned short)_DAT_a802afec - 51;
    t = t % 8;
    _DAT_a802afec = t + 0x34;
  }
  FUN_a00a900c(_DAT_a802afec - 0x34, 1);
}
