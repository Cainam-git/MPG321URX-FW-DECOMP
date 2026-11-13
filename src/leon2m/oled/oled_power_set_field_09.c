/* oled_power_set_field_09  (FUN_a01278e4)
 *
 * Store field +0x09 of the OLED power state record.
 * Name basis: descriptive - byte at 0xA802D896 + 0x09
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01278e4, flags -mcpu=v8 -O2 -g.
 */
extern unsigned char oled_power_state_sensing_requested;

/* Store value in byte +0x09 of the OLED power state record. */
void oled_power_set_field_09(unsigned char value)
{
    oled_power_state_sensing_requested = value;
}
