/* pq_gamma_enable_first_curve_stage  (FUN_a010afac)
 *
 * Switch the first preset-curve stage on.
 * Name basis: derived - bit 0 of 0xCF00EAC8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010afac @ 0xa010afac, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: a single assignment that ORs bit 0 into the register.
 */
#define reg_pq_gamma_lut_control (*(volatile unsigned int *)0xcf00eac8)
#define GAMMA_LUT_FIRST_CURVE_STAGE 1   /* bit 0: first preset-curve stage on */

/*
 * Switch the first preset-curve stage on: set bit 0 of the gamma LUT control register (0xCF00EAC8).
 * The register also holds bit 7 = primary LUT on, bit 3 = secondary LUT on, bit 6 = option.
 *
 * Callers: pq_apply_picture_mode and pq_api_enable_preset_curves.
 */
void pq_gamma_enable_first_curve_stage(void)
{
  reg_pq_gamma_lut_control = reg_pq_gamma_lut_control | GAMMA_LUT_FIRST_CURVE_STAGE;
  return;
}
