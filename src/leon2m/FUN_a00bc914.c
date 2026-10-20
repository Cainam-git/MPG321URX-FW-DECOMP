/* leon2m FUN_a00bc914 @ 0xa00bc914-0xa00bc954 (16 words), flags -mcpu=v8 -O3 -g. Same family as
 * FUN_a00bdb48 / FUN_a00bdb88.
 * Code facts: text bytes DAT_a802d078[7..9] = '0', '0', '1' (0x30, 0x30, 0x31); FUN_a00bacc4(0xf);
 * p = param_1 & 0xff; FUN_a00ba950(p); tail call FUN_a00babe4(p, 11).
 * Required forms: FUN_a00bacc4 takes ONE argument (fw sets only %o0 = 0xf); bdb48 form for p. Aids: none.
 */
extern unsigned char DAT_a802d078[];
extern void FUN_a00bacc4(unsigned char);
extern int FUN_a00ba950();
extern void FUN_a00babe4(unsigned char param_1, unsigned char param_2);

void FUN_a00bc914(unsigned int param_1)
{
  DAT_a802d078[7] = 0x30;
  DAT_a802d078[8] = 0x30;
  DAT_a802d078[9] = 0x31;
  FUN_a00bacc4(0xf);
  param_1 &= 0xff;
  (void)FUN_a00ba950(param_1);
  FUN_a00babe4(param_1, 0xb);
}
