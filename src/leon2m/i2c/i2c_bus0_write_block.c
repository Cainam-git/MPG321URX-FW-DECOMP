/* i2c_bus0_write_block  (FUN_a0125644)
 *
 * Write a block to a device on software I2C bus 0.
 * Name basis: derived - fills the bus descriptor at 0xA802A430 and calls i2c_gpio_write_block
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125644 @ 0xa0125644, flags -mcpu=v8 -O3 -g.
 * Source form: the descriptor element is addressed through `bus_index`, so the offset-0 load uses the register
 * that holds `bus_index` (known to be 0 there). The descriptor is copied to a local `bus` that is passed on.
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
extern unsigned short i2c_gpio_write_block(struct i2c_bus *, unsigned short, unsigned short, unsigned char *,
                                           unsigned char, unsigned char);

/*
 * Write `length` bytes from `buf` to memory address `memory_address` of an I2C device on the software I2C bus.
 *   device         device address byte; stored in the bus descriptor
 *   address_bytes  bytes of memory address the device takes; stored in the bus descriptor
 *   delay          wait unit between line changes; stored in the bus descriptor
 *   bus_index      only bus 0 is handled; any other value returns 0 without touching the bus
 *   tries          attempts, passed to i2c_gpio_write_block (which is called with stop = 1)
 * Returns what i2c_gpio_write_block returns (bytes written).
 * Called by i2c_api_write_block.
 */
unsigned short i2c_bus0_write_block(unsigned char device, unsigned char address_bytes, unsigned short memory_address,
                                    unsigned short delay, unsigned char bus_index, unsigned char *buf,
                                    unsigned short length, unsigned char tries)
{
    struct i2c_bus bus;
    unsigned short written = 0;

    if (bus_index == 0) {
        i2c_bus0_descriptors[bus_index].device = device;
        i2c_bus0_descriptors[bus_index].address_bytes = address_bytes;
        i2c_bus0_descriptors[bus_index].delay = delay;
        bus = i2c_bus0_descriptors[bus_index];
        written = i2c_gpio_write_block(&bus, memory_address, length, buf, tries, 1);
    }
    return written;
}
