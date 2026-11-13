/* i2c_gpio_start  (FUN_a002a910)
 *
 * Send a software-I2C START, clocking the bus free when SDA is stuck low.
 * Note: Uses the bus descriptor at 0xA802D992 (SCL/SDA port and mask, half-bit delay).
 * Name basis: proven - header: START sequence and recovery clocks; callers are the bit-banged I2C transfers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002a910 @ 0xa002a910, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the clock wait is "while (!gpio_read_pin(...) && --wait) { nop; nop; }"
 * with the two nops written as asm statements (they are real instructions in the firmware); the recovery loop is a
 * for loop with an unsigned char counter.
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
#define MAX_RECOVERY_CLOCKS 9           /* clock pulses tried to free a data line held low */

/*
 * Put a START condition on the software I2C bus in i2c_bus_descriptor: SDA falls while SCL is high. If a device
 * holds SDA low, the routine first clocks the bus to make the device let go.
 *
 * No parameters, no return value, and it cannot fail or wait for ever: every wait is counted (the clock waits
 * at most I2C_SCL_WAIT_ROUNDS rounds, the recovery at most MAX_RECOVERY_CLOCKS pulses). A bus that stays stuck
 * just runs the counters out and the START is made anyway.
 *
 * Order:
 *  1. Drive SDA and SCL high, release SCL and wait until it reads high (a device may hold the clock), take SCL
 *     back, release SDA, wait one bit time.
 *  2. While SDA reads low, give one clock pulse (SCL low, wait, SCL high and released, wait for SCL to read high,
 *     take SCL back, wait), at most MAX_RECOVERY_CLOCKS times.
 *  3. Take SDA, drive it low while SCL is high (this is the START), wait, drive SCL low.
 *
 * Called by every transfer routine of the bus (the write and read routines and the address probe); the block
 * read and the write-then-read call it a second time as the repeated START.
 *
 * "Release" is gpio_set_pin_input(port, mask, 1): the line floats and can be read back. gpio_set_pin_input(..., 0)
 * takes the line back so that gpio_write_pin drives it.
 */
void i2c_gpio_start(void)
{
    unsigned char pulse;
    unsigned short wait;

    gpio_set_pin_input(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 0);
    gpio_write_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 1);
    gpio_write_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 1);
    gpio_set_pin_input(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 1);
    /* Wait for the clock line to come up (a device may hold it low). */
    wait = I2C_SCL_WAIT_ROUNDS;
    while (!gpio_read_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask) && --wait) {
        __asm__ __volatile__("nop");
        __asm__ __volatile__("nop");
    }
    gpio_set_pin_input(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 0);
    gpio_set_pin_input(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 1);
    timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
    /* SDA held low by a device: send clock pulses until it lets go. */
    for (pulse = 0; !gpio_read_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask) && pulse <= MAX_RECOVERY_CLOCKS - 1; pulse++) {
        gpio_write_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 0);
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
    }
    /* START: SDA goes low while SCL is high, then SCL goes low. */
    gpio_set_pin_input(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 0);
    gpio_write_pin(i2c_bus_descriptor.sda_port, i2c_bus_descriptor.sda_mask, 0);
    timer_delay_nop_rounds(i2c_bus_descriptor.delay * 2);
    gpio_write_pin(i2c_bus_descriptor.scl_port, i2c_bus_descriptor.scl_mask, 0);
}
