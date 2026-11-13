/* oled_user_get_temperature  (FUN_a00dab30)
 *
 * Return the panel temperature.
 * Returns: temperature
 * Name basis: proven - forwards to OLEDIIC_getTempSensing
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dab30 @ 0xa00dab30, flags -mcpu=v8 -O2 -g (section default; -O3 -g and -Os -g give the same
 * bytes).
 * Source form: the result is returned as an unsigned short (the firmware masks it to 16 bits after the call).
 */
extern int OLEDIIC_getTempSensing();

/* Return the panel temperature as the OLED panel controller reports it (OLEDIIC_getTempSensing). */
unsigned short oled_user_get_temperature(void)
{
  return OLEDIIC_getTempSensing();
}
