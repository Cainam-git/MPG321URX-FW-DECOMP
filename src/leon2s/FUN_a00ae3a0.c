/* leon2s FUN_a00ae3a0 @ 0xa00ae3a0 (-mcpu=v8 -Os -g)
 * For the 300-byte record (p & 0xff) at 0xA807DC18: FUN_a0084c74(p, byte +0x118), FUN_a0084c94(p, byte +0x11a) and
 * FUN_a00a6c98(p, 200, 0x30, byte +0x11b) (register 200, mask 0x30, value from the record; tail call). The record
 * pointer is computed once and kept in a register.
 */

extern void FUN_a0084c74(int, unsigned char);
extern void FUN_a0084c94(int, unsigned char);
extern void FUN_a00a6c98(int, int, int, unsigned char);
extern char ARR_a807dc18[];
void FUN_a00ae3a0(unsigned int param_1)
{
  char *p;
  param_1 = param_1 & 0xff;
  p = &ARR_a807dc18[param_1 * 300];
  FUN_a0084c74(param_1, p[0x118]);
  FUN_a0084c94(param_1, p[0x11a]);
  FUN_a00a6c98(param_1, 200, 0x30, p[0x11b]);
}
