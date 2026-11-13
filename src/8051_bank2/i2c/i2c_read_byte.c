/* i2c_read_byte  (FUN_CODE_db1c)
 *
 * Read one byte on the update agent's I2C bus and send ACK or NACK.
 * Returns: byte
 * Name basis: proven - bit-banged read with ACK/NACK (record)
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC). The three locals are declared idata, in this order.
 * value is not set before the loop: the eight shifts replace all its bits.
 */
sfr P1 = 0x90;
sbit SDA = P1 ^ 6;      /* data line of the bus the update agent drives by hand */
sbit SCL = P1 ^ 7;      /* clock line */
void i2c_bit_delay(void);

#define SCL_WAIT_READS  0xff    /* reads of SCL while it is held low before the code goes on */

/* i2c_read_byte: read one byte on the bit-banged bus (P1.6 = SDA, P1.7 = SCL), most significant bit first, and
 * answer it.
 *
 * last: 0 = more bytes follow, answer with an acknowledge (SDA low); 1 = the last byte, SDA stays high. Only bit 0
 * counts.
 * Returns the byte.
 *
 * SDA is released first. Each bit: SCL high, i2c_bit_delay, then while SCL still reads low it is read again, at most
 * SCL_WAIT_READS times (the code goes on either way); SDA is read into bit 0, SCL goes low, i2c_bit_delay. The
 * answer bit gets one more clock.
 * Callers: i2c_read_packet and i2c_read_bytes. */
unsigned char i2c_read_byte(unsigned char last)
{
    unsigned char idata bit_count;
    unsigned char idata value;
    unsigned char idata scl_wait;
    last &= 1;
    SDA = 1;
    for (bit_count = 0; bit_count < 8; bit_count++) {
        value <<= 1;
        SCL = 1;
        i2c_bit_delay();
        scl_wait = SCL_WAIT_READS;
        while (!SCL && --scl_wait);
        if (!SDA) value &= 0xfe; else value |= 0x01;
        SCL = 0;
        i2c_bit_delay();
    }
    /* The answer bit: acknowledge unless this is the last byte. */
    if (!last) SDA = 0; else SDA = 1;
    i2c_bit_delay();
    SCL = 1;
    i2c_bit_delay();
    SCL = 0;
    i2c_bit_delay();
    return value;
}
