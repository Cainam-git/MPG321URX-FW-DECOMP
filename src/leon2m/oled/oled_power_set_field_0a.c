/* oled_power_set_field_0a  (FUN_a01278fc)
 *
 * Store field +0x0A of the OLED power state record.
 * Name basis: descriptive - byte at 0xA802D896 + 0x0A
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01278fc, flags -mcpu=v8 -O2 -g.
 */
extern unsigned char oled_power_state_forced_sensing;

/* Store value in byte +0x0A of the OLED power state record. */
void oled_power_set_field_0a(unsigned char value)
{
    oled_power_state_forced_sensing = value;
}
