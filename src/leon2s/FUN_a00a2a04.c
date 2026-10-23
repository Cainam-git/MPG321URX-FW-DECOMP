/* leon2s FUN_a00a2a04 @ 0xa00a2a04 (-mcpu=v8 -Os -g)
 * Clears bit p + 2 of register 0xCF03C890 (mask 4 << p).
 */
#define _DAT_cf03c890 (*(volatile unsigned int *)0xcf03c890)

void FUN_a00a2a04(unsigned char param_1)
{
  unsigned int mask = 4 << param_1;
  _DAT_cf03c890 = _DAT_cf03c890 & ~mask;
  return;
}
