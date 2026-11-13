/* gpio_read_port_bit  (FUN_CODE_af47)
 *
 * Return whether the masked pins of one GPIO port are high.
 *   port: port 1..14
 *   mask: pin bits
 * Returns: 1 when any masked bit is set
 * Name basis: derived - ports 1..13 = 0xF000.., 14 = P3; used by the key and wake pin scans
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_af47, OPTIMIZE(8,SPEED) (also with REGFILE(R.ORC)). Keil switch with a 3-byte LJMP table; the
 * shared tail is cross-jumped. No volatile needed (each register is read once). 'return r != 0;' also matches;
 * 'return r;' does not.
 */
#include <reg51.h>
extern unsigned char xdata reg_gpio_port1;
extern unsigned char xdata reg_gpio_port2;
extern unsigned char xdata reg_gpio_port3;
extern unsigned char xdata reg_gpio_port4;
extern unsigned char xdata reg_gpio_port5;
extern unsigned char xdata reg_gpio_port6;
extern unsigned char xdata reg_gpio_port7;
extern unsigned char xdata reg_gpio_port8;
extern unsigned char xdata reg_gpio_port9;
extern unsigned char xdata reg_gpio_port10;
extern unsigned char xdata reg_gpio_port11;
extern unsigned char xdata reg_gpio_port12;
extern unsigned char xdata reg_gpio_port13;
/*
 * gpio_read_port_bit - read GPIO port n and test it against mask. Ports 1..13 are the same XDATA registers
 * gpio_write_port writes (0xF000.., 0xF114.., 0xF118..); port 14 is the 8051's P3. Any other n counts as 0.
 * Returns 1 when any masked bit is set, else 0.
 * Callers: power_scan_wake_keys, power_find_active_wake_pin and usb_update_dp_port_flags.
 */
bit gpio_read_port_bit(unsigned char port, unsigned char mask)
{
    unsigned char masked;
    switch (port) {
    case 1: masked = reg_gpio_port1 & mask; break;
    case 2: masked = reg_gpio_port2 & mask; break;
    case 3: masked = reg_gpio_port3 & mask; break;
    case 4: masked = reg_gpio_port4 & mask; break;
    case 5: masked = reg_gpio_port5 & mask; break;
    case 6: masked = reg_gpio_port6 & mask; break;
    case 7: masked = reg_gpio_port7 & mask; break;
    case 8: masked = reg_gpio_port8 & mask; break;
    case 9: masked = reg_gpio_port9 & mask; break;
    case 10: masked = reg_gpio_port10 & mask; break;
    case 11: masked = reg_gpio_port11 & mask; break;
    case 12: masked = reg_gpio_port12 & mask; break;
    case 13: masked = reg_gpio_port13 & mask; break;
    case 14: masked = P3 & mask; break;
    default: masked = 0; break;
    }
    if (masked) return 1;
    return 0;
}
