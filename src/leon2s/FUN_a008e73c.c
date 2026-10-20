/* leon2s FUN_a008e73c @ 0xa008e73c  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: decomp-permuter (AST mutations), judged by exact bytes
 */

extern int FUN_a00a7fd8();
extern int FUN_a00a8054();
extern int FUN_a00a80cc();
inline int inline_fn(unsigned char arg0)
{
  return arg0 | 1;
}

void FUN_a008e73c(unsigned char param_1, unsigned char param_2, int param_3, int param_4, int param_5, int param_6)
{
  unsigned char uVar1;
  unsigned char uVar2;
  unsigned int uVar3;
  uVar2 = param_1 & 0xff;
  uVar3 = uVar2;
  if (param_2 == 1)
  {
    FUN_a00a80cc(uVar3, 1, 0x3b, 0x40, 1);
    uVar1 = FUN_a00a7fd8(uVar3, 1, 0x3b) & 0xf0;
    FUN_a00a8054(uVar3, 1, 0x3b, uVar1, param_5, param_6);
  }
  else
  {
    FUN_a00a80cc(uVar3, 1, 0x3b, 0x40, 0);
    if (((!param_6) && (!param_6)) && (!param_6))
    {
    }
    uVar1 = FUN_a00a7fd8(uVar3, 1, 0x3b) & 0xf1;
    uVar1 = inline_fn(uVar1);
    FUN_a00a8054(uVar3, 1, 0x3b, uVar1, param_5, param_6);
  }
}
