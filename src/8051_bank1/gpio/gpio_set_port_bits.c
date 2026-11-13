/* gpio_set_port_bits  (FUN_CODE_5f73)
 *
 * Set or clear bits of one GPIO port's output register.
 *   port: port 1..14
 *   mask: pin bits
 *   set: 1 set, 0 clear
 * Name basis: derived - ports 1..13 = 0xF000..0xF11E with partner registers, 14 = P3; used by the power-cut
 *   and standby pin lists
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_5f73 @ 0x5f73 .. 0x611a. Options: OPTIMIZE(8,SPEED).
 * Two Keil switches with 14-entry LJMP tables (0x5F98, 0x6063).
 * Source form: 'if ((set = set & 1) == 1)' keeps the masked value in R3 (MOV A,R3 / ANL / MOV R3,A); the case
 * statements 'reg = reg | partner | mask' read the partner first, and Keil cross-jumps the shared tails (0x6042,
 * 0x610D).
 */
sfr P3 = 0xb0;
extern unsigned char xdata reg_gpio_port1;
extern unsigned char xdata reg_gpio_port2;
extern unsigned char xdata reg_gpio_port3;
extern unsigned char xdata reg_gpio_port4;
extern unsigned char xdata reg_gpio_port5;
extern unsigned char xdata reg_gpio_port1_partner;
extern unsigned char xdata reg_gpio_port2_partner;
extern unsigned char xdata reg_gpio_port3_partner;
extern unsigned char xdata reg_gpio_port4_partner;
extern unsigned char xdata reg_gpio_port5_partner;
extern unsigned char xdata reg_gpio_port6;
extern unsigned char xdata reg_gpio_port6_partner;
extern unsigned char xdata reg_gpio_port7;
extern unsigned char xdata reg_gpio_port7_partner;
extern unsigned char xdata reg_gpio_port8;
extern unsigned char xdata reg_gpio_port8_partner;
extern unsigned char xdata reg_gpio_port9;
extern unsigned char xdata reg_gpio_port9_partner;
extern unsigned char xdata reg_gpio_port10;
extern unsigned char xdata reg_gpio_port10_partner;
extern unsigned char xdata reg_gpio_port11;
extern unsigned char xdata reg_gpio_port11_partner;
extern unsigned char xdata reg_gpio_port12;
extern unsigned char xdata reg_gpio_port12_partner;
extern unsigned char xdata reg_gpio_port13;
extern unsigned char xdata reg_gpio_port13_partner;

#define GPIO_PORT_P3 14          /* port 14 = the 8051's own port P3 (no partner register) */

/*
 * gpio_set_port_bits - set or clear pins of one GPIO port.
 *   port  1..13: output register reg_gpio_port<N>; 14: port P3; any other value changes nothing
 *   mask  the pins
 *   set   bit 0 set: the pins go to 1; clear: they go to 0 (higher bits are ignored)
 * For ports 1..13 the new value is built from the output register ORed with its partner register
 * (reg_gpio_port<N>_partner), so every bit set in the partner register is also written as 1.
 * Called by power_apply_cut_list and power_apply_standby_pins with the pin settings of their lists
 * (bits 0..3 = pin number, bit 4 = level).
 */
void gpio_set_port_bits(unsigned char port, unsigned char mask, unsigned char set)
{
    if ((set = set & 1) == 1) {
        switch (port) {
        case 1: reg_gpio_port1 = reg_gpio_port1 | reg_gpio_port1_partner | mask; break;
        case 2: reg_gpio_port2 = reg_gpio_port2 | reg_gpio_port2_partner | mask; break;
        case 3: reg_gpio_port3 = reg_gpio_port3 | reg_gpio_port3_partner | mask; break;
        case 4: reg_gpio_port4 = reg_gpio_port4 | reg_gpio_port4_partner | mask; break;
        case 5: reg_gpio_port5 = reg_gpio_port5 | reg_gpio_port5_partner | mask; break;
        case 6: reg_gpio_port6 = reg_gpio_port6 | reg_gpio_port6_partner | mask; break;
        case 7: reg_gpio_port7 = reg_gpio_port7 | reg_gpio_port7_partner | mask; break;
        case 8: reg_gpio_port8 = reg_gpio_port8 | reg_gpio_port8_partner | mask; break;
        case 9: reg_gpio_port9 = reg_gpio_port9 | reg_gpio_port9_partner | mask; break;
        case 10: reg_gpio_port10 = reg_gpio_port10 | reg_gpio_port10_partner | mask; break;
        case 11: reg_gpio_port11 = reg_gpio_port11 | reg_gpio_port11_partner | mask; break;
        case 12: reg_gpio_port12 = reg_gpio_port12 | reg_gpio_port12_partner | mask; break;
        case 13: reg_gpio_port13 = reg_gpio_port13 | reg_gpio_port13_partner | mask; break;
        case GPIO_PORT_P3: P3 |= mask; break;
        }
    } else {
        switch (port) {
        case 1: reg_gpio_port1 = (reg_gpio_port1 | reg_gpio_port1_partner) & ~mask; break;
        case 2: reg_gpio_port2 = (reg_gpio_port2 | reg_gpio_port2_partner) & ~mask; break;
        case 3: reg_gpio_port3 = (reg_gpio_port3 | reg_gpio_port3_partner) & ~mask; break;
        case 4: reg_gpio_port4 = (reg_gpio_port4 | reg_gpio_port4_partner) & ~mask; break;
        case 5: reg_gpio_port5 = (reg_gpio_port5 | reg_gpio_port5_partner) & ~mask; break;
        case 6: reg_gpio_port6 = (reg_gpio_port6 | reg_gpio_port6_partner) & ~mask; break;
        case 7: reg_gpio_port7 = (reg_gpio_port7 | reg_gpio_port7_partner) & ~mask; break;
        case 8: reg_gpio_port8 = (reg_gpio_port8 | reg_gpio_port8_partner) & ~mask; break;
        case 9: reg_gpio_port9 = (reg_gpio_port9 | reg_gpio_port9_partner) & ~mask; break;
        case 10: reg_gpio_port10 = (reg_gpio_port10 | reg_gpio_port10_partner) & ~mask; break;
        case 11: reg_gpio_port11 = (reg_gpio_port11 | reg_gpio_port11_partner) & ~mask; break;
        case 12: reg_gpio_port12 = (reg_gpio_port12 | reg_gpio_port12_partner) & ~mask; break;
        case 13: reg_gpio_port13 = (reg_gpio_port13 | reg_gpio_port13_partner) & ~mask; break;
        case GPIO_PORT_P3: P3 &= ~mask; break;
        }
    }
}
