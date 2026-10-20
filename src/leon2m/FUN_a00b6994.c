/* leon2m FUN_a00b6994 @ 0xa00b6994  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: decomp-permuter (AST mutations), judged by exact bytes
 */

extern unsigned int _DAT_a802d404;
extern int FUN_a00a9f30();
extern int FUN_a00d7d48();
void FUN_a00b6994(void)
{
  int new_var;
  unsigned int uVar1;
  ;
  uVar1 = FUN_a00d7d48(new_var);
  if (uVar1 != 0)
  {
    FUN_a00a9f30(2, 0);
    return;
  }
  FUN_a00a9f30(2, (_DAT_a802d404 >> 0xf) & 1);
  return;
}
