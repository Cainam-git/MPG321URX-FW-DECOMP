/* leon2s FUN_a00b1a4c @ 0xa00b1a4c (-mcpu=v8 -Os -g)
 * Read-modify-write sequence on volatile 32-bit registers: sets bit 5 (0x20) of 0x9F120030 and 0x9F100090; clears
 * bit 5 of 0x9F120028; clears bit 7 (0x80) of 0x9F120048; sets bit 7 of 0x9F120080; sets bit 23 (0x800000) of
 * 0x9F120048; sets bit 5 of 0x9F120034. The two operations on 0x9F120048 are separate load-modify-store sequences.
 */
typedef unsigned int uint;

#define REG_9f120030 (*(volatile uint *)0x9f120030)
#define REG_9f100090 (*(volatile uint *)0x9f100090)
#define REG_9f120028 (*(volatile uint *)0x9f120028)
#define REG_9f120048 (*(volatile uint *)0x9f120048)
#define REG_9f120080 (*(volatile uint *)0x9f120080)
#define REG_9f120034 (*(volatile uint *)0x9f120034)

void FUN_a00b1a4c(void)
{
    REG_9f120030 = REG_9f120030 | 0x20;
    REG_9f100090 = REG_9f100090 | 0x20;
    REG_9f120028 = REG_9f120028 & 0xffffffdf;
    REG_9f120048 = REG_9f120048 & 0xffffff7f;
    REG_9f120080 = REG_9f120080 | 0x80;
    REG_9f120048 = REG_9f120048 | 0x800000;
    REG_9f120034 = REG_9f120034 | 0x20;
}
