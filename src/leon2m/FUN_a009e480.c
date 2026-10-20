/* leon2m FUN_a009e480 @ 0xa009e480-0xa009e538 (46 words), flags -mcpu=v8 -O3 -g.
 * Code facts (afec % 3 loop family): FUN_a00a93bc((u8)(word 0xa802afec + 0xf)); loop t = (lduh 0xa802afee, low
 * half of afec) - 0xef; t = t % 3 (signed, smul 0x55555556); afec = t + 0xf1; until FUN_a00aad30((u8)t) == 1.
 * FUN_a00a9650((u8)(afec + 0xf), 1); then byte 0xa802d46d = afec + 0xf; v = byte 0xa8025c55 (not c56); tail
 * FUN_a00a813c(1, v, afec - 0xf1 != v) as two calls. void(void). Twins: FUN_a009e3c8 (-0xf0) / FUN_a009e480
 * (-0xef). Fixes vs the earlier draft: aad30 takes 1 arg, (unsigned short)_DAT_a802afec, the d46d store comes
 * AFTER a9650, no volatile on RAM, real u8/void prototypes. Aids: none.
 */
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d46d;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);

void FUN_a009e480(void)
{
  int t;

  FUN_a00a93bc(_DAT_a802afec + 0xf);
  do {
    t = (unsigned short)_DAT_a802afec - 0xef;
    t = t % 3;
    _DAT_a802afec = t + 0xf1;
  } while (FUN_a00aad30(t) != 1);
  FUN_a00a9650(_DAT_a802afec + 0xf, 1);
  DAT_a802d46d = _DAT_a802afec + 0xf;
  {
    unsigned char v = DAT_a8025c55;
    if (_DAT_a802afec - 0xf1 == v)
      FUN_a00a813c(1, v, 0);
    else
      FUN_a00a813c(1, v, 1);
  }
}
