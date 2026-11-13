/* input_block_measure_hfreq  (FUN_a0120a18)
 *
 * Measure the horizontal frequency of the signal on an input block.
 * Returns: frequency, 0xFFFF when out of range
 * Name basis: proven - 96 MHz divided by the measured count, in units of 100 Hz
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0120a18 @ 0xa0120a18, flags -mcpu=v8 -O3 -g.
 * Source form: the range test is (unsigned short)(count - 147) > 0x1ead; the result is stored to
 * input_measured_hfreq and read back for the compare and the return.
 */
extern unsigned short input_measured_hfreq;
extern unsigned short input_measure_read16(unsigned char port, unsigned char reg);
extern unsigned char input_block_get_reg8c_bit7(unsigned char port);
extern unsigned short input_capture_read16(unsigned char port, unsigned char reg);
extern void input_measure_update_bits(unsigned char port, unsigned char reg, unsigned char mask, unsigned char val);

#define HFREQ_COUNT_MIN   147               /* smallest line count that counts as a measurement */
#define HFREQ_COUNT_MAX   8000              /* largest */
#define HFREQ_CLOCK       96000000          /* divided by the count */
#define HFREQ_LOW_LIMIT   332               /* at or below this value (33.2 kHz) bit 7 of register 0x2E is set */

/*
 * Measure the horizontal (line) frequency of the signal on an input block, in units of 100 Hz.
 *
 * The line count is the 13-bit value of registers 0x12/0x13 of the measure block. From 147 to 8000 the
 * frequency is (96000000 / count + 50) / 100. Outside that range there is no measurement: when bit 7 of
 * register 0x8C of the block is set (input_block_get_reg8c_bit7) the frequency is 120000 / (value of register
 * pair 0x57 of the capture block + 1), otherwise 0xFFFF.
 *
 * Bit 7 of register 0x2E is then set when the result is 332 or less, and cleared otherwise. The result is also
 * kept in input_measured_hfreq.
 *
 *   port  input block
 *
 * Called from input_block_calc_rates, input_adc_auto_adjust, input_is_sample_rate_too_high and input_fill_port_timing.
 */
unsigned short input_block_measure_hfreq(unsigned char port)
{
    unsigned int count;

    count = input_measure_read16(port, 0x12) & 0x1fff;
    if ((unsigned short)(count - HFREQ_COUNT_MIN) > HFREQ_COUNT_MAX - HFREQ_COUNT_MIN) {
        /* No measurement: second source, or 0xFFFF. */
        if (input_block_get_reg8c_bit7(port) == 1)
            input_measured_hfreq = 120000 / (unsigned short)(input_capture_read16(port, 0x57) + 1);
        else
            input_measured_hfreq = 0xffff;
    } else
        input_measured_hfreq = (HFREQ_CLOCK / count + 50) / 100;
    if (input_measured_hfreq <= HFREQ_LOW_LIMIT)
        input_measure_update_bits(port, 0x2e, 0x80, 1);
    else
        input_measure_update_bits(port, 0x2e, 0x80, 0);
    return input_measured_hfreq;
}
