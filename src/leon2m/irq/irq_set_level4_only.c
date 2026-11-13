/* irq_set_level4_only  (FUN_a002992c)
 *
 * Enable only interrupt level 4 when on, otherwise disable all levels.
 *   level4_on: non-zero = enable level 4
 * Note: Overwrites the whole LEON2 interrupt mask register 0x9F000090.
 * Name basis: derived - writes 0x10 / 0 to the LEON2 interrupt mask register
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002992c @ 0xa002992c-0xa0029964 (14 words), flags -mcpu=v8 -O3 -g.
 * Source form: each arm has its own reg_write32 call (both are tail calls).
 */
extern void reg_write32(unsigned int addr, unsigned int value);

#define IRQ_MASK_REG     0x9f000090     /* LEON2 interrupt mask register: bit n = interrupt level n */
#define IRQ_LEVEL4_BIT   0x10           /* level 4; its source handlers include timer_tick_isr and uart_rx_isr */

/*
 * Write the whole interrupt mask register: only level 4 enabled when 'level4_on' is non-zero, no level at
 * all otherwise. Called by SYSAPI_PowerOff and SYSAPI_PowerSaving.
 */
void irq_set_level4_only(unsigned char level4_on)
{
    if (level4_on != 0) {
        reg_write32(IRQ_MASK_REG, IRQ_LEVEL4_BIT);
        return;
    }
    reg_write32(IRQ_MASK_REG, 0);
}
