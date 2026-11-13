/* dp_get_hactive  (FUN_a00acac0)
 *
 * Return the horizontal active width of a DP input.
 *   port: DP receiver
 * Returns: pixels
 * Name basis: derived - high << 8 | low of two receiver registers; h2 slot (hactive) of
 *   input_read_port_timing; dp_is_high_rate_mode tests 0xD70 (3440)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00acac0 @ 0xa00acac0, flags -mcpu=v8 -Os -g.
 * Source form: the first read is masked and shifted right after its call, then the second read is made and added;
 * the 16-bit cast of the sum gives the final shift pair.
 */
extern unsigned int dp_reg_read8(unsigned int, unsigned short);

/*
 * Read the 16-bit horizontal active width of a DP input from receiver registers 0x89 (high byte) and 0x8A
 * (low byte). The callers store it as the hactive field of the port's timing.
 *   port: DP receiver
 */
unsigned short dp_get_hactive(unsigned int port)
{
    unsigned int high;

    port = port & 0xff;
    high = (dp_reg_read8(port, 0x89) & 0xff) << 8;
    return (unsigned short)(high + (dp_reg_read8(port, 0x8a) & 0xff));
}
