/* oled_power_set_field_0e  (FUN_a0127980)
 *
 * Store field +0x0E of the OLED power state record.
 * Name basis: descriptive - byte at 0xA802D896 + 0x0E
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0127980 @ 0xa0127980, flags -mcpu=v8 -O2 -g.
 * Source form: a direct store to the extern byte.
 */
extern unsigned char oled_power_state_byte_0xe;

/*
 * Store field +0x0E of the OLED power state record. No routine of the firmware calls it.
 *
 *   value  new field value
 */
void oled_power_set_field_0e(unsigned char value)
{
    oled_power_state_byte_0xe = value;
}
