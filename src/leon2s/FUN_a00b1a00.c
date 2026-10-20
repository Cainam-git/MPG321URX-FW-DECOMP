/* leon2s FUN_a00b1a00 @ 0xa00b1a00 (-mcpu=v8 -Os -g)
 * Twin of FUN_a00b1b98: same code, other constants.
 */
#define REG_9f120048 (*(volatile unsigned int *)0x9f120048)
#define REG_9f120080 (*(volatile unsigned int *)0x9f120080)
#define REG_9f120034 (*(volatile unsigned int *)0x9f120034)

void FUN_a00b1a00(void)
{
  REG_9f120048 = REG_9f120048 | 0x40;
  REG_9f120048 = REG_9f120048 & ~0x400000;
  REG_9f120080 = REG_9f120080 | 0x40;
  REG_9f120034 = REG_9f120034 | 0x20;
}
