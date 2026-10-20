/* leon2m FUN_a009d8f4 @ 0xa009d8f4-0xa009d9b0 (47 words), flags -mcpu=v8 -O3 -g.
 * Code facts (afec % 2 loop family, FUN_a009dd9c form): FUN_a00a93bc((u8)(word 0xa802afec + 0x4c)); loop
 * t = (lduh 0xa802afee, low half of afec) - 0xb3; t = t % 2 (signed); afec = t + 0xb4; until
 * FUN_a00aad30((u8)t) == 1. Then bit 15 of word 0xa802d290+0xa8 = bit 0 of (u8)(afec + 0x4c) (andn 0x8000 /
 * sll 15 / or, a 1-bit BIT-FIELD), FUN_a00a9650((u8)(afec + 0x4c), 1); v = byte 0xa8025c56; tail
 * FUN_a00a813c(1, v, afec - 0xb4 != v) as two calls. void(void). Byte-identical twin: FUN_a009d9b0. Required
 * forms: aad30 takes 1 arg, (unsigned short)_DAT_a802afec, no volatile on RAM, real u8/void
 * prototypes. Aids: none.
 */
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
struct Rec290 {
    unsigned char pad[0xa8];
    unsigned int hi : 16;
    unsigned int b15 : 1;
    unsigned int lo : 15;
};
extern struct Rec290 DAT_a802d290;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);

void FUN_a009d8f4(void)
{
  int t;

  FUN_a00a93bc(_DAT_a802afec + 0x4c);
  do {
    t = (unsigned short)_DAT_a802afec - 0xb3;
    t = t % 2;
    _DAT_a802afec = t + 0xb4;
  } while (FUN_a00aad30(t) != 1);
  DAT_a802d290.b15 = (unsigned char)(_DAT_a802afec + 0x4c);
  FUN_a00a9650(_DAT_a802afec + 0x4c, 1);
  {
    unsigned char v = DAT_a8025c56;
    if (_DAT_a802afec - 0xb4 == v)
      FUN_a00a813c(1, v, 0);
    else
      FUN_a00a813c(1, v, 1);
  }
}
