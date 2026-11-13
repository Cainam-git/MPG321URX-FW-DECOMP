/* irq_service_level5  (FUN_a0029df4)
 *
 * Run and acknowledge the registered handlers of pending level-5 interrupt sources.
 * Note: Status 0x9F020080, mask 0x9F020048 (upper half: run handler before the ack), 16 source(s), handlers at
 *   0xA802B170 row 5.
 * Name basis: proven - entry 4 of handler table 0xA8027B50 (trap type 0x15)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0029df4 @ 0xa0029df4-0xa0029f14 (72 words), flags -mcpu=v8 -O3 -g -msoft-float (plain -O3 -g
 * does not build these bytes). The same source as irq_service_level1, with this level's constants.
 * Source form: the hook table is a constant pointer indexed by source + HOOK_ROW.
 */
extern unsigned int reg_read32(unsigned int addr);
extern void reg_write32(unsigned int addr, unsigned int value);
extern void reg_write32_masked(volatile unsigned int *p, unsigned int v, unsigned int mask);

#define IRQ_MASK_REG     0x9f000090     /* LEON2 interrupt mask register: bit n enables interrupt level n */
#define IRQ_CLEAR_REG    0x9f00009c     /* LEON2 interrupt clear register */
#define IRQ_ACTIVE_REG   0x9f020028     /* the level's bit is set here while its sources are served */
#define IRQ_REG_0034     0x9f020034     /* the level's bit is written here when it is done */
#define IRQ_SOURCE_HOOKS 0xa802b170     /* irq_source_hooks: 16 handler words per level (irq_set_source_handler) */

/* This level. */
#define LEVEL_BIT         0x20          /* level 5 */
#define SOURCE_STATUS_REG 0x9f020080    /* 0x9F02006C + 4 * level: pending sources; writing a bit acknowledges it */
#define SOURCE_MASK_REG   0x9f020048    /* 0x9F020034 + 4 * level: low half masks sources, high half = call the
                                           handler before the acknowledge */
#define HOOK_ROW          0x50          /* level * 16 */
#define LAST_SOURCE       15            /* sources 0..15 */

/*
 * Service routine of interrupt level 5 (entry 4 of the interrupt level table, called by irq_dispatch).
 * Registered source handlers: sys_latch_unit_event_ch0 .. ch3 (sources 0..3), sys_latch_unit_event_ch6
 * (source 12), ch7 (source 13) and ch4 (source 14).
 *
 * Works like irq_service_level1: the level is disabled while it runs; each pending, unmasked source with a
 * handler gets its handler called and its status bit acknowledged (after the handler when its bit in the high
 * half of the mask register is set, before it otherwise); then the level bit goes to 0x9F020034 and to the
 * interrupt clear register and the level is enabled again.
 */
void irq_service_level5(void)
{
    unsigned int status, source_mask, pending, handler_first;
    unsigned int *hooks;
    unsigned int source;

    reg_write32_masked((volatile unsigned int *)IRQ_MASK_REG, 0, LEVEL_BIT);
    reg_write32_masked((volatile unsigned int *)IRQ_ACTIVE_REG, LEVEL_BIT, LEVEL_BIT);

    status = reg_read32(SOURCE_STATUS_REG);
    source_mask = reg_read32(SOURCE_MASK_REG);
    pending = status & ~source_mask;
    pending &= 0xffff;
    handler_first = (source_mask >> 16) & 0xffff;

    hooks = (unsigned int *)IRQ_SOURCE_HOOKS;
    source = 0;
    do {
        unsigned int source_bit = 1 << source;
        if ((source_bit & pending) != 0) {
            if (hooks[source + HOOK_ROW] != 0) {
                if ((source_bit & handler_first) != 0) {
                    ((void (*)(void))hooks[source + HOOK_ROW])();
                    reg_write32(SOURCE_STATUS_REG, source_bit);
                } else {
                    reg_write32(SOURCE_STATUS_REG, source_bit);
                    ((void (*)(void))hooks[source + HOOK_ROW])();
                }
            }
        }
        source++;
    } while (source <= LAST_SOURCE);

    reg_write32(IRQ_REG_0034, LEVEL_BIT);
    reg_write32(IRQ_CLEAR_REG, LEVEL_BIT);
    reg_write32_masked((volatile unsigned int *)IRQ_ACTIVE_REG, 0, LEVEL_BIT);
    reg_write32_masked((volatile unsigned int *)IRQ_MASK_REG, LEVEL_BIT, LEVEL_BIT);
}
