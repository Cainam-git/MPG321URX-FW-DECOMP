/* dp_write_port_option_regs  (FUN_a00abbc4)
 *
 * Write DP receiver registers 0x3B0..0x3C4 from the port record settings.
 *   port: DP receiver 0/1
 * Name basis: derived - record bytes +0x110..+0x124; caller dp_write_capability_regs
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00abbc4 @ 0xa00abbc4-0xa00abe20, flags -mcpu=v8 -Os -g.
 * Source form: each arm holds its complete call (as in dp_write_capability_regs).
 */
/* The fields of the port record read here. */
struct dp_input_record {
    unsigned char before_0x110[0x110];
    unsigned char byte_0x110;                   /* 1..3 selects the value of register 0x3B1 and 0x3B3 */
    unsigned char byte_0x111;                   /* 1..2 selects the value of register 0x3B2 */
    unsigned char byte_0x112;                   /* port 0 only: non-zero adds the 0x3B5..0x3BB writes */
    unsigned char pad_0x113[2];
    unsigned char byte_0x115;                   /* non-zero sets bit 0x40 of register 0x3B7 */
    unsigned char pad_0x116[0x123 - 0x116];
    unsigned char byte_0x123;                   /* non-zero writes registers 0x3C0, 0x3C2, 0x3C3 */
    unsigned char byte_0x124;                   /* non-zero writes register 0x3C4 */
    unsigned char after_0x124[0x12c - 0x125];
};
extern struct dp_input_record dp_input_records[];   /* one 300-byte record per port */
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);

/*
 * Write the option registers 0x3B0..0x3C4 of a DP receiver from the settings in its port record.
 *
 * Registers 0x3B0, 0x3B4, 0x3B6 and 0x3BD get fixed values and bit 4 of 0x3BA is set. 0x3B1 gets 0x1E, 0x14,
 * 10 or 6 for byte 0x110 = 3, 2, 1 or other; 0x3B2 gets 0xC4, 0xC2 or 0xC1 for byte 0x111 = 2, 1 or other;
 * 0x3B3 gets 0x81 for byte 0x110 = 3, else 1. After these the optional groups follow, each only when its byte
 * is non-zero (see the record). Called by dp_write_capability_regs.
 *   port: DP receiver 0 or 1
 */
void dp_write_port_option_regs(unsigned char port)
{
    dp_reg_write8(port, 0x3b0, 0x14);
    if (dp_input_records[port].byte_0x110 == 3)
        dp_reg_write8(port, 0x3b1, 0x1e);
    else if (dp_input_records[port].byte_0x110 == 2)
        dp_reg_write8(port, 0x3b1, 0x14);
    else if (dp_input_records[port].byte_0x110 == 1)
        dp_reg_write8(port, 0x3b1, 10);
    else
        dp_reg_write8(port, 0x3b1, 6);
    if (dp_input_records[port].byte_0x111 == 2)
        dp_reg_write8(port, 0x3b2, 0xc4);
    else if (dp_input_records[port].byte_0x111 == 1)
        dp_reg_write8(port, 0x3b2, 0xc2);
    else
        dp_reg_write8(port, 0x3b2, 0xc1);
    if (dp_input_records[port].byte_0x110 == 3)
        dp_reg_write8(port, 0x3b3, 0x81);
    else
        dp_reg_write8(port, 0x3b3, 1);
    dp_reg_write8(port, 0x3b4, 1);
    dp_reg_write8(port, 0x3b6, 1);
    dp_reg_update_bits(port, 0x3ba, 4, 1);
    dp_reg_write8(port, 0x3bd, 0);
    if (port == 0 && dp_input_records[port].byte_0x112 != 0) {
        dp_reg_write8(port, 0x3b5, 1);
        dp_reg_write8(port, 0x3b7, 0x81);
        dp_reg_write8(port, 0x3b8, 0);
        dp_reg_write8(port, 0x3b9, 0);
        dp_reg_write8(port, 0x3ba, 4);
        dp_reg_write8(port, 0x3bb, 0);
    }
    if (dp_input_records[port].byte_0x115 != 0)
        dp_reg_update_bits(port, 0x3b7, 0x40, 1);
    if (dp_input_records[port].byte_0x123 != 0) {
        dp_reg_write8(port, 0x3c0, 0xf0);
        dp_reg_write8(port, 0x3c2, 0x10);
        dp_reg_write8(port, 0x3c3, 0x10);
    }
    if (dp_input_records[port].byte_0x124 != 0)
        dp_reg_write8(port, 0x3c4, 1);
}
