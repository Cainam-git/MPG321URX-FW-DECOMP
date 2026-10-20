/* leon2m FUN_a00aba34 @ 0xa00aba34-0xa00abad0 (39 words), flags -mcpu=v8 -O3 -g. jf 100.00 match=True,
 * rawcmp 0 mismatches. Twin of FUN_a00abc64 (channel 10, rec byte 0x14).
 * Code facts: v = (param_1 != 0 ? 0 : 0x50) + 0x742 (cmp/addx, and 0x50, add 0x742);
 * FUN_a00ab5f0(0x2c, 10, rec[0x14], 7, param_1) with rec = DAT_a802d290 (byte at a802d290 + 0x14),
 * FUN_a0146a80(0x28 / 0x2b / 0x32, 10, 3 / 1 / 1, v, 0), FUN_a0146b50(0xea, 0), tail call
 * FUN_a00b6ec8(0x29, 10, rec[0x14]) (byte re-read after the calls). void.
 * Fixes vs the autoc draft (89.74): real base DAT_a802d290 (byte array, ldub [base + 0x14]; the draft's
 * mid-record volatile uint gave ld + and 0xff); callee prototypes (FUN_a00ab5f0 u8 x5, FUN_a00b6ec8 void
 * u8 x3, FUN_a0146a80 u16,u16,u8,u16,u8); v as unsigned short. Aids: none.
 */
extern unsigned char DAT_a802d290[];
extern void FUN_a00ab5f0(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a00b6ec8(unsigned char, unsigned char, unsigned char);

void FUN_a00aba34(unsigned char param_1)
{
  unsigned short v = ((param_1 != 0) - 1 & 0x50) + 0x742;

  FUN_a00ab5f0(0x2c, 10, DAT_a802d290[0x14], 7, param_1);
  FUN_a0146a80(0x28, 10, 3, v, 0);
  FUN_a0146a80(0x2b, 10, 1, v, 0);
  FUN_a0146a80(0x32, 10, 1, v, 0);
  FUN_a0146b50(0xea, 0);
  FUN_a00b6ec8(0x29, 10, DAT_a802d290[0x14]);
}
