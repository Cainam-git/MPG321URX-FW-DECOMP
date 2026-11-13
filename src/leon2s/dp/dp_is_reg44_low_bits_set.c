/* dp_is_reg44_low_bits_set  (FUN_a00ad644)
 *
 * Return whether either of the low two bits of register 0x44 is set.
 * Returns: 0 or 1
 * Name basis: descriptive - plain test
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad644 @ 0xa00ad644, flags -mcpu=v8 -Os -g. Leaf. The result is a full word (a compare giving 0 or 1).
 */
extern unsigned int dp_reg_read8(unsigned int port, unsigned short reg);

/* Return 1 when bit 0 or bit 1 of receiver register 0x44 is set, else 0. dp_run_link_state prints it in its "Fifo Abnormal" lines.
 *   port: DP receiver
 */
unsigned int dp_is_reg44_low_bits_set(unsigned int port)
{
    return (dp_reg_read8(port & 0xff, 0x44) & 3) != 0;
}
