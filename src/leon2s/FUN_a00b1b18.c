/* leon2s FUN_a00b1b18 @ 0xa00b1b18 (-mcpu=v8 -Os -g)
 * Read-modify-write sequence on volatile 32-bit registers (full-word ld / st): sets bit 5 (0x20) of 0x9F120030
 * and 0x9F100090; clears bit 5 of 0x9F120028; clears bit 8 (0x100) of 0x9F120048; sets bit 8 of 0x9F120080; sets
 * bit 24 (0x1000000) of 0x9F120048; sets bit 5 of 0x9F120034. Same shape as FUN_a00b1a4c with other bits.
 */
typedef unsigned int uint;

#define REG_9f100090 (*(volatile uint *)0x9f100090)
#define REG_9f120028 (*(volatile uint *)0x9f120028)
#define REG_9f120030 (*(volatile uint *)0x9f120030)
#define REG_9f120034 (*(volatile uint *)0x9f120034)
#define REG_9f120048 (*(volatile uint *)0x9f120048)
#define REG_9f120080 (*(volatile uint *)0x9f120080)

void FUN_a00b1b18(void)
{
    REG_9f120030 = REG_9f120030 | 0x20;
    REG_9f100090 = REG_9f100090 | 0x20;
    REG_9f120028 = REG_9f120028 & ~0x20;
    REG_9f120048 = REG_9f120048 & ~0x100;
    REG_9f120080 = REG_9f120080 | 0x100;
    REG_9f120048 = REG_9f120048 | 0x1000000;
    REG_9f120034 = REG_9f120034 | 0x20;
}
