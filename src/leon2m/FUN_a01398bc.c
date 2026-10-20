/* leon2m FUN_a01398bc @ 0xa01398bc  MATCH (-mcpu=v8 -O3 -g, twin)
 * Twin of FUN_a013a454: same code, constants swapped; byte-exact.
 * See FUN_a013a454 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern void func_0x4008c4d0();
extern void func_0x4008c5f8();
extern int func_0x4008d1a0();
void FUN_a01398bc(unsigned char param_1)
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
    goto LAB_a013992c;
  }
  do
  {
    func_0x4008d1a0(1);
    counter--;
    func_0x4008c4d0(2, 0x20, &local_c, 1);
    if (counter == 0)
    {
      goto LAB_a0139950;
    }
    if (local_c != 0)
    {
      continue;
    }
    goto LAB_a013992c;
  }
  while (1);
  LAB_a0139950:
  if (local_c == 0)
  {
    goto LAB_a013992c;
  }

  goto LAB_a0139960;
  LAB_a013992c:
  local_c = new_var | 0x60000000;

  func_0x4008c5f8(2, 0x20, &local_c, 1);
  LAB_a0139960:
  return;

}
