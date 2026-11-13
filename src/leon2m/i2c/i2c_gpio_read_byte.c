/* i2c_gpio_read_byte  (FUN_a002ae4c)
 *
 * Read one byte over software I2C and answer ACK, or NACK when last is set.
 *   last: non-zero for the final byte (NACK)
 * Returns: byte read
 * Name basis: proven - header: bit-banged byte read + ACK/NACK
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002ae4c @ 0xa002ae4c, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the shifted byte "shifted = value << 1" is taken at the top of each bit
 * round and value = shifted or shifted | 1 after the SDA sample; the NACK flag is "last & 1" held in an unsigned int
 * local; both ifs are written with the 0 arm first; the clock wait is "while (!gpio_read_pin(...) && --wait)
 * { nop; nop; }" with the nops as asm statements.
 */
/* The software-I2C bus descriptor (10 bytes, copied by the transfer routines to i2c_bus_descriptor). */
struct i2c_bus {
    unsigned char scl_port, scl_mask;       /* clock line: GPIO port and pin mask */
    unsigned char sda_port, sda_mask;       /* data line: GPIO port and pin mask */
    unsigned short delay;                   /* wait unit: timer_delay_nop_rounds(delay) or (delay * 2) between line changes */
    unsigned char device;                   /* device address byte */
    unsigned char address_bytes;            /* bytes of memory address the device takes */
    unsigned short mode : 2, rest : 14;     /* mode 2 = driven through the GPIO pins */
};
extern struct i2c_bus i2c_bus_descriptor;
extern void gpio_write_pin(unsigned char, unsigned char, unsigned char);
extern void gpio_set_pin_input(unsigned char, unsigned char, unsigned char);
extern unsigned char gpio_read_pin(unsigned char, unsigned char);
extern void timer_delay_nop_rounds(unsigned short);

#define I2C_SCL_WAIT_ROUNDS 0xffff      /* longest wait for a released clock line to read high */

/*
 * Read one byte from the device on the software I2C bus in i2c_bus_descriptor, most significant bit first, and
 * answer it with an acknowledge or a refusal.
 *
 *   last  0: acknowledge the byte (the device sends more); non-zero: answer with NACK (this was the final byte)
 *
 * Returns the byte read. It cannot report an error: a dead bus simply reads as SDA level (a floating line
 * gives 0xFF). Both clock waits are counted (I2C_SCL_WAIT_ROUNDS rounds), so it never waits for ever.
 *
 * SDA is released first so the device can drive it. Per bit: raise SCL (released, then wait until it reads
 * high), take SCL back, wait, sample SDA into the byte, drive SCL low, wait. Then SDA is driven low (acknowledge)
 * or high (NACK) for one more clock pulse.
 *
 * Called by i2c_gpio_read_block and i2c_gpio_write_read once per data byte.
 */
unsigned char i2c_gpio_read_byte(unsigned char last)
{
    unsigned char bit;
    unsigned int value, shifted;
    unsigned short wait;
    unsigned int nack = last & 1;

    gpio_set_pin_input(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 1);
    gpio_write_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 1);
    value = 0;
    for (bit = 0; bit <= 7; bit++) {
        shifted = value << 1;
        gpio_write_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 1);
        gpio_set_pin_input(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 1);
        wait = I2C_SCL_WAIT_ROUNDS;
        while (!gpio_read_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask) && --wait) {
            __asm__ __volatile__("nop");
            __asm__ __volatile__("nop");
        }
        gpio_set_pin_input(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 0);
        timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
        /* Sample the data line while the clock is high. */
        if (!gpio_read_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask))
            value = shifted;
        else
            value = shifted | 1;
        gpio_write_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 0);
        timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
    }
    /* Ninth clock: SDA low = acknowledge, SDA high = NACK. */
    gpio_set_pin_input(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 0);
    if (!nack)
        gpio_write_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 0);
    else
        gpio_write_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 1);
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
    gpio_write_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 0);
    timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
    return value;
}
