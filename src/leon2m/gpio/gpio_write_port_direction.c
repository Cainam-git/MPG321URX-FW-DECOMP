/* gpio_write_port_direction  (FUN_a00de088)
 *
 * Write the direction byte of one of the 17 GPIO ports.
 * Name basis: descriptive - registers 0xCF03C014..0xCF03CC4C; used by startup_init_pins
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de088 @ 0xa00de088-0xa00de1fc.
 * Source form: one switch on the port with a volatile word store per case; the registers are accessed through
 * the macros below.
 */

/* Input-select register of each GPIO port (gpio_set_pin_input sets and clears single pin bits in it). */
#define GPIO_INPUT_1   (*(volatile unsigned int *)0xCF03C014)
#define GPIO_INPUT_2   (*(volatile unsigned int *)0xCF03C018)
#define GPIO_INPUT_3   (*(volatile unsigned int *)0xCF03C01C)
#define GPIO_INPUT_4   (*(volatile unsigned int *)0xCF03C020)
#define GPIO_INPUT_5   (*(volatile unsigned int *)0xCF03C024)
#define GPIO_INPUT_6   (*(volatile unsigned int *)0xCF03C044)
#define GPIO_INPUT_7   (*(volatile unsigned int *)0xCF03C04C)
#define GPIO_INPUT_8   (*(volatile unsigned int *)0xCF03C454)
#define GPIO_INPUT_9   (*(volatile unsigned int *)0xCF03C45C)
#define GPIO_INPUT_10  (*(volatile unsigned int *)0xCF03C464)
#define GPIO_INPUT_11  (*(volatile unsigned int *)0xCF03C46C)
#define GPIO_INPUT_12  (*(volatile unsigned int *)0xCF03C474)
#define GPIO_INPUT_13  (*(volatile unsigned int *)0xCF03C47C)
#define GPIO_INPUT_14  (*(volatile unsigned int *)0xCF03CC40)
#define GPIO_INPUT_15  (*(volatile unsigned int *)0xCF03CC44)
#define GPIO_INPUT_16  (*(volatile unsigned int *)0xCF03CC48)
#define GPIO_INPUT_17  (*(volatile unsigned int *)0xCF03CC4C)

/*
 * Write a byte to the input-select register of one GPIO port. startup_init_pins uses it to write the
 * direction byte of each port from a fixed list.
 *
 *   port   GPIO port 1..17; any other number does nothing
 *   value  the byte to write
 */
void gpio_write_port_direction(unsigned char port, unsigned char value)
{
    switch (port) {
    case 1: GPIO_INPUT_1 = value; break;
    case 2: GPIO_INPUT_2 = value; break;
    case 3: GPIO_INPUT_3 = value; break;
    case 4: GPIO_INPUT_4 = value; break;
    case 5: GPIO_INPUT_5 = value; break;
    case 6: GPIO_INPUT_6 = value; break;
    case 7: GPIO_INPUT_7 = value; break;
    case 8: GPIO_INPUT_8 = value; break;
    case 9: GPIO_INPUT_9 = value; break;
    case 10: GPIO_INPUT_10 = value; break;
    case 11: GPIO_INPUT_11 = value; break;
    case 12: GPIO_INPUT_12 = value; break;
    case 13: GPIO_INPUT_13 = value; break;
    case 14: GPIO_INPUT_14 = value; break;
    case 15: GPIO_INPUT_15 = value; break;
    case 16: GPIO_INPUT_16 = value; break;
    case 17: GPIO_INPUT_17 = value; break;
    }
}
