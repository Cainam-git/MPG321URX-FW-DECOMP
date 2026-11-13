/* gpio_set_pin_input  (FUN_a002cb30)
 *
 * Release the pins of mask on GPIO port 1..17 (on = 1) or drive them (on = 0)
 *   port: GPIO port 1..17
 *   mask: pin bits
 *   on: 1 = release (input)
 * Note: The software I2C releases a line with on = 1 before reading it.
 * Name basis: proven - header: direction registers 0xCF03C014..; I2C usage
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002cb30 @ 0xa002cb30..0xa002cd38 (130 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - 'if (on == 1) set-switch else clear-switch' (the compiler moves the == arm out of line);
 *  - one switch on the port in each arm: the two compiled jump tables (0xA002C794 for on == 1, 0xA002C7DC for
 *    the other case) equal the firmware's; the table at 0xA002C7DC lies outside the image piece the exact
 *    check links (see gpio/gpio_read_pin.c);
 *  - the registers are volatile (hardware registers); the macros below expand to the same accesses.
 */

/* Input-select register of each GPIO port (gpio_write_pin ORs it into the port's data register). */
#define GPIO_INPUT_1  (*(volatile unsigned int *)0xCF03C014)
#define GPIO_INPUT_2  (*(volatile unsigned int *)0xCF03C018)
#define GPIO_INPUT_3  (*(volatile unsigned int *)0xCF03C01C)
#define GPIO_INPUT_4  (*(volatile unsigned int *)0xCF03C020)
#define GPIO_INPUT_5  (*(volatile unsigned int *)0xCF03C024)
#define GPIO_INPUT_6  (*(volatile unsigned int *)0xCF03C044)
#define GPIO_INPUT_7  (*(volatile unsigned int *)0xCF03C04C)
#define GPIO_INPUT_8  (*(volatile unsigned int *)0xCF03C454)
#define GPIO_INPUT_9  (*(volatile unsigned int *)0xCF03C45C)
#define GPIO_INPUT_10 (*(volatile unsigned int *)0xCF03C464)
#define GPIO_INPUT_11 (*(volatile unsigned int *)0xCF03C46C)
#define GPIO_INPUT_12 (*(volatile unsigned int *)0xCF03C474)
#define GPIO_INPUT_13 (*(volatile unsigned int *)0xCF03C47C)
#define GPIO_INPUT_14 (*(volatile unsigned int *)0xCF03CC40)
#define GPIO_INPUT_15 (*(volatile unsigned int *)0xCF03CC44)
#define GPIO_INPUT_16 (*(volatile unsigned int *)0xCF03CC48)
#define GPIO_INPUT_17 (*(volatile unsigned int *)0xCF03CC4C)

/*
 * Set (on == 1) or clear (any other value) the pins of mask in the input-select register of one GPIO port.
 *
 *   port   GPIO port 1..17; port 0 and ports above 17 write nothing
 *   mask   the pins to change, one bit per pin
 *   on     1 sets the bits; every other value clears them
 *
 * The routine works in two steps:
 *   1. on picks the set arm or the clear arm;
 *   2. in that arm, the port picks its input-select register, and one read-modify-write changes it.
 *
 * The software I2C routines (i2c_gpio_start, i2c_gpio_read_byte and the others) call it with 1 on a line just
 * before they read that line with gpio_read_pin, and with 0 afterwards. power_prepare_standby_pins also calls
 * it with 1. A leaf: no loop, no wait, no failure path.
 */
void gpio_set_pin_input(unsigned char port, unsigned char mask, unsigned char on)
{
    if (on == 1) {
        /* Set the input-select bits of mask. */
        switch (port) {
        case 1:
            GPIO_INPUT_1 |= mask;
            break;
        case 2:
            GPIO_INPUT_2 |= mask;
            break;
        case 3:
            GPIO_INPUT_3 |= mask;
            break;
        case 4:
            GPIO_INPUT_4 |= mask;
            break;
        case 5:
            GPIO_INPUT_5 |= mask;
            break;
        case 6:
            GPIO_INPUT_6 |= mask;
            break;
        case 7:
            GPIO_INPUT_7 |= mask;
            break;
        case 8:
            GPIO_INPUT_8 |= mask;
            break;
        case 9:
            GPIO_INPUT_9 |= mask;
            break;
        case 10:
            GPIO_INPUT_10 |= mask;
            break;
        case 11:
            GPIO_INPUT_11 |= mask;
            break;
        case 12:
            GPIO_INPUT_12 |= mask;
            break;
        case 13:
            GPIO_INPUT_13 |= mask;
            break;
        case 14:
            GPIO_INPUT_14 |= mask;
            break;
        case 15:
            GPIO_INPUT_15 |= mask;
            break;
        case 16:
            GPIO_INPUT_16 |= mask;
            break;
        case 17:
            GPIO_INPUT_17 |= mask;
            break;
        }
    } else {
        /* Clear the input-select bits of mask. */
        switch (port) {
        case 1:
            GPIO_INPUT_1 &= ~mask;
            break;
        case 2:
            GPIO_INPUT_2 &= ~mask;
            break;
        case 3:
            GPIO_INPUT_3 &= ~mask;
            break;
        case 4:
            GPIO_INPUT_4 &= ~mask;
            break;
        case 5:
            GPIO_INPUT_5 &= ~mask;
            break;
        case 6:
            GPIO_INPUT_6 &= ~mask;
            break;
        case 7:
            GPIO_INPUT_7 &= ~mask;
            break;
        case 8:
            GPIO_INPUT_8 &= ~mask;
            break;
        case 9:
            GPIO_INPUT_9 &= ~mask;
            break;
        case 10:
            GPIO_INPUT_10 &= ~mask;
            break;
        case 11:
            GPIO_INPUT_11 &= ~mask;
            break;
        case 12:
            GPIO_INPUT_12 &= ~mask;
            break;
        case 13:
            GPIO_INPUT_13 &= ~mask;
            break;
        case 14:
            GPIO_INPUT_14 &= ~mask;
            break;
        case 15:
            GPIO_INPUT_15 &= ~mask;
            break;
        case 16:
            GPIO_INPUT_16 &= ~mask;
            break;
        case 17:
            GPIO_INPUT_17 &= ~mask;
            break;
        }
    }
}
