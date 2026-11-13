/* i2c_sw_read_regs  (FUN_CODE_8622)
 *
 * Read registers of a device on the software I2C bus.
 *   device: device address
 *   reg: register
 *   count
 *   buf: destination
 * Name basis: proven - start, address with 10 retries, register byte(s), repeated start, address | 1, n bytes,
 *   stop
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_8622 @ 0x8622..0x8731 (271 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Source form: the two i2c_sw_read_byte calls are separate statements ('CLR A / MOV R7,A' for the 0, shared call
 *   and store), and i2c_sw_stop() is written in both arms of 'if (i != ADDRESS_TRIES)' (shared 'LCALL / RET' tail
 *   instead of LJMP). volatile on 0xF00A: written in the loop.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
extern unsigned char xdata i2c_sw_id_match_flag;
extern void i2c_sw_start(void);
extern unsigned char i2c_sw_write_byte(unsigned char v);
extern void i2c_sw_bit_delay(void);
extern unsigned char i2c_sw_read_byte(unsigned char last);
extern void i2c_sw_stop(void);

#define ADDRESS_TRIES      10
#define TWO_BYTE_REGISTER  1     /* i2c_sw_id_match_flag value: send the register number as two bytes */
#define I2C_READ_BIT       1
#define LAST_BYTE          1     /* i2c_sw_read_byte argument for the last byte */

/*
 * i2c_sw_read_regs - read count bytes from a device on the software I2C bus, starting at register reg.
 *   device  bus address (write form)
 *   reg     first register; sent as two bytes (high byte first) when i2c_sw_id_match_flag is 1, else as one
 *   count   number of bytes read
 *   buf     receives them
 * The address is sent up to 10 times until the device answers; when it never does, the bus is stopped and
 * nothing is read. The read address (device | 1) is tried the same way, but the bytes are read whatever its
 * last try gave.
 * Only caller: i2c_sw_match_device_id.
 */
void i2c_sw_read_regs(unsigned char device, unsigned int reg, unsigned int count, unsigned char *buf)
{
    unsigned int i;

    i2c_sw_start();
    for (i = 0; i < ADDRESS_TRIES; i++) {
        if (!i2c_sw_write_byte(device))
            break;
        i2c_sw_bit_delay();
    }
    if (i != ADDRESS_TRIES) {
        if ((unsigned int)i2c_sw_id_match_flag == TWO_BYTE_REGISTER) {
            i2c_sw_write_byte(reg >> 8);
            i2c_sw_write_byte(reg);
        } else {
            i2c_sw_write_byte(reg);
        }
        /* Repeated start, then the read address. */
        i2c_sw_start();
        for (i = 0; i < ADDRESS_TRIES; i++) {
            if (!i2c_sw_write_byte(device | I2C_READ_BIT))
                break;
            i2c_sw_bit_delay();
        }
        for (i = 0; i < count; i++) {
            DAT_EXTMEM_f00a = 0x55;
            if (i == count - 1) buf[i] = i2c_sw_read_byte(LAST_BYTE); else buf[i] = i2c_sw_read_byte(0);
        }
        i2c_sw_stop();
    } else {
        i2c_sw_stop();
    }
}
