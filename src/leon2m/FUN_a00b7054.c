/* FUN_a00b7054 (leon2m, 0xa00b7054-0xa00b7188, 77 words). Flags -mcpu=v8 -O3 -g. jf 100.00 match=True, rawcmp 0 mismatches.
 Code facts: twin of FUN_a00b7530 / FUN_a00b7e68 with the DAT_a802d290[9] byte. ab5f0(0x2c, 6, rec[9], 6, p); p != 0 -> v = 0x742, a9468(1, 3),
 else v = 0x792, a9468(1, 2); v &= 0x7d2; three 6a80 calls with v, two 6b20 calls (0x3f, 0x40), 6b50(0xe6, 0), 577f4(buf, 0x1981d0, rec[9]),
 buf[0] = 3, 6b6c(2, 0), a31a4(0, 0x28, 6, 2, buf, 0).
 Required forms: the twins' lever, v and the a9468 call set in BOTH arms (no default before the if), local rec base; u8 prototypes. Aids: none.
 */
extern unsigned char DAT_a802d290[];
extern void FUN_a0146b50(unsigned int, unsigned char);
extern void FUN_a00ab5f0(unsigned int, unsigned int, unsigned char, unsigned int, unsigned int);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a0146a80(unsigned int, unsigned int, unsigned char, unsigned int, unsigned char);
extern void FUN_a0146b20(unsigned int, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);
extern void FUN_a01577f4(unsigned char *, unsigned int, unsigned char);
extern void FUN_a0146b6c(unsigned int, unsigned int);
extern void FUN_a00a31a4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *, unsigned int);

void FUN_a00b7054(unsigned char param_1)
{
  unsigned short v;
  unsigned char buf[8];
  unsigned char *rec = DAT_a802d290;

  FUN_a00ab5f0(0x2c, 6, rec[9], 6, param_1);
  if (param_1 != 0) {
    v = 0x742;
    FUN_a00a9468(1, 3);
  } else {
    v = 0x792;
    FUN_a00a9468(1, 2);
  }
  v &= 0x7d2;
  FUN_a0146a80(0x28, 6, 3, v, 0);
  FUN_a0146a80(0x2b, 6, 1, v, 0);
  FUN_a0146b20(0, 0x2b, 6, 1, 0x3f, 0);
  FUN_a0146a80(0x32, 6, 1, v, 0);
  FUN_a0146b20(0, 0x32, 6, 1, 0x40, 0);
  FUN_a0146b50(0xe6, 0);
  FUN_a01577f4(buf, 0x1981d0, DAT_a802d290[9]);
  buf[0] = 3;
  FUN_a0146b6c(2, 0);
  FUN_a00a31a4(0, 0x28, 6, 2, buf, 0);
}
