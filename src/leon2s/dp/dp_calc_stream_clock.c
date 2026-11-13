/* dp_calc_stream_clock  (FUN_a00aef04)
 *
 * Read the stream's clock measurement values and program the clock recovery from them.
 * Name basis: derived - eight indirect registers 0x0A..0x11; numerator / denominator form
 *
 * Matching notes
 * --------------
 * FUN_a00aef04 (leon2s, 0xa00aef04-0xa00af168, 612 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the order denom, num, hres sets the firmware schedule of the byte-pair joins. The routine ends in
 * a tail call of dp_set_clock_divider; the firmware masks the parameter again for that call (port_arg & 0xff),
 * hence the separate byte local port.
 */
extern unsigned int dp_reg_read8(unsigned int, unsigned short);
extern void dp_reg_write8(unsigned int, unsigned short, unsigned char);
extern void dp_set_clock_divider(unsigned int, unsigned int, unsigned char);

/* Reads the clock measurement of a DisplayPort input and programs the clock recovery from it.
 *
 * The measurement sits in eight indirect registers 0x0a..0x11 of the receiver. The values 0x0c:0x0d (num),
 * 0x0e:0x0f (hres) and 0x10:0x11 (denom) are 16-bit values, high byte first; registers 0x0a and 0x0b are read
 * and the result is not used. A denom of 0 is replaced by 0x3c0 and an hres of 0 by 0x1e0. ratio is
 * num / denom (as a byte); register 0x481 is written 0x10, 0x20 or 0x40 for a ratio of 1, 2 or 4 and 0x80 for
 * any other ratio. The last step is dp_set_clock_divider(port, hres, ratio).
 *
 * port_arg: DP receiver. Called by dp_enable_dsc when it switches the recovery on.
 */
void dp_calc_stream_clock(unsigned int port_arg)
{
    unsigned char port = port_arg;
    unsigned int r0c, r0d, r0e, r0f, r10, r11;
    unsigned short num, hres, denom;
    unsigned char ratio;

    /* Each indirect read: register 0x70 = 0, register 0x73 = number, value from register 0x7a. */
    dp_reg_write8(port, 0x70, 0);
    dp_reg_write8(port, 0x73, 0xa);
    dp_reg_read8(port, 0x7a);
    dp_reg_write8(port, 0x70, 0);
    dp_reg_write8(port, 0x73, 0xb);
    dp_reg_read8(port, 0x7a);
    dp_reg_write8(port, 0x70, 0);
    dp_reg_write8(port, 0x73, 0xc);
    r0c = dp_reg_read8(port, 0x7a);
    dp_reg_write8(port, 0x70, 0);
    dp_reg_write8(port, 0x73, 0xd);
    r0d = dp_reg_read8(port, 0x7a);
    dp_reg_write8(port, 0x70, 0);
    dp_reg_write8(port, 0x73, 0xe);
    r0e = dp_reg_read8(port, 0x7a);
    dp_reg_write8(port, 0x70, 0);
    dp_reg_write8(port, 0x73, 0xf);
    r0f = dp_reg_read8(port, 0x7a);
    dp_reg_write8(port, 0x70, 0);
    dp_reg_write8(port, 0x73, 0x10);
    r10 = dp_reg_read8(port, 0x7a);
    dp_reg_write8(port, 0x70, 0);
    dp_reg_write8(port, 0x73, 0x11);
    r11 = dp_reg_read8(port, 0x7a);

    denom = (r10 & 0xff) * 0x100 + (r11 & 0xff);
    num = (r0c & 0xff) * 0x100 + (r0d & 0xff);
    hres = (r0e & 0xff) * 0x100 + (r0f & 0xff);
    /* A measurement of 0 is replaced by a fixed default. */
    if (denom == 0)
        denom = 0x3c0;
    if (hres == 0)
        hres = 0x1e0;
    ratio = num / denom;

    switch (ratio) {
    case 2:
        dp_reg_write8(port, 0x481, 0x20);
        break;
    case 4:
        dp_reg_write8(port, 0x481, 0x40);
        break;
    case 1:
        dp_reg_write8(port, 0x481, 0x10);
        break;
    default:
        dp_reg_write8(port, 0x481, 0x80);
        break;
    }
    dp_set_clock_divider(port_arg & 0xff, hres, ratio);
}
