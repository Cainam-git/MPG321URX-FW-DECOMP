/* pq_gamma_is_second_curve_stage_enabled  (FUN_a010b160)
 *
 * Return whether the second preset-curve stage is switched on.
 * Returns: 0 or 1
 * Name basis: derived - bit 2 of 0xCF00EAC8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010b160 @ 0xa010b160, flags -mcpu=v8 -O3 -g.
 * Source form: the masked bit is held in a local and compared with 0 (same form as sys_frc_is_active).
 */
#define reg_pq_gamma_lut_control (*(volatile unsigned int *)0xcf00eac8)

#define GAMMA_LUT_SECOND_CURVE_STAGE 0x4    /* bit 2 of reg_pq_gamma_lut_control: second preset-curve stage on */

/*
 * Return 1 when the second preset-curve stage is on, else 0.
 * Called by pq_apply_picture_mode, which reloads preset 2 unless both stages are already on.
 */
unsigned int pq_gamma_is_second_curve_stage_enabled(void)
{
    unsigned int enabled = reg_pq_gamma_lut_control & GAMMA_LUT_SECOND_CURVE_STAGE;
    return enabled != 0;
}
