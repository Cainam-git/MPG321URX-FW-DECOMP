/* i2c_gpio_read_block  (FUN_a002bb28)
 *
 * Read len bytes at addr of an I2C device (e.g. the settings EEPROM) over software I2C.
 *   bus: bus descriptor
 *   addr: memory address in the device
 *   len: byte count
 *   buf: receive buffer
 * Returns: bytes read
 * Note: Runs at start-up step 5 through the EEPROM read wrapper nvram_read; no answer to the device byte ->
 *   STOP, 0.
 * Name basis: proven - header: random read of the EEPROM; caller nvram_read (settings read)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002bb28 @ 0xa002bb28, flags -mcpu=v8 -O3 -g (-msoft-float gives the same code).
 * Source forms the exact build depends on:
 *  (1) the address bytes are a full if/else, "if (address_bytes == 1) send(addr); else { send(addr >> 8);
 *      send(addr); }" (the compiler merges the common call, as in the firmware). The form "if (address_bytes != 1)
 *      send(addr >> 8); send(addr);" leaves a skippable block, and the optimiser then shares the address of the
 *      descriptor between the STOP-on-failure block and the address block, one register more than the firmware;
 *  (2) the clock wait "wait = 0xffff; while (!gpio_read_pin(...) && --wait) { nop; nop; }": the firmware's nops are
 *      real instructions, written as asm statements.
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
 * Read len bytes from a device on the software I2C bus, starting at memory address addr (random read of the
 * settings EEPROM): START, device byte, address, repeated START, device byte with the read bit, data, STOP.
 *
 *   bus   bus descriptor, copied to i2c_bus_descriptor
 *   addr  memory address in the device
 *   len   number of bytes to read
 *   buf   receives the data
 *
 * Returns the number of bytes read (len), or 0 when nothing was read: the descriptor mode is not I2C_MODE_GPIO
 * (the bus is then not touched), or the device never acknowledged the device byte (then buf is not touched and
 * a STOP is sent).
 *
 * Device byte: the descriptor's device byte; for a device with a one-byte address it also carries address bits
 * 8..10 (bits 1..3 of the device byte). The device byte is tried up to I2C_DEVICE_TRIES times with a wait
 * between tries. A one-byte address goes out as the low byte only, a two-byte address high byte first; their
 * acknowledge is not checked. The device byte of the read (without the address bits) is tried the same way, and
 * its result is not checked either: after ten refusals the read goes on. The last byte is answered with a NACK.
 *
 * Called by nvram_read for EEPROM devices, and by edid_read_port_edid.
 */
unsigned short i2c_gpio_read_block(struct i2c_bus *bus, unsigned short addr, unsigned short len, unsigned char *buf)
{
    unsigned short count = 0, i, wait;
    unsigned char device;

    i2c_bus_descriptor = *bus;
    if (i2c_bus_descriptor.address_bytes == 1)
        device = ((addr >> 7) & 0xe) | i2c_bus_descriptor.device;
    else
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
        if (i2c_bus_descriptor.address_bytes == 1)
            i2c_gpio_send_byte(addr);
        else {
            i2c_gpio_send_byte(addr >> 8);
            i2c_gpio_send_byte(addr);
        }
        /* Repeated START, then the device byte again with the read bit. */
        i2c_gpio_start();
        for (i = 0; i <= I2C_DEVICE_TRIES - 1; i++) {
            if (!i2c_gpio_send_byte(i2c_bus_descriptor.device | I2C_READ_BIT))
                break;
            timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
        }
        for (i = 0; i < len; i++) {
            /* The last byte is answered with a NACK. */
            if (i == len - 1)
                buf[i] = i2c_gpio_read_byte(1);
            else
                buf[i] = i2c_gpio_read_byte(0);
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
