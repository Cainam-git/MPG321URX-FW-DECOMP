/* leon2s FUN_a00a4370 @ 0xa00a4370 (-mcpu=v8 -Os -g)
 */

extern unsigned int DAT_a006bf18;
extern unsigned int DAT_a006bf68;
extern int FUN_a0073044();
extern int FUN_a0091a4c();
extern int FUN_a0091cf4();
extern unsigned char FUN_a0091d64(unsigned int param_1, unsigned int param_2);
extern void FUN_a0094ac4(unsigned char param_1, unsigned char param_2);
extern void FUN_a00a8054();
extern void FUN_a00a80cc();
extern unsigned int ARR_a807873c[];
extern unsigned int ARR_a807db6c[];
extern unsigned char DAT_a80791b0[];
extern unsigned char DAT_a80791e8[];
extern unsigned char DAT_a8079208[];
unsigned int FUN_a00a4370(unsigned int param_1, unsigned int param_2)
{
  unsigned char y;
  param_1 = param_1 & 0xff;
  if (ARR_a807db6c[param_1] == ARR_a807873c[param_1])
  {
    goto skip_init;
  }
  FUN_a0073044(&DAT_a006bf18, param_1);
  ARR_a807873c[param_1] = ARR_a807db6c[param_1];
  FUN_a00a80cc(param_1, 1, 0x39, 0x10, 0);
  FUN_a00a8054(param_1, 4, 0xe0, 0);
  FUN_a00a8054(param_1, 4, 0xe1, 0);
  FUN_a0091cf4(param_1, 0x10, 0x20);
  skip_init:
  y = FUN_a0091d64(param_1, 0x10);

  if (DAT_a8079208[param_1] != 0)
  {
    ARR_a807db6c[param_1] = 2;
    DAT_a8079208[param_1] = 0;
    return 0;
  }
  if (((y & 0x10) != 0) || (DAT_a80791b0[param_1] != 0))
  {
    FUN_a00a80cc(param_1, 1, 0x39, 0x10, 0);
    FUN_a00a8054(param_1, 4, 0xe0, 0);
    FUN_a00a8054(param_1, 4, 0xe1, 0);
    FUN_a0094ac4(param_1, 0);
    if ((y & 0x10) != 0)
    {
      FUN_a0091cf4(param_1, 0x10, 0x10);
    }
    else
    {
      DAT_a80791b0[param_1] = 0;
      FUN_a0073044(&DAT_a006bf68, param_1);
    }
    FUN_a0091a4c(param_1);
  }
  else
    if (!((y & 0x20) == 0))
  {
    FUN_a0091cf4(param_1, 0x10, 0x20);
    ARR_a807db6c[param_1] = 3;
    DAT_a80791e8[param_1] = 0;
  }
  else
  {
    ARR_a807db6c[param_1] = 5;
  }
  return 0;
}
