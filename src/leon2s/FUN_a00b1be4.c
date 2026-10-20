/* leon2s FUN_a00b1be4 @ 0xa00b1be4  MATCH (-mcpu=v8 -Os -g, twin)
 * Twin of FUN_a00b1b18: same code, constants swapped; byte-exact.
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
