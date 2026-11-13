/* pq_gamma_disable_primary_lut  (FUN_a010ae70)
 *
 * Switch the primary gamma look-up table off.
 * Name basis: derived - bit 7 of 0xCF00EAC8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010ae70 @ 0xa010ae70, flags -mcpu=v8 -O2 -g (section default).
 */
#define reg_pq_gamma_lut_control (*(volatile unsigned int *)0xcf00eac8)
#define PRIMARY_LUT_ON 0x80 /* bit 7: primary LUT on */

/*
 * Switch the primary gamma look-up table off: clear bit 7 of the gamma LUT control register (0xCF00EAC8);
 * the counterpart of pq_gamma_enable_primary_lut.
 *
 * Callers: pq_load_gamma (before it writes new gamma data into the primary LUT), pq_fga_handle_command and
 * pq_api_enable_primary_gamma_lut.
 */
void pq_gamma_disable_primary_lut(void)
{
  reg_pq_gamma_lut_control = reg_pq_gamma_lut_control & ~PRIMARY_LUT_ON;
  return;
}
