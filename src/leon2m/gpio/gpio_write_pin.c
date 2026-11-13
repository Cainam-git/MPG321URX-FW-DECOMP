/* gpio_write_pin  (FUN_a002c86c)
 *
 * Drive the pins of mask on GPIO port 1..17 to level.
 *   port: GPIO port 1..17
 *   mask: pin bits
 *   level: bit 0 = output level
 * Name basis: proven - header: port data registers 0xCF03C000..; used by the software I2C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002c86c @ 0xa002c86c..0xa002cb30 (177 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - 'switch (level & 1) { case 1: ...; default: ...; }': an if/else puts the other arm in the fall-through;
 *  - one switch on the port in each arm: the two compiled jump tables (0xA002C704 for level 1, 0xA002C74C for
 *    level 0) equal the firmware's;
 *  - the registers are volatile (hardware registers); the macros below expand to the same accesses.
 */

/* Data register of each GPIO port: written here, read by gpio_read_pin. */
#define GPIO_DATA_1   (*(volatile unsigned int *)0xCF03C000)
#define GPIO_DATA_2   (*(volatile unsigned int *)0xCF03C004)
#define GPIO_DATA_3   (*(volatile unsigned int *)0xCF03C008)
#define GPIO_DATA_4   (*(volatile unsigned int *)0xCF03C00C)
#define GPIO_DATA_5   (*(volatile unsigned int *)0xCF03C010)
#define GPIO_DATA_6   (*(volatile unsigned int *)0xCF03C040)
#define GPIO_DATA_7   (*(volatile unsigned int *)0xCF03C048)
#define GPIO_DATA_8   (*(volatile unsigned int *)0xCF03C450)
#define GPIO_DATA_9   (*(volatile unsigned int *)0xCF03C458)
#define GPIO_DATA_10  (*(volatile unsigned int *)0xCF03C460)
#define GPIO_DATA_11  (*(volatile unsigned int *)0xCF03C468)
#define GPIO_DATA_12  (*(volatile unsigned int *)0xCF03C470)
#define GPIO_DATA_13  (*(volatile unsigned int *)0xCF03C478)
#define GPIO_DATA_14  (*(volatile unsigned int *)0xCF03CC00)
#define GPIO_DATA_15  (*(volatile unsigned int *)0xCF03CC04)
#define GPIO_DATA_16  (*(volatile unsigned int *)0xCF03CC08)
#define GPIO_DATA_17  (*(volatile unsigned int *)0xCF03CC0C)
/* Input-select register of each GPIO port: a pin bit is set and cleared by gpio_set_pin_input. */
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
 * Set (level bit 0 = 1) or clear (level bit 0 = 0) the pins of mask in the data register of one GPIO port.
 *
 *   port   GPIO port 1..17; port 0 and ports above 17 write nothing
 *   mask   the pins to change, one bit per pin
 *   level  only bit 0 counts (callers also pass 0xFF for high)
 *
 * The routine works in two steps:
 *   1. bit 0 of level picks the set arm or the clear arm;
 *   2. in that arm, the port picks its data register and input-select register, and one read-modify-write
 *      changes the data register.
 * Each write puts the data register's value ORed with the port's input-select register back, then sets or
 * clears the pins of mask. Pins whose input-select bit is set are therefore written as 1, except the pins of
 * mask in the clear arm.
 *
 * Callers: the software I2C routines (i2c_gpio_start, i2c_gpio_send_byte, i2c_gpio_read_byte and the block
 * routines), startup_init_pins, nvram_write, APPSetPowerOff and the many one-pin gpio_set_port* helpers.
 * A leaf: no loop, no wait, no failure path.
 */
