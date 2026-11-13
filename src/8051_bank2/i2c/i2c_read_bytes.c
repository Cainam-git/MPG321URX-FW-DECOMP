/* i2c_read_bytes  (FUN_CODE_cd68)
 *
 * Read bytes from a device on the update agent's I2C bus.
 *   address: device address
 *   buf: destination
 *   len: byte count
 * Returns: 0 on success
 * Name basis: proven - bit-banged: start, address | 1 with 10 tries, two dropped reads, len bytes, last one
 *   NACKed, stop
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC). Without REGFILE(R.ORC) it is 243 B: both loop counters stay in
 * R4:R5 across the i2c_write_byte / i2c_bit_delay / i2c_read_byte calls only when the register-usage file says
 * those callees leave R4/R5 alone.
 * LARGE parameters address (0x08F0), buf (generic pointer, 0x08F1..0x08F3) and len (uint, 0x08F4..0x08F5); locals
 * dropped (0x08F6) and count (uint, 0x08F7..0x08F8).
 * Source forms the bytes depend on: the two first reads are stored to count and dropped, and count is then
 * overwritten with len; the last-byte arm and the other arm each have their own 'buf[j] = i2c_read_byte(...);'
 * (Keil cross-jumps the shared tail). A flag variable 'b = 1 / b = 0; buf[j] = i2c_read_byte(b)' stores b and is 206 B.
 */
void i2c_start(void);
void i2c_stop(void);
void i2c_bit_delay(void);
void timer_delay_units(unsigned char n);
unsigned char i2c_write_byte(unsigned char b);
unsigned char i2c_read_byte(unsigned char last);

#define ADDRESS_TRIES   10
#define I2C_READ_BIT    0x01
#define NOT_LAST        0       /* i2c_read_byte argument: acknowledge, more bytes follow */
#define LAST_BYTE       1       /* i2c_read_byte argument: no acknowledge */

/* i2c_read_bytes: read len bytes into buf from the device at address on the bit-banged bus.
 *
 * address: device address; it goes out with I2C_READ_BIT set, up to ADDRESS_TRIES times with an i2c_bit_delay
 *          after each try that is not acknowledged. Without an acknowledge the bus is stopped and the result is 1.
 * Returns 0 after the bytes are read.
 *
 * After the address: timer_delay_units(1), then two bytes are read and thrown away; then the len bytes. The last
 * one is read after six bit delays and without acknowledge. Only caller: fwupd_pick_valid_region. */
unsigned char i2c_read_bytes(unsigned char address, unsigned char *buf, unsigned int len)
{
    unsigned char dropped;
    unsigned int count;
    unsigned int j;
    i2c_start();
    for (j = 0; j != ADDRESS_TRIES; j++) {
        if (i2c_write_byte(address | I2C_READ_BIT) == 0) break;
        i2c_bit_delay();
    }
    if (j == ADDRESS_TRIES) {
        i2c_stop();
        return 1;
    }
    timer_delay_units(1);
    count = i2c_read_byte(NOT_LAST);
    dropped = i2c_read_byte(NOT_LAST);
    count = len;
    for (j = 0; j < count; j++) {
        if (j == count - 1) {
            i2c_bit_delay();
            i2c_bit_delay();
            i2c_bit_delay();
            i2c_bit_delay();
            i2c_bit_delay();
            i2c_bit_delay();
            buf[j] = i2c_read_byte(LAST_BYTE);
        } else buf[j] = i2c_read_byte(NOT_LAST);
    }
    i2c_stop();
    return 0;
}
