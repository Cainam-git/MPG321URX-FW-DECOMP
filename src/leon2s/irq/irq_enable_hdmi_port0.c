/* irq_enable_hdmi_port0  (FUN_a00b1980)
 *
 * Switch the interrupt sources of HDMI input 0 on.
 * Name basis: derived - read-modify-writes of the interrupt mask and clear registers at 0x9F100090 and
 *   0x9F1200xx
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1980 @ 0xa00b1980 (-mcpu=v8 -Os -g)
 * The two accesses to the level 5 source mask are separate read-modify-writes in the firmware and are written as
 * two statements, in this order.
 */
typedef unsigned int uint;
#define IRQ_REG_0030          (*(volatile uint *)0x9f120030)    /* purpose of this register is not shown */
#define IRQ_MASK_REG          (*(volatile uint *)0x9f100090)    /* bit n = interrupt level n */
#define IRQ_ACTIVE_REG        (*(volatile uint *)0x9f120028)    /* level bit set while its sources are served */
#define LEVEL5_SOURCE_MASK_REG (*(volatile uint *)0x9f120048)   /* source mask of level 5 (0x9f120034 + 4 * 5) */
#define IRQ_REG_0080          (*(volatile uint *)0x9f120080)    /* purpose of this register is not shown */
#define IRQ_REG_0034          (*(volatile uint *)0x9f120034)    /* purpose of this register is not shown */

#define LEVEL5_BIT            0x20      /* interrupt level 5, in the three registers above */
#define HDMI0_SOURCE_BIT      0x40      /* bit 6: HDMI input 0 */
#define HDMI0_SOURCE_BIT_HI   0x400000  /* bit 22 of the level 5 source mask: set after the bit 6 step */

/*
 * Turn on the interrupt of HDMI input 0 (level 5): set LEVEL5_BIT in IRQ_REG_0030 and in the mask register,
 * clear it in the active register, clear bit 6 and later set bit 22 of the level 5 source mask, set bit 6 of
 * IRQ_REG_0080 and LEVEL5_BIT in IRQ_REG_0034. Called by _hdmi_Init_Interrupt; the second input is
 * irq_enable_hdmi_port1.
 */
void irq_enable_hdmi_port0(void)
{
    IRQ_REG_0030 = IRQ_REG_0030 | LEVEL5_BIT;
    IRQ_MASK_REG = IRQ_MASK_REG | LEVEL5_BIT;
    IRQ_ACTIVE_REG = IRQ_ACTIVE_REG & 0xffffffdf;
    LEVEL5_SOURCE_MASK_REG = LEVEL5_SOURCE_MASK_REG & 0xffffffbf;
    IRQ_REG_0080 = IRQ_REG_0080 | HDMI0_SOURCE_BIT;
    LEVEL5_SOURCE_MASK_REG = LEVEL5_SOURCE_MASK_REG | HDMI0_SOURCE_BIT_HI;
    IRQ_REG_0034 = IRQ_REG_0034 | LEVEL5_BIT;
}
