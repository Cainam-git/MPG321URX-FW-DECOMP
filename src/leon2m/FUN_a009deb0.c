/* leon2m FUN_a009deb0 @ 0xa009deb0-0xa009df5c (43 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 43 words. Family of FUN_a009d79c / d848 / de04 / deb0
 * (the afec % N loop family, FUN_a0091de8 / FUN_a009dc84 form).
 * Code facts: FUN_a00a93bc((u8)(word 0xa802afec + 0x48)); loop: t = (lduh 0xa802afee = low half of word
 * 0xa802afec) - 0xb7; t = t % 3 (signed, smul 0x55555556); word 0xa802afec = t + 0xb8; repeat until
 * FUN_a00aad30((u8)t) returns 1. FUN_a00a9650((u8)(afec + 0x48), 1). v = byte 0xa8025c56; tail call
 * FUN_a00a813c(1, v, afec - 0xb8 != v) written as two calls with 0 / 1. void(void).
 * Required forms: FUN_a00aad30 takes 1 arg; the half-word
 * read is (unsigned short)_DAT_a802afec (no separate afee symbol); DAT_a8025c56 is plain RAM (no volatile);
 * real u8/void prototypes. Aids: none.
 */
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);

void FUN_a009deb0(void)
{
  int t;

  FUN_a00a93bc(_DAT_a802afec + 0x48);
  do {
    t = (unsigned short)_DAT_a802afec - 0xb7;
    t = t % 3;
    _DAT_a802afec = t + 0xb8;
  } while (FUN_a00aad30(t) != 1);
  FUN_a00a9650(_DAT_a802afec + 0x48, 1);
  {
    unsigned char v = DAT_a8025c56;
    if (_DAT_a802afec - 0xb8 == v)
      FUN_a00a813c(1, v, 0);
    else
      FUN_a00a813c(1, v, 1);
  }
}
