/* leon2m FUN_a00bdb88 @ 0xa00bdb88-0xa00bdbcc (17 words), flags -mcpu=v8 -O3 -g. Twin of FUN_a00bdb48.
 * Code facts: text bytes DAT_a802d078[7..9] = 'V', '2', '3' (0x56, 0x32, 0x33); FUN_a00bac3c(0x30);
 * p = param_1 & 0xff; FUN_a00ba950(p); tail call FUN_a00babe4(p, 11).
 * Fixes vs the autoc draft (88.24): BEHAVIOUR, FUN_a00ba950 and FUN_a00babe4 take the u8 parameter
 * (the draft passed 0x30 to both; fw: and %i0,0xff,%i0 then mov %i0,%o0); same form as bdb48. Aids: none.
 */
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c();
extern int FUN_a00ba950();
extern void FUN_a00babe4(unsigned char param_1, unsigned char param_2);

void FUN_a00bdb88(unsigned int param_1)
{
  DAT_a802d078[7] = 0x56;
  DAT_a802d078[8] = 0x32;
  DAT_a802d078[9] = 0x33;
  (void)FUN_a00bac3c(0x30);
  param_1 &= 0xff;
  (void)FUN_a00ba950(param_1);
  FUN_a00babe4(param_1, 0xb);
}
