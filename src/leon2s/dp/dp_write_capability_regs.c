/* dp_write_capability_regs  (FUN_a00abe20)
 *
 * Rewrite the capability registers 0x200..0x203 and 0x266 of a DP receiver.
 *   port: DP receiver 0/1
 * Name basis: derived - mailbox command 0x25; values from the port record bytes
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00abe20 @ 0xa00abe20-0xa00abff0, flags -mcpu=v8 -Os -g.
 * Source form: each arm holds its complete call; GCC shares the common arguments. The last
 * dp_reg_update_bits call is a tail call.
 */
/* The fields of the port record read here. */
struct dp_input_record {
    unsigned char before_0x110[0x110];
    unsigned char byte_0x110;                   /* 1..3 */
    unsigned char byte_0x111;                   /* 1..2 */
    unsigned char pad_0x112[5];
    unsigned char byte_0x117;                   /* 0, 1 or 2 */
    unsigned char after_0x117[0x12c - 0x118];
};
extern struct dp_input_record dp_input_records[];   /* one 300-byte record per port */
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern void dp_write_port_option_regs(unsigned char);

/*
 * Rewrite the capability registers 0x200..0x203 and 0x266 of a DP receiver from its port record.
 *
 * Bit 7 of register 0x30 is set while the registers are written and cleared at the end. The values:
 *   0x200 = 0x12 when byte 0x117 is 1 or 2, else 0x11
 *   0x201 = 0x14 when byte 0x110 is 2 or 3, 10 when it is 1, else 6
 *   0x202 = 0x84 / 0x82 / 0x81 for byte 0x111 = 2 / 1 / other, then bit 0x40 set when byte 0x117 is non-zero,
 *           else cleared
 *   0x203 = 0x81 when byte 0x110 is 3, else 1
 *   0x266 = 0x83 when byte 0x117 is 2, and then the option registers are written (dp_write_port_option_regs);
 *           else 0
 * Mailbox command 0x25 (ipc_set_dp_rx_capabilities) calls this after storing the two mode bytes.
 *   port: DP receiver 0 or 1
 */
void dp_write_capability_regs(unsigned char port)
{
    dp_reg_update_bits(port, 0x30, 0x80, 1);
    if ((unsigned char)(dp_input_records[port].byte_0x117 - 1) <= 1)
        dp_reg_write8(port, 0x200, 0x12);
    else
        dp_reg_write8(port, 0x200, 0x11);
    if ((unsigned char)(dp_input_records[port].byte_0x110 - 2) <= 1)
        dp_reg_write8(port, 0x201, 0x14);
    else if (dp_input_records[port].byte_0x110 == 1)
        dp_reg_write8(port, 0x201, 10);
    else
        dp_reg_write8(port, 0x201, 6);
    if (dp_input_records[port].byte_0x111 == 2)
        dp_reg_write8(port, 0x202, 0x84);
    else if (dp_input_records[port].byte_0x111 == 1)
        dp_reg_write8(port, 0x202, 0x82);
    else
        dp_reg_write8(port, 0x202, 0x81);
    if (dp_input_records[port].byte_0x117 == 0)
        dp_reg_update_bits(port, 0x202, 0x40, 0);
    else
        dp_reg_update_bits(port, 0x202, 0x40, 1);
    if (dp_input_records[port].byte_0x110 == 3)
        dp_reg_write8(port, 0x203, 0x81);
    else
        dp_reg_write8(port, 0x203, 1);
    if (dp_input_records[port].byte_0x117 == 2) {
        dp_reg_write8(port, 0x266, 0x83);
        dp_write_port_option_regs(port);
    } else {
        dp_reg_write8(port, 0x266, 0);
    }
    dp_reg_update_bits(port, 0x30, 0x80, 0);
}
