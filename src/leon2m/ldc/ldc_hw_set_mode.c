/* ldc_hw_set_mode  (FUN_a00f99a0)
 *
 * Switch the grid block on or off and write its 4-bit mode.
 * Returns: 0
 * Name basis: descriptive - bit 31 of 0xD0040000 and bits 0..3 of 0xD00400D8; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f99a0 @ 0xa00f99a0, flags -mcpu=v8 -O3 -g.
 * Source form: a static field-write helper write_field(reg, mask, shift, value) =
 * '*reg = (*reg & ~mask) | ((value << shift) & mask)' is inlined; it keeps the 'and' with the sethi'd mask
 * after the shift.
 */
#define LDC_REG_CTRL 0xd0040000         /* bit 31: enable */
#define LDC_REG_MODE 0xd00400d8         /* bits 0..3: mode */
#define LDC_CTRL_ENABLE_MASK 0x80000000
#define LDC_CTRL_ENABLE_SHIFT 31
#define LDC_MODE_MASK 0xf

#define REG_CTRL (*(volatile unsigned int *)LDC_REG_CTRL)
#define REG_MODE (*(volatile unsigned int *)LDC_REG_MODE)

/* Replace the bits of 'mask' in *reg by 'value' shifted left by 'shift'. */
static void write_field(volatile unsigned int *reg, unsigned int mask, unsigned int shift, unsigned int value)
{
    *reg = (*reg & ~mask) | ((value << shift) & mask);
}

/*
 * Switch the grid block on or off and write its mode. Bit 31 of the control register is set when 'mode' is
 * not zero and cleared otherwise; the low four bits of 'mode' go to the mode field. Always returns 0. Called
 * by ldc_hw_run_mode3_pass.
 */
int ldc_hw_set_mode(unsigned int mode)
{
    write_field(&REG_CTRL, LDC_CTRL_ENABLE_MASK, LDC_CTRL_ENABLE_SHIFT, mode != 0);
    write_field(&REG_MODE, LDC_MODE_MASK, 0, mode);
    return 0;
}
