/* leon2m FUN_a00a9f30 @ 0xa00a9f30 (-mcpu=v8 -O3 -g)
 * v = (2 * p1 - 8) & 0xff when p1 > 6, else (2 * p1 + 6) & 0xff. For j = 0..2: p2 != 0 -> FUN_a0146a80(0x22, v, 3, 0x792, 0)
 * and FUN_a0146b20(0, j + 0x22, v, 1, j + 0x37, 0); p2 == 0 -> FUN_a0146a80(0x22, v, 3, 0x592, 0) and
 * FUN_a0146b20(0, j + 0x22, v, 1, j + 0x34, 0). Callers include FUN_a00b6994 and FUN_a00b6d58.
 * Compiler aid: the counter reset of the second arm is written 'if (uVar1) loop_i = 0; else loop_i = 0;'. It emits no extra
 * instruction; it moves 'clr %i1' into the delay slot of the 'be' (a plain 'loop_i = 0;' puts it before the branch).
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
