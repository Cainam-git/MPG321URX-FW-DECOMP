/* pq_gamma_is_primary_lut_enabled  (FUN_a010ae38)
 *
 * Return whether the primary gamma look-up table is switched on.
 * Returns: 0 or 1
 * Name basis: derived - bit 7 of 0xCF00EAC8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010ae38 @ 0xa010ae38, flags -mcpu=v8 -O3 -g.
 * Source form: single expression returning the comparison result.
 */
#define reg_pq_gamma_lut_control (*(volatile unsigned int *)0xcf00eac8)

#define PRIMARY_LUT_ON_MASK 0x80   /* bit 7: primary LUT on */

/*
 * Return whether the primary gamma look-up table is switched on.
 * Reads bit 7 of the gamma LUT control register.
 * Callers: pq_load_gamma and pq_api_is_primary_gamma_lut_enabled.
 */
unsigned int pq_gamma_is_primary_lut_enabled(void)
{
    unsigned int primary_lut_on_mask = reg_pq_gamma_lut_control & PRIMARY_LUT_ON_MASK;
    return primary_lut_on_mask != 0;
}
