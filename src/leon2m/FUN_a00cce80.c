/* leon2m FUN_a00cce80 @ 0xa00cce80-0xa00ccef4 (29 words), flags -mcpu=v8 -O3 -g. No direct callers.
 * v = byte 0xa802d049 (port 2) / 0xa802d0a1 (port 3) / 0xa802d0d9 (other ports); byte 0xa802d298 = v - '0';
 * then FUN_a00d4888(), FUN_a00b88cc(), FUN_a00baa6c(port), FUN_a00ba950(port), FUN_a00bab80(port, 6); returns 0.
 * Same form as FUN_a00c12b4 without the range test.
 */
extern unsigned char DAT_a802d049;
extern unsigned char DAT_a802d0a1;
extern unsigned char DAT_a802d0d9;
extern unsigned char DAT_a802d298;
extern void FUN_a00d4888(void);
extern void FUN_a00b88cc(void);
extern void FUN_a00baa6c(unsigned char);
extern void FUN_a00ba950(unsigned char);
extern void FUN_a00bab80(unsigned char, int);

int FUN_a00cce80(unsigned char param_1)
{
  unsigned char value;

  if (param_1 == 2)
    value = DAT_a802d049;
  else if (param_1 == 3)
    value = DAT_a802d0a1;
  else
    value = DAT_a802d0d9;
  DAT_a802d298 = value - 0x30;
  FUN_a00d4888();
  FUN_a00b88cc();
  FUN_a00baa6c(param_1);
  FUN_a00ba950(param_1);
  FUN_a00bab80(param_1, 6);
  return 0;
}
