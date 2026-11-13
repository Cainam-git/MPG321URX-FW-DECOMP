/* irq_service_level15  (FUN_a002a84c)
 *
 * Acknowledge interrupt level 15 (no source handlers)
 * Note: Writes the whole word 0x8000 to 0x9F020034 and to the LEON2 clear register 0x9F00009C (plain stores,
 *   no read first).
 * Name basis: proven - entry 14 of handler table 0xA8027B50 (trap type 0x1F)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002a84c @ 0xa002a84c, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: reg_write32 is declared without a prototype; the second call passes the routine's parameters
 * 3..6 on unchanged (the firmware never touches %i2..%i5, which the restore of the tail call hands on as
 * %o2..%o5).
 */
extern int reg_write32();

#define IRQ_CLEAR_REG    0x9f00009c     /* LEON2 interrupt clear register */
#define IRQ_REG_0034     0x9f020034     /* the level's bit is written here when it is done */
#define LEVEL_BIT        0x8000         /* level 15 */

/*
 * Service routine of interrupt level 15 (entry 14 of the interrupt level table, called by irq_dispatch).
 * Unlike the other levels it neither disables the level nor looks at sources: it only writes the level bit
 * to 0x9F020034 and to the interrupt clear register. The parameters are not used (see the matching notes).
 */
void irq_service_level15(unsigned int unused_1, unsigned int unused_2, unsigned int pass_3, unsigned int pass_4,
                 unsigned int pass_5, unsigned int pass_6)
{
  reg_write32(IRQ_REG_0034, LEVEL_BIT);
  reg_write32(IRQ_CLEAR_REG, LEVEL_BIT, pass_3, pass_4, pass_5, pass_6);
}