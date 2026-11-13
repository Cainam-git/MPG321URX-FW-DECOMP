/* input_block_set_sync_source  (FUN_a012127c)
 *
 * Select the sync source bits of an input block.
 * Name basis: descriptive - high bits of register 4 from the mode and register 0x1A; skipped for three signal
 *   codes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012127c @ 0xa012127c, flags -mcpu=v8 -O3 -g.
 * Source form: the signal code is fetched again for each comparison (three separate calls for the three early
 * exits, a fourth for 0x91); the nibble and the high part are unsigned chars.
 */
extern unsigned char input_block_get_signal_code(unsigned char);
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned char input_measure_read8(unsigned char blk, unsigned char reg);

/*
 * Rewrite the high nibble of capture register 4 of an input block, keeping the low nibble. Nothing is written
 * when the signal code of the block is 0x71, 0x81 or 0xB1.
 *
 * The high nibble is 0x80 when on is 0. When on is non-zero it is 0xE0 for signal code 0x91; otherwise it
 * depends on line_rate: above 0x3B3 it is 0xF0, above 0x1DE 0xE0, above 0xF4 0xC0, else 0x80, and it is shifted
 * left by one bit (as a byte) when measure register 0x1A is above 0x1F.
 *
 *   blk        input block
 *   line_rate  line rate of the channel (timing field 0)
 *   on         non-zero: choose the nibble from the signal code and line rate
 *
 * Called from input_setup_converter_port and input_block_handle_mode_change.
 */
void input_block_set_sync_source(unsigned char blk, unsigned short line_rate, unsigned char on)
{
    unsigned char low, high;

    low = input_capture_read8(blk, 4) & 0xf;
    if (input_block_get_signal_code(blk) == 0x71)
        return;
    if (input_block_get_signal_code(blk) == 0x81)
        return;
    if (input_block_get_signal_code(blk) == 0xb1)
        return;
    high = 0x80;
    if (on) {
        if (input_block_get_signal_code(blk) == 0x91)
            high = 0xe0;
        else {
            if (line_rate > 0x3b3)
                high = 0xf0;
            else if (line_rate > 0x1de)
                high = 0xe0;
            else if (line_rate > 0xf4)
                high = 0xc0;
            if (input_measure_read8(blk, 0x1a) > 0x1f)
                high <<= 1;
        }
    }
    input_capture_write8(blk, 4, low | high);
}
