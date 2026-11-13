/* i2c_bus0_write_two_buffers  (FUN_a0125754)
 *
 * Write two buffers in one transfer to a device on software I2C bus 0.
 * Name basis: derived - fills the bus descriptor and calls i2c_gpio_write_two_buffers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125754 @ 0xa0125754, flags -mcpu=v8 -O3 -g.
 * Source form: as i2c_bus0_write_block (descriptor element addressed through `bus_index`, copied to a local).
 * The first data part is passed as an int, as the firmware's call does.
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
extern unsigned short i2c_gpio_write_two_buffers(struct i2c_bus *, int, unsigned short, unsigned char *,
                                                 unsigned short, unsigned char, int);

/*
 * Send the device address byte, then two data buffers, in one transfer to an I2C device on the software I2C bus.
 *   device       device address byte; stored in the bus descriptor (the address length is set to 1)
 *   first_buf    first data part (an address passed as int), first_length bytes
 *   buf          second data part, length bytes
 *   delay        wait unit between line changes; stored in the bus descriptor
 *   bus_index    only bus 0 is handled; any other value returns 0 without touching the bus
 *   tries        attempts, passed to i2c_gpio_write_two_buffers (which is called with stop = 1)
 * Returns what i2c_gpio_write_two_buffers returns (bytes of the second buffer acknowledged).
 * Called by i2c_api_write_two_buffers.
 */
unsigned short i2c_bus0_write_two_buffers(unsigned char device, int first_buf, unsigned short first_length,
                                          unsigned short delay, unsigned char bus_index, unsigned char *buf,
                                          unsigned short length, unsigned char tries)
{
    struct i2c_bus bus;
    unsigned short count = 0;

    if (bus_index == 0) {
        i2c_bus0_descriptors[bus_index].device = device;
        i2c_bus0_descriptors[bus_index].address_bytes = 1;
        i2c_bus0_descriptors[bus_index].delay = delay;
        bus = i2c_bus0_descriptors[bus_index];
        count = i2c_gpio_write_two_buffers(&bus, first_buf, first_length, buf, length, tries, 1);
    }
    return count;
}
