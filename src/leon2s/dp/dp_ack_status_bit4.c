/* dp_ack_status_bit4  (FUN_a00ad684)
 *
 * Copy the inverse of bit 4 of receiver register 0x8F into bit 1 of register 0x22A.
 * Name basis: descriptive - one register bit write
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad684 @ 0xa00ad684, flags -mcpu=v8 -Os -g.
 * Source form: an if/else with the same call in both arms, only the last argument differs; the compiler sets up
 * the first three arguments before the branch.
 */
extern unsigned int dp_reg_read8(unsigned int, unsigned short);
extern unsigned int dp_reg_update_bits(unsigned int, unsigned short, int, int);

/*
 * Copy the inverse of bit 4 of receiver register 0x8F into bit 1 of register 0x22A: bit 4 set clears the
 * bit, bit 4 clear sets it. Returns what dp_reg_update_bits returns. dp_run_link_state calls it.
 *   port_arg: DP receiver
 */
unsigned int dp_ack_status_bit4(unsigned int port_arg)
{
    unsigned int status;
    unsigned int port;

    port = port_arg & 0xff;
    status = dp_reg_read8(port, 0x8f);

    if (status & 0x10) {
        return dp_reg_update_bits(port, 0x22a, 2, 0);
    } else {
        return dp_reg_update_bits(port, 0x22a, 2, 1);
    }
}
