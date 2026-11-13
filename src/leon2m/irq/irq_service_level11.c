/* irq_service_level11  (FUN_a002a45c)
 *
 * Acknowledge interrupt level 11 (no source handlers)
 * Note: Masks level 11 in 0x9F000090, sets its bit in 0x9F020028, writes the word 0x800 to 0x9F020034 and
 *   0x9F00009C, clears the bit in 0x9F020028, unmasks.
 * Name basis: proven - entry 10 of handler table 0xA8027B50 (trap type 0x1B)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002a45c @ 0xa002a45c, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: reg_write32 and reg_write32_masked are declared without a prototype and get the register
 * addresses as plain numbers.
 */
extern void reg_write32();
extern void reg_write32_masked();

#define IRQ_MASK_REG     0x9f000090     /* LEON2 interrupt mask register: bit n enables interrupt level n */
#define IRQ_CLEAR_REG    0x9f00009c     /* LEON2 interrupt clear register */
#define IRQ_ACTIVE_REG   0x9f020028     /* the level's bit is set here while it is served */
#define IRQ_REG_0034     0x9f020034     /* the level's bit is written here when it is done */
#define LEVEL_BIT        0x800          /* level 11 */

/*
 * Service routine of interrupt level 11 (entry 10 of the interrupt level table, called by irq_dispatch).
 * The same frame as the other level handlers, without the source loop: no source handler is called and no
 * source status is acknowledged here.
 */
void irq_service_level11(void)
{
  reg_write32_masked(IRQ_MASK_REG, 0, LEVEL_BIT);
  reg_write32_masked(IRQ_ACTIVE_REG, LEVEL_BIT, LEVEL_BIT);
  reg_write32(IRQ_REG_0034, LEVEL_BIT);
  reg_write32(IRQ_CLEAR_REG, LEVEL_BIT);
  reg_write32_masked(IRQ_ACTIVE_REG, 0, LEVEL_BIT);
  reg_write32_masked(IRQ_MASK_REG, LEVEL_BIT, LEVEL_BIT);
}