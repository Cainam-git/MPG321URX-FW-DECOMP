/* irq_raise_software_irq_bit1  (FUN_a00b1948)
 *
 * Raise software interrupt bit 1 for the main processor.
 * Name basis: descriptive - write of 2 to core register 0x9F020024
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1948 @ 0xa00b1948 (-mcpu=v8 -Os -g)
 * Source form: the register write goes through reg_write32_copy, declared without a prototype.
 */
extern int reg_write32_copy();

#define SOFTWARE_IRQ_REG 0x9f020024     /* same register as irq_raise_software_irq_bit0 */
#define SOFTWARE_IRQ_BIT1 2

/*
 * Write 2 (bit 1) to SOFTWARE_IRQ_REG. Called from the HDMI 2.1 receiver event code when a port's
 * mode-change signal is set in the shared status word.
 */
void irq_raise_software_irq_bit1(void)

{
  reg_write32_copy(SOFTWARE_IRQ_REG,SOFTWARE_IRQ_BIT1);
  return;
}
