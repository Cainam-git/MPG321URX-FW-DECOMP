/* pq_api_is_secondary_gamma_lut_enabled  (FUN_a014e308)
 *
 * Return whether the secondary gamma look-up table is switched on.
 * Returns: 1 when on
 * Name basis: descriptive - reads bit 0xCF00EAC8.3; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e308 @ 0xa014e308, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the callee is declared without a prototype and returning int.
 */
extern int pq_gamma_is_secondary_lut_enabled();

/* Return 1 when bit 3 of the gamma look-up table control register 0xCF00EAC8 is set, else 0. Nothing in the
   firmware calls this routine. */
unsigned char pq_api_is_secondary_gamma_lut_enabled(void)
{
  return pq_gamma_is_secondary_lut_enabled();
}
