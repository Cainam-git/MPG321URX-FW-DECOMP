/* leon2m FUN_a00a5420 @ 0xa00a5420 (-mcpu=v8 -O3 -g)
 */

extern void FUN_a0146a80(unsigned short param_1, unsigned short param_2, unsigned char param_3, unsigned short param_4, unsigned char param_5);
extern void FUN_a0146b20(unsigned char param_1, unsigned short param_2, unsigned short param_3, unsigned char param_4, unsigned char param_5, unsigned char param_6);
void FUN_a00a5420(unsigned char i0, unsigned char i1)
{
  unsigned char v;
  unsigned char j;
  if (i0 > 6)
  {
    v = (unsigned char) ((i0 * 2) - 8);
  }
  else
  {
    v = (unsigned char) ((i0 * 2) + 6);
  }
  if (i1 != 0)
  {
    j = 0;
    do
    {
      FUN_a0146a80(0x22, v, 3, 0x742, 0);
      FUN_a0146b20(0, (unsigned short) (j + 0x22), v, 1, j + 0x37, 0);
      j++;
    }
    while (j <= 2);
  }
  else
  {
    if (v)
    {
      j = 0;
    }
    else
    {
      j = 0;
    }
    do
    {
      FUN_a0146a80(0x22, v, 3, 0x542, 0);
      FUN_a0146b20(0, (unsigned short) (j + 0x22), v, 1, j + 0x34, 0);
      j++;
    }
    while (j <= 2);
  }
}
