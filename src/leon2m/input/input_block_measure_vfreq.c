/* input_block_measure_vfreq  (FUN_a0120b38)
 *
 * Measure the vertical frequency of the signal on an input block.
 * Returns: frequency, 0xFFFF when out of range
 * Name basis: proven - from the frame-period count, in tenths of a hertz
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0120b38 @ 0xa0120b38, flags -mcpu=v8 -O3 -g.
 * Source form: the range test is (unsigned short)(count - 1027) > 0x453b; the result is an unsigned short
 * variable assigned in three arms; the clock constant is unsigned (120000000u), so the divisions are unsigned.
 */
struct input_block_config { unsigned int word_0, word_4, word_8; };
extern struct input_block_config input_block_configs[];
extern unsigned short input_measure_read16(unsigned char, unsigned char);

#define VFREQ_COUNT_MIN 1027                /* smallest frame count that counts as a measurement */
#define VFREQ_COUNT_MAX 18750               /* largest */
#define VFREQ_CLOCK     120000000u          /* divided by the count */

/*
 * Measure the vertical (frame) frequency of the signal on an input block, in tenths of a hertz.
 *
 * The frame count is the 16-bit value of registers 0x14/0x15 of the measure block. Outside 1027..18750 there
 * is no measurement and the result is 0xFFFF. Otherwise the frequency is 120000000 / count, rounded to nearest
 * after a division by 32 when word 4 of the block's configuration (input_block_configs) is 1, and by 256
 * otherwise. With the division by 32, a count of 6250 gives 600 (60.0 Hz).
 *
 *   blk  input block
 *
 * Called from input_block_calc_rates, input_bring_up_set_pixel_clock, input_fill_port_timing and drv_PanelLimitation. The same routine exists in
 * the earlier firmware FW.012.
 */
unsigned short input_block_measure_vfreq(unsigned char blk)
{
    unsigned short count = input_measure_read16(blk, 0x14);
    unsigned short vfreq;

    if ((unsigned short)(count - VFREQ_COUNT_MIN) > VFREQ_COUNT_MAX - VFREQ_COUNT_MIN)
        vfreq = 0xffff;
    else if (input_block_configs[blk].word_4 == 1)
        vfreq = (VFREQ_CLOCK / count + 0x10) >> 5;
    else
        vfreq = (VFREQ_CLOCK / count + 0x80) >> 8;
    return vfreq;
}