void gpio_write_pin(unsigned char port, unsigned char mask, unsigned char level)
{
    switch (level & 1) {
    case 1:
        /* Drive the pins of mask high. */
        switch (port) {
        case 1:
            GPIO_DATA_1 = GPIO_DATA_1 | GPIO_INPUT_1 | mask;
            break;
        case 2:
            GPIO_DATA_2 = GPIO_DATA_2 | GPIO_INPUT_2 | mask;
            break;
        case 3:
            GPIO_DATA_3 = GPIO_DATA_3 | GPIO_INPUT_3 | mask;
            break;
        case 4:
            GPIO_DATA_4 = GPIO_DATA_4 | GPIO_INPUT_4 | mask;
            break;
        case 5:
            GPIO_DATA_5 = GPIO_DATA_5 | GPIO_INPUT_5 | mask;
            break;
        case 6:
            GPIO_DATA_6 = GPIO_DATA_6 | GPIO_INPUT_6 | mask;
            break;
        case 7:
            GPIO_DATA_7 = GPIO_DATA_7 | GPIO_INPUT_7 | mask;
            break;
        case 8:
            GPIO_DATA_8 = GPIO_DATA_8 | GPIO_INPUT_8 | mask;
            break;
        case 9:
            GPIO_DATA_9 = GPIO_DATA_9 | GPIO_INPUT_9 | mask;
            break;
        case 10:
            GPIO_DATA_10 = GPIO_DATA_10 | GPIO_INPUT_10 | mask;
            break;
        case 11:
            GPIO_DATA_11 = GPIO_DATA_11 | GPIO_INPUT_11 | mask;
            break;
        case 12:
            GPIO_DATA_12 = GPIO_DATA_12 | GPIO_INPUT_12 | mask;
            break;
        case 13:
            GPIO_DATA_13 = GPIO_DATA_13 | GPIO_INPUT_13 | mask;
            break;
        case 14:
            GPIO_DATA_14 = GPIO_DATA_14 | GPIO_INPUT_14 | mask;
            break;
        case 15:
            GPIO_DATA_15 = GPIO_DATA_15 | GPIO_INPUT_15 | mask;
            break;
        case 16:
            GPIO_DATA_16 = GPIO_DATA_16 | GPIO_INPUT_16 | mask;
            break;
        case 17:
            GPIO_DATA_17 = GPIO_DATA_17 | GPIO_INPUT_17 | mask;
            break;
        }
        break;
    default:
        /* Drive the pins of mask low. */
        switch (port) {
        case 1:
            GPIO_DATA_1 = (GPIO_DATA_1 | GPIO_INPUT_1) & ~mask;
            break;
        case 2:
            GPIO_DATA_2 = (GPIO_DATA_2 | GPIO_INPUT_2) & ~mask;
            break;
        case 3:
            GPIO_DATA_3 = (GPIO_DATA_3 | GPIO_INPUT_3) & ~mask;
            break;
        case 4:
            GPIO_DATA_4 = (GPIO_DATA_4 | GPIO_INPUT_4) & ~mask;
            break;
        case 5:
            GPIO_DATA_5 = (GPIO_DATA_5 | GPIO_INPUT_5) & ~mask;
            break;
        case 6:
            GPIO_DATA_6 = (GPIO_DATA_6 | GPIO_INPUT_6) & ~mask;
            break;
        case 7:
            GPIO_DATA_7 = (GPIO_DATA_7 | GPIO_INPUT_7) & ~mask;
            break;
        case 8:
            GPIO_DATA_8 = (GPIO_DATA_8 | GPIO_INPUT_8) & ~mask;
            break;
        case 9:
            GPIO_DATA_9 = (GPIO_DATA_9 | GPIO_INPUT_9) & ~mask;
            break;
        case 10:
            GPIO_DATA_10 = (GPIO_DATA_10 | GPIO_INPUT_10) & ~mask;
            break;
        case 11:
            GPIO_DATA_11 = (GPIO_DATA_11 | GPIO_INPUT_11) & ~mask;
            break;
        case 12:
            GPIO_DATA_12 = (GPIO_DATA_12 | GPIO_INPUT_12) & ~mask;
            break;
        case 13:
            GPIO_DATA_13 = (GPIO_DATA_13 | GPIO_INPUT_13) & ~mask;
            break;
        case 14:
            GPIO_DATA_14 = (GPIO_DATA_14 | GPIO_INPUT_14) & ~mask;
            break;
        case 15:
            GPIO_DATA_15 = (GPIO_DATA_15 | GPIO_INPUT_15) & ~mask;
            break;
        case 16:
            GPIO_DATA_16 = (GPIO_DATA_16 | GPIO_INPUT_16) & ~mask;
            break;
        case 17:
            GPIO_DATA_17 = (GPIO_DATA_17 | GPIO_INPUT_17) & ~mask;
            break;
        }
        break;
    }
}
