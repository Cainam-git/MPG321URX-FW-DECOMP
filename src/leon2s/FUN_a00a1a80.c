/* leon2s FUN_a00a1a80 @ 0xa00a1a80-0xa00a1b08 (34 words), flags -mcpu=v8 -Os -g.
 * For u8 i = 0..1 over the 400-byte records DAT_a807d7e0[i]: when byte +3 != 0: byte +2 = 1,
 * FUN_a009e9cc(i) if byte +1 == 1 else FUN_a009e9fc(i), then byte +1 = 0 (address recomputed after the
 * call); when byte +3 == 0: byte +2 = 0. void(void).
 * The base is DAT_a807d7e0 (not 0xa807d7e1). Source form: the != 0 arm comes first.
 */
extern unsigned char DAT_a807d7e0[];
extern void FUN_a009e9cc(unsigned char);
extern void FUN_a009e9fc(unsigned char);

void FUN_a00a1a80(void)
{
  unsigned char i;

  for (i = 0; i <= 1; i++) {
    if (DAT_a807d7e0[i * 400 + 3] != 0) {
      DAT_a807d7e0[i * 400 + 2] = 1;
      if (DAT_a807d7e0[i * 400 + 1] == 1)
        FUN_a009e9cc(i);
      else
        FUN_a009e9fc(i);
      DAT_a807d7e0[i * 400 + 1] = 0;
    } else
      DAT_a807d7e0[i * 400 + 2] = 0;
  }
}
