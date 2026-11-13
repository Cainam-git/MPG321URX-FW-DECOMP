/* i2c_bus0_write_read  (FUN_a01257f0)
 *
 * Write, then read, in one transfer with a device on software I2C bus 0.
 * Name basis: derived - fills the bus descriptor and calls i2c_gpio_write_read
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01257f0 @ 0xa01257f0, flags -mcpu=v8 -O3 -g.
 * Source form: as i2c_bus0_write_block (descriptor element addressed through `bus_index`, copied to a local).
 * The write buffer is passed as an int, as the firmware's call does.
 */
/* The software-I2C bus descriptor (10 bytes); element 0 of i2c_bus0_descriptors is bus 0. */
struct i2c_bus {
    unsigned char scl_port, scl_mask;       /* clock line: GPIO port and pin mask */
    unsigned char sda_port, sda_mask;       /* data line: GPIO port and pin mask */
    unsigned short delay;                   /* wait unit between line changes */
    unsigned char device;                   /* device address byte (write form) */
    unsigned char address_bytes;            /* bytes of memory address the device takes */
    unsigned short mode : 2, rest : 14;     /* the i2c_gpio routines act only on mode 2 */
};
extern struct i2c_bus i2c_bus0_descriptors[];
extern unsigned short i2c_gpio_write_read(struct i2c_bus *, int, unsigned short, unsigned char *, unsigned short);

/*
 * Write `write_length` bytes, then read `read_length` bytes, in one transfer with an I2C device on the software
 * I2C bus.
 *   device        device address byte; stored in the bus descriptor (the address length is set to 1)
 *   write_buf     bytes to send (an address passed as int)
 *   delay         wait unit between line changes; stored in the bus descriptor
 *   bus_index     only bus 0 is handled; any other value returns 0 without touching the bus
 *   read_buf      receives the answer
 * Returns what i2c_gpio_write_read returns (bytes read).
 * Called by i2c_api_write_read.
 */
unsigned short i2c_bus0_write_read(unsigned char device, int write_buf, unsigned short write_length,
                                   unsigned short delay, unsigned char bus_index, unsigned char *read_buf,
                                   unsigned short read_length)
{
    struct i2c_bus bus;
    unsigned short count = 0;

    if (bus_index == 0) {
        i2c_bus0_descriptors[bus_index].device = device;
        i2c_bus0_descriptors[bus_index].address_bytes = 1;
        i2c_bus0_descriptors[bus_index].delay = delay;
        bus = i2c_bus0_descriptors[bus_index];
        count = i2c_gpio_write_read(&bus, write_buf, write_length, read_buf, read_length);
    }
    return count;
}
