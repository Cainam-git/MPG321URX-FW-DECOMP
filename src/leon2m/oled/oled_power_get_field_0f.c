/* oled_power_get_field_0f  (FUN_a0127920)
 *
 * Return field +0x0F of the OLED power state record.
 * Returns: byte
 * Name basis: descriptive - byte at 0xA802D896 + 0x0F
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0127920, flags -mcpu=v8 -O2 -g.
 */
extern unsigned char oled_power_state_after_sensing;

/* Return byte +0x0F of the OLED power state record (the byte oled_power_reset_state sets to 2). */
unsigned char oled_power_get_field_0f(void)
{
    return oled_power_state_after_sensing;
}
