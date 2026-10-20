/* leon2m FUN_a009d9b0 @ 0xa009d9b0-0xa009da6c (47 words), flags -mcpu=v8 -O3 -g.
 * Byte-identical twin of FUN_a009d8f4 (same constants, same callees). Code facts: FUN_a00a93bc((u8)(word
 * 0xa802afec + 0x4c)); loop t = (lduh 0xa802afee) - 0xb3; t %= 2; afec = t + 0xb4; until FUN_a00aad30((u8)t)
 * == 1; bit 15 of word 0xa802d290+0xa8 = (u8)(afec + 0x4c) as a 1-bit BIT-FIELD; FUN_a00a9650((u8)(afec +
 * 0x4c), 1); tail FUN_a00a813c(1, v = byte 0xa8025c56, afec - 0xb4 != v). void(void). Aids: none.
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

void FUN_a009d9b0(void)
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
