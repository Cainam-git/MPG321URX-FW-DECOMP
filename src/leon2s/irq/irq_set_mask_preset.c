/* irq_set_mask_preset  (FUN_a00b1fe0)
 *
 * Write one of two value sets to the interrupt mask registers.
 * Name basis: descriptive - set by a command from the main processor
 *
 * Matching notes
 * --------------
 * FUN_a00b1fe0 (leon2s 0xa00b1fe0-0xa00b2064, 132 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the "on" branch writes the first three registers twice, as in the firmware.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define IRQ_MASK_REG    0x9f100090      /* bit n = interrupt level n */
#define IRQ_ACTIVE_REG  0x9f120028      /* level bit set while its sources are served */
#define IRQ_REG_0044    0x9f120044      /* purpose of these two registers is not shown */
#define IRQ_REG_0038    0x9f120038

/*
 * on != 0: write the "on" values 0x10 / 0xffef / 0xfffd / 0xffff to the mask, active, 0044 and 0038 registers
 * and then the first three again. on == 0: write 0 to the mask register and 0xffff to the other three.
 * The command handler (ipc_dispatch_command) calls it with 1 before it powers off the receivers and with 0 after it,
 * in the two power-down commands.
 */
void irq_set_mask_preset(unsigned char on)
{
    if (on != 0) {
        R(IRQ_MASK_REG) = 0x10;
        R(IRQ_ACTIVE_REG) = 0xffef;
        R(IRQ_REG_0044) = 0xfffd;
        R(IRQ_REG_0038) = 0xffff;
        R(IRQ_MASK_REG) = 0x10;
        R(IRQ_ACTIVE_REG) = 0xffef;
        R(IRQ_REG_0044) = 0xfffd;
    } else {
        R(IRQ_MASK_REG) = 0;
        R(IRQ_ACTIVE_REG) = 0xffff;
        R(IRQ_REG_0044) = 0xffff;
        R(IRQ_REG_0038) = 0xffff;
    }
}
