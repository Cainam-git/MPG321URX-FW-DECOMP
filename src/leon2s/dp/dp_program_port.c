/* dp_program_port  (FUN_a00abff0)
 *
 * Write the full register set-up of a DP receiver from its port record.
 *   port: DP receiver 0/1
 * Name basis: derived - mailbox commands 0x21 / 0x33; calls dp_write_capability_regs
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00abff0 @ 0xa00abff0-0xa00ac41c (1068 bytes), flags -mcpu=v8 -Os -g.
 * Source forms: every value choice is a separate call per arm (the compiler merges the common call); the
 * 0x30e / 0x333 writes and the 0x45d write are written in each arm; the 0x450 test is
 * 'byte_0x116 != 0 && (byte_0x112 == 1 && port == 0) == 0' (long arm first, the inner && as flag arithmetic).
 * The last dp_reg_update_bits call is a tail call.
 */
/* The fields of the port record read here. */
struct dp_input_record {
    unsigned char before_0x112[0x112];
    unsigned char byte_0x112;                   /* port 0 only: non-zero selects the alternative set-up */
    unsigned char byte_0x113;                   /* non-zero: registers 0x2A8, 0x2AA, 0x2AB get the second values */
    unsigned char byte_0x114;
    unsigned char byte_0x115;                   /* sets or clears bit 0x40 of register 0x207 */
    unsigned char byte_0x116;                   /* non-zero: the 0x450..0x45D group is written */
    unsigned char byte_0x117;                   /* 0 clears byte_0x112 */
    unsigned char pad_0x118[6];
    unsigned char byte_0x11e;                   /* picks the value of register 0x21C */
    unsigned char after_0x11e[0x12c - 0x11f];
};
extern struct dp_input_record dp_input_records[];   /* one 300-byte record per port */
extern unsigned char dp_dsc_4_slices_option;
extern void dp_write_capability_regs(unsigned char);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);

/*
 * Write the register set-up of a DP receiver from its port record.
 *
 * In order: byte 0x112 is cleared first when byte 0x117 is 0; the capability registers are written
 * (dp_write_capability_regs); then, with bit 7 of register 0x30 set around them, a fixed group of registers
 * 0x204..0x261 and 0x332, where register 0x21C depends on byte 0x11E. Registers 0x205, 0x207 and 0x301 are
 * set to 1, 0x81 and 1 for port 0 when byte 0x112 is non-zero, and cleared otherwise; 0x30E and 0x333 are
 * cleared in both cases. Byte 0x113 selects the values of 0x2A8, 0x2AA and 0x2AB, byte 0x115 sets or clears
 * bit 0x40 of register 0x207. The group 0x450..0x45D is written with its values when byte 0x116 is non-zero
 * and the port is not port 0 with byte 0x112 equal to 1; otherwise only 0x450 and 0x45D are cleared. Registers
 * 0x454 and 0x459 take their value from dp_dsc_4_slices_option being 1 or not. Last come 0x3E0..0x3E5 and the
 * clearing of bit 7 of register 0x30.
 * Called by dp_reset_port, by mailbox commands 0x21 and 0x33, and by the routines that store the options
 * +0x112, +0x115 and +0x116.
 *   port: DP receiver 0 or 1
 */
void dp_program_port(unsigned char port)
{
    if (dp_input_records[port].byte_0x117 == 0)
        dp_input_records[port].byte_0x112 = 0;
    dp_write_capability_regs(port);
    dp_reg_update_bits(port, 0x30, 0x80, 1);
    dp_reg_write8(port, 0x204, 1);
    dp_reg_write8(port, 0x206, 1);
    if (dp_input_records[port].byte_0x11e == 0)
        dp_reg_write8(port, 0x21c, 0x14);
    else
        dp_reg_write8(port, 0x21c, 6);
    dp_reg_write8(port, 0x21d, 0x84);
    dp_reg_write8(port, 0x225, 0x41);
    dp_reg_write8(port, 0x226, 0);
    dp_reg_update_bits(port, 0x20a, 4, 1);
    dp_reg_write8(port, 0x261, 0);
    dp_reg_write8(port, 0x332, 0x41);
    if (port == 0 && dp_input_records[port].byte_0x112) {
        dp_reg_write8(port, 0x205, 1);
        dp_reg_write8(port, 0x207, 0x81);
        dp_reg_write8(port, 0x301, 1);
        dp_reg_write8(port, 0x30e, 0);
        dp_reg_write8(port, 0x333, 0);
    } else {
        dp_reg_write8(port, 0x205, 0);
        dp_reg_write8(port, 0x207, 0);
        dp_reg_write8(port, 0x301, 0);
        dp_reg_write8(port, 0x30e, 0);
        dp_reg_write8(port, 0x333, 0);
    }
    if (dp_input_records[port].byte_0x113 == 0)
        dp_reg_write8(port, 0x2a8, 1);
    else {
        dp_reg_write8(port, 0x2a8, 3);
        dp_reg_write8(port, 0x2aa, 1);
        dp_reg_write8(port, 0x2ab, 1);
    }
    if (dp_input_records[port].byte_0x115)
        dp_reg_update_bits(port, 0x207, 0x40, 1);
    else
        dp_reg_update_bits(port, 0x207, 0x40, 0);
    if (dp_input_records[port].byte_0x116 != 0 && (dp_input_records[port].byte_0x112 == 1 && port == 0) == 0) {
        dp_reg_write8(port, 0x450, 1);
        dp_reg_write8(port, 0x451, 0x21);
        dp_reg_write8(port, 0x452, 0);
        dp_reg_write8(port, 0x453, 0x76);
        if (dp_dsc_4_slices_option == 1)
            dp_reg_write8(port, 0x454, 0xb);
        else
            dp_reg_write8(port, 0x454, 0x2b);
        dp_reg_write8(port, 0x455, 1);
        dp_reg_write8(port, 0x456, 1);
        dp_reg_write8(port, 0x457, 7);
        dp_reg_write8(port, 0x458, 0xe);
        if (dp_dsc_4_slices_option == 1)
            dp_reg_write8(port, 0x459, 2);
        else
            dp_reg_write8(port, 0x459, 1);
        dp_reg_write8(port, 0x45a, 8);
        dp_reg_write8(port, 0x45b, 0);
        dp_reg_write8(port, 0x45c, 4);
        dp_reg_write8(port, 0x45d, 0xbf);
    } else {
        dp_reg_write8(port, 0x450, 0);
        dp_reg_write8(port, 0x45d, 0);
    }
    dp_reg_write8(port, 0x3e0, 0x38);
    dp_reg_write8(port, 0x3e1, 0xec);
    dp_reg_write8(port, 0x3e2, 0x11);
    dp_reg_write8(port, 0x3e3, 0);
    dp_reg_write8(port, 0x3e4, 0);
    dp_reg_write8(port, 0x3e5, 0);
    dp_reg_update_bits(port, 0x30, 0x80, 0);
}
