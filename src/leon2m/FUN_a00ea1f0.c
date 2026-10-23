/* leon2m FUN_a00ea1f0 @ 0xa00ea1f0 (-mcpu=v8 -O2 -g)
 * Calls FUN_a00e9c80(p1, p2, p3, i, p4, p6) for i = 0 .. p5 - 1 (no call when p5 <= 0) and returns p1. p5 is a signed
 * int (signed compare); the other five arguments are passed through unchanged, with the counter i inserted as the
 * fourth argument.
 */

extern void FUN_a00e9c80();

int FUN_a00ea1f0(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4, int param_5, unsigned int param_6)
{
  int i;
  for (i = 0; i < param_5; i++)
    FUN_a00e9c80(param_1, param_2, param_3, i, param_4, param_6);
  return param_1;
}
