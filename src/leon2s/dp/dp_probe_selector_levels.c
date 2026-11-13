/* dp_probe_selector_levels  (FUN_a00af524)
 *
 * Probe a status register for five selector values and return a 2-bit result.
 * Returns: 0..3
 * Name basis: descriptive - selector written to register 0x60, result read from 0x62
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00af524 @ 0xa00af524-0xa00af690, -mcpu=v8 -Os -g.
 * Source form: the register accessors are declared with unsigned char values here (the firmware masks at each
 * use); the result starts at 0.
 */
extern unsigned int dp_status_reg_read8(unsigned char, unsigned short);
extern unsigned char dp_reg_read8(unsigned char, unsigned short);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);

#define SELECTOR_REG   0x60     /* the low 5 bits select what register 0x62 shows; the high 3 bits are kept */
#define PROBE_MODE_REG 0x61     /* 3 is written before the probe */
#define READING_REG    0x62

/*
 * Return 2 at once when bit 6 of register 5 of the port's status block is clear. Otherwise write 3 to register
 * 0x61 and read register 0x62 with the selector (low 5 bits of register 0x60) at 1, 2 and 3. When the three
 * readings are 0x1A, 0 and 0, the result is built from two more readings: bit 1 of the result is set when
 * bit 5 of register 0x62 is clear with selector 6, and bit 0 is set when bit 5 is set with selector 9. For any
 * other three readings the result is 2. Register 0x60 is restored before returning.
 *   port: DP receiver (0 or 1)
 * Returns 0..3. dp_update_port_status_flags copies bit 0 and bit 1 of the result into the port's published
 * flags.
 */
unsigned char dp_probe_selector_levels(unsigned char port)
{
    unsigned char saved, high_bits, reading_1, reading_2, reading_3, result;

    result = 0;
    if ((dp_status_reg_read8(port, 5) & 0x40) == 0)
        return 2;
    dp_reg_write8(port, PROBE_MODE_REG, 3);
    saved = dp_reg_read8(port, SELECTOR_REG);
    high_bits = saved & 0xe0;
    dp_reg_write8(port, SELECTOR_REG, high_bits | 1);
    reading_1 = dp_reg_read8(port, READING_REG);
    dp_reg_write8(port, SELECTOR_REG, high_bits | 2);
    reading_2 = dp_reg_read8(port, READING_REG);
    dp_reg_write8(port, SELECTOR_REG, high_bits | 3);
    reading_3 = dp_reg_read8(port, READING_REG);
    if (reading_1 == 0x1a && reading_2 == 0 && reading_3 == 0) {
        dp_reg_write8(port, SELECTOR_REG, high_bits | 6);
        if ((dp_reg_read8(port, READING_REG) & 0x20) == 0)
            result = 2;
        dp_reg_write8(port, SELECTOR_REG, high_bits | 9);
        if (dp_reg_read8(port, READING_REG) & 0x20)
            result |= 1;
    } else {
        result = 2;
    }
    dp_reg_write8(port, SELECTOR_REG, saved);
    return result;
}
