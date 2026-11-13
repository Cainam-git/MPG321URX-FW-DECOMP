/* gpio_read_port_data  (FUN_a00ddf24)
 *
 * Read the data byte of one of the 17 GPIO ports.
 * Returns: byte
 * Name basis: derived - registers 0xCF03C000..0xCF03CC0C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ddf24 @ 0xa00ddf24, flags -mcpu=v8 -O3 -g.
 * Source form: a switch on the port number with a local initialised to 0; the registers are volatile words
 * read at their constant addresses.
 */

/* Data registers of the 17 GPIO ports; the port number is the argument of gpio_read_port_data. */
#define GPIO_PORT_1_DATA  (*(volatile unsigned int *)0xcf03c000)
#define GPIO_PORT_2_DATA  (*(volatile unsigned int *)0xcf03c004)
#define GPIO_PORT_3_DATA  (*(volatile unsigned int *)0xcf03c008)
#define GPIO_PORT_4_DATA  (*(volatile unsigned int *)0xcf03c00c)
#define GPIO_PORT_5_DATA  (*(volatile unsigned int *)0xcf03c010)
#define GPIO_PORT_6_DATA  (*(volatile unsigned int *)0xcf03c040)
#define GPIO_PORT_7_DATA  (*(volatile unsigned int *)0xcf03c048)
#define GPIO_PORT_8_DATA  (*(volatile unsigned int *)0xcf03c450)
#define GPIO_PORT_9_DATA  (*(volatile unsigned int *)0xcf03c458)
#define GPIO_PORT_10_DATA (*(volatile unsigned int *)0xcf03c460)
#define GPIO_PORT_11_DATA (*(volatile unsigned int *)0xcf03c468)
#define GPIO_PORT_12_DATA (*(volatile unsigned int *)0xcf03c470)
#define GPIO_PORT_13_DATA (*(volatile unsigned int *)0xcf03c478)
#define GPIO_PORT_14_DATA (*(volatile unsigned int *)0xcf03cc00)
#define GPIO_PORT_15_DATA (*(volatile unsigned int *)0xcf03cc04)
#define GPIO_PORT_16_DATA (*(volatile unsigned int *)0xcf03cc08)
#define GPIO_PORT_17_DATA (*(volatile unsigned int *)0xcf03cc0c)

/*
 * Read the data register of GPIO port number 'port' (1..17) and return its low byte. Any other number gives 0.
 * The ports are not at regular spacing (0xCF03C000.., 0xCF03C040/48, 0xCF03C450.., 0xCF03CC00..), hence the table
 * of cases. Called by ipc_8051_set_indicator.
 */
unsigned char gpio_read_port_data(unsigned char port)
{
    unsigned char value = 0;

    switch (port) {
    case 1: value = GPIO_PORT_1_DATA; break;
    case 2: value = GPIO_PORT_2_DATA; break;
    case 3: value = GPIO_PORT_3_DATA; break;
    case 4: value = GPIO_PORT_4_DATA; break;
    case 5: value = GPIO_PORT_5_DATA; break;
    case 6: value = GPIO_PORT_6_DATA; break;
    case 7: value = GPIO_PORT_7_DATA; break;
    case 8: value = GPIO_PORT_8_DATA; break;
    case 9: value = GPIO_PORT_9_DATA; break;
    case 10: value = GPIO_PORT_10_DATA; break;
    case 11: value = GPIO_PORT_11_DATA; break;
    case 12: value = GPIO_PORT_12_DATA; break;
    case 13: value = GPIO_PORT_13_DATA; break;
    case 14: value = GPIO_PORT_14_DATA; break;
    case 15: value = GPIO_PORT_15_DATA; break;
    case 16: value = GPIO_PORT_16_DATA; break;
    case 17: value = GPIO_PORT_17_DATA; break;
    }
    return value;
}
