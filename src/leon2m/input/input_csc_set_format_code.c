/* input_csc_set_format_code  (FUN_a0100e6c)
 *
 * Set the colour format code from a selector and a signal code.
 * Name basis: descriptive - byte at 0xA8027A75; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0100e6c @ 0xa0100e6c, flags -mcpu=v8 -O3 -g.
 * Source form: input_block_get_capture_hstart and input_block_get_capture_vstart (12-bit results) are declared
 * returning unsigned short (the build truncates right after the calls); the codes are tested in pairs in one ||
 * and the other codes as separate arms; the 1920 x 1080 / 1280 x 720 test is written out twice, as in the
 * firmware.
 */
extern unsigned int input_csc_selector;
extern unsigned char input_csc_option_byte, input_csc_format_code;
extern unsigned short input_block_get_capture_hstart(unsigned char blk);
extern unsigned short input_block_get_capture_vstart(unsigned char blk);
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void timer_sleep_ticks(int ms);

/*
 * Set input_csc_format_code, the colour format code of the conversion set-up, from input_csc_selector.
 *
 *   selector 2      format code 1
 *   selector 1      depends on the signal code (see below)
 *   anything else   the option byte (input_csc_option_byte)
 *
 * With selector 1, for the signal codes 0x31, 0x41, 0x51, 0x61, 0x71 and 0x81 the format code is the caller's
 * value. For signal code 0x21 the size of the capture window decides: for 1920 x 1080 and for 1280 x 720
 * register 1 of the block gets 0x24 and the format code becomes 9; for every other size register 1 gets 1 and
 * the format code becomes 3. Between the register write and the store it calls timer_sleep_ticks(20). For any
 * other signal code the format code is 1 (the selector).
 *
 *   unused       not used
 *   port         input block
 *   signal_code  signal code of the block (input_block_get_signal_code)
 *   value        format code to take for the codes that pass it on
 *
 * No routine in the image calls it; input_csc_setup contains the same logic inline.
 */
void input_csc_set_format_code(unsigned int unused, unsigned char port, unsigned char signal_code, unsigned char value)
{
    if (input_csc_selector == 1) {
        if (signal_code == 0x31 || signal_code == 0x41)
            input_csc_format_code = value;
        else if (signal_code == 0x51 || signal_code == 0x61)
            input_csc_format_code = value;
        else if (signal_code == 0x21) {
            unsigned short width = input_block_get_capture_hstart(port);
            unsigned short height = input_block_get_capture_vstart(port);

            if ((width == 0x780 && height == 0x438) || (width == 0x500 && height == 0x2d0))
                input_capture_write8(port, 1, 0x24);
            else
                input_capture_write8(port, 1, 1);
            timer_sleep_ticks(20);
            if ((width == 0x780 && height == 0x438) || (width == 0x500 && height == 0x2d0))
                input_csc_format_code = 9;
            else
                input_csc_format_code = 3;
        } else if (signal_code == 0x71)
            input_csc_format_code = value;
        else if (signal_code == 0x81)
            input_csc_format_code = value;
        else
            input_csc_format_code = input_csc_selector;
    } else if (input_csc_selector == 2)
        input_csc_format_code = 1;
    else
        input_csc_format_code = input_csc_option_byte;
}
