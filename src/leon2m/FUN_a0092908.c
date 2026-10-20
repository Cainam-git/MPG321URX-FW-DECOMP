/* leon2m FUN_a0092908 @ 0xa0092908-0xa0092998 (36 words).
 * Calls FUN_a00b4144(afec - 2, 2) with the selection word 0xa802afec, sets the selection to 0x26, and while
 * FUN_a00aa520(afec - 0x26) does not return 1 steps it forwards through 0x26..0x29: t = ((low halfword of afec) - 37)
 * % 4, afec = t + 0x26. Then FUN_a00a900c(afec - 0x26, 1). Finally byte 0xa802d433 is cleared. Same loop as
 * FUN_a0091668.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a900c(unsigned char, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00b4144(unsigned char, int);
extern unsigned char DAT_a802d433;

void FUN_a0092908(void)
{
  int t;

  FUN_a00b4144(_DAT_a802afec - 2, 2);
  _DAT_a802afec = 0x26;
  for (;;) {
    if (FUN_a00aa520(_DAT_a802afec - 0x26) == 1)
      break;
    t = (unsigned short)_DAT_a802afec - 37;
    t = t % 4;
    _DAT_a802afec = t + 0x26;
  }
  FUN_a00a900c(_DAT_a802afec - 0x26, 1);
  DAT_a802d433 = 0;
}
