/* leon2s FUN_a00b1c64 @ 0xa00b1c64 (-mcpu=v8 -Os -g)
 * Four separate read-modify-writes of volatile registers: 0x9F120048 |= bit 9, 0x9F120048 &= ~bit 25, 0x9F120080
 * |= bit 9, 0x9F120034 |= bit 5.
 */
typedef unsigned int uint;
#define REG_9f120048 (*(volatile uint *)0x9f120048)
#define REG_9f120080 (*(volatile uint *)0x9f120080)
#define REG_9f120034 (*(volatile uint *)0x9f120034)

void FUN_a00b1c64(void)
{
    REG_9f120048 = REG_9f120048 | 0x200;
    REG_9f120048 = REG_9f120048 & 0xfdffffff;
    REG_9f120080 = REG_9f120080 | 0x200;
    REG_9f120034 = REG_9f120034 | 0x20;
    return;
}
