/* irq_disable_hdmi_port1  (FUN_a00b1acc)
 *
 * Switch the interrupt sources of HDMI input 1 off.
 * Name basis: derived - read-modify-writes of the level 5 source mask 0x9F120048 (bits 7 and 23), of
 *   0x9F120080 and of 0x9F120034
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1acc @ 0xa00b1acc (-mcpu=v8 -Os -g)
 * The clear of bit 23 follows the set of bit 7 of the same register as a separate read-modify-write.
 */
typedef unsigned int uint;
#define LEVEL5_SOURCE_MASK_REG (*(volatile uint *)0x9f120048)   /* source mask of level 5 */
#define IRQ_REG_0080           (*(volatile uint *)0x9f120080)   /* purpose of this register is not shown */
#define IRQ_REG_0034           (*(volatile uint *)0x9f120034)   /* purpose of this register is not shown */

/*
 * Counterpart of irq_enable_hdmi_port1: set bit 7 and clear bit 23 of the level 5 source mask, set bit 7 of
 * IRQ_REG_0080 and bit 5 of IRQ_REG_0034.
 */
void irq_disable_hdmi_port1(void)
{
    LEVEL5_SOURCE_MASK_REG = LEVEL5_SOURCE_MASK_REG | 0x80;
    LEVEL5_SOURCE_MASK_REG = LEVEL5_SOURCE_MASK_REG & 0xff7fffff;
    IRQ_REG_0080 = IRQ_REG_0080 | 0x80;
    IRQ_REG_0034 = IRQ_REG_0034 | 0x20;
    return;
}
