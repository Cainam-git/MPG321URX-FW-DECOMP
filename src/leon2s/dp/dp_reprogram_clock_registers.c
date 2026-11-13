/* dp_reprogram_clock_registers  (FUN_a00ad0c4)
 *
 * Recompute a port's clock value and rewrite its registers 0x45 / 0x47.
 * Name basis: descriptive - with a short wait and a read-back
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad0c4 @ 0xa00ad0c4-0xa00ad27c (440 bytes), flags -mcpu=v8 -Os -g.
 * Source form: dp_calc_pixel_clock is declared returning int (its value is narrowed to 16 bits at the
 * compare), and the one unsigned short variable value also holds the byte read back from register 0x47. The
 * last call, dp_set_reg44_low_bits, is a tail call.
 */
extern int dp_calc_pixel_clock(unsigned int);
extern unsigned short dp_get_hactive(unsigned int);
extern unsigned short dp_reg_read16(unsigned int, unsigned short);
extern unsigned int dp_reg_read8(unsigned int, unsigned short);
extern void dp_reg_write8(unsigned int, unsigned short, unsigned char);
extern void dp_reg_update_bits(unsigned int, unsigned short, unsigned int, unsigned int);
extern void timer_delay_long_units(int);
extern void dp_set_reg44_low_bits(unsigned int);

/*
 * Recompute register 0x47 of a DP receiver after clearing bits 6 and 7 of register 0x45, and write it.
 *
 * The first value for register 0x47 is the horizontal active width of the input divided by 256 when the pixel
 * clock value (dp_calc_pixel_clock) is above 0x104, else divided by 64, limited to 0xFF. When bit 2 of register
 * 0x46 is set, the value is replaced: by 0xFF if bit 0 of register 0xC0 is set, otherwise, after one long wait
 * unit, by register pair 0x48 divided by 8 (limited to 0xFF); bit 6 of register 0x45 is then set. The value of
 * register 0x47 is read back and written again with bit 7 of register 0x45 set around the write. Last, bit 3
 * of register 3 is set when bits 0..1 of register 0x80 are non-zero, else cleared, and the low bits of
 * register 0x44 are set (dp_set_reg44_low_bits). Called by the link state machine (DP_GetClrSpace).
 *   port: DP receiver
 */
void dp_reprogram_clock_registers(unsigned int port)
{
    unsigned short value;

    port &= 0xff;
    value = dp_calc_pixel_clock(port);
    dp_reg_update_bits(port, 0x45, 0x40, 0);
    dp_reg_update_bits(port, 0x45, 0x80, 0);
    if (value > 0x104)
        value = dp_get_hactive(port) >> 8;
    else
        value = dp_get_hactive(port) >> 6;
    if (value > 0xff)
        value = 0xff;
    dp_reg_write8(port, 0x47, value & 0xff);
    if (dp_reg_read8(port, 0x46) & 4) {
        if (dp_reg_read8(port, 0xc0) & 1) {
            dp_reg_write8(port, 0x47, 0xff);
        } else {
            timer_delay_long_units(1);
            value = dp_reg_read16(port, 0x48) >> 3;
            if (value > 0xff)
                value = 0xff;
            dp_reg_write8(port, 0x47, value & 0xff);
        }
        dp_reg_update_bits(port, 0x45, 0x40, 1);
    }
    value = dp_reg_read8(port, 0x47) & 0xff;
    dp_reg_update_bits(port, 0x45, 0x80, 1);
    dp_reg_write8(port, 0x47, value);
    dp_reg_update_bits(port, 0x45, 0x80, 0);
    if (dp_reg_read8(port, 0x80) & 3)
        dp_reg_update_bits(port, 3, 8, 1);
    else
        dp_reg_update_bits(port, 3, 8, 0);
    dp_set_reg44_low_bits(port);
}
