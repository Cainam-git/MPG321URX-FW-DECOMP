/* ldc_hw_suspend_or_resume  (FUN_a00fbaa4)
 *
 * Save and clear the block's enable bit, or restore it.
 * Returns: 1
 * Name basis: descriptive - bit 31 of 0xD0040000 kept at 0xA802B7E8; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fbaa4, flags -mcpu=v8 -O3 -g.
 * Source form: a static field-write helper wr(reg, mask, shift, val) ('*r = (*r & ~mask) | ((val << shift) &
 * mask)') inlined; it keeps the 'and' with the sethi'd mask after the shift.
 */

/* Control register of the grid block; bit 31 is its enable bit. */
#define LDC_REG_CTRL    (*(volatile unsigned int *)0xd0040000)
#define LDC_ENABLE_BIT  0x80000000

extern unsigned char ldc_saved_enable_bit;

/* Replace the bits of *reg selected by mask with val shifted left by shift. */
static void wr(volatile unsigned int *reg, unsigned int mask, unsigned int shift, unsigned int val)
{
    *reg = (*reg & ~mask) | ((val << shift) & mask);
}

/*
 * Suspend (suspend nonzero) or resume (suspend 0) the grid block. Suspending keeps the enable bit in
 * ldc_saved_enable_bit and clears it; resuming writes the kept bit back. Always returns 1.
 * No routine calls this copy; ldc_hw_command has the same code inline for its suspend command.
 */
int ldc_hw_suspend_or_resume(unsigned char suspend)
{
    if (suspend) {
        unsigned int ctrl = LDC_REG_CTRL;
        ldc_saved_enable_bit = ctrl >> 31;
        LDC_REG_CTRL = ctrl & ~LDC_ENABLE_BIT;
    } else
        wr(&LDC_REG_CTRL, LDC_ENABLE_BIT, 31, ldc_saved_enable_bit);
    return 1;
}
