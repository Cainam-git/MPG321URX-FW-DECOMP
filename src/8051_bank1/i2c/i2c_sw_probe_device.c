/* i2c_sw_probe_device  (FUN_CODE_d47f)
 *
 * Probe an address on the software I2C bus; an empty start/stop pair goes before and after.
 *   address_byte
 * Returns: 1 when the device acknowledged
 * Note: Not called anywhere.
 * Name basis: derived - start (97c4), byte write with ack test (6781), stop (c6ec); an empty start/stop pair
 *   before and after
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d47f @ 0xD47F..0xD4B0 (49 bytes), OPTIMIZE(8,SPEED) LARGE. Returns a bit (carry).
 * The parameter is a LARGE parameter (XDATA 0xA77D); the result is a bit local (BIT 0x12). No aids.
 */
#define I2C_SW_ACK 0  /* return value of i2c_sw_write_byte: the device acknowledged */

void i2c_sw_start(void);
void i2c_sw_stop(void);
void i2c_sw_bit_delay(void);
unsigned char i2c_sw_write_byte(unsigned char x);

/*
 * Probe a device on the software I2C bus: start, stop, delay, start, send the address byte, stop, delay, start,
 * stop. Returns 1 when the device acknowledged the address byte. Nothing in the image calls this routine.
 */
bit i2c_sw_probe_device(unsigned char address_byte)
{
    bit acked;

    i2c_sw_start();
    i2c_sw_stop();
    i2c_sw_bit_delay();
    i2c_sw_start();
    if (i2c_sw_write_byte(address_byte) != I2C_SW_ACK) acked = 0;
    else acked = 1;
    i2c_sw_stop();
    i2c_sw_bit_delay();
    i2c_sw_start();
    i2c_sw_stop();
    return acked;
}
