/* input_scan_keys  (FUN_a0125e60)
 *
 * Scan the control keys once and return the key code.
 * Returns: key code
 * Name basis: proven - two analogue readings with two ranges each, then eight pin keys
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125e60 @ 0xa0125e60-0xa012621c (239 words), -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the pin-key check is one static helper, inlined eight times. After the two analogue reads the
 * source tests the last value of 'level' once more, with an empty arm. This test is reconstructed. Evidence: the
 * same source without it is not byte-exact, here or in the 247-word build of this routine in another firmware of
 * the same SDK (one more pin key, mask 0x40); with it both are. None of the other forms tried without such a
 * compare gives these bytes (extra ranges in either read, range tests, uses of the value with an effect). The
 * bytes do not show the compared value, nor what the arm held, if anything: every direct compare of the value
 * tried after the two reads (other constants, ==, !=, <, a compare with the result; directly after the reads,
 * among the key checks or before the return) gives the same bytes. 'level > 0xa0' is a chosen spelling: 0xa0 is
 * the upper end of the higher key range of both reads.
 */
/* One entry of input_control_key_table (3 bytes), indexed by the number of the key's bit in the key mask. */
struct control_key_entry {
    unsigned char pin_port;         /* 0xff: this slot has no key */
    unsigned char pin_mask;
    unsigned char active_level;     /* value gpio_read_pin returns while the key is pressed */
};
extern const struct control_key_entry input_control_key_table[];
extern unsigned char gpio_read_adc_channel(unsigned char n);
extern int gpio_read_pin(int, int);

/*
 * Read the pin key of slot 'mask' (a single bit). The slot's entry is input_control_key_table[number of the
 * lowest set bit of mask, 8 when mask is 0]. Returns mask when the entry names a pin (port not 0xff) and the pin
 * reads its active level, else 0.
 */
static unsigned char scan_pin_key(unsigned char mask)
{
    unsigned char rest = mask;
    unsigned char i, pin_port, pin_mask, active_level;

    for (i = 0; i <= 7; i++) {
        if (rest & 1)
            break;
        rest >>= 1;
    }
    pin_port = input_control_key_table[i].pin_port;
    pin_mask = input_control_key_table[i].pin_mask;
    active_level = input_control_key_table[i].active_level;
    if (pin_port != 0xff && (gpio_read_pin(pin_port, pin_mask) & 0xff) == active_level)
        return mask;
    return 0;
}

/*
 * Read the control keys once and return the key code, a bit mask. Returns: key code (0 = nothing pressed).
 * The result is not debounced; input_read_keys_debounced does that by calling this routine repeatedly.
 *
 * Four keys on two analogue channels, then pin keys:
 *   analogue channel 6: reading <= 0x50 gives 0x04, reading 0x60..0xa0 gives 0x08;
 *   analogue channel 5, read only when channel 6 gave nothing: <= 0x50 gives 0x10, 0x60..0xa0 gives 0x20;
 *   the pin keys of the slots with mask 1 and 2 are looked up in input_control_key_table and added when pressed.
 * The other six pin slots are checked with mask 0, which never adds anything.
 */
unsigned char input_scan_keys(void)
{
    unsigned char keys = 0;
    unsigned char level;

    level = gpio_read_adc_channel(6);
    if (level <= 0x50)
        keys = 4;
    else if ((unsigned char)(level - 0x60) <= 0x40)
        keys = 8;
    if (keys == 0) {
        level = gpio_read_adc_channel(5);
        if (level <= 0x50)
            keys |= 0x10;
        else if ((unsigned char)(level - 0x60) <= 0x40)
            keys |= 0x20;
    }
    if (level > 0xa0) {
        /* reconstructed, see the matching notes */
    }
    keys |= scan_pin_key(1);
    keys |= scan_pin_key(2);
    keys |= scan_pin_key(0);
    keys |= scan_pin_key(0);
    keys |= scan_pin_key(0);
    keys |= scan_pin_key(0);
    keys |= scan_pin_key(0);
    keys |= scan_pin_key(0);
    return keys;
}
