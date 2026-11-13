/* panel_pwm_set_channel_output_mode  (FUN_a011e794)
 *
 * Write the 2-bit output mode of a grouped PWM channel 0x10..0x17.
 * Name basis: descriptive - field in 0xCF016480 + 4 * (channel pair)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011e794, flags -mcpu=v8 -O3 -g.
 * Source form: if/else chains on the channel number (the firmware has a compare chain, no jump table); the
 * low bit is set first and the high bit cleared in a second statement.
 */
#define R(a) (*(volatile unsigned int *)(a))

/*
 * Write the 2-bit output mode of one of the grouped PWM channels 0x10..0x17.
 *
 * Each of the registers 0xCF016480, 0xCF016484, 0xCF016488 and 0xCF01648C holds the fields of two channels:
 * bits 6..7 for the even channel and bits 2..3 for the odd one (register = 0xCF016480 + 4 * ((channel - 0x10) / 2)).
 *
 *   channel  0x10..0x17; any other number writes nothing
 *   mode     1: the field is set to 0 (both bits cleared); any other value: the field is set to 1 (its low bit
 *            set, its high bit cleared)
 *
 * Called by panel_blurfree_set_channel_output_mode, which SetPSMMixMode calls with 1 when it switches on and 0
 * when it switches off. What the field values mean is not shown by the code.
 */
void panel_pwm_set_channel_output_mode(unsigned char channel, unsigned char mode)
{
    if (mode == 1) {
        if (channel == 0x10) {
            R(0xcf016480) &= ~0xc0;
        } else if (channel == 0x11) {
            R(0xcf016480) &= ~0xc;
        } else if (channel == 0x12) {
            R(0xcf016484) &= ~0xc0;
        } else if (channel == 0x13) {
            R(0xcf016484) &= ~0xc;
        } else if (channel == 0x14) {
            R(0xcf016488) &= ~0xc0;
        } else if (channel == 0x15) {
            R(0xcf016488) &= ~0xc;
        } else if (channel == 0x16) {
            R(0xcf01648c) &= ~0xc0;
        } else if (channel == 0x17) {
            R(0xcf01648c) &= ~0xc;
        }
    } else {
        if (channel == 0x10) {
            R(0xcf016480) |= 0x40;
            R(0xcf016480) &= ~0x80;
        } else if (channel == 0x11) {
            R(0xcf016480) |= 4;
            R(0xcf016480) &= ~8;
        } else if (channel == 0x12) {
            R(0xcf016484) |= 0x40;
            R(0xcf016484) &= ~0x80;
        } else if (channel == 0x13) {
            R(0xcf016484) |= 4;
            R(0xcf016484) &= ~8;
        } else if (channel == 0x14) {
            R(0xcf016488) |= 0x40;
            R(0xcf016488) &= ~0x80;
        } else if (channel == 0x15) {
            R(0xcf016488) |= 4;
            R(0xcf016488) &= ~8;
        } else if (channel == 0x16) {
            R(0xcf01648c) |= 0x40;
            R(0xcf01648c) &= ~0x80;
        } else if (channel == 0x17) {
            R(0xcf01648c) |= 4;
            R(0xcf01648c) &= ~8;
        }
    }
}
