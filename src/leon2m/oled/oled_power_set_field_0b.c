/* oled_power_set_field_0b  (FUN_a0127908)
 *
 * Store field +0x0B of the OLED power state record.
 * Name basis: descriptive - byte at 0xA802D896 + 0x0B
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0127908, flags -mcpu=v8 -O2 -g.
 */
extern unsigned char oled_power_state_byte_0xb;

/* Store value in byte +0x0B of the OLED power state record. */
void oled_power_set_field_0b(unsigned char value)
{
    oled_power_state_byte_0xb = value;
}
