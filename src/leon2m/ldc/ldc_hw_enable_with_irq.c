/* ldc_hw_enable_with_irq  (FUN_a00fbf5c)
 *
 * Switch the grid block on or off together with its interrupt source.
 * Name basis: derived - bit 31 of 0xD0040000; irq_set_source_handler and irq_unmask_sources / irq_mask_sources
 *   for source 0xC / 0x100
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fbf5c, flags -mcpu=v8 -O3 -g.
 * The firmware leaves the (byte-extended) parameter in %i0, so the function is written as returning on; each arm
 * has its own return (one return after the if/else schedules the 0x100 argument differently).
 */

/* Interrupt level and source mask of the grid block's interrupt. */
#define LDC_IRQ_LEVEL  0xc
#define LDC_IRQ_SOURCE 0x100

extern unsigned char ldc_hw_mode3_pass_entry[];
extern void irq_set_source_handler(int, int, int);
extern void irq_unmask_sources(int, int);
extern void irq_mask_sources(int, int);

/*
 * Switch the grid block on (on == 1) or off (any other value). On: set the enable bit (bit 31 of the control
 * register 0xD0040000), register ldc_hw_mode3_pass_entry as the handler of the block's interrupt source and unmask
 * it. Off: clear the enable bit and mask the source. Returns on. Called by ldc_hw_api_set_enable_mode.
 */
unsigned char ldc_hw_enable_with_irq(unsigned char on)
{
    if (on == 1) {
        *(volatile unsigned int *)0xd0040000 |= 0x80000000;
        irq_set_source_handler(LDC_IRQ_LEVEL, LDC_IRQ_SOURCE, ldc_hw_mode3_pass_entry);
        irq_unmask_sources(LDC_IRQ_LEVEL, LDC_IRQ_SOURCE);
        return on;
    } else {
        *(volatile unsigned int *)0xd0040000 &= ~0x80000000;
        irq_mask_sources(LDC_IRQ_LEVEL, LDC_IRQ_SOURCE);
        return on;
    }
}
