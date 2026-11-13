/* oled_power_get_field_0e  (FUN_a0127974)
 *
 * Return field +0x0E of the OLED power state record.
 * Returns: byte
 * Name basis: descriptive - byte at 0xA802D896 + 0x0E
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0127974 @ 0xa0127974, flags -mcpu=v8 -O2 -g.
 * Source form: a direct read of the extern byte.
 */
extern unsigned char oled_power_state_byte_0xe;

/*
 * Return field +0x0E of the OLED power state record. No routine of the firmware calls it.
 */
unsigned char oled_power_get_field_0e(void)
{
    return oled_power_state_byte_0xe;
}
