/* leon2m FUN_a009221c @ 0xa009221c-0xa00922f0 (53 words).
 * Calls FUN_a00b4144(afec - 2, 2) with afec = word 0xa802afec, then sets afec to
 * FUN_a01445fc(byte 0xa802d2ae) + 0x1e. While FUN_a00aa520(afec - 0x1e) does not return 1, afec steps
 * forwards through 0x1e..0x22: t = ((low halfword of afec) - 0x1d) % 5, afec = t + 0x1e. Then FUN_a00a900c(afec -
 * 0x1e, 1), FUN_a0146c40(6, 0, 0), FUN_a00a9468(1, 3) and FUN_a00b34d4(0, 4) are called. Same loop as FUN_a0092b18.
 */
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d2ae;
extern void FUN_a00a900c(unsigned char, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00b4144(unsigned char, int);
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00b34d4(unsigned int, unsigned int);

void FUN_a009221c(void)
{
  int t;

  FUN_a00b4144(_DAT_a802afec - 2, 2);
  _DAT_a802afec = FUN_a01445fc(DAT_a802d2ae) + 0x1e;
  for (;;) {
    if (FUN_a00aa520(_DAT_a802afec - 0x1e) == 1)
      break;
    t = (unsigned short)_DAT_a802afec - 0x1d;
    t = t % 5;
    _DAT_a802afec = t + 0x1e;
  }
  FUN_a00a900c(_DAT_a802afec - 0x1e, 1);
  FUN_a0146c40(6, 0, 0);
  FUN_a00a9468(1, 3);
  FUN_a00b34d4(0, 4);
}
