/* leon2s FUN_a00b1980 @ 0xa00b1980 (-mcpu=v8 -Os -g)
 * Read-modify-writes, in this order: 0x9F120030 |= 0x20, 0x9F100090 |= 0x20, 0x9F120028 &= ~0x20,
 * 0x9F120048 &= ~0x40, 0x9F120080 |= 0x40, 0x9F120048 |= 0x400000, 0x9F120034 |= 0x20. The two accesses to
 * 0x9F120048 are separate read-modify-writes in the firmware and are written as two statements.
 */
typedef unsigned int uint;
#define REG_9f120030 (*(volatile uint *)0x9f120030)
#define REG_9f100090 (*(volatile uint *)0x9f100090)
#define REG_9f120028 (*(volatile uint *)0x9f120028)
#define REG_9f120048 (*(volatile uint *)0x9f120048)
#define REG_9f120080 (*(volatile uint *)0x9f120080)
#define REG_9f120034 (*(volatile uint *)0x9f120034)

void FUN_a00b1980(void)
{
    REG_9f120030 = REG_9f120030 | 0x20;
    REG_9f100090 = REG_9f100090 | 0x20;
    REG_9f120028 = REG_9f120028 & 0xffffffdf;
    REG_9f120048 = REG_9f120048 & 0xffffffbf;
    REG_9f120080 = REG_9f120080 | 0x40;
    REG_9f120048 = REG_9f120048 | 0x400000;
    REG_9f120034 = REG_9f120034 | 0x20;
}
