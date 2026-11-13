/* i2c_gpio_write_block  (FUN_a002b3e4)
 *
 * Write len bytes at addr of an I2C device (e.g. the settings EEPROM) over software I2C.
 *   bus: bus descriptor
 *   addr: memory address in the device
 *   len: byte count
 *   buf: data
 *   tries: repeat limit: the transfer runs at most tries + 1 times
 *   stop: send STOP at the end
 * Returns: number of data bytes acknowledged in the last attempt
 * Note: With a one-byte address, address bits 8..10 go into the device byte; pings the 8051 first
 *   (ipc_signal_alive).
 * Name basis: proven - header: page write used by the settings write nvram_write
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002b3e4 @ 0xa002b3e4, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: one byte variable (byte) carries every byte sent (device, address, data).
 * Because it is set several times inside the retry loop, the compiler does not move the unsigned char truncation of
 * the device byte out of that loop, and the firmware truncates it after each START; passing "device" straight to
 * i2c_gpio_send_byte would move it out. The STOP sequence is written out where it is used; the clock wait is
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
extern void ipc_signal_alive(void);

/*
 * Write len bytes to a device on the software I2C bus, starting at memory address addr (one page write of the
 * settings EEPROM), repeating the whole transfer while the last byte is refused.
 *
 *   bus     bus descriptor, copied to i2c_bus_descriptor
 *   addr    memory address in the device
 *   len     number of data bytes
 *   buf     the data
 *   tries   repeat limit: the transfer runs at most tries + 1 times
 *   stop    non-zero: finish each attempt with a STOP
 *
 * Returns the number of data bytes that were acknowledged in the last attempt (0 when the device byte was
 * never acknowledged).
 *
 * Device byte: the descriptor's device byte; for a device with a one-byte address it also carries address bits
 * 8..10 (bits 1..3 of the device byte), the rest of the address goes out as one byte. A two-byte address goes
 * out high byte first. The acknowledge of the address bytes is not checked.
 *
 * Each attempt (only when the descriptor mode is I2C_MODE_GPIO; with another mode the attempt counter does not
 * rise and the loop would not end while the last result is "refused"):
 *   1. START, then the device byte, up to I2C_DEVICE_TRIES times with a wait between tries. If every try is
 *      refused, send STOP and return 0 at once (no repeat).
 *   2. The address byte(s), then the data bytes up to the first refused one, counting the acknowledged bytes.
 *   3. STOP, if stop is set.
 * An attempt is repeated while its last data byte was refused and the attempt count has not passed tries.
 * ipc_signal_alive is called once before the first attempt and after every attempt: it copies the 8051's alive
 * counters, and the 8051 resets the chip when they stay unanswered.
 *
 * Called by nvram_write, one chunk of at most 16 bytes per call with tries 1 and stop 1; the caller then
 * polls the device with i2c_gpio_probe_device.
 */
unsigned short i2c_gpio_write_block(struct i2c_bus *bus, unsigned short addr, unsigned short len, unsigned char *buf,
                            unsigned char tries, unsigned char stop)
{
    unsigned short acked, i, wait;
    unsigned char device, last_result = I2C_NO_ACK, attempts = 0, byte;

    i2c_bus_descriptor = *bus;
    if (i2c_bus_descriptor.address_bytes == 1)
        device = ((addr >> 7) & 0xe) | i2c_bus_descriptor.device;
    else
        device = i2c_bus_descriptor.device;
    ipc_signal_alive();
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
            if (i2c_bus_descriptor.address_bytes != 1) {
                byte = addr >> 8;
                i2c_gpio_send_byte(byte);
            }
            byte = addr;
            i2c_gpio_send_byte(byte);
            for (i = 0; i < len; i++) {
                byte = buf[i];
                last_result = i2c_gpio_send_byte(byte);
                if (last_result == I2C_NO_ACK)
                    break;
                acked++;
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
        ipc_signal_alive();
    } while (last_result == I2C_NO_ACK && attempts <= tries);
    return acked;
}
