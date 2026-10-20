/* leon2m FUN_a009ba34 @ 0xa009ba34-0xa009bb0c (54 words), flags -mcpu=v8 -O3 -g.
 * The afec % N loop family (FUN_a009dc84 form).
 * Code facts: FUN_a00a93bc(word 0xa802afec + 0x19, u8); loop: t = (lduh 0xa802afee) - 0xe6, t %= 3 (smul
 * 0x55555556), word afec = t + 0xe7, until FUN_a00aad30(t) == 1. Byte 0xa802d2db = afec + 0x19 (stored before the
 * call), FUN_a00a9650(afec + 0x19, 1), FUN_a00d5eac(1) (ONE arg), FUN_a00a813c(1, byte 0xa8025c55, 0 when
 * afec - 0xe7 == that byte else 1; two calls cross-jumped), byte 0xa802b08e |= 2, tail FUN_a014a8d4(1, 0, 0).
 * Source form: the FUN_a00a813c third argument as an if/else of two calls; a (u16) read of afec; void/u8
 * prototypes. Aids: none.
 */
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a802d2db;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);
extern void FUN_a00d5eac(int);
extern void FUN_a014a8d4(int, int, int);

void FUN_a009ba34(void)
{
  int t;

  FUN_a00a93bc(_DAT_a802afec + 0x19);
  do {
    t = (unsigned short)_DAT_a802afec - 0xe6;
    t = t % 3;
    _DAT_a802afec = t + 0xe7;
  } while (FUN_a00aad30(t) != 1);
  DAT_a802d2db = _DAT_a802afec + 0x19;
  FUN_a00a9650(_DAT_a802afec + 0x19, 1);
  FUN_a00d5eac(1);
  {
    unsigned char v = DAT_a8025c55;
    if (_DAT_a802afec - 0xe7 == v)
      FUN_a00a813c(1, v, 0);
    else
      FUN_a00a813c(1, v, 1);
  }
  DAT_a802b08e |= 2;
  FUN_a014a8d4(1, 0, 0);
}
