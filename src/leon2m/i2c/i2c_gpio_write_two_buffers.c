/* i2c_gpio_write_two_buffers  (FUN_a002b058)
 *
 * Write the device byte, then buf1 and buf2 over software I2C with retries.
 *   bus: bus descriptor
 *   buf1: first data part
 *   buf1_len: its length
 *   buf2: second data part
 *   buf2_len: its length
 *   tries: repeat limit: the transfer runs at most tries + 1 times
 *   stop: send STOP at the end
 * Returns: bytes of buf2 acknowledged
 * Note: Copies *d to the shared descriptor at 0xA802D992; 10 NACKs of the device byte abort with 0.
 * Name basis: proven - header: START + device byte + two buffers; uses the bit-banged helpers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002b058 @ 0xa002b058, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: one byte variable (byte) carries every byte sent; the STOP sequence is
 * written out where it is used (no helper); the clock wait is "while (!gpio_read_pin(...) && --wait) { nop; nop; }"
 * with the nops as asm statements.
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
extern void ipc_signal_alive(void);

/*
 * Write the device byte, then two data buffers, to a device on the software I2C bus, repeating the whole
 * transfer while the last byte is refused.
 *
 *   bus     bus descriptor, copied to i2c_bus_descriptor
 *   buf1    first part of the data, buf1_len bytes
 *   buf2    second part, buf2_len bytes
 *   tries   repeat limit: the transfer runs at most tries + 1 times
 *   stop    non-zero: finish each attempt with a STOP
 *
 * Returns the number of bytes of buf2 that were acknowledged. There are no memory-address bytes: the data
 * follows the device byte directly.
 *
 * Each attempt (only when the descriptor mode is I2C_MODE_GPIO; with another mode nothing is sent, the attempt
 * counter does not rise and the first-time value of "last byte refused" keeps the loop turning):
 *   1. START, then the device byte, up to I2C_DEVICE_TRIES times with a wait between tries. If every try is
 *      refused, send STOP and return 0 at once (no repeat).
 *   2. buf1 byte by byte, up to the first refused byte.
 *   3. Only if all of buf1 was acknowledged: buf2 the same way, counting the acknowledged bytes.
 *   4. STOP, if stop is set.
 * An attempt is repeated while its last byte was refused and the attempt count has not passed tries.
 *
 * Called by i2c_bus0_write_two_buffers with stop set.
 */
unsigned short i2c_gpio_write_two_buffers(struct i2c_bus *bus, unsigned char *buf1, unsigned short buf1_len, unsigned char *buf2,
                            unsigned short buf2_len, unsigned char tries, unsigned char stop)
{
    unsigned short acked, i, wait;
    unsigned char device, last_result = I2C_NO_ACK, attempts = 0, byte;

    i2c_bus_descriptor = *bus;
    device = i2c_bus_descriptor.device;
    do {
        acked = 0;
        if (i2c_bus_descriptor.mode == I2C_MODE_GPIO) {
            i2c_gpio_start();
            byte = device;
            for (i = 0; i <= I2C_DEVICE_TRIES - 1; i++) {
                if (!i2c_gpio_send_byte(byte))
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
            for (i = 0; i < buf1_len; i++) {
                byte = buf1[i];
                last_result = i2c_gpio_send_byte(byte);
                if (last_result == I2C_NO_ACK)
                    break;
            }
            /* The second buffer follows only when the whole first one was taken. */
            if (i == buf1_len) {
                for (i = 0; i < buf2_len; i++) {
                    byte = buf2[i];
                    last_result = i2c_gpio_send_byte(byte);
                    if (last_result == I2C_NO_ACK)
                        break;
                    acked++;
                }
            }
            if (stop) {
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
            attempts++;
        }
    } while (last_result == I2C_NO_ACK && attempts <= tries);
    return acked;
}
