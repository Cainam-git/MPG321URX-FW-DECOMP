/* ldc_hw_latch_level_field  (FUN_a00fa560)
 *
 * Copy a 10-bit register field and flag a change of its top two bits.
 * Name basis: descriptive - bits 16..25 of 0xD0040014; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fa560, flags -mcpu=v8 -O3 -g.
 * Source form: the top two bits are kept in an unsigned char local.
 */

/* Level register of the grid block: bits 16..25 hold the level field, bits 30..31 the top bits. */
#define LDC_REG_LEVEL (*(volatile unsigned int *)0xd0040014)

extern unsigned short ldc_level_field;
extern unsigned char ldc_level_top_bits, ldc_level_changed_flag;

/*
 * Latch the grid block's level register.
 *
 * Stores the level field (bits 16..25) in ldc_level_field and compares the top two bits with the ones kept from
 * the last call: ldc_level_changed_flag is set to 1 when they differ (the new bits are kept) and to 0 when they
 * are the same. ldc_hw_update_arrays_if_changed reads the flag. No routine calls this one; ldc_hw_run_mode3_pass
 * has the same steps inline.
 */
void ldc_hw_latch_level_field(void)
{
    unsigned int level_reg = LDC_REG_LEVEL;
    unsigned char top_bits;

    ldc_level_field = (level_reg << 6) >> 22;
    top_bits = level_reg >> 30;
    if (top_bits != ldc_level_top_bits) {
        ldc_level_top_bits = top_bits;
        ldc_level_changed_flag = 1;
    } else
        ldc_level_changed_flag = 0;
}
