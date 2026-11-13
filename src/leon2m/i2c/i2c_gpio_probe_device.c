/* i2c_gpio_probe_device  (FUN_a002be7c)
 *
 * Return 1 when device dev acknowledges its address on the software I2C bus.
 *   device: device address byte
 * Returns: 1 = device answered
 * Note: Used as the EEPROM write-cycle poll after every 16-byte chunk.
 * Name basis: proven - header: address probe used by the settings write nvram_write
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002be7c @ 0xa002be7c, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the first clock wait is the "&& --wait" form like the other two; the
 * probe result is an if/else ("if (i2c_gpio_send_byte(device) == 0) result = 1; else result = 0;"), which keeps the
 * result in the register the firmware uses (the "== 0" expression and the "?:" form change 90 words); the STOP
 * sequence is written out each time.
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

/*
 * Ask whether a device answers its address on the software I2C bus in i2c_bus_descriptor: send START, the
 * device byte and STOP, and look at the acknowledge.
 *
 *   device  device address byte to try
 *
 * Returns 1 when the device acknowledged, 0 when it did not or when the descriptor mode is not I2C_MODE_GPIO
 * (the bus is then not touched). It uses the descriptor left in i2c_bus_descriptor by the last transfer
 * routine and does not copy one itself.
 *
 * Order: START, STOP, wait, START, device byte (acknowledged = 1), STOP, wait, START, STOP. The first and
 * the last START/STOP pair carry no data. The clock waits inside the STOPs are counted.
 *
 * Used by nvram_write after every chunk written to an EEPROM: it calls this routine in a loop without a limit
 * until the device answers again (the chip does not answer while it is storing). A device that never answers
 * keeps the caller in that loop.
 */
unsigned char i2c_gpio_probe_device(unsigned char device)
{
    unsigned char result = 0;
    unsigned short wait;

    if (i2c_bus_descriptor.mode == I2C_MODE_GPIO) {
        i2c_gpio_start();
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
        timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
        i2c_gpio_start();
        if (i2c_gpio_send_byte(device) == 0) result = 1; else result = 0;
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
        timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
        i2c_gpio_start();
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
    return result & 1;
}
