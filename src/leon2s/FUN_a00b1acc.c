/* leon2s FUN_a00b1acc @ 0xa00b1acc  MATCH (-mcpu=v8 -Os -g)
 * The function sets a bit (0x80) in three different registers and clears bit 0x800000 in the first register. The order of operations matters: the clear on 0x9f120048 comes immediately after the set on the same register, before moving to the other registers.
 */
typedef unsigned int uint;
#define REG_9f120048 (*(volatile uint *)0x9f120048)
#define REG_9f120080 (*(volatile uint *)0x9f120080)
#define REG_9f120034 (*(volatile uint *)0x9f120034)

void FUN_a00b1acc(void)
{
    REG_9f120048 = REG_9f120048 | 0x80;
    REG_9f120048 = REG_9f120048 & 0xff7fffff;
    REG_9f120080 = REG_9f120080 | 0x80;
    REG_9f120034 = REG_9f120034 | 0x20;
    return;
}
