/* power_find_active_wake_pin  (FUN_CODE_a085)
 *
 * Return the first wake-up pin from the standby table that is at its active level.
 * Returns: index, or 0xFF
 * Name basis: derived - six entries 0xA611 (standby table) tested with gpio_read_port_bit; prints index and
 *   entry
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_a085 @ 0xa085 (189 bytes), OPTIMIZE(8,SPEED) LARGE.
 * LARGE locals: i 0xA473, found 0xA474, entry 0xA475..0xA476.
 * volatile: the firmware reads the entry again after the range test (same in power_apply_cut_list and the other
 *   readers of the standby tables).
 * Source form: the call arguments go to locals first (port, bit_number) and the mask is '1 << bit_number'. The
 *   comparison is cast to unsigned char (its 0/1 value goes to R7 before the test).
 */
extern volatile unsigned char xdata power_key_table_wake_pins[6][2];
extern void lib_printf517(void *fmt, ...) large;
bit gpio_read_port_bit(unsigned char n, unsigned char mask);

#define WAKE_PIN_ENTRIES  6
#define WAKE_PIN_NONE     0xff  /* no pin at its level */
#define KEY_CODE_GPIO     0x10  /* entry byte 0 = 0x10 + GPIO port; other values end the list */
#define KEY_GPIO_BIT      0x0f  /* entry byte 1 bits 0..3: bit of the port */
#define KEY_GPIO_LEVEL    0x10  /* entry byte 1 bit 4: the level that counts */

/*
 * power_find_active_wake_pin - return the index of the first wake-up pin of the standby table (0xA611, six
 * 2-byte entries) whose GPIO bit reads at the entry's level, and print "Key%02X : %02X %02X" with the index and
 * the entry. The list ends at the first entry whose byte 0 is not 0x10..0x1F. Returns WAKE_PIN_NONE when no pin
 * matches.
 * Only caller: sys_main, which takes the index + WAKE_PIN_FIRST as the wake-up reason.
 */
unsigned char power_find_active_wake_pin(void)
{
    unsigned char i, found;
    unsigned char entry[2];
    unsigned char port, bit_number;

    found = WAKE_PIN_NONE;
    for (i = 0; i < WAKE_PIN_ENTRIES; i++) {
        if ((unsigned char)(power_key_table_wake_pins[i][0] + 0xf0) <= 0x0f) {
            entry[0] = power_key_table_wake_pins[i][0];
            entry[1] = power_key_table_wake_pins[i][1];
            port = entry[0] - KEY_CODE_GPIO;
            bit_number = entry[1] & KEY_GPIO_BIT;
            if ((unsigned char)(gpio_read_port_bit(port, 1 << bit_number) == ((entry[1] & KEY_GPIO_LEVEL) >> 4))) {
                lib_printf517((void code *)0x98d2, i, entry[0], entry[1]);   /* "Key%02X : %02X %02X\r\n" */
                found = i;
                break;
            }
        } else break;
    }
    return found;
}
