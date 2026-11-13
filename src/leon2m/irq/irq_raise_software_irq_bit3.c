/* irq_raise_software_irq_bit3  (FUN_a00deb80)
 *
 * Write 8 (bit 3) to the software interrupt register 0x9F120024.
 * Note: Called only by sys_set_c940_bit2_and_notify, which no routine calls; who takes this interrupt bit is
 *   not shown.
 * Name basis: descriptive - reg_write32(0x9F120024, 8); the bit 0 routine of the same register is used after a
 *   mailbox command is placed
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00deb80 @ 0xa00deb80, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the register write is a call to the RAM register-write helper (reg_write32) with the
 * address and the value as plain constants.
 */
extern int reg_write32();

/* Register 0x9F120024: each irq_raise_software_irq_bit<n> routine writes 1 << n to it. */
#define SOFTWARE_IRQ_REG  0x9f120024
#define SOFTWARE_IRQ_BIT3 8             /* 1 << 3 */

/*
 * Write 1 << 3 to the software interrupt register.
 * Called by sys_set_c940_bit2_and_notify after it has changed bit 2 of register 0xCF03C940.
 */
void irq_raise_software_irq_bit3(void)

{
  reg_write32(SOFTWARE_IRQ_REG,SOFTWARE_IRQ_BIT3);
  return;
}
