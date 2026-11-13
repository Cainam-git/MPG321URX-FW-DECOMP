/* gpio_write_port_config_pair  (FUN_a00de1fc)
 *
 * Write two configuration bytes of one of the 17 GPIO ports.
 * Name basis: descriptive - register pairs selected by the port; used by startup_init_pins
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de1fc @ 0xa00de1fc-0xa00de444 (146 words), flags -mcpu=v8 -O3 -g; the switch uses the jump table
 * at 0xa00ddd28. Every register is a volatile word written with a byte value.
 */

/* Two registers per GPIO port, numbered 1..17 as in gpio_write_pin. What the bits do is not shown in the
   firmware; the only writer is startup_init_pins. The registers lie in three groups (ports 1..7, 8..13,
   14..17), 4 bytes apart; in the B row ports 6 and 7 follow port 5 after a gap of 8 bytes. */
#define GPIO_CONFIG_A_1  (*(volatile unsigned int *)0xcf03c2c0)
#define GPIO_CONFIG_A_2  (*(volatile unsigned int *)0xcf03c2c4)
#define GPIO_CONFIG_A_3  (*(volatile unsigned int *)0xcf03c2c8)
#define GPIO_CONFIG_A_4  (*(volatile unsigned int *)0xcf03c2cc)
#define GPIO_CONFIG_A_5  (*(volatile unsigned int *)0xcf03c2d0)
#define GPIO_CONFIG_A_6  (*(volatile unsigned int *)0xcf03c2d4)
#define GPIO_CONFIG_A_7  (*(volatile unsigned int *)0xcf03c2d8)
#define GPIO_CONFIG_A_8  (*(volatile unsigned int *)0xcf03c4c0)
#define GPIO_CONFIG_A_9  (*(volatile unsigned int *)0xcf03c4c4)
#define GPIO_CONFIG_A_10 (*(volatile unsigned int *)0xcf03c4c8)
#define GPIO_CONFIG_A_11 (*(volatile unsigned int *)0xcf03c4cc)
#define GPIO_CONFIG_A_12 (*(volatile unsigned int *)0xcf03c4d0)
#define GPIO_CONFIG_A_13 (*(volatile unsigned int *)0xcf03c4d4)
#define GPIO_CONFIG_A_14 (*(volatile unsigned int *)0xcf03cc80)
#define GPIO_CONFIG_A_15 (*(volatile unsigned int *)0xcf03cc84)
#define GPIO_CONFIG_A_16 (*(volatile unsigned int *)0xcf03cc88)
#define GPIO_CONFIG_A_17 (*(volatile unsigned int *)0xcf03cc8c)
#define GPIO_CONFIG_B_1  (*(volatile unsigned int *)0xcf03c31c)
#define GPIO_CONFIG_B_2  (*(volatile unsigned int *)0xcf03c320)
#define GPIO_CONFIG_B_3  (*(volatile unsigned int *)0xcf03c324)
#define GPIO_CONFIG_B_4  (*(volatile unsigned int *)0xcf03c328)
#define GPIO_CONFIG_B_5  (*(volatile unsigned int *)0xcf03c32c)
#define GPIO_CONFIG_B_6  (*(volatile unsigned int *)0xcf03c338)
#define GPIO_CONFIG_B_7  (*(volatile unsigned int *)0xcf03c33c)
#define GPIO_CONFIG_B_8  (*(volatile unsigned int *)0xcf03c4e0)
#define GPIO_CONFIG_B_9  (*(volatile unsigned int *)0xcf03c4e4)
#define GPIO_CONFIG_B_10 (*(volatile unsigned int *)0xcf03c4e8)
#define GPIO_CONFIG_B_11 (*(volatile unsigned int *)0xcf03c4ec)
#define GPIO_CONFIG_B_12 (*(volatile unsigned int *)0xcf03c4f0)
#define GPIO_CONFIG_B_13 (*(volatile unsigned int *)0xcf03c4f4)
#define GPIO_CONFIG_B_14 (*(volatile unsigned int *)0xcf03ccc0)
#define GPIO_CONFIG_B_15 (*(volatile unsigned int *)0xcf03ccc4)
#define GPIO_CONFIG_B_16 (*(volatile unsigned int *)0xcf03ccc8)
#define GPIO_CONFIG_B_17 (*(volatile unsigned int *)0xcf03cccc)

/*
 * Write one byte to each of the two configuration registers of a GPIO port.
 *
 *   port    GPIO port 1..17; any other value writes nothing
 *   first   byte for the GPIO_CONFIG_A register of the port
 *   second  byte for the GPIO_CONFIG_B register of the port
 *
 * Called only by startup_init_pins, once for each port 1..17 in order, when the boot byte from the 8051 is 0
 * or 1. The values it writes: first = 7, 7, 0, 0xF0, 3, 7, 0x84, 0, 8, 0, 0, 0xC1, 0x6C, 0, 0, 0, 0 for ports
 * 1..17; second = 2 for port 2 and 0 for all others.
 */
void gpio_write_port_config_pair(unsigned char port, unsigned char first, unsigned char second)
{
    switch (port) {
    case 1:
        GPIO_CONFIG_A_1 = first;
        GPIO_CONFIG_B_1 = second;
        break;
    case 2:
        GPIO_CONFIG_A_2 = first;
        GPIO_CONFIG_B_2 = second;
        break;
    case 3:
        GPIO_CONFIG_A_3 = first;
        GPIO_CONFIG_B_3 = second;
        break;
    case 4:
        GPIO_CONFIG_A_4 = first;
        GPIO_CONFIG_B_4 = second;
        break;
    case 5:
        GPIO_CONFIG_A_5 = first;
        GPIO_CONFIG_B_5 = second;
        break;
    case 6:
        GPIO_CONFIG_A_6 = first;
        GPIO_CONFIG_B_6 = second;
        break;
    case 7:
        GPIO_CONFIG_A_7 = first;
        GPIO_CONFIG_B_7 = second;
        break;
    case 8:
        GPIO_CONFIG_A_8 = first;
        GPIO_CONFIG_B_8 = second;
        break;
    case 9:
        GPIO_CONFIG_A_9 = first;
        GPIO_CONFIG_B_9 = second;
        break;
    case 10:
        GPIO_CONFIG_A_10 = first;
        GPIO_CONFIG_B_10 = second;
        break;
    case 11:
        GPIO_CONFIG_A_11 = first;
        GPIO_CONFIG_B_11 = second;
        break;
    case 12:
        GPIO_CONFIG_A_12 = first;
        GPIO_CONFIG_B_12 = second;
        break;
    case 13:
        GPIO_CONFIG_A_13 = first;
        GPIO_CONFIG_B_13 = second;
        break;
    case 14:
        GPIO_CONFIG_A_14 = first;
        GPIO_CONFIG_B_14 = second;
        break;
    case 15:
        GPIO_CONFIG_A_15 = first;
        GPIO_CONFIG_B_15 = second;
        break;
    case 16:
        GPIO_CONFIG_A_16 = first;
        GPIO_CONFIG_B_16 = second;
        break;
    case 17:
        GPIO_CONFIG_A_17 = first;
        GPIO_CONFIG_B_17 = second;
        break;
    }
}
