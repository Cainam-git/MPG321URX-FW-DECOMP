/* gpio_write_port_partner  (FUN_CODE_b33e)
 *
 * Write the partner register of one numbered GPIO port.
 *   port: port 1..13
 *   value
 * Note: No caller in the bank-1 image.
 * Name basis: descriptive - partner registers 0xF005.. of ports 1..13 (counterpart of gpio_write_port)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_b33e, OPTIMIZE(7,SPEED) (the same bytes at OPTIMIZE(8,SPEED) LARGE). Keil switch with a jump
 * table; each case ends in its own RET. The registers are hardware registers (volatile).
 */
extern unsigned char volatile xdata reg_gpio_port1_partner, reg_gpio_port2_partner, reg_gpio_port3_partner, reg_gpio_port4_partner;
extern unsigned char volatile xdata reg_gpio_port5_partner, reg_gpio_port6_partner, reg_gpio_port7_partner, reg_gpio_port8_partner;
extern unsigned char volatile xdata reg_gpio_port9_partner, reg_gpio_port10_partner, reg_gpio_port11_partner, reg_gpio_port12_partner;
extern unsigned char volatile xdata reg_gpio_port13_partner;

/*
 * gpio_write_port_partner - write the partner register of GPIO port 1..13: the register one address above the one
 * gpio_write_port writes (0xF005..0xF009, 0xF011, 0xF013, 0xF115, 0xF117, 0xF119, 0xF11B, 0xF11D, 0xF11F). Any
 * other port number writes nothing. No caller in the bank-1 image.
 */
void gpio_write_port_partner(unsigned char port, unsigned char value)
{
    switch (port) {
    case 1: reg_gpio_port1_partner = value; break;
    case 2: reg_gpio_port2_partner = value; break;
    case 3: reg_gpio_port3_partner = value; break;
    case 4: reg_gpio_port4_partner = value; break;
    case 5: reg_gpio_port5_partner = value; break;
    case 6: reg_gpio_port6_partner = value; break;
    case 7: reg_gpio_port7_partner = value; break;
    case 8: reg_gpio_port8_partner = value; break;
    case 9: reg_gpio_port9_partner = value; break;
    case 10: reg_gpio_port10_partner = value; break;
    case 11: reg_gpio_port11_partner = value; break;
    case 12: reg_gpio_port12_partner = value; break;
    case 13: reg_gpio_port13_partner = value; break;
    }
}
