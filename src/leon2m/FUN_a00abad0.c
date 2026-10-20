/* FUN_a00abad0 (leon2m, 0xa00abad0-0xa00abb98, 50 words). Flags -mcpu=v8 -O3 -g.
 Code facts: third twin of FUN_a00abff8/FUN_a00abd00 (here DAT_a802d290[0x14], channel 0xa, b50(0xea), tail FUN_a00d972c). v = rec[0x14] - 1 (u8);
 v > 100 -> rec[0x14] = 0; else rec[0x14] = v, ab5f0(0x2c,0xa,v,7,1), three 6a80 calls, 6b50(0xea,0), b6ec8(0x29,0xa,rec[0x14]), d972c(); then
 DAT_a802b08e |= 2.
 Fixes vs draft: BEHAVIOUR the draft subtracted 1 twice (range test on v - 1); FUN_a00abff8 form: clamp arm first, void u8 prototypes. Aids: none.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802b08e;
extern void FUN_a00ab5f0(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a00b6ec8(unsigned char, unsigned char, unsigned char);
extern void FUN_a00d972c(void);

void FUN_a00abad0(void)
{
  unsigned char v = DAT_a802d290[0x14] - 1;

  if (v > 100) {
    DAT_a802d290[0x14] = 0;
  } else {
    DAT_a802d290[0x14] = v;
    FUN_a00ab5f0(0x2c, 0xa, v, 7, 1);
    FUN_a0146a80(0x28, 0xa, 3, 0x742, 0);
    FUN_a0146a80(0x2b, 0xa, 1, 0x742, 0);
    FUN_a0146a80(0x32, 0xa, 1, 0x742, 0);
    FUN_a0146b50(0xea, 0);
    FUN_a00b6ec8(0x29, 0xa, DAT_a802d290[0x14]);
    FUN_a00d972c();
  }
  DAT_a802b08e |= 2;
}
