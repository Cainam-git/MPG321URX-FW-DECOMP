/* leon2s FUN_a00a8694 @ 0xa00a8694  MATCH (-mcpu=v8 -Os -g, twin)
 * Twin of FUN_a00a8844: same code, constants swapped; byte-exact.
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
