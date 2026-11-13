/* gpio_write_port_data  (FUN_a00dddb8)
 *
 * Write the data byte of one of the 17 GPIO ports.
 * Name basis: derived - registers 0xCF03C000..0xCF03CC0C; used by startup_init_pins
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dddb8 @ 0xa00dddb8-0xa00ddf24 (91 words), flags -mcpu=v8 -O3 -g.
 * Source form: one switch on the port with a volatile word store per case; the registers are accessed through
 * the macros below.
 */

/* Data register of each GPIO port (the same registers gpio_write_pin changes bit by bit). */
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
 * Write a byte to the data register of one GPIO port.
 *
 *   port   GPIO port 1..17; any other number does nothing
 *   value  the byte to write
 *
 * Called from startup_init_pins, which gives every port its start value.
 */
void gpio_write_port_data(unsigned char port, unsigned char value)
{
    switch (port) {
    case 1: GPIO_DATA_1 = value; break;
    case 2: GPIO_DATA_2 = value; break;
    case 3: GPIO_DATA_3 = value; break;
    case 4: GPIO_DATA_4 = value; break;
    case 5: GPIO_DATA_5 = value; break;
    case 6: GPIO_DATA_6 = value; break;
    case 7: GPIO_DATA_7 = value; break;
    case 8: GPIO_DATA_8 = value; break;
    case 9: GPIO_DATA_9 = value; break;
    case 10: GPIO_DATA_10 = value; break;
    case 11: GPIO_DATA_11 = value; break;
    case 12: GPIO_DATA_12 = value; break;
    case 13: GPIO_DATA_13 = value; break;
    case 14: GPIO_DATA_14 = value; break;
    case 15: GPIO_DATA_15 = value; break;
    case 16: GPIO_DATA_16 = value; break;
    case 17: GPIO_DATA_17 = value; break;
    }
}
