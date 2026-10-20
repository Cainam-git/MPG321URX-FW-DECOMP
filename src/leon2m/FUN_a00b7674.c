/* leon2m FUN_a00b7674 @ 0xa00b7674-0xa00b77b4 (80 words), flags -mcpu=v8 -O3 -g.
 * Called by FUN_a0098ddc, FUN_a0098e28, FUN_a00a44f4, FUN_a00a454c and FUN_a00af44c.
 * Code facts: n = byte 0xc of the record DAT_a802d290;
 * FUN_a00ab5f0(0x2c, 6, (n * 4 - 20) & 0xfc, 6, param_1); v = 0x742, or 0x792 when param_1 == 0, with
 * FUN_a00a9468(1, 3) / (1, 2); v &= 0x7d2; FUN_a0146a80(0x28/0x2b/0x32, 6, 3/1/1, v, 0) with
 * FUN_a0146b20(0, 0x2b/0x32, 6, 1, 0x3f/0x40, 0) after the 2nd and 3rd; FUN_a0146b50(0xe6, 0);
 * FUN_a01577f4(buf, 0x1981d0 "n%3d", rec[0xc]); buf[0] = 3; FUN_a0146b6c(2, 0);
 * FUN_a00a31a4(0, 0x28, 6, 2, buf, 0). void.
 * Same body as FUN_a00b7530 with record byte 0xc and the value n * 4 - 20.
 * Source form: the first read goes through a local base pointer (or base; ldub [base + 0xc]), the second
 * through DAT_a802d290[0xc] (the kept high part is or-ed again); v is set in both arms. Aids: none.
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

void FUN_a00b7674(unsigned char param_1)
{
  unsigned short v;
  unsigned char buf[8];
  unsigned char *rec = DAT_a802d290;

  FUN_a00ab5f0(0x2c, 6, (rec[0xc] * 4 - 20) & 0xfc, 6, param_1);
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
  FUN_a01577f4(buf, 0x1981d0, DAT_a802d290[0xc]);
  buf[0] = 3;
  FUN_a0146b6c(2, 0);
  FUN_a00a31a4(0, 0x28, 6, 2, buf, 0);
}
