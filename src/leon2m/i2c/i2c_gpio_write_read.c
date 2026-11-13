/* i2c_gpio_write_read  (FUN_a002b758)
 *
 * Write wbuf, then read rlen bytes into rbuf over software I2C.
 *   bus: bus descriptor
 *   write_buf: bytes to send
 *   write_len: their count
 *   read_buf: receive buffer
 *   read_len: bytes to read
 * Returns: bytes read
 * Note: Returns 0 without touching the bus unless the descriptor mode is 2.
 * Name basis: proven - header: write-then-read with the bit-banged helpers; caller i2c_bus0_write_read
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002b758 @ 0xa002b758, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the write loop ends with the test "i < write_len" (the firmware's
 * "cmp write_len, i; bleu"); the final STOP is written out without a condition around it; the clock wait is
 * "while (!gpio_read_pin(...) && --wait) { nop; nop; }" with the nops as asm statements.
 */
/* The software-I2C bus descriptor (10 bytes, copied from the caller to i2c_bus_descriptor). */
struct i2c_bus {
    unsigned char scl_port, scl_mask;       /* clock line: GPIO port and pin mask */
    unsigned char sda_port, sda_mask;       /* data line: GPIO port and pin mask */
    unsigned short delay;                   /* wait unit: timer_delay_nop_rounds(delay) or (delay * 2) between line changes */
    unsigned char device;                   /* device address byte (write form) */
    unsigned char address_bytes;            /* bytes of memory address the device takes: 1 or 2 */
    unsigned short mode : 2, rest : 14;     /* the routines act only on mode I2C_MODE_GPIO */
};
extern struct i2c_bus i2c_bus_descriptor;
extern void gpio_write_pin(unsigned char, unsigned char, unsigned char);
extern void gpio_set_pin_input(unsigned char, unsigned char, unsigned char);
extern unsigned char gpio_read_pin(unsigned char, unsigned char);
extern void timer_delay_nop_rounds(unsigned short);
extern void i2c_gpio_start(void);
extern unsigned char i2c_gpio_send_byte(unsigned char);

#define I2C_MODE_GPIO        2          /* descriptor mode in which the bus is driven through the GPIO pins */
#define I2C_SCL_WAIT_ROUNDS  0xffff     /* longest wait for a released clock line to read high */
#define I2C_DEVICE_TRIES     10         /* attempts to get the device byte acknowledged */
#define I2C_NO_ACK           1          /* result of i2c_gpio_send_byte when the byte was not acknowledged */
#define I2C_READ_BIT         1          /* device byte | 1 = read access */
extern unsigned char i2c_gpio_read_byte(unsigned char);

/*
 * Write a command to a device on the software I2C bus, then read the answer in the same transfer (START,
 * write, repeated START, read, STOP).
 *
 *   bus        bus descriptor, copied to i2c_bus_descriptor
 *   write_buf  bytes to send after the device byte, write_len of them
 *   read_buf   receives the answer, read_len bytes
 *
 * Returns the number of bytes read (read_len), or 0 when nothing was read: the descriptor mode is not
 * I2C_MODE_GPIO (the bus is then not touched), the device byte was never acknowledged, or a write byte was
 * refused. In the last two cases a STOP is sent first. There is no repeat and no memory address.
 *
 * Order: START; device byte, up to I2C_DEVICE_TRIES times with a wait between tries; the write bytes up to the
 * first refused one; repeated START; device byte with the read bit set, tried the same way (the result is not
 * checked, the read goes on after the last try); read_len bytes, the last one answered with a NACK; STOP.
 *
 * Called by i2c_bus0_write_read.
 */
unsigned short i2c_gpio_write_read(struct i2c_bus *bus, unsigned char *write_buf, unsigned short write_len, unsigned char *read_buf,
                            unsigned short read_len)
{
    unsigned short count = 0, i, wait;
    unsigned char device;

    i2c_bus_descriptor = *bus;
    device = i2c_bus_descriptor.device;
    if (i2c_bus_descriptor.mode == I2C_MODE_GPIO) {
        i2c_gpio_start();
        for (i = 0; i <= I2C_DEVICE_TRIES - 1; i++) {
            if (!i2c_gpio_send_byte(device))
                break;
            timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
        }
        if (i == I2C_DEVICE_TRIES) {
            /* Nobody answered: STOP and give up. */
            gpio_write_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 0);
            timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
            gpio_write_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 1);
            gpio_set_pin_input(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 1);
            wait = I2C_SCL_WAIT_ROUNDS;
            while (!gpio_read_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask) && --wait) {
                __asm__ __volatile__("nop");
                __asm__ __volatile__("nop");
            }
            gpio_set_pin_input(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 0);
            timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
            gpio_write_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 1);
            return 0;
        }
        for (i = 0; i < write_len; i++) {
            if (i2c_gpio_send_byte(write_buf[i]) == I2C_NO_ACK)
                break;
        }
        if (i < write_len) {
            /* A write byte was refused: STOP and give up. */
            gpio_write_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 0);
            timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
            gpio_write_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 1);
            gpio_set_pin_input(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 1);
            wait = I2C_SCL_WAIT_ROUNDS;
            while (!gpio_read_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask) && --wait) {
                __asm__ __volatile__("nop");
                __asm__ __volatile__("nop");
            }
            gpio_set_pin_input(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 0);
            timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
            gpio_write_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 1);
            return 0;
        }
        /* Repeated START, then the device byte again with the read bit. */
        i2c_gpio_start();
        for (i = 0; i <= I2C_DEVICE_TRIES - 1; i++) {
            if (!i2c_gpio_send_byte(i2c_bus_descriptor.device | I2C_READ_BIT))
                break;
            timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
        }
        for (i = 0; i < read_len; i++) {
            /* The last byte is answered with a NACK. */
            if (i == read_len - 1)
                read_buf[i] = i2c_gpio_read_byte(1);
            else
                read_buf[i] = i2c_gpio_read_byte(0);
            count++;
        }
            /* STOP: SDA low, SCL high (waiting for it to come up), SDA high. */
            gpio_write_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 0);
            timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
            gpio_write_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 1);
            gpio_set_pin_input(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 1);
            wait = I2C_SCL_WAIT_ROUNDS;
            while (!gpio_read_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask) && --wait) {
                __asm__ __volatile__("nop");
                __asm__ __volatile__("nop");
            }
            gpio_set_pin_input(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 0);
            timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
            gpio_write_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 1);
    }
    return count;
}
