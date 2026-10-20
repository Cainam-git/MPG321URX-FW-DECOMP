/* leon2m FUN_a009c8ec @ 0xa009c8ec-0xa009c99c (44 words), flags -mcpu=v8 -O3 -g.
 * Code facts (afec % 4 loop family, FUN_a009dc84 form): FUN_a00a93bc((u8)(word 0xa802afec - 0x6c)); loop t = (lduh
 * 0xa802afee, low half of afec) - 0x6b; t = t % 4 (signed: sra/srl 30/and -4); afec = t + 0x6c; until
 * FUN_a00aad30((u8)t) == 1. Then byte DAT_a802d290[0x11] (0xa802d2a1) = afec - 0x6c (stb in the call delay slot),
 * FUN_a00d9764(void), FUN_a00a9650((u8)(afec - 0x6c), 1); v = byte 0xa8025c56; tail FUN_a00a813c(1, v, afec - 0x6c
 * != v) as two calls. void(void). Twin of FUN_a009c83c, which subtracts 0x69 where this one subtracts 0x6b.
 * FUN_a00aad30 takes one argument.
 * Source form: the halfword is read as (unsigned short)_DAT_a802afec (no separate afee symbol); the store goes
 * through the record base DAT_a802d290; RAM globals are not volatile.
 * Compiler aids: none.
 */
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);
extern void FUN_a00d9764(void);

void FUN_a009c8ec(void)
{
  int t;

  FUN_a00a93bc(_DAT_a802afec - 0x6c);
  do {
    t = (unsigned short)_DAT_a802afec - 0x6b;
    t = t % 4;
    _DAT_a802afec = t + 0x6c;
  } while (FUN_a00aad30(t) != 1);
  DAT_a802d290[0x11] = _DAT_a802afec - 0x6c;
  FUN_a00d9764();
  FUN_a00a9650(_DAT_a802afec - 0x6c, 1);
  {
    unsigned char v = DAT_a8025c56;
    if (_DAT_a802afec - 0x6c == v)
      FUN_a00a813c(1, v, 0);
    else
      FUN_a00a813c(1, v, 1);
  }
}
