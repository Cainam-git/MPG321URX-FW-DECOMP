/* pq_gamma_disable_first_curve_stage  (FUN_a010afc8)
 *
 * Switch the first preset-curve stage off.
 * Name basis: derived - bit 0 of 0xCF00EAC8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010afc8 @ 0xa010afc8, flags -mcpu=v8 -O2 -g (section default).
 */
#define reg_pq_gamma_lut_control (*(volatile unsigned int *)0xcf00eac8)
#define GAMMA_LUT_FIRST_CURVE_STAGE 1   /* bit 0: first preset-curve stage on */

/*
 * Switch the first preset-curve stage off: clear bit 0 of the gamma LUT control register (0xCF00EAC8);
 * the counterpart of pq_gamma_enable_first_curve_stage.
 *
 * Callers: pq_apply_picture_mode, pq_load_gamma, pq_fga_handle_command, pq_api_load_preset_curves and
 * pq_api_enable_preset_curves.
 */
void pq_gamma_disable_first_curve_stage(void)
{
  reg_pq_gamma_lut_control = reg_pq_gamma_lut_control & ~GAMMA_LUT_FIRST_CURVE_STAGE;
  return;
}
