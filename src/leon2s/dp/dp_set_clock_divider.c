/* dp_set_clock_divider  (FUN_a00aee08)
 *
 * Write a 16-bit value and an n-bit mask to the clock registers of a port.
 * Name basis: descriptive - registers 0x8B / 0x8C and 0x9A
 *
 * Matching notes
 * --------------
 * FUN_a00aee08 (leon2s 0xa00aee08-0xa00aef04, 252 bytes), flags -mcpu=v8 -Os -g.
 * Source forms: the saved bytes are unsigned short locals (the firmware masks them at the read and again at the
 * write); the mask is an unsigned char; the bit counter is initialised at its declaration and again before the
 * loop.
 */
extern unsigned int dp_reg_read8(unsigned int, unsigned short);
extern void dp_reg_write8(unsigned int, unsigned short, unsigned char);
extern void dp_reg_update_bits(unsigned int, unsigned short, unsigned int, unsigned int);

/*
 * Set bit 3 of register 0x482, set bit 6 of register 0x9F and bit 2 of register 0x32, write registers 0x89 and
 * 0x8A back with the values they had, write the high byte and the low byte of divider to registers 0x8B and 0x8C
 * and a mask of the lowest bit_count bits to register 0x9A, then clear bit 6 of register 0x9F.
 *   port: DP receiver (0 or 1)
 *   divider: 16-bit value for registers 0x8B (high byte) and 0x8C (low byte)
 *   bit_count: number of low bits set in the value written to register 0x9A
 * Called by dp_calc_stream_clock with its horizontal size value and its ratio.
 */
void dp_set_clock_divider(unsigned int port, unsigned int divider, unsigned char bit_count)
{
    unsigned short saved_89;
    unsigned short saved_8a;
    unsigned char i = 0;
    unsigned char mask;

    port &= 0xff;
    dp_reg_update_bits(port, 0x482, 8, 1);
    saved_89 = dp_reg_read8(port, 0x89) & 0xff;
    saved_8a = dp_reg_read8(port, 0x8a) & 0xff;
    dp_reg_update_bits(port, 0x9f, 0x40, 1);
    dp_reg_update_bits(port, 0x32, 4, 1);
    dp_reg_write8(port, 0x89, saved_89);
    dp_reg_write8(port, 0x8a, saved_8a);
    dp_reg_write8(port, 0x8b, (unsigned short)divider >> 8);
    dp_reg_write8(port, 0x8c, divider);
    mask = 0;
    i = 0;
    if (bit_count != 0) {
        do {
            mask = (1 << i) | mask;
            i++;
        } while (i < bit_count);
    }
    dp_reg_write8(port, 0x9a, mask);
    dp_reg_update_bits(port, 0x9f, 0x40, 0);
}
