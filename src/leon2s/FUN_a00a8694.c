/* leon2s FUN_a00a8694 @ 0xa00a8694 (-mcpu=v8 -Os -g)
 * Calls FUN_a00a8508(p1, 0, a) with a = {0, 0x10, 0, 0}, FUN_a00a8508(p1, 1, c) with c = the 4 bytes copied from
 * 0xA00B4DC8 (FUN_a00b15d8), and FUN_a00a8508(p1, 2, b) with b = {0x40, 0, 0, 0}. Same code as FUN_a00a8844.
 * See FUN_a00a8844 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_a00b4dc8[];
extern void FUN_a00a8508(unsigned char, unsigned char, unsigned char *);
extern void *FUN_a00b15d8(void *, const void *, unsigned int);

void FUN_a00a8694(unsigned char param_1)
{
  unsigned char a[4] = { 0 };
  unsigned char b[4] = { 0 };
  unsigned char c[8];

  a[1] = 0x10;
  b[0] = 0x40;

  FUN_a00b15d8(c, DAT_a00b4dc8, 4);
  FUN_a00a8508(param_1, 0, a);
  FUN_a00a8508(param_1, 1, c);
  FUN_a00a8508(param_1, 2, b);
}
