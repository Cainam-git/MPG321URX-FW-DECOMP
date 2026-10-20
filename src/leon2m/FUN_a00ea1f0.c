/* leon2m FUN_a00ea1f0 @ 0xa00ea1f0 (-mcpu=v8 -O2 -g)
 */

extern void FUN_a00e9c80();
inline int inline_fn(int arg0)
{
  return arg0 + 1;
}

int FUN_a00ea1f0(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4, int param_5, unsigned int param_6)
{
  int iVar1;
  iVar1 = 0;
  if (iVar1 < param_5)
  {
    do
    {
      FUN_a00e9c80(param_1, param_2, param_3, iVar1, param_4, param_6);
      iVar1 = inline_fn(iVar1);
      if (iVar1 >= param_5)
      {
        break;
        iVar1 = inline_fn(iVar1);
        FUN_a00e9c80(param_1, param_2, param_3, iVar1, param_4, param_6);
      }
    }
    while (iVar1 < param_5);
  }
  return param_1;
}
