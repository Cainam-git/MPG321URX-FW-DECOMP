/* irq_set_source_handler  (FUN_a002a880)
 *
 * Register handler v for the lowest source bit in mask of interrupt level i.
 *   level: interrupt level row (< 15)
 *   source_bits: source bit (lowest set bit used)
 *   handler: handler address
 * Note: Ignored when the bit is beyond the level's source count (byte table 0x199278).
 * Name basis: proven - fills the hook table 0xA802B170 the level handlers call
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002a880 @ 0xa002a880-0xa002a910 (36 words), flags -mcpu=v8 -O3 -g.
 * Source form: the bit search is a for loop with an unsigned short counter and a break; the three checks
 * after it are separate early returns.
 */
extern const unsigned char irq_level_source_counts[];
extern unsigned int irq_source_hooks[15][16];

#define IRQ_SOURCES_PER_LEVEL 16        /* handler words per level in irq_source_hooks */
#define IRQ_LEVEL_ROWS        15        /* rows of irq_source_hooks */

/*
 * Register 'handler' for one interrupt source: the lowest set bit of 'source_bits' picks the source within
 * row 'level' of irq_source_hooks, which irq_service_level<level> calls when that source is pending.
 * Nothing is stored when 'source_bits' is 0, when 'level' is 15 or more, or when the source number is not
 * below the level's entry in irq_level_source_counts.
 *
 * Callers (level, bits): startup_init_core and sys_core_setup_unit_0320 (1, 0x10), System_Initialize (1, 1 and
 * 2), timer_init (4, 1 and 0x10), uart_init (4, 0x20), input_blocks_init (5, seven sources) and
 * ldc_hw_enable_with_irq / ldc_hw_start / ldc_hw_setup_for_panel_size (12, 0x100).
 */
void irq_set_source_handler(unsigned int level, unsigned short source_bits, unsigned int handler)
{
    unsigned short source;

    /* Lowest set bit; IRQ_SOURCES_PER_LEVEL when there is none. */
    for (source = 0; source < IRQ_SOURCES_PER_LEVEL; source++)
        if ((source_bits >> source) & 1)
            break;
    if (source == IRQ_SOURCES_PER_LEVEL)
        return;
    if (level >= IRQ_LEVEL_ROWS)
        return;
    if (source >= irq_level_source_counts[level])
        return;
    irq_source_hooks[level][source] = handler;
}
