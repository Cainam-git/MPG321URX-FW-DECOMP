/* leon2m FUN_a013a670 @ 0xa013a670 (-mcpu=v8 -O3 -g)
 * Reads a word w (preset to 0xFFFFFFFF) through func_0x4008c4d0(2, 0x20, &w, 1); while it is nonzero, calls
 * func_0x4008d1a0(1) and reads again, at most 100 times. When w reads 0, writes 0x53000000 | (p1 & 0xff) << 16 |
 * (sign-extended low 16 bits of p2) through func_0x4008c5f8(2, 0x20, &w, 1); otherwise returns without a write.
 * Same code as FUN_a013a5b8 with other constants.
 * See FUN_a013a5b8 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern void func_0x4008c4d0();
extern void func_0x4008c5f8();
extern int func_0x4008d1a0();
void FUN_a013a670(unsigned char param_1, unsigned int param_2)
{
  unsigned int local_c;
  int counter;
  local_c = 0xffffffff;
  func_0x4008c4d0(2, 0x20, &local_c, 1);
  counter = 100;
  if (local_c == 0)
  {
    goto success;
  }
  do
  {
    func_0x4008d1a0(1);
    counter--;
    func_0x4008c4d0(2, 0x20, &local_c, 1);
    if (counter == 0)
    {
      goto check;
    }
    if (local_c == 0)
    {
      goto success;
    }
  }
  while (1);
  check:
  if (local_c == 0)
  {
    goto success;
  }

  return;
  success:
  local_c = (param_1 & 0xff) << 0x10;

  counter = (param_2 << 0x10) >> 0x10;
  local_c |= 0x53000000;
  local_c |= counter;
  func_0x4008c5f8(2, 0x20, &local_c, 1);
}
