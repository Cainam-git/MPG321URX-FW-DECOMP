/* oled_power_set_field_0d  (FUN_a01278f0)
 *
 * Store field +0x0D of the OLED power state record.
 * Name basis: descriptive - byte at 0xA802D896 + 0x0D
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01278f0, flags -mcpu=v8 -O2 -g.
 */
extern unsigned char oled_power_state_power_down_request;

/* Store value in byte +0x0D of the OLED power state record. */
void oled_power_set_field_0d(unsigned char value)
{
    oled_power_state_power_down_request = value;
}
