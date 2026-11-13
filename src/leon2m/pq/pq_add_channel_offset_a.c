/* pq_add_channel_offset_a  (FUN_a0150e80)
 *
 * Add the signed per-channel offset (first set) to a value, stopping at 0 below and at 0xFF above.
 * Returns: adjusted value
 * Note: Offset byte 0x80 or a colour other than 0..2 returns the value unchanged, also when it is above 0xFF.
 * Name basis: derived - offset bytes 0xA802E3E2..E4 chosen by channel; 0x80 means no change
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0150e80 @ 0xa0150e80-0xa0150f44 (49 words), flags -mcpu=v8 -O3 -g.
 * Source form (the same as pq_add_channel_offset_b): offset_byte is preset to OFFSET_ZERO before the switch
 * (no default case), and the lowering arm (bit 7 clear) is written first.
 */
extern unsigned char sys_config_red_offset_first, sys_config_green_offset_first, sys_config_blue_offset_first;

#define RGB_RED   0
#define RGB_GREEN 1
#define RGB_BLUE  2

/* An offset byte holds 0x80 + the offset: 0x80 is no offset, below it lowers the value, above it raises it. */
#define OFFSET_ZERO     0x80
#define OFFSET_UP_BIT   0x80            /* bit 7 set (and not 0x80 itself): the offset raises the value */
#define VALUE_MAX       0xff

/*
 * Add the offset of one colour from the first offset set (sys_config bytes +0x12..+0x14, stored by
 * pq_api_set_channel_offset_first) to a value.
 *
 *   color  RGB_RED, RGB_GREEN or RGB_BLUE; any other value leaves the value unchanged
 *   value  the value to adjust
 *
 * Returns the adjusted value. A lowered value stops at 0, a raised one at 0xFF. With offset byte 0x80 the
 * value comes back unchanged. No code in the firmware calls this routine.
 */
unsigned short pq_add_channel_offset_a(unsigned char color, unsigned short value)
{
    unsigned char offset_byte;

    offset_byte = OFFSET_ZERO;
    switch (color) {
    case RGB_RED:
        offset_byte = sys_config_red_offset_first;
        break;
    case RGB_GREEN:
        offset_byte = sys_config_green_offset_first;
        break;
    case RGB_BLUE:
        offset_byte = sys_config_blue_offset_first;
        break;
    }
    if (offset_byte != OFFSET_ZERO) {
        if (!(offset_byte & OFFSET_UP_BIT)) {
            /* Lower by 0x80 - offset_byte, but not below 0. */
            if (value > OFFSET_ZERO - offset_byte)
                value = offset_byte + value - OFFSET_ZERO;
            else
                value = 0;
        } else {
            /* Raise by offset_byte - 0x80, but not above 0xFF. */
            value = offset_byte + value - OFFSET_ZERO;
            if (value > VALUE_MAX)
                value = VALUE_MAX;
        }
    }
    return value;
}
