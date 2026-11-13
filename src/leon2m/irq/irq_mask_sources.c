/* irq_mask_sources  (FUN_a0029968)
 *
 * Mask the given sources of interrupt level n.
 *   level: interrupt level
 *   source_mask: source bit mask
 * Note: Sets the bits in mask register 0x9F020034 + 4n.
 * Name basis: derived - counterpart of irq_unmask_sources; same register the handlers use as mask
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0029968 @ 0xa0029968-0xa0029990 (10 words), flags -mcpu=v8 -O3 -g.
 * Source form: the source mask is an unsigned short parameter, passed as both value and mask (tail call).
 */
extern void reg_write32_masked(volatile unsigned int *p, unsigned int v, unsigned int mask);

#define IRQ_MASK_BASE    0x9f020034     /* base of the per-level source mask registers (a set bit masks a source) */
#define IRQ_LEVEL_STRIDE 4              /* one 32-bit register per level */

/*
 * Mask the selected sources of an interrupt level: the bits of 'source_mask' are set in source mask register
 * 0x9F020034 + 4 * level. irq_unmask_sources clears them again.
 * Callers: fwupd_run_progress_loop, ldc_hw_enable_with_irq, input_block_power.
 */
void irq_mask_sources(int level, unsigned short source_mask)
{
    reg_write32_masked((volatile unsigned int *)(IRQ_MASK_BASE + level * IRQ_LEVEL_STRIDE), source_mask, source_mask);
}
