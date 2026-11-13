/* irq_raise_software_irq_bit3  (FUN_a00b1964)
 *
 * Raise software interrupt bit 3 for the main processor.
 * Name basis: descriptive - write of 8 to core register 0x9F020024
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1964 @ 0xa00b1964 (-mcpu=v8 -Os -g)
 * Source form: the register write goes through reg_write32_copy, declared without a prototype.
 */
extern int reg_write32_copy();

#define SOFTWARE_IRQ_REG 0x9f020024     /* same register as irq_raise_software_irq_bit0 */
#define SOFTWARE_IRQ_BIT3 8

/*
 * Write 8 (bit 3) to SOFTWARE_IRQ_REG. Called from the DisplayPort input code after it has set the port's
 * event bit.
 */
void irq_raise_software_irq_bit3(void)

{
  reg_write32_copy(SOFTWARE_IRQ_REG,SOFTWARE_IRQ_BIT3);
  return;
}
