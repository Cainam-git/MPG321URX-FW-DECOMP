/* leon2m FUN_a013a454 @ 0xa013a454  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: decomp-permuter (AST mutations), judged by exact bytes
 */

extern void func_0x4008c4d0();
extern void func_0x4008c5f8();
extern int func_0x4008d1a0();
void FUN_a013a454(unsigned char param_1)
{
  short new_var;
  unsigned int local_c;
  int counter;
  local_c = 0xffffffff;
  new_var = param_1 & 0xff;
  func_0x4008c4d0(2, 0x20, &local_c, 1);
  counter = 100;
  if (local_c == 0)
  {
    goto LAB_a013a4c4;
  }
  do
  {
    func_0x4008d1a0(1);
    counter--;
    func_0x4008c4d0(2, 0x20, &local_c, 1);
    if (counter == 0)
    {
      goto LAB_a013a4e8;
    }
    if (local_c != 0)
    {
      continue;
    }
    goto LAB_a013a4c4;
  }
  while (1);
  LAB_a013a4e8:
  if (local_c == 0)
  {
    goto LAB_a013a4c4;
  }

  goto LAB_a013a4f8;
  LAB_a013a4c4:
  local_c = new_var | 0x50000000;

  func_0x4008c5f8(2, 0x20, &local_c, 1);
  LAB_a013a4f8:
  return;

}
