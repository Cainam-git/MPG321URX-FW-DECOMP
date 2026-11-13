/* dp_tx_get_reg70_bit4  (FUN_a0088f28)
 *
 * Return bit 4 of register 0x70 of a DP output.
 *   port: output
 * Name basis: descriptive - single register read; callers ipc_dispatch_command and a port state routine
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: dp_tx_reg_read8 returns an unsigned char; the bit test goes through the unsigned int 'bits'.
 */
extern unsigned char dp_tx_reg_read8(unsigned int, unsigned short);

/*
 * Return 1 when bit 4 of register 0x70 of a DP output is set, else 0. The bit is the one dp_tx_set_reg70_bit4
 * writes.
 *
 *   port: DP output 0..4
 *
 * Called from the mailbox command dispatcher (ipc_dispatch_command) and from hdcp_tx_service_port.
 */
unsigned int dp_tx_get_reg70_bit4(unsigned int port)
{
    unsigned int bits = dp_tx_reg_read8(port & 0xff, 0x70) & 0x10;
    return bits != 0;
}
