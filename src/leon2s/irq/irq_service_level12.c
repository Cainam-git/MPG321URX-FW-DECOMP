/* irq_service_level12  (FUN_a006102c)
 *
 * Service interrupt 12: run the handlers of its two sources and acknowledge them.
 * Note: Source bits with the upper (edge) half set are acknowledged after the handler, others before it.
 * Name basis: proven - vector table 0xA8076040 slot 11 = 0xA006102C; same mask/ack sequence as the other
 *   levels, table 0xA8079378
 *
 * Matching notes
 * --------------
 * FUN_a006102c (leon2s 0xa006102c-0xa0061138, 268 bytes), flags -mcpu=v8 -Os -g.
 * Hardware registers are volatile (the R macro); the table entry is tested and called directly (no
 * function-pointer local).
 */
/* Interrupt registers as the interrupt routines of this program use them. */
#define R(a) (*(volatile unsigned int *)(a))
#define IRQ_MASK_REG      0x9f100090            /* bit n = level n; cleared on entry to the service routine, set again on exit */
#define IRQ_CLEAR_REG     0x9f10009c            /* the level bit is written here on exit */
#define IRQ_ACTIVE_REG    0x9f120028            /* level bit set while the level's sources are served */
#define IRQ_REG_0034      0x9f120034            /* the level bit is written here on exit */
#define LEVEL12_BIT       0x1000                /* bit 12: interrupt level 12 */
#define SOURCE_STATUS_REG 0x9f12009c            /* level 12: 0x9f12006c + 4 * 12; write a source bit = acknowledge */
#define SOURCE_MASK_REG   0x9f120064            /* level 12: 0x9f120034 + 4 * 12; low half masks, high half = run handler before acknowledge */
#define LEVEL12_SOURCES   2                     /* sources 0 and 1 have a slot in irq_level12_handlers */
extern void (*irq_level12_handlers[])(void);

/*
 * Service routine of interrupt level 12 (entry 11 of the vector table at 0xA8076040).
 *
 * Takes the level out of the mask, then for each pending, unmasked source (0 or 1) that has a handler in
 * irq_level12_handlers: a source whose bit in the upper half of the mask register is set runs its handler
 * first and is acknowledged afterwards; any other source is acknowledged first. On exit the level bit is
 * written to both clear registers and the level is put back into the mask.
 */
void irq_service_level12(void)
{
    unsigned int pending;
    unsigned int handler_first;
    unsigned int source;
    unsigned int source_bit;

    R(IRQ_MASK_REG) &= ~LEVEL12_BIT;
    R(IRQ_ACTIVE_REG) |= LEVEL12_BIT;
    pending = R(SOURCE_STATUS_REG);
    pending &= ~R(SOURCE_MASK_REG);
    handler_first = R(SOURCE_MASK_REG) >> 16;
    for (source = 0; source < LEVEL12_SOURCES; source++) {
        source_bit = 1 << source;
        if (pending & source_bit) {
            if (irq_level12_handlers[source]) {
                if (handler_first & source_bit) {
                    irq_level12_handlers[source]();
                    R(SOURCE_STATUS_REG) = source_bit;
                } else {
                    R(SOURCE_STATUS_REG) = source_bit;
                    irq_level12_handlers[source]();
                }
            }
        }
    }
    R(IRQ_REG_0034) = LEVEL12_BIT;
    R(IRQ_CLEAR_REG) = LEVEL12_BIT;
    R(IRQ_ACTIVE_REG) &= ~LEVEL12_BIT;
    R(IRQ_MASK_REG) |= LEVEL12_BIT;
}
