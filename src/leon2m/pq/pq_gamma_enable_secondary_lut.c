/* pq_gamma_enable_secondary_lut  (FUN_a010af34)
 *
 * Switch the secondary gamma look-up table on.
 * Name basis: derived - bit 3 of 0xCF00EAC8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010af34 @ 0xa010af34, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: a single assignment that ORs bit 3 into the register.
 */
#define reg_pq_gamma_lut_control (*(volatile unsigned int *)0xcf00eac8)
#define GAMMA_LUT_SECONDARY_ENABLE 8   /* bit 3: secondary LUT on */

/*
 * Switch the secondary gamma look-up table on: set bit 3 of the gamma LUT control register (0xCF00EAC8).
 *
 * Callers: pq_load_gamma and pq_api_enable_secondary_gamma_lut.
 */
void pq_gamma_enable_secondary_lut(void)
{
  reg_pq_gamma_lut_control = reg_pq_gamma_lut_control | GAMMA_LUT_SECONDARY_ENABLE;
  return;
}
