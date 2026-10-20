/* leon2s FUN_a0072fd8 @ 0xa0072fd8  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: decomp-permuter (AST mutations), judged by exact bytes
 */

extern int FUN_a006122c();
void FUN_a0072fd8(char *param_1, int param_2)
{
  int i;
  if (param_1 == 0)
  {
    return 0;
  }
  if ((param_2 == 1) && (param_1[0] == 0))
  {
    return 0;
  }
  i = 0;
  while (i < param_2)
  {
    FUN_a006122c((((((((((param_1[i] & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF);
    if (param_1[i] == '\n')
    {
      FUN_a006122c(0xd);
    }
    i++;
  }

  return 0;
}
