/* irq_disable_hdmi_port0  (FUN_a00b1a00)
 *
 * Switch the interrupt sources of HDMI input 0 off.
 * Name basis: derived - read-modify-writes of the level 5 source mask 0x9F120048 (bits 6 and 22), of
 *   0x9F120080 and of 0x9F120034
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1a00 @ 0xa00b1a00 (-mcpu=v8 -Os -g)
 * The two accesses to 0x9F120048 are separate read-modify-writes. Same code as irq_disable_dp_port0 with other
 * constants.
 */
#define LEVEL5_SOURCE_MASK_REG (*(volatile unsigned int *)0x9f120048)   /* source mask of level 5 */
#define IRQ_REG_0080           (*(volatile unsigned int *)0x9f120080)   /* purpose of this register is not shown */
#define IRQ_REG_0034           (*(volatile unsigned int *)0x9f120034)   /* purpose of this register is not shown */

/*
 * Counterpart of irq_enable_hdmi_port0: set bit 6 and clear bit 22 of the level 5 source mask, set bit 6 of
 * IRQ_REG_0080 and bit 5 of IRQ_REG_0034.
 */
void irq_disable_hdmi_port0(void)
{
  LEVEL5_SOURCE_MASK_REG = LEVEL5_SOURCE_MASK_REG | 0x40;
  LEVEL5_SOURCE_MASK_REG = LEVEL5_SOURCE_MASK_REG & ~0x400000;
  IRQ_REG_0080 = IRQ_REG_0080 | 0x40;
  IRQ_REG_0034 = IRQ_REG_0034 | 0x20;
}
