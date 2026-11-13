/* i2c_bus0_read_block  (FUN_a01256d0)
 *
 * Read a block from a device on software I2C bus 0.
 * Name basis: derived - fills the bus descriptor at 0xA802A430 and calls i2c_gpio_read_block
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01256d0 @ 0xa01256d0, flags -mcpu=v8 -O3 -g.
 * Source form: as i2c_bus0_write_block (descriptor element addressed through `bus_index`, copied to a local).
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
extern unsigned short i2c_gpio_read_block(struct i2c_bus *, unsigned short, unsigned short, unsigned char *);

/*
 * Read `length` bytes from memory address `memory_address` of an I2C device on the software I2C bus into `buf`.
 *   device         device address byte; stored in the bus descriptor
 *   address_bytes  bytes of memory address the device takes; stored in the bus descriptor
 *   delay          wait unit between line changes; stored in the bus descriptor
 *   bus_index      only bus 0 is handled; any other value returns 0 without touching the bus
 * Returns what i2c_gpio_read_block returns (bytes read).
 * Called by i2c_api_read_block.
 */
unsigned short i2c_bus0_read_block(unsigned char device, unsigned char address_bytes, unsigned short memory_address,
                                   unsigned short delay, unsigned char bus_index, unsigned char *buf,
                                   unsigned short length)
{
    struct i2c_bus bus;
    unsigned short count = 0;

    if (bus_index == 0) {
        i2c_bus0_descriptors[bus_index].device = device;
        i2c_bus0_descriptors[bus_index].address_bytes = address_bytes;
        i2c_bus0_descriptors[bus_index].delay = delay;
        bus = i2c_bus0_descriptors[bus_index];
        count = i2c_gpio_read_block(&bus, memory_address, length, buf);
    }
    return count;
}
