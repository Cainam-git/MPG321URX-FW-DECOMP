/* gpio_read_pin  (FUN_a002cd38)
 *
 * Return 1 when any pin of mask on GPIO port 1..17 reads high.
 *   port: GPIO port 1..17
 *   mask: pin bits
 * Returns: 0 or 1
 * Name basis: proven - reads the port data registers 0xCF03C000.. (the registers gpio_write_pin writes); used
 *   by the software I2C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002cd38 @ 0xa002cd38, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: a switch on the port with one case per port; the compiled jump table
 * equals the firmware's (entries relative to the function). The registers are volatile (hardware registers).
 * This routine runs at its listing address, so the runtime shift of the main body does not apply to its jump table.
 */
/* Data register of each GPIO port (the same registers gpio_write_pin writes). */
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

/*
 * Read the level of GPIO pins: tell whether any pin of mask on one port reads high.
 *
 *   port  GPIO port 1..17
 *   mask  pin bits to look at
 *
 * Returns 1 when at least one of the masked pins reads high, otherwise 0. Port 0 and ports above 17 have no
 * register and give 0. Each port has its own 32-bit data register; only the low byte of the masked value is kept.
 *
 * A single register read, so it never waits. The software I2C routines use it to look at SCL and SDA.
 */
unsigned char gpio_read_pin(unsigned char port, unsigned char mask)
{
    unsigned char pins;

    switch (port) {
    case 1:
        pins = GPIO_DATA_1 & mask;
        break;
    case 2:
        pins = GPIO_DATA_2 & mask;
        break;
    case 3:
        pins = GPIO_DATA_3 & mask;
        break;
    case 4:
        pins = GPIO_DATA_4 & mask;
        break;
    case 5:
        pins = GPIO_DATA_5 & mask;
        break;
    case 6:
        pins = GPIO_DATA_6 & mask;
        break;
    case 7:
        pins = GPIO_DATA_7 & mask;
        break;
    case 8:
        pins = GPIO_DATA_8 & mask;
        break;
    case 9:
        pins = GPIO_DATA_9 & mask;
        break;
    case 10:
        pins = GPIO_DATA_10 & mask;
        break;
    case 11:
        pins = GPIO_DATA_11 & mask;
        break;
    case 12:
        pins = GPIO_DATA_12 & mask;
        break;
    case 13:
        pins = GPIO_DATA_13 & mask;
        break;
    case 14:
        pins = GPIO_DATA_14 & mask;
        break;
    case 15:
        pins = GPIO_DATA_15 & mask;
        break;
    case 16:
        pins = GPIO_DATA_16 & mask;
        break;
    case 17:
        pins = GPIO_DATA_17 & mask;
        break;
    default:
        pins = 0;
        break;
    }
    return pins != 0;
}
