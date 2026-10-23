/* leon2s FUN_a007a79c @ 0xa007a79c (-mcpu=v8 -Os -g)
 * p = p1 & 0xff. FUN_a007a708(p); for lanes i = 0..3: FUN_a00a7424(0, 7, p, DAT_a00b3b18[i]) and
 * FUN_a00a7488(p, DAT_a00b3b10[i], 0xffffff, 0x18000000). Then for each lane i whose bit is set in p2 & 0xff, the same
 * two calls followed by FUN_a00a7488(p, reg, mask, value) on the lane's registers from the halfword tables
 * DAT_a00b3b40 / b50 / b38 / b48 (value 0x88000000 / 0x88), DAT_a00b3b30 / b28 (bytes 1 and 2 cleared), and again
 * b40 / b50 / b38 / b48 with 0x8000000 / 8.
 * Compiler aid: the clear-bit case is written 'if (p || i) goto skip; else goto skip;'. It emits no extra
 * instruction; it gives the firmware's annulled 'be,a' with the counter increment in its delay slot (a single
 * 'goto skip' gives a plain 'be').
 */

extern void FUN_a007a708(unsigned char param_1);
extern void FUN_a00a7424(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned short param_4);
extern void FUN_a00a7488(unsigned int param_1, unsigned short param_2, unsigned int param_3, unsigned int param_4);
extern unsigned short DAT_a00b3b10[4];
extern unsigned short DAT_a00b3b18[4];
extern unsigned short DAT_a00b3b28[4];
extern unsigned short DAT_a00b3b30[4];
extern unsigned short DAT_a00b3b38[4];
extern unsigned short DAT_a00b3b40[4];
extern unsigned short DAT_a00b3b48[4];
extern unsigned short DAT_a00b3b50[4];
void FUN_a007a79c(unsigned int param_1, int param_2)
{
  int i;
  unsigned int j;
  unsigned short v30;
  unsigned short v28;
  unsigned short v40;
  unsigned short v50;
  unsigned short v38;
  unsigned short v48;
  param_1 &= 0xff;
  i = 0;
  FUN_a007a708(param_1);
  do
  {
    FUN_a00a7424(0, 7, param_1, DAT_a00b3b18[i]);
    if (i <= 3)
      FUN_a00a7488(param_1, DAT_a00b3b10[i], 0xffffff, 0x18000000);
    i++;
  }
  while (i < 4);
  i = 0;
  do
  {
    unsigned int bit = (param_2 & 0xff) >> i;
    if ((bit & 1) == 0)
    {
      if (param_1 || i)
      {
        goto skip;
      }
      else
      {
        goto skip;
      }
    }
    if (i > 3)
    {
      goto skip;
    }
    FUN_a00a7424(0, 7, param_1, DAT_a00b3b18[i]);
    FUN_a00a7488(param_1, DAT_a00b3b10[i], 0xffffff, 0x18000000);
    v40 = DAT_a00b3b40[i];
    FUN_a00a7488(param_1, v40, 0xffffff, 0x88000000);
    v50 = DAT_a00b3b50[i];
    FUN_a00a7488(param_1, v50, 0xffffff00, 0x88);
    v38 = DAT_a00b3b38[i];
    FUN_a00a7488(param_1, v38, 0xffffff, 0x88000000);
    v48 = DAT_a00b3b48[i];
    FUN_a00a7488(param_1, v48, 0xffffff00, 0x88);
    v30 = DAT_a00b3b30[i];
    FUN_a00a7488(param_1, v30, 0xffff00ff, 0);
    v28 = DAT_a00b3b28[i];
    FUN_a00a7488(param_1, v28, 0xffff00ff, 0);
    FUN_a00a7488(param_1, v30, 0xff00ffff, 0);
    FUN_a00a7488(param_1, v28, 0xff00ffff, 0);
    FUN_a00a7488(param_1, v40, 0xffffff, 0x8000000);
    FUN_a00a7488(param_1, v50, 0xffffff00, 8);
    FUN_a00a7488(param_1, v38, 0xffffff, 0x8000000);
    FUN_a00a7488(param_1, v48, 0xffffff00, 8);
    skip:
    i++;

  }
  while (i < 4);
}
