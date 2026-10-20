/* leon2s FUN_a00ae3a0 @ 0xa00ae3a0  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: decomp-permuter (AST mutations), judged by exact bytes
 */

extern void FUN_a0084c74(int, unsigned char);
extern void FUN_a0084c94(int, unsigned char);
extern void FUN_a00a6c98(int, int, int, unsigned char);
extern char ARR_a807dc18[];
void FUN_a00ae3a0(unsigned int param_1)
{
  char *p;
  param_1 = (param_1 & 0xff) & 0xff;
  p = &ARR_a807dc18[param_1 * 300];
  FUN_a0084c74(param_1, p[0x118]);
  param_1 = param_1;
  FUN_a0084c94(param_1, p[0x11a]);
  FUN_a00a6c98(param_1, 200, 0x30, p[0x11b]);
}
