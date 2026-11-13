/* i2c_write_packet  (FUN_CODE_bfcf)
 *
 * Write a packet with XOR checksum to a service bus device.
 *   address: slave address
 *   len: length
 *   buf: payload
 * Returns: 0 on success
 * Name basis: derived - address with 10 retries, payload, XOR checksum, stop; device 0x6E
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC). The three locals are unsigned int in the firmware's code.
 */
void i2c_start(void);
unsigned char i2c_write_byte(unsigned char b);
void i2c_bit_delay(void);
void i2c_stop(void);

#define ADDRESS_TRIES    10
#define NO_DEVICE        0x0f   /* result when the address byte was never acknowledged */

/* i2c_write_packet: send one packet on the bit-banged bus: the address byte, len bytes of buf and an XOR checksum.
 *
 * address: first byte on the bus (SVC_ADDRESS for the service packets); sent up to ADDRESS_TRIES times, with an
 *          i2c_bit_delay after each try that is not acknowledged. Without an acknowledge the bus is stopped and the
 *          result is NO_DEVICE.
 * len, buf: the payload.
 * The checksum byte = address XOR all payload bytes. Returns the acknowledge result of the checksum byte alone
 * (I2C_SW_ACK 0 / I2C_SW_NACK 1): the results of the payload bytes are ORed into status, but status is then
 * overwritten. */
unsigned char i2c_write_packet(unsigned char address, unsigned char len, unsigned char *buf)
{
    unsigned int i, checksum, status;
    status = 0;
    i2c_start();
    for (i = 0; i < ADDRESS_TRIES; i++) {
        if (!i2c_write_byte(address)) break;
        i2c_bit_delay();
    }
    if (i == ADDRESS_TRIES) {
        i2c_stop();
        return NO_DEVICE;
    }
    checksum = address;
    for (i = 0; i < len; i++) {
        status |= i2c_write_byte(buf[i]);
        checksum ^= buf[i];
    }
    status = i2c_write_byte(checksum);
    i2c_stop();
    return status;
}
