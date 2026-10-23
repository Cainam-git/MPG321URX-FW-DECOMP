/* leon2s FUN_a00b1be4 @ 0xa00b1be4 (-mcpu=v8 -Os -g)
 * In this order: sets bit 5 of registers 0x9F120030 and 0x9F100090, clears bit 5 of register 0x9F120028, clears
 * bit 9 of register 0x9F120048, sets bit 9 of register 0x9F120080, sets bit 25 of register 0x9F120048 and sets bit
 * 5 of register 0x9F120034. Same code as FUN_a00b1b18 with other constants.
 */
typedef unsigned int uint;

#define REG_9f100090 (*(volatile uint *)0x9f100090)
#define REG_9f120028 (*(volatile uint *)0x9f120028)
#define REG_9f120030 (*(volatile uint *)0x9f120030)
#define REG_9f120034 (*(volatile uint *)0x9f120034)
#define REG_9f120048 (*(volatile uint *)0x9f120048)
#define REG_9f120080 (*(volatile uint *)0x9f120080)

void FUN_a00b1be4(void)
{
    REG_9f120030 = REG_9f120030 | 0x20;
    REG_9f100090 = REG_9f100090 | 0x20;
    REG_9f120028 = REG_9f120028 & ~0x20;
    REG_9f120048 = REG_9f120048 & ~0x200;
    REG_9f120080 = REG_9f120080 | 0x200;
    REG_9f120048 = REG_9f120048 | 0x2000000;
    REG_9f120034 = REG_9f120034 | 0x20;
}
