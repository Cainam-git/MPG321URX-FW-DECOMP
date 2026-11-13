/* dp_tx_init_port_link_regs  (FUN_a0085b80)
 *
 * Write the start-up link registers of a DP output and store its default limits.
 *   port: output
 * Name basis: derived - link rate register 2 = 0x1E (HBR3) and lane register 3 = 0x84 (4 lanes, enhanced
 *   framing) kept as limits
 *
 * Matching notes
 * --------------
 * FUN_a0085b80 (leon2s 0xa0085b80-0xa0085dcc), flags -mcpu=v8 -Os -g.
 * dp_tx_limits_others and dp_tx_limits_port0 are volatile as in their other matched users (dp_tx_set_max_link_rate,
 * dp_tx_set_max_lane_count, dp_tx_init_sink_caps, dp_tx_handle_test_request, dp_tx_choose_link_config).
 * Source form: port 0 and the other outputs are two separate copies of the register sequence.
 */
#define R8E80 (*(volatile unsigned int *)0xcf018e80)
#define R8E84 (*(volatile unsigned int *)0xcf018e84)
#define R8E8C (*(volatile unsigned int *)0xcf018e8c)
#define R8EA8 (*(volatile unsigned int *)0xcf018ea8)
#define R8EAC (*(volatile unsigned int *)0xcf018eac)
#define R8EB0 (*(volatile unsigned int *)0xcf018eb0)
#define R8ED0 (*(volatile unsigned int *)0xcf018ed0)
#define R8ED4 (*(volatile unsigned int *)0xcf018ed4)

extern volatile unsigned char dp_tx_limits_port0[];
extern volatile unsigned char dp_tx_limits_others[];
extern void dp_tx_reg_update_bits(unsigned int port, short reg, unsigned int mask, unsigned int mode);
extern void dp_tx_reg_write8(unsigned int, unsigned short, unsigned int);
extern unsigned char dp_tx_reg_read8(unsigned int, unsigned short);
extern void dp_tx_set_lane_routing(unsigned char);

/*
 * Write the start-up link registers of one DP output, store its default link limits and finish with
 * dp_tx_set_lane_routing.
 *
 *   port  DP output 0..4
 *
 * Called from dp_tx_init_ports for each output not skipped there.
 *
 * The sequence is the same for every output (transmitter registers 0x72, 0x75, 2, 3, 0x71, 1, 0x76, 0x18,
 * 0x6d): register 2 (link rate) gets 0x1e, register 3 keeps its bit 6 and gets 0x84 in the other bits. The two
 * values 0x1e and 0x84 are also stored as the limit pair of the output (byte 0 rate code, byte 1 lane count
 * byte): output 0 has its own pair (dp_tx_limits_port0), outputs 1..4 share one (dp_tx_limits_others).
 * Output 0 alone also writes the registers 0xcf018e80..0xcf018ed4 and sets bit 4 of its register 0x7d.
 */
void dp_tx_init_port_link_regs(unsigned char port)
{
    if (port == 0) {
        dp_tx_reg_update_bits(0, 0x72, 0x20, 1);
        dp_tx_reg_update_bits(0, 0x75, 0x80, 1);
        dp_tx_reg_write8(0, 2, 0x1e);
        dp_tx_reg_write8(0, 3, (unsigned char)((dp_tx_reg_read8(0, 3) & 0x40) | 0x84));
        dp_tx_limits_port0[0] = 0x1e;
        dp_tx_limits_port0[1] = 0x84;
        dp_tx_reg_write8(0, 0x71, 0xfe);
        dp_tx_reg_update_bits(0, 1, 0x20, 1);
        dp_tx_reg_update_bits(0, 0x76, 4, 1);
        dp_tx_reg_update_bits(0, 0x18, 0x11, 1);
        dp_tx_reg_update_bits(0, 0x6d, 0x80, 1);
        /* Output 0 only: fixed values in the registers 0xcf018e80..0xcf018ed4. */
        R8EA8 = 0x84;
        R8E80 = 0x13;
        R8EB0 |= 1;
        R8E84 &= ~0x70;
        R8E84 |= 4;
        R8E8C = 5;
        R8EAC = 0x38;
        R8ED0 = 0x30;
        R8ED4 = 0xaa;
        dp_tx_reg_update_bits(0, 0x7d, 0x10, 1);
    } else {
        dp_tx_reg_update_bits(port, 0x72, 0x20, 1);
        dp_tx_reg_update_bits(port, 0x75, 0x80, 1);
        dp_tx_reg_write8(port, 2, 0x1e);
        dp_tx_reg_write8(port, 3, (unsigned char)((dp_tx_reg_read8(port, 3) & 0x40) | 0x84));
        dp_tx_limits_others[0] = 0x1e;
        dp_tx_limits_others[1] = 0x84;
        dp_tx_reg_write8(port, 0x71, 0xfe);
        dp_tx_reg_update_bits(port, 1, 0x20, 1);
        dp_tx_reg_update_bits(port, 0x76, 4, 1);
        dp_tx_reg_update_bits(port, 0x18, 0x11, 1);
        dp_tx_reg_update_bits(port, 0x6d, 0x80, 1);
    }
    /* The lane selection reads the lane counts set above. */
    dp_tx_set_lane_routing(port);
}
