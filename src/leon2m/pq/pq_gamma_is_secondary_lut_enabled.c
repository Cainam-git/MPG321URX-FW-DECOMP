/* pq_gamma_is_secondary_lut_enabled  (FUN_a010af18)
 *
 * Return whether the secondary gamma look-up table is switched on.
 * Returns: 0 or 1
 * Name basis: derived - bit 3 of 0xCF00EAC8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010af18 @ 0xa010af18, flags -mcpu=v8 -O3 -g.
 * Source form: the masked value is kept in its own unsigned int local before the comparison.
 */
/* Gamma LUT control register: bit 7 = primary LUT on, bit 3 = secondary LUT on, bit 6 = option, bit 0 = first
   preset-curve stage. */
#define reg_pq_gamma_lut_control (*(volatile unsigned int *)0xcf00eac8)
#define SECONDARY_LUT_ON_BIT 0x8   /* bit 3: secondary LUT on */

/*
 * Return whether the secondary gamma look-up table is switched on: 1 when bit 3 of the gamma LUT control
 * register is set, else 0.
 *
 * Callers: pq_load_gamma and pq_api_is_secondary_gamma_lut_enabled.
 */
unsigned int pq_gamma_is_secondary_lut_enabled(void)
{
    unsigned int secondary_lut_on = reg_pq_gamma_lut_control & SECONDARY_LUT_ON_BIT;
    return secondary_lut_on != 0;
}
