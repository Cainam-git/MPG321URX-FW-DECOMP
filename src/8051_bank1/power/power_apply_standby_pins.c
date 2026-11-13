/* power_apply_standby_pins  (FUN_CODE_b881)
 *
 * Set the pins listed in the standby table.
 * Name basis: derived - entries 0xA61D (standby table, FillKeyDetectList) through gpio_set_port_bits; caller
 *   sys_main
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_b881, OPTIMIZE(8,SPEED) LARGE.
 * volatile: the firmware reads the entry again after the range test (same in power_find_active_wake_pin).
 * Source form: the three call arguments are written in the call itself. 'unused' is set to 0xFF and never read.
 */
extern volatile unsigned char xdata power_key_table_standby_pins[6][2];
extern void gpio_set_port_bits(unsigned char sel, unsigned char mask, unsigned char on);

/*
 * power_apply_standby_pins - go through the six 2-byte entries of the standby table (XDATA 0xA61D) and call
 * gpio_set_port_bits for each one, until an entry whose byte 0 is outside 0x10..0x1F (that entry ends the loop).
 *   byte 0 - 0x10: port number
 *   byte 1 bits 0..3: pin number (mask = 1 << pin); bit 4: the level to set (0 or 1)
 * Same entry layout as power_find_active_wake_pin (table at 0xA611 there). Caller: sys_main (code at 0x425F).
 */
void power_apply_standby_pins(void)
{
    unsigned char index, unused;
    unsigned char entry[2];

    unused = 0xff;
    for (index = 0; index < 6; index++) {
        if ((unsigned char)(power_key_table_standby_pins[index][0] + 0xf0) <= 0x0f) {
            entry[0] = power_key_table_standby_pins[index][0];
            entry[1] = power_key_table_standby_pins[index][1];
            gpio_set_port_bits(entry[0] - 0x10, 1 << (entry[1] & 0x0f), (entry[1] & 0x10) >> 4);
        } else break;
    }
}
