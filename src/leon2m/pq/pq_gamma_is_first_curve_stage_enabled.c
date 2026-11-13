/* pq_gamma_is_first_curve_stage_enabled  (FUN_a010af98)
 *
 * Return whether the first preset-curve stage is switched on.
 * Returns: 0 or 1
 * Name basis: derived - bit 0 of 0xCF00EAC8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010af98 @ 0xa010af98, flags -mcpu=v8 -O3 -g.
 * Source form: the result is the masked bit itself (no comparison).
 */
#define reg_pq_gamma_lut_control (*(volatile unsigned int *)0xcf00eac8)
#define GAMMA_FIRST_CURVE_STAGE_ENABLE 1 /* bit 0 of reg_pq_gamma_lut_control */

/*
 * Return whether the first preset-curve stage is switched on: bit 0 of the gamma LUT control register
 * (0xCF00EAC8), as 0 or 1.
 *
 * Only caller: pq_apply_picture_mode.
 */
unsigned int pq_gamma_is_first_curve_stage_enabled(void)

{
  return reg_pq_gamma_lut_control & GAMMA_FIRST_CURVE_STAGE_ENABLE;
}
