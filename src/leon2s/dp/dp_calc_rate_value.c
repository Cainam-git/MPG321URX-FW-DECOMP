/* dp_calc_rate_value  (FUN_a00aceec)
 *
 * Compute a rate value from four registers and a 2-bit selector.
 * Returns: value
 * Name basis: descriptive - ((a * k / b) * 10000) >> 9
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00aceec @ 0xa00aceec, flags -mcpu=v8 -Os -g.
 * Source form: one complete formula per case.
 */
extern int dp_reg_read24_stable(unsigned char, unsigned short);
extern int dp_reg_read8(unsigned char, unsigned short);

/*
 * Compute ((count * factor / divisor) * 10000) >> 9 from receiver registers; dp_update_range_flag tests the result.
 *   count: the 24-bit register 0x63 (dp_reg_read24_stable)
 *   divisor: the 24-bit value of registers 0x68 (high byte), 0x67, 0x66
 *   factor: 0xA2, 0x10E, 0x21C or 0x32A for bits 0..1 of register 0x80 = 0, 1, 2, 3
 * Returns 0 when count or divisor is 0. The result is cut to 16 bits.
 *   port: DP receiver
 */
unsigned short dp_calc_rate_value(unsigned char port)
{
    unsigned int count, divisor;
    unsigned int result = 0;

    count = dp_reg_read24_stable(port, 0x63);
    divisor = dp_reg_read8(port, 0x68) & 0xff;
    divisor <<= 8;
    divisor |= dp_reg_read8(port, 0x67) & 0xff;
    divisor <<= 8;
    divisor |= dp_reg_read8(port, 0x66) & 0xff;
    if (count == 0 || divisor == 0)
        return 0;
    switch (dp_reg_read8(port, 0x80) & 3) {
    case 0:
        result = (count * 0xa2 / divisor) * 10000 >> 9;
        break;
    case 1:
        result = (count * 0x10e / divisor) * 10000 >> 9;
        break;
    case 2:
        result = (count * 0x21c / divisor) * 10000 >> 9;
        break;
    case 3:
        result = (count * 0x32a / divisor) * 10000 >> 9;
        break;
    }
    return result;
}
