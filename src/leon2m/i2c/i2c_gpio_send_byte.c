/* i2c_gpio_send_byte  (FUN_a002ab04)
 *
 * Send one byte MSB first over software I2C and return whether the receiver acknowledged.
 *   byte: byte to send
 * Returns: 0 = acknowledged, 1 = not acknowledged
 * Note: One ACK wait is unbounded (late ACK with SCL held).
 * Name basis: proven - header: bit-banged byte send + ACK
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002ab04 @ 0xa002ab04, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the bit masks are an initialised local array; the clock wait is
 * "while (!gpio_read_pin(...) && --wait) { nop; nop; }" with real nop instructions written as asm statements; the
 * result is an unsigned char returned as "result & 1".
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
#define I2C_ACK    0                    /* result: the device pulled SDA low */
#define I2C_NO_ACK 1                    /* result: no acknowledge */

/*
 * Send one byte on the software I2C bus in i2c_bus_descriptor, most significant bit first, and read the
 * acknowledge bit that follows.
 *
 *   byte  the byte to send
 *
 * Returns I2C_ACK (0) when the device acknowledged and I2C_NO_ACK (1) when it did not. The callers retry the
 * device byte on 1 and, for data bytes, stop at the first 1.
 *
 * Per bit: wait, SCL low, wait, SDA to the bit, wait, SCL high (released) and wait until it reads high, so a
 * device may stretch the clock; the wait is counted and gives up after I2C_SCL_WAIT_ROUNDS rounds. Then SDA
 * is released for the acknowledge bit and SCL is raised the same way. After that the line states decide:
 *   - SCL reads low:  no acknowledge (1);
 *   - SDA reads low:  acknowledge (0);
 *   - both high: a late acknowledge is waited for. The loop runs while SDA is still high and the counter
 *     (7 at the start) is not zero, and in every case until SCL reads high; the counter only ends the wait
 *     for SDA. The result is 1 when the counter has reached 0. This loop is the one wait of the I2C routines
 *     that has no limit of its own: its only exit is SCL reading high, so a device holding SCL low after the
 *     missing acknowledge keeps the processor here.
 * At the end SCL and SDA are taken and driven low.
 */
unsigned char i2c_gpio_send_byte(unsigned char byte)
{
    unsigned char bit_mask[8] = { 0x80, 0x40, 0x20, 0x10, 8, 4, 2, 1 };
    unsigned char bit, late_ack_count, result;
    unsigned short wait;

    for (bit = 0; bit <= 7; bit++) {
        timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
        gpio_write_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 0);
        timer_delay_nop_rounds(i2c_bus_descriptor.delay);
        if (byte & bit_mask[bit])
            gpio_write_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 1);
        else
            gpio_write_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 0);
        timer_delay_nop_rounds(i2c_bus_descriptor.delay);
        gpio_write_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 1);
        gpio_set_pin_input(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 1);
        /* Clock stretching: wait for the clock line to come up. */
        wait = I2C_SCL_WAIT_ROUNDS;
        while (!gpio_read_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask) && --wait) {
            __asm__ __volatile__("nop");
            __asm__ __volatile__("nop");
        }
        gpio_set_pin_input(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 0);
    }
    /* Ninth clock: release SDA so that the device can answer. */
    timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
    gpio_write_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 0);
    timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
    gpio_write_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 0);
    gpio_set_pin_input(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 1);
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
    gpio_set_pin_input(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 1);
    if (!gpio_read_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask))
        result = I2C_NO_ACK;
    else if (!gpio_read_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask))
        result = I2C_ACK;
    else {
        /* Late acknowledge: see the block comment above. */
        late_ack_count = 7;
        while ((gpio_read_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask) && late_ack_count)
               || !gpio_read_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask)) {
            timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
            late_ack_count--;
        }
        result = (late_ack_count == 0);
    }
    gpio_set_pin_input(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 0);
    gpio_write_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 0);
    gpio_set_pin_input(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 0);
    gpio_write_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 0);
    timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
    return result & 1;
}
