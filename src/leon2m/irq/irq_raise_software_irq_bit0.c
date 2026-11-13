/* irq_raise_software_irq_bit0  (FUN_a00de970)
 *
 * Raise software interrupt bit 0 for the other side.
 * Name basis: descriptive - reg_write32(0x9F120024, 1); used after a command is placed in the mailbox
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de970 @ 0xa00de970, flags -mcpu=v8 -O2 -g.
 * Source form: the call is followed by an explicit 'return;', and a blank line separates the header from the
 * brace.
 */

#define SOFTWARE_IRQ_REG  0x9f120024    /* writing 1 << n raises software interrupt bit n */

extern int reg_write32();

/*
 * Write 1 to the software interrupt register, which raises software interrupt bit 0.
 * Called from ipc_send_command and ipc_send_command_nop_wait right after the command is written into the mailbox.
 */
void irq_raise_software_irq_bit0(void)

{
  reg_write32(SOFTWARE_IRQ_REG,1);
  return;
}
