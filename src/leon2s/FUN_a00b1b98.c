/* leon2s FUN_a00b1b98 @ 0xa00b1b98 (-mcpu=v8 -Os -g)
 * Four read-modify-write operations: sets bit 8 (0x100) of register 0x9F120048, clears bit 24 (0x1000000) of the
 * same register, sets bit 8 of 0x9F120080 and sets bit 5 (0x20) of 0x9F120034.
 */
#define REG_9f120048 (*(volatile unsigned int *)0x9f120048)
#define REG_9f120080 (*(volatile unsigned int *)0x9f120080)
#define REG_9f120034 (*(volatile unsigned int *)0x9f120034)

void FUN_a00b1b98(void)
{
  REG_9f120048 = REG_9f120048 | 0x100;
  REG_9f120048 = REG_9f120048 & ~0x1000000;
  REG_9f120080 = REG_9f120080 | 0x100;
  REG_9f120034 = REG_9f120034 | 0x20;
}
