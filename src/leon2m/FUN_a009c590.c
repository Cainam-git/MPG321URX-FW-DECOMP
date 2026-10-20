/* leon2m FUN_a009c590 @ 0xa009c590-0xa009c67c (59 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 59 words.
 * Code facts (afec % 5 loop family): FUN_a00a93bc((u8)(word 0xa802afec - 100)); loop t = (lduh 0xa802afee, low
 * half of afec) - 0x63; t = t % 5 (signed, smul 0x66666667); afec = t + 100; until FUN_a00aad30((u8)t) == 1.
 * Then bits 16..19 of word 0xa802d290+0x34 = (afec - 100) & 0xf (FUN_a00962ac 4-bit BIT-FIELD form),
 * FUN_a00d58f8(), FUN_a00d58d8(), FUN_a00d4998() (all void(void)), FUN_a00a9650((u8)(afec - 100), 1); v = byte
 * 0xa8025c56; tail FUN_a00a813c(1, v, afec - 100 != v) as two calls. void(void). Twins: FUN_a009c4a4 (-0x60) /
 * FUN_a009c590 (-0x63). Fixes vs the autoc draft: aad30 takes 1 arg, (unsigned short)_DAT_a802afec, real bit-
 * field record. Aids: none.
 */
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
struct Rec290 {
    unsigned char pad[0x34];
    unsigned int hi : 12;
    unsigned int f : 4;
    unsigned int lo : 16;
};
extern struct Rec290 DAT_a802d290;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);
extern void FUN_a00d4998(void);
extern void FUN_a00d58d8(void);
extern void FUN_a00d58f8(void);

void FUN_a009c590(void)
{
  int t;

  FUN_a00a93bc(_DAT_a802afec - 100);
  do {
    t = (unsigned short)_DAT_a802afec - 0x63;
    t = t % 5;
    _DAT_a802afec = t + 100;
  } while (FUN_a00aad30(t) != 1);
  DAT_a802d290.f = _DAT_a802afec - 100;
  FUN_a00d58f8();
  FUN_a00d58d8();
  FUN_a00d4998();
  FUN_a00a9650(_DAT_a802afec - 100, 1);
  {
    unsigned char v = DAT_a8025c56;
    if (_DAT_a802afec - 100 == v)
      FUN_a00a813c(1, v, 0);
    else
      FUN_a00a813c(1, v, 1);
  }
}
