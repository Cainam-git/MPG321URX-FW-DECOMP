/* dp_write_rate_divider_regs  (FUN_a00ab6e0)
 *
 * Write DP receiver registers 0x26..0x2C from 48000 divided by a value.
 *   port: DP receiver
 *   divider
 *   force: 1 = always
 * Name basis: descriptive - value = port record halfword +0x120 (default 600), skipped when unchanged; caller
 *   dp_reset_port
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ab6e0 @ 0xa00ab6e0-0xa00ab884, flags -mcpu=v8 -Os -g.
 * Source forms: rest is an unsigned short local; the clamp is 'lo = 0xff; if (h <= 0xff) lo = h;'; the
 * division is signed.
 */
/* The settings record of a DP input port; only the fields read here are named. */
struct dp_input_record {
    unsigned char before_0x11f[0x11f];
    unsigned char byte_0x11f;                   /* 1 selects the other value of register 0x2B */
    unsigned char after_0x11f[0x12c - 0x120];
};
extern struct dp_input_record dp_input_records[];   /* one 300-byte record per port */
extern unsigned short dp_rate_divider;
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern unsigned int dp_reg_read8(unsigned int, unsigned short);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);

/*
 * Write the receiver registers 0x26..0x2C from the quotient 48000 / divider.
 *
 * Does nothing when divider is 0, or when it equals the value stored last in dp_rate_divider (one variable for
 * all ports) and force is 0. Otherwise the quotient q is split into lo = q / 2 (at most 0xFF) and
 * rest = q - lo. Registers 0x26 and 0x27 get lo / 2 and lo, 0x28 gets rest / 2 and 0x29 the remainder of rest
 * after what register 0x28 reads back. When rest / 2 does not fit in a byte the four registers get the fixed
 * values 0x80, 0xFF, 0xFF, 0xF0 instead. Register 0x2A gets 0x36, bits 0x31 of register 0x2E are set, and
 * register 0x2B gets 0xCC when byte 0x11F of the port's record is 1, else 0xD9; register 0x2C gets 0xF.
 *   port: DP receiver
 *   divider: value to divide 48000 by; dp_reset_port passes halfword 0x120 of the port record (default 600)
 *   force: 1 = write even when divider is the stored value
 */
void dp_write_rate_divider_regs(unsigned char port, unsigned short divider, unsigned char force)
{
    unsigned int quotient, half, lo;
    unsigned short rest;

    if (divider == 0)
        return;
    if (dp_rate_divider == divider && force == 0)
        return;
    quotient = 48000 / divider;
    half = quotient >> 1;
    dp_rate_divider = divider;
    lo = 0xff;
    if (half <= 0xff)
        lo = half;
    rest = quotient - lo;
    if ((rest >> 1) > 0xff) {
        /* Does not fit in the register pair: fixed values. */
        dp_reg_write8(port, 0x26, 0x80);
        dp_reg_write8(port, 0x27, 0xff);
        dp_reg_write8(port, 0x28, 0xff);
        dp_reg_write8(port, 0x29, 0xf0);
    } else {
        dp_reg_write8(port, 0x26, (unsigned short)lo >> 1);
        dp_reg_write8(port, 0x27, lo);
        dp_reg_write8(port, 0x28, rest >> 1);
        dp_reg_write8(port, 0x29, rest - dp_reg_read8(port, 0x28));
    }
    dp_reg_write8(port, 0x2a, 0x36);
    dp_reg_update_bits(port, 0x2e, 0x31, 1);
    if (dp_input_records[port].byte_0x11f == 1)
        dp_reg_write8(port, 0x2b, 0xcc);
    else
        dp_reg_write8(port, 0x2b, 0xd9);
    dp_reg_write8(port, 0x2c, 0xf);
}
