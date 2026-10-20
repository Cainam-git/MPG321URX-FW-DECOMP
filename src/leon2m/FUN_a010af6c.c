/* leon2m FUN_a010af6c @ 0xa010af6c  MATCH (-mcpu=v8 -O2 -g)
 * Tail-calls FUN_a00f2e98((((param_1 << 4) - 46) | 4) & 0xFE, 0, 64, param_2). The shift is written as '<< 4';
 * the form 'param_1 * 16' gives a different register allocation.
 */
/* FUN_a00f2e98 at 0xa00f2e98 – printf-like / utility routine called by FUN_a010af6c */
extern int FUN_a00f2e98(int a, int b, int c, int d);

void FUN_a010af6c(int param_1, int param_2)
{
    FUN_a00f2e98((((param_1 << 4) - 46) | 4) & 0xfe, 0, 64, param_2);
}
