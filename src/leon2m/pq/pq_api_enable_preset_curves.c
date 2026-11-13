/* pq_api_enable_preset_curves  (FUN_a014e19c)
 *
 * Switch both preset-curve stages on or off.
 * Name basis: derived - bits 0 and 2 of 0xCF00EAC8, the stages loaded by pq_api_load_preset_curves; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e19c @ 0xa014e19c, flags -mcpu=v8 -O2 -g (section default).
 * Source form: six int parameters, the low byte of the first tested; the callees are declared without a
 * prototype and the second one gets all six incoming parameters (a tail call). The non-zero path is the
 * fall-through and the zero path the branch target.
 */
extern int pq_gamma_enable_first_curve_stage();
extern int pq_gamma_disable_first_curve_stage();
extern int pq_gamma_enable_second_curve_stage();
extern int pq_gamma_disable_second_curve_stage();

/*
 * Set (low byte of on non-zero) or clear bits 0 and 2 of the gamma look-up table control register 0xCF00EAC8,
 * the first and the second curve stage. The four callees take no argument; the values passed on are not used.
 * Nothing in the firmware calls this routine.
 */
void pq_api_enable_preset_curves(unsigned int on, unsigned int pass_1, unsigned int pass_2,
                  unsigned int pass_3, unsigned int pass_4, unsigned int pass_5)
{
    if ((on & 0xff) != 0) {
        pq_gamma_enable_first_curve_stage();
        pq_gamma_enable_second_curve_stage(on, pass_1, pass_2, pass_3, pass_4, pass_5);
        return;
    }
    pq_gamma_disable_first_curve_stage();
    pq_gamma_disable_second_curve_stage(on, pass_1, pass_2, pass_3, pass_4, pass_5);
}
