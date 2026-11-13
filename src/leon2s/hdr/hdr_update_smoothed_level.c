/* hdr_update_smoothed_level  (FUN_a00d378c)
 *
 * Compute the new target level and smooth towards it.
 * Name basis: descriptive - stores the result at 0xA8078C3C
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d378c @ 0xa00d378c-0xa00d38a8.
 * Source form: hdr_level_index is declared unsigned long and written through an unsigned long pointer. That type
 * gives the store a different alias set from the unsigned int tables, so it does not order the later table loads
 * and the scheduler places the sethi of hdr_level_ratio_table before it, as in the firmware. Register 0xb70803a0
 * is read three times (the middle read has no use).
 */
extern unsigned int reg_read32(unsigned int);
extern unsigned int hdr_level_base_table[];
extern unsigned int hdr_level_scale_table[];
extern unsigned int hdr_level_ratio_table[];
extern unsigned long hdr_level_index;
extern unsigned int hdr_level_target;
extern unsigned int hdr_level_scale_percent;
extern unsigned short hdr_gain;
extern void hdr_smooth_level(unsigned int, int);

#define SELECT_REG_A   0xb7091090       /* its value indexes hdr_level_scale_table */
#define SELECT_REG_B   0xb70803a0       /* its low 10 bits index hdr_level_base_table */
#define SELECT_MASK    0x3ff
#define PRODUCT_LIMIT  0x400            /* above this the index is 100 */

/*
 * Work out hdr_level_target and pass it to hdr_smooth_level (mode 1, tail call).
 *
 * Steps: the product hdr_level_base_table[B] * hdr_level_scale_table[A] / 100 (A and B are the two registers
 * above) gives hdr_level_index as product * 100 >> 10, or 100 when the product is above 0x400.
 * hdr_level_scale_percent = hdr_level_ratio_table[0] * 100 / hdr_level_ratio_table[hdr_level_index];
 * hdr_level_target = hdr_gain * hdr_level_scale_percent / 100. Called by hdr_task when hdr_mode_byte
 * is 1.
 */
void hdr_update_smoothed_level(void)
{
    unsigned int a;
    unsigned int v;
    unsigned long *p = &hdr_level_index;

    a = reg_read32(SELECT_REG_A);
    if (hdr_level_base_table[reg_read32(SELECT_REG_B) & SELECT_MASK] * hdr_level_scale_table[a] / 100 <= PRODUCT_LIMIT) {
        reg_read32(SELECT_REG_B);
        v = hdr_level_base_table[reg_read32(SELECT_REG_B) & SELECT_MASK] * hdr_level_scale_table[a] / 100 * 100 >> 10;
    } else
        v = 100;
    *p = v;
    hdr_level_scale_percent = hdr_level_ratio_table[0] * 100 / hdr_level_ratio_table[hdr_level_index];
    hdr_level_target = hdr_gain * hdr_level_scale_percent / 100;
    hdr_smooth_level(hdr_level_target, 1);
}
