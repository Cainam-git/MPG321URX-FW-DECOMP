/* dp_read_slice_count  (FUN_a00af1e8)
 *
 * Return the slice count of a port's DSC stream: the quotient of two 16-bit stream values.
 * Returns: count; 0 when no stream or the divisor is 0
 * Name basis: proven - indirect registers 0x0C:0x0D divided by 0x10:0x11; dp_check_timing_change prints the
 *   result as 'Slice Number'
 *
 * Matching notes
 * --------------
 * FUN_a00af1e8 (leon2s, 0xa00af1e8-0xa00af320, 78 words). Flags -mcpu=v8 -Os -g.
 * Twin of dp_has_slice_count.
 * Source form: the bytes are joined with + (firmware add, not or); the result is an unsigned char (an unsigned
 * int result puts the quotient in %l1, the firmware uses %i0). The port is masked at each use.
 */
extern int dp_is_stream_present(unsigned int);
extern unsigned int dp_reg_read8(unsigned int, unsigned short);
extern void dp_reg_write8(unsigned int, unsigned short, unsigned int);

/* Indirect register access of the receiver: the index goes to register 0x73, the data comes from register 0x7A. */
#define INDIRECT_SELECT_REG   0x70      /* 0 is written before every index */
#define INDIRECT_INDEX_REG    0x73
#define INDIRECT_DATA_REG     0x7a

/*
 * Return the quotient of two 16-bit values of the stream measurement: the value in indirect registers 0x0C:0x0D
 * (high byte first) divided by the value in 0x10:0x11. Return 0 when the port receives no stream
 * (dp_is_stream_present) or when the divisor is 0.
 *   port: DP receiver (0 or 1)
 * Called by dp_check_timing_change.
 */
unsigned char dp_read_slice_count(char port)
{
    unsigned short numerator;
    unsigned short divisor;
    unsigned int num_high, num_low, div_high, div_low;
    unsigned char result;

    if ((dp_is_stream_present(port & 0xff) & 0xff) == 0) {
        return 0;
    }

    dp_reg_write8(port & 0xff, INDIRECT_SELECT_REG, 0);
    dp_reg_write8(port & 0xff, INDIRECT_INDEX_REG, 0xc);
    num_high = dp_reg_read8(port & 0xff, INDIRECT_DATA_REG);
    dp_reg_write8(port & 0xff, INDIRECT_SELECT_REG, 0);
    dp_reg_write8(port & 0xff, INDIRECT_INDEX_REG, 0xd);
    num_low = dp_reg_read8(port & 0xff, INDIRECT_DATA_REG);
    dp_reg_write8(port & 0xff, INDIRECT_SELECT_REG, 0);
    dp_reg_write8(port & 0xff, INDIRECT_INDEX_REG, 0x10);
    div_high = dp_reg_read8(port & 0xff, INDIRECT_DATA_REG);
    dp_reg_write8(port & 0xff, INDIRECT_SELECT_REG, 0);
    dp_reg_write8(port & 0xff, INDIRECT_INDEX_REG, 0x11);
    div_low = dp_reg_read8(port & 0xff, INDIRECT_DATA_REG);

    divisor = ((div_high & 0xff) << 8) + (div_low & 0xff);
    numerator = ((num_high & 0xff) << 8) + (num_low & 0xff);

    result = 0;
    if (divisor != 0) {
        result = numerator / divisor;
    }
    return result;
}
