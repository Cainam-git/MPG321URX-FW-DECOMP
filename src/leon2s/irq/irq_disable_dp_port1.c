/* irq_disable_dp_port1  (FUN_a00b1c64)
 *
 * Switch the interrupt sources of DisplayPort input 1 off.
 * Name basis: derived - read-modify-writes of the level 5 source mask 0x9F120048 (bits 9 and 25), of
 *   0x9F120080 and of 0x9F120034
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1c64 @ 0xa00b1c64 (-mcpu=v8 -Os -g)
 * Four separate read-modify-writes of volatile registers.
 */
typedef unsigned int uint;
#define LEVEL5_SOURCE_MASK_REG (*(volatile uint *)0x9f120048)   /* source mask of level 5 */
#define IRQ_REG_0080           (*(volatile uint *)0x9f120080)   /* purpose of this register is not shown */
#define IRQ_REG_0034           (*(volatile uint *)0x9f120034)   /* purpose of this register is not shown */

/*
 * Counterpart of irq_enable_dp_port1: set bit 9 and clear bit 25 of the level 5 source mask, set bit 9 of
 * IRQ_REG_0080 and bit 5 of IRQ_REG_0034.
 */
void irq_disable_dp_port1(void)
{
    LEVEL5_SOURCE_MASK_REG = LEVEL5_SOURCE_MASK_REG | 0x200;
    LEVEL5_SOURCE_MASK_REG = LEVEL5_SOURCE_MASK_REG & 0xfdffffff;
    IRQ_REG_0080 = IRQ_REG_0080 | 0x200;
    IRQ_REG_0034 = IRQ_REG_0034 | 0x20;
    return;
}
