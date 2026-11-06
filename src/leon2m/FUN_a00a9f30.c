/* leon2m FUN_a00a9f30 @ 0xa00a9f30 (-mcpu=v8 -O3 -g)
 * v = (2 * p1 - 8) & 0xff when p1 > 6, else (2 * p1 + 6) & 0xff. For j = 0..2: p2 != 0 -> FUN_a0146a80(0x22, v, 3, 0x792, 0)
 * and FUN_a0146b20(0, j + 0x22, v, 1, j + 0x37, 0); p2 == 0 -> FUN_a0146a80(0x22, v, 3, 0x592, 0) and
 * FUN_a0146b20(0, j + 0x22, v, 1, j + 0x34, 0). Callers include FUN_a00b6994 and FUN_a00b6d58.
 * Source form: one j loop with the 'p2 == 0' test inside it (the 0x592 arm first); -O3 loop unswitching makes the two
 * loops at 0xa00a9f60 and 0xa00a9fc0.
 */

extern void FUN_a0146a80(unsigned short param_1, unsigned short param_2, unsigned char param_3, unsigned short param_4, unsigned char param_5);
extern void FUN_a0146b20(unsigned char param_1, unsigned short param_2, unsigned short param_3, unsigned char param_4, unsigned char param_5, unsigned char param_6);
void FUN_a00a9f30(unsigned char param_1, unsigned char param_2)
{
  unsigned char v;
  unsigned char j;

  if (param_1 > 6)
    v = param_1 * 2 - 8;
  else
    v = param_1 * 2 + 6;
  for (j = 0; j < 3; j++) {
    if (param_2 == 0) {
      FUN_a0146a80(0x22, v, 3, 0x592, 0);
      FUN_a0146b20(0, j + 0x22, v, 1, j + 0x34, 0);
    } else {
      FUN_a0146a80(0x22, v, 3, 0x792, 0);
      FUN_a0146b20(0, j + 0x22, v, 1, j + 0x37, 0);
    }
  }
}
