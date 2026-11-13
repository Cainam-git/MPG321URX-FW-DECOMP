/* irq_enable_dp_port0  (FUN_a00b1b18)
 *
 * Switch the interrupt sources of DisplayPort input 0 on.
 * Name basis: derived - read-modify-writes of the interrupt mask and clear registers at 0x9F100090 and
 *   0x9F1200xx
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1b18 @ 0xa00b1b18 (-mcpu=v8 -Os -g)
 * Full-word loads and stores; the two accesses to the level 5 source mask are separate read-modify-writes.
 */
typedef unsigned int uint;

#define IRQ_MASK_REG           (*(volatile uint *)0x9f100090)   /* bit n = interrupt level n */
#define IRQ_ACTIVE_REG         (*(volatile uint *)0x9f120028)   /* level bit set while its sources are served */
#define IRQ_REG_0030           (*(volatile uint *)0x9f120030)   /* purpose of this register is not shown */
#define IRQ_REG_0034           (*(volatile uint *)0x9f120034)   /* purpose of this register is not shown */
#define LEVEL5_SOURCE_MASK_REG (*(volatile uint *)0x9f120048)   /* source mask of level 5 (0x9f120034 + 4 * 5) */
#define IRQ_REG_0080           (*(volatile uint *)0x9f120080)   /* purpose of this register is not shown */

#define LEVEL5_BIT             0x20     /* interrupt level 5, in the registers above */
#define DP0_SOURCE_BIT         0x100    /* bit 8: DisplayPort input 0 */
#define DP0_SOURCE_BIT_HI      0x1000000 /* bit 24 of the level 5 source mask: set after the bit 8 step */

/*
 * Same steps as irq_enable_hdmi_port0 with the bits of DisplayPort input 0 (bit 8 and bit 24).
 */
void irq_enable_dp_port0(void)
{
    IRQ_REG_0030 = IRQ_REG_0030 | LEVEL5_BIT;
    IRQ_MASK_REG = IRQ_MASK_REG | LEVEL5_BIT;
    IRQ_ACTIVE_REG = IRQ_ACTIVE_REG & ~LEVEL5_BIT;
    LEVEL5_SOURCE_MASK_REG = LEVEL5_SOURCE_MASK_REG & ~DP0_SOURCE_BIT;
    IRQ_REG_0080 = IRQ_REG_0080 | DP0_SOURCE_BIT;
    LEVEL5_SOURCE_MASK_REG = LEVEL5_SOURCE_MASK_REG | DP0_SOURCE_BIT_HI;
    IRQ_REG_0034 = IRQ_REG_0034 | LEVEL5_BIT;
}
