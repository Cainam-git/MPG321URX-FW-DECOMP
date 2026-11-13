/* gpio_write_port  (FUN_CODE_acf2)
 *
 * Write the output register of one numbered GPIO port.
 *   port: port 1..14
 *   value
 * Note: No caller in the bank-1 image.
 * Name basis: descriptive - ports 1..13 = 0xF000..0xF11E, 14 = P3 (same numbering as gpio_set_port_bits)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_acf2. Keil switch with a jump table; each case ends in its own RET.
 */
sfr P3 = 0xb0;
extern unsigned char xdata reg_gpio_port1, reg_gpio_port2, reg_gpio_port3, reg_gpio_port4;
extern unsigned char xdata reg_gpio_port5, reg_gpio_port6, reg_gpio_port7, reg_gpio_port8;
extern unsigned char xdata reg_gpio_port9, reg_gpio_port10, reg_gpio_port11, reg_gpio_port12;
extern unsigned char xdata reg_gpio_port13;

/*
 * gpio_write_port - write the output register of GPIO port 1..13 (XDATA registers 0xF000..0xF004, 0xF010, 0xF012,
 * 0xF114, 0xF116, 0xF118, 0xF11A, 0xF11C, 0xF11E, one byte per port); port 14 is the 8051's own P3, written with
 * bits 2, 3, 6 and 7 forced to 1. Any other port number writes nothing.
 * Counterpart of gpio_write_port_partner, which writes the odd registers (0xF005.., 0xF011.., 0xF115..).
 * No caller in the bank-1 image.
 */
void gpio_write_port(unsigned char port, unsigned char value)
{
    switch (port) {
    case 1: reg_gpio_port1 = value; break;
    case 2: reg_gpio_port2 = value; break;
    case 3: reg_gpio_port3 = value; break;
    case 4: reg_gpio_port4 = value; break;
    case 5: reg_gpio_port5 = value; break;
    case 6: reg_gpio_port6 = value; break;
    case 7: reg_gpio_port7 = value; break;
    case 8: reg_gpio_port8 = value; break;
    case 9: reg_gpio_port9 = value; break;
    case 10: reg_gpio_port10 = value; break;
    case 11: reg_gpio_port11 = value; break;
    case 12: reg_gpio_port12 = value; break;
    case 13: reg_gpio_port13 = value; break;
    case 14: P3 = value | 0xcc; break;
    }
}
