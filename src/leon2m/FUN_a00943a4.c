/* leon2m FUN_a00943a4 @ 0xa00943a4  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: decomp-permuter (AST mutations), judged by exact bytes
 */

extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern unsigned int _DAT_a802d290;
extern unsigned char DAT_a802d433;
extern int FUN_a00a6b98();
extern int FUN_a00b5080();
extern int func_0x4008e2a4();
void FUN_a00943a4(void)
{
  unsigned char *p = (unsigned char *) 0xa802d290;
  int new_var;
  DAT_a8025c55 = p[0x13e];
  new_var = 0;
  _DAT_a802afec = 0x108;
  p[0x1a3] = new_var;
 do { FUN_a00b5080(); func_0x4008e2a4(); } while (new_var);
  func_0x4008e2a4();
  FUN_a00a6b98(new_var, 1, new_var);
}
