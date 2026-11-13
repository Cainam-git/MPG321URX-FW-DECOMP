/* input_block_calc_rates  (FUN_a0105af8)
 *
 * Compute line and frame rate values of an input block as floating-point numbers.
 * Name basis: descriptive - from input_block_measure_hfreq / _vfreq and a block register; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0105af8 @ 0xa0105af8, flags -mcpu=v8 -O3 -g -msoft-float (the float arithmetic is libgcc
 * soft-float calls; plain -O3 -g does not match).
 * Source form: the first product is one expression of the two unsigned short returning calls (the firmware
 * zero-extends the first result before the second call); the three callees return unsigned short. The two
 * divisions by 1000.0f are separate statements (the constant is loaded once). The unsigned short cast on
 * size[1] and the +65536.0f for a negative size[0] are the firmware's conversions.
 */
extern void pq_block_update_bits(unsigned char, unsigned int, unsigned int, unsigned int);
extern unsigned short pq_block_read16(unsigned char, unsigned char);
extern unsigned short input_block_measure_hfreq(unsigned char);
extern unsigned short input_block_measure_vfreq(unsigned char);

/*
 * Compare two figures derived from the measured rates of an input block and set or clear bit 2 of register
 * 0x91 of the picture block of the same number:
 *
 *   line_value = measured line frequency * register pair 0x4C of the picture block / 1000
 *   frame_value = size[0] * size[1] * measured frame frequency / 1000 / 1000   (floating point)
 *
 * Bit 2 is set when line_value / (unsigned) frame_value is at most 14, and cleared otherwise.
 *
 *   port  input block
 *   size  two 16-bit values: size[0] is read as a 16-bit number (65536 is added when it is negative as a short),
 *         size[1] as unsigned
 *
 * No routine in the image calls it.
 */
void input_block_calc_rates(unsigned char port, short *size)
{
    unsigned int line_value;
    float frame_value;

    line_value = (unsigned int)(input_block_measure_hfreq(port) * pq_block_read16(port, 0x4c)) / 1000;
    frame_value = size[0];
    if (size[0] < 0)
        frame_value += 65536.0f;
    frame_value = frame_value * (unsigned short)size[1];
    frame_value = frame_value * input_block_measure_vfreq(port);
    frame_value = frame_value / 1000.0f;
    frame_value = frame_value / 1000.0f;
    if (line_value / (unsigned int)frame_value <= 14)
        pq_block_update_bits(port, 0x91, 4, 1);
    else
        pq_block_update_bits(port, 0x91, 4, 0);
}
