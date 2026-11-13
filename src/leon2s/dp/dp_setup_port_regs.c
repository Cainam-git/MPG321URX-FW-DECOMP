/* dp_setup_port_regs  (FUN_a00ac66c)
 *
 * Write the fixed register set-up of a DP receiver port.
 *   port: DP receiver
 * Name basis: derived - long write list branching on record bytes +0x110 / +0x112; port 0 also enables its
 *   interrupt; mailbox command 0x21
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ac66c @ 0xa00ac66c-0xa00acac0 (277 words), flags -mcpu=v8 -Os -g.
 * Source form: both record reads index dp_input_records[port] the same way, so the compiler shares one address; the
 * byte_0x110 value is read after the register 0xA0 call (the firmware loads it after the call). The last
 * dp_reg_update_bits call is a tail call.
 */
/* The fields of the port record read here. */
struct dp_input_record {
    unsigned char before_0x110[0x110];
    unsigned char byte_0x110;                   /* 0 or 1 picks the value of register 0x47 */
    unsigned char pad_0x111;
    unsigned char byte_0x112;                   /* port 0 only: non-zero adds the alternative set-up block */
    unsigned char after_0x112[300 - 0x113];
};
extern struct dp_input_record dp_input_records[];   /* one 300-byte record per port */
extern void dp_reg_write8(unsigned int, unsigned short, unsigned int);
extern void dp_reg_update_bits(unsigned int, unsigned short, unsigned int, unsigned int);
extern void dp_status_reg_write8(unsigned int, unsigned short, unsigned int);
extern void irq_enable_dp_port0(void);

/*
 * Write the fixed register set-up of a DP receiver.
 *
 * A long list of register writes and bit updates, the same for every port, with these exceptions:
 *  - register 0xC0 bit 0 is cleared only when byte 0x112 of the port record is 0;
 *  - register 0x47 gets 0x40 when byte 0x110 is 0 and 0x80 when it is 1 (left alone for other values);
 *  - register 0x24 bit 7 is set for port 0 and cleared for the other ports;
 *  - port 0 with byte 0x112 non-zero runs one more block: bit 5 of hardware word 0xCF004680 is set, registers
 *    0xF7, 0, 0x38 and 9..0xE of port 0 and register 0x3E of its status block are written,
 *    irq_enable_dp_port0 is called, and bit 0 of 0xCF0046A8 and bit 1 of 0xCF0046AC are cleared.
 * Called by dp_reset_port, by the mailbox command 0x21 and by the routines that store options +0x115 / +0x116
 * and port 0 option +0x112, each after dp_program_port.
 *   port: DP receiver 0 or 1
 */
void dp_setup_port_regs(unsigned char port)
{
    unsigned char setting;

    dp_reg_write8(port, 0, 0x1f);
    dp_reg_write8(port, 0x30, 0x30);
    dp_reg_update_bits(port, 0xc0, 8, 0);
    dp_reg_update_bits(port, 0xc0, 0x10, 1);
    if (dp_input_records[port].byte_0x112 == 0) {
        dp_reg_update_bits(port, 0xc0, 1, 0);
    }
    dp_reg_update_bits(port, 0x33, 0x87, 1);
    dp_reg_update_bits(port, 0x37, 0x38, 1);
    dp_reg_write8(port, 0x3a, 0x82);
    dp_reg_write8(port, 0x34, 4);
    dp_reg_write8(port, 0xc7, 0x20);
    dp_reg_update_bits(port, 1, 0xf, 0);
    dp_reg_write8(port, 0x3f, 0x20);
    dp_reg_update_bits(port, 0xa0, 8, 1);
    dp_reg_write8(port, 0xb4, 0x49);
    dp_reg_update_bits(port, 0x42, 0x40, 1);
    dp_reg_update_bits(port, 0xa0, 4, 1);
    setting = dp_input_records[port].byte_0x110;
    if (setting == 0) {
        dp_reg_write8(port, 0x47, 0x40);
    } else if (setting == 1) {
        dp_reg_write8(port, 0x47, 0x80);
    }
    dp_reg_write8(port, 0x57, 3);
    dp_reg_update_bits(port, 0x55, 0x80, 0);
    dp_reg_write8(port, 0x58, 0);
    dp_reg_write8(port, 0x5a, 0);
    dp_reg_write8(port, 0x59, 0);
    dp_reg_write8(port, 0x70, 1);
    dp_reg_write8(port, 0x71, 0xff);
    dp_reg_write8(port, 0x50, 0x80);
    dp_reg_write8(port, 0x54, 0xff);
    dp_reg_write8(port, 0x11, 0xad);
    dp_reg_write8(port, 0x10, 0xb);
    dp_reg_write8(port, 0xf, 0);
    dp_reg_write8(port, 0x14, 0);
    dp_reg_write8(port, 0x13, 0x80);
    dp_reg_write8(port, 0x12, 0);
    if (!(port == 0)) {
        dp_reg_update_bits(port, 0x24, 0x80, 0);
    } else {
        dp_reg_update_bits(0, 0x24, 0x80, 1);
        if (dp_input_records[0].byte_0x112 != 0) {
            dp_reg_update_bits(0, 0x30, 0x80, 1);
            *((volatile unsigned int *) 0xcf004680) = (*((volatile unsigned int *) 0xcf004680)) | 0x20;
            dp_reg_update_bits(0, 0x30, 0x80, 0);
            dp_reg_write8(0, 0xf7, 3);
            dp_reg_write8(0, 0xf7, 0x91);
            irq_enable_dp_port0();
            *((volatile unsigned int *) 0xcf0046a8) = (*((volatile unsigned int *) 0xcf0046a8)) & 0xfffffffe;
            *((volatile unsigned int *) 0xcf0046ac) = (*((volatile unsigned int *) 0xcf0046ac)) & 0xfffffffd;
            dp_reg_update_bits(0, 0, 0x20, 1);
            dp_reg_update_bits(0, 0x38, 2, 1);
            dp_reg_write8(0, 9, 0);
            dp_reg_write8(0, 10, 0x1e);
            dp_reg_write8(0, 0xb, 0xe0);
            dp_reg_write8(0, 0xc, 0);
            dp_reg_write8(0, 0xd, 0x80);
            dp_reg_write8(0, 0xe, 0);
            dp_status_reg_write8(0, 0x3e, 1);
        }
    }
    dp_reg_update_bits(port, 0x39, 2, 1);
    dp_reg_update_bits(port, 0xc2, 1, 1);
    dp_reg_update_bits(port, 0x38, 8, 1);
    dp_reg_update_bits(port, 0x38, 0x10, 0);
    dp_reg_update_bits(port, 0xc2, 0x80, 1);
    dp_reg_update_bits(port, 0x40, 1, 0);
}
