/* dp_has_slice_count  (FUN_a00af320)
 *
 * Return whether a port's slice count is non-zero while bit 6 of register 0x8F is set.
 * Returns: 1 or 0
 * Name basis: derived - same quotient as dp_read_slice_count (indirect registers 0x0C:0x0D by 0x10:0x11),
 *   gated by register 0x8F bit 6
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00af320 @ 0xa00af320-0xa00af464 (81 words), flags -mcpu=v8 -Os -g.
 * Twin of dp_read_slice_count.
 * Source form: the bytes are combined with '+' (firmware add); the quotient is kept in an unsigned int and the
 * result is '(quotient & 0xff) != 0'. The port is masked at each use.
 */
extern unsigned int dp_reg_read8(unsigned int, unsigned short);
extern void dp_reg_write8(unsigned int, unsigned short, unsigned int);

/* Indirect register access of the receiver: the index goes to register 0x73, the data comes from register 0x7A. */
#define INDIRECT_SELECT_REG   0x70      /* 0 is written before every index */
#define INDIRECT_INDEX_REG    0x73
#define INDIRECT_DATA_REG     0x7a

/*
 * Do the same measurement as dp_read_slice_count, but take bit 6 of register 0x8F instead of
 * dp_is_stream_present as the test for a stream. Return 0 when that bit is clear. Otherwise return 1 when the
 * quotient of the value in indirect registers 0x0C:0x0D by the value in 0x10:0x11 (0 for a divisor of 0) is
 * non-zero in its low byte, else 0.
 *   port: DP receiver (0 or 1)
 * Called from dp_run_link_state.
 */
int dp_has_slice_count(char port)
{
    unsigned short numerator;
    unsigned short divisor;
    unsigned int num_high, num_low, div_high, div_low;
    unsigned int quotient;

    if ((dp_reg_read8(port & 0xff, 0x8f) & 0x40) == 0) {
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

    quotient = 0;
    if (divisor != 0) {
        quotient = numerator / divisor;
    }
    return (quotient & 0xff) != 0;
}
