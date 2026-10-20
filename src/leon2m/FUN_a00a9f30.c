/* leon2m FUN_a00a9f30 @ 0xa00a9f30 (-mcpu=v8 -O3 -g)
 */

extern void FUN_a0146a80(unsigned short param_1, unsigned short param_2, unsigned char param_3, unsigned short param_4, unsigned char param_5);
extern void FUN_a0146b20(unsigned char param_1, unsigned short param_2, unsigned short param_3, unsigned char param_4, unsigned char param_5, unsigned char param_6);
void FUN_a00a9f30(unsigned char param_1, unsigned char param_2)
{
  unsigned char uVar1;
  unsigned char loop_i;
  if (param_1 > 6)
  {
    uVar1 = (unsigned char) ((param_1 * 2) - 8);
  }
  else
  {
    uVar1 = (unsigned char) ((param_1 * 2) + 6);
  }
  if (param_2 != 0)
  {
    loop_i = 0;
    do
    {
      FUN_a0146a80(0x22, uVar1, 3, 0x792, 0);
      FUN_a0146b20(0, (unsigned short) (loop_i + 0x22), uVar1, 1, (unsigned char) (loop_i + 0x37), 0);
      loop_i++;
    }
    while (loop_i <= 2);
  }
  else
  {
    if (uVar1)
    {
      loop_i = 0;
    }
    else
    {
      loop_i = 0;
    }
    do
    {
      FUN_a0146a80(0x22, uVar1, 3, 0x592, 0);
      FUN_a0146b20(0, (unsigned short) (loop_i + 0x22), uVar1, 1, (unsigned char) (loop_i + 0x34), 0);
      loop_i++;
    }
    while (loop_i <= 2);
  }
}
