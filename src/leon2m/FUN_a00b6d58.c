/* leon2m FUN_a00b6d58 @ 0xa00b6d58 (-mcpu=v8 -O3 -g)
 */

extern unsigned int _DAT_a802d3ac;
extern int FUN_a00a9f30();
extern int FUN_a00d7d48();
void FUN_a00b6d58(void)
{
  int new_var;
 do { if (0 != FUN_a00d7d48(new_var)) { FUN_a00a9f30(1, 0); return; } new_var = 1; FUN_a00a9f30(new_var, (_DAT_a802d3ac >> 4) & new_var); } while (0);
}
