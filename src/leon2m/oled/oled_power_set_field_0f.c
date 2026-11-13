/* oled_power_set_field_0f  (FUN_a0127914)
 *
 * Store field +0x0F of the OLED power state record.
 * Name basis: descriptive - byte at 0xA802D896 + 0x0F
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0127914, flags -mcpu=v8 -O2 -g.
 */
extern unsigned char oled_power_state_after_sensing;

/* Store value in byte +0x0F of the OLED power state record. */
void oled_power_set_field_0f(unsigned char value)
{
    oled_power_state_after_sensing = value;
}
