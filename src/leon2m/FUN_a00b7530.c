/* leon2m FUN_a00b7530 @ 0xa00b7530-0xa00b7674 (81 words), flags -mcpu=v8 -O3 -g.
 * Twin of FUN_a00b7e68. Code facts: n = byte rec[0xf] (rec = DAT_a802d290).
 * FUN_a00ab5f0(0x2c, 6, (n * 20) & 0xfc, 6, param_1); v = 0x742, or 0x792 when param_1 == 0, with
 * FUN_a00a9468(1, 3) / (1, 2); v &= 0x7d2; FUN_a0146a80(0x28/0x2b/0x32, 6, 3/1/1, v, 0) with
 * FUN_a0146b20(0, 0x2b/0x32, 6, 1, 0x3f/0x40, 0) after the 2nd and 3rd; FUN_a0146b50(0xe6, 0);
 * FUN_a01577f4(buf, 0x1981d0, rec[0xf]); buf[0] = 3; FUN_a0146b6c(2, 0);
 * FUN_a00a31a4(0, 0x28, 6, 2, buf, 0). void.
 * Fixes vs the autoc draft: real base DAT_a802d290 (byte 0xf) read through a local base
 * pointer for the first read (fw: or base; ldub [base + 0xf]) and as DAT_a802d290[0xf] for the second
 * (fw re-ors the kept HIGH); v is set in BOTH arms (a default before the if puts 'mov 0x742' in the
 * delay slot, 97.53); u16 v; callee prototypes from FUN_a00b7e68. Aids: none.
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

void FUN_a00b7530(unsigned char param_1)
{
  unsigned short v;
  unsigned char buf[8];
  unsigned char *rec = DAT_a802d290;

  FUN_a00ab5f0(0x2c, 6, rec[0xf] * 20 & 0xfc, 6, param_1);
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
  FUN_a01577f4(buf, 0x1981d0, DAT_a802d290[0xf]);
  buf[0] = 3;
  FUN_a0146b6c(2, 0);
  FUN_a00a31a4(0, 0x28, 6, 2, buf, 0);
}
