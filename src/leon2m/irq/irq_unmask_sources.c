/* irq_unmask_sources  (FUN_a0029820)
 *
 * Unmask the given sources of interrupt level n and clear their pending bits.
 *   level: interrupt level
 *   source_mask: source bit mask
 * Note: Mask register 0x9F020034 + 4n, status register 0x9F02006C + 4n (as read by the level handlers).
 * Name basis: derived - register pair matches the level handlers' status/mask registers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0029820 @ 0xa0029820-0xa0029858 (14 words).
 * Source form: the second reg_write32 call is the last statement, so it is the tail call.
 * Source form: the address arithmetic is base + level * 4; the macros expand to the original constants.
 */
extern void reg_write32(unsigned int addr, unsigned int value);
extern void reg_write32_masked(volatile unsigned int *p, unsigned int v, unsigned int mask);

#define IRQ_MASK_BASE   0x9f020034   /* base of the per-level mask registers (a set bit masks a source) */
#define IRQ_STATUS_BASE 0x9f02006c   /* base of the per-level status registers (written to clear) */
#define IRQ_LEVEL_STRIDE 4           /* one 32-bit register per level */

/*
 * Unmask the selected sources of an interrupt level, then clear their pending bits.
 * level is the interrupt level; source_mask selects the sources within that level.
 * The mask bits of the sources are cleared in mask register 0x9F020034 + 4 * level, then source_mask is written
 * to status register 0x9F02006C + 4 * level.
 *
 * Callers: System_Initialize, timer_init, input_blocks_init, ldc_hw_enable_with_irq, ldc_hw_start,
 * ldc_hw_setup_for_panel_size, fwupd_run_progress_loop; irq_init_controller has its own inlined copy.
 */
void irq_unmask_sources(int level, unsigned short source_mask)
{
    reg_write32_masked((volatile unsigned int *)(IRQ_MASK_BASE + level * IRQ_LEVEL_STRIDE), 0, source_mask);
    reg_write32(IRQ_STATUS_BASE + level * IRQ_LEVEL_STRIDE, source_mask);
}
