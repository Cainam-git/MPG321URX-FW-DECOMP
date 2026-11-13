/* input_block_measure_pixel_clock  (FUN_a0120c90)
 *
 * Compute the timing value of an input block that the output clock is derived from.
 * Name basis: derived - floating-point computation from the measured counts
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0120c90 @ 0xa0120c90, flags -mcpu=v8 -O3 -g -msoft-float (float source; the callees at
 * 0xa0155xxx and 0xa01560ac are the libgcc soft-float routines, see src/leon2m/*.lib).
 * Source form: line_count is an int and frame_count a short (an unsigned short frame_count is extended again,
 * an int one gives 'and o0,l0' instead of the firmware's 'and l0,o0'); the result is an unsigned short.
 */
struct input_block_config { unsigned int word_0, word_4, word_8; };
extern struct input_block_config input_block_configs[];
extern unsigned short input_measure_read16(unsigned char, unsigned char);
extern unsigned char input_capture_read8(unsigned char, unsigned char);

/*
 * Return a timing value of the signal on an input block, or 0 when the counts are out of range.
 *
 * The line count is the 13-bit value of registers 0x12/0x13 of the measure block and must lie in 147..8000;
 * the frame count is the 13-bit value of registers 0x14/0x15 and must lie in 1027..18750 (the ranges
 * input_block_measure_hfreq and input_block_measure_vfreq use). Otherwise the result is 0.
 *
 * When bit 1 of register 4 of the capture block is set and register 0x54 of it is 0x20, the result is
 * frame_count * 256 / line_count, or frame_count * 2048 / line_count when word 4 of the block's configuration
 * is not 1, rounded to nearest (floating point). In every other case it is register pair 0x26 of the measure
 * block plus 1.
 *
 *   port  input block
 *
 * Called from input_adc_set_capture_offsets, panel_calc_output_pixel_clock and input_fill_port_timing.
 */
unsigned short input_block_measure_pixel_clock(unsigned char port)
{
    int line_count;
    short frame_count;
    float scaled;

    line_count = input_measure_read16(port, 0x12) & 0x1fff;
    if ((unsigned short)(line_count - 0x93) > 0x1ead)
        return 0;
    frame_count = input_measure_read16(port, 0x14) & 0x1fff;
    if ((unsigned short)(frame_count - 0x403) > 0x453b)
        return 0;
    if ((input_capture_read8(port, 4) & 2) && input_capture_read8(port, 0x54) == 0x20) {
        if (input_block_configs[port].word_4 == 1)
            scaled = (float)frame_count * 256.0f;
        else
            scaled = (float)frame_count * 2048.0f;
        return (unsigned int)((double)(scaled / (float)line_count) + 0.5);
    }
    return input_measure_read16(port, 0x26) + 1;
}
