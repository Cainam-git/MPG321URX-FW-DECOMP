/* pq_gamma_enable_primary_lut  (FUN_a010ae54)
 *
 * Switch the primary gamma look-up table on.
 * Name basis: derived - bit 7 of 0xCF00EAC8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010ae54 @ 0xa010ae54, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: a single assignment that ORs bit 7 into the register.
 */
#define reg_pq_gamma_lut_control (*(volatile unsigned int *)0xcf00eac8)
#define PRIMARY_LUT_ON 0x80 /* bit 7: primary LUT on */

/*
 * Switch the primary gamma look-up table on: set bit 7 of the gamma LUT control register (0xCF00EAC8).
 * The register also holds bit 3 (secondary LUT on), bit 6 (an option, pq_gamma_set_lut_options) and bit 0
 * (first preset-curve stage).
 *
 * Callers: pq_load_gamma and pq_api_enable_primary_gamma_lut.
 */
void pq_gamma_enable_primary_lut(void)
{
  reg_pq_gamma_lut_control = reg_pq_gamma_lut_control | PRIMARY_LUT_ON;
  return;
}
