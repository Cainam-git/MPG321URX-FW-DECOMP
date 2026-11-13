/* pq_gamma_enable_second_curve_stage  (FUN_a010b17c)
 *
 * Switch the second preset-curve stage on.
 * Name basis: derived - bit 2 of 0xCF00EAC8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010b17c @ 0xa010b17c, flags -mcpu=v8 -O2 -g.
 * Source form: one read-modify-write of the volatile register.
 */
#define reg_pq_gamma_lut_control (*(volatile unsigned int *)0xcf00eac8)

#define GAMMA_LUT_SECOND_CURVE_STAGE 0x4    /* bit 2 of reg_pq_gamma_lut_control: second preset-curve stage on */

/*
 * Set the enable bit of the second preset-curve stage.
 * Called by pq_apply_picture_mode and pq_api_enable_preset_curves.
 */
void pq_gamma_enable_second_curve_stage(void)
{
  reg_pq_gamma_lut_control = reg_pq_gamma_lut_control | GAMMA_LUT_SECOND_CURVE_STAGE;
}
