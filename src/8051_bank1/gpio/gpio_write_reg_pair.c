/* gpio_write_reg_pair  (FUN_CODE_9a43)
 *
 * Write two values to the register pair of one numbered port.
 *   port: port 1..13
 *   first_value
 *   second_value
 * Note: No caller in the bank-1 image.
 * Name basis: descriptive - 13 pairs 0xF0B0/0xF0C7 .. 0xF135/0xF13D by sel 1..13 (same numbering as the GPIO
 *   ports)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_9a43 @ 0x9A43..0x9B11 (206 bytes), OPTIMIZE(7,SPEED) (the same bytes at OPTIMIZE(8,SPEED) LARGE).
 * Source form: a switch with 13 cases (jump table of 13 LJMPs at 0x9A5B); each case ends in its own RET. The
 *   registers are volatile.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f0b0, DAT_EXTMEM_f0b1, DAT_EXTMEM_f0b2, DAT_EXTMEM_f0b3;
extern unsigned char volatile xdata DAT_EXTMEM_f0b4, DAT_EXTMEM_f0b5, DAT_EXTMEM_f0b6;
extern unsigned char volatile xdata DAT_EXTMEM_f0c7, DAT_EXTMEM_f0c8, DAT_EXTMEM_f0c9, DAT_EXTMEM_f0ca;
extern unsigned char volatile xdata DAT_EXTMEM_f0cb, DAT_EXTMEM_f0ce, DAT_EXTMEM_f0cf;
extern unsigned char volatile xdata DAT_EXTMEM_f130, DAT_EXTMEM_f131, DAT_EXTMEM_f132, DAT_EXTMEM_f133;
extern unsigned char volatile xdata DAT_EXTMEM_f134, DAT_EXTMEM_f135;
extern unsigned char volatile xdata DAT_EXTMEM_f138, DAT_EXTMEM_f139, DAT_EXTMEM_f13a, DAT_EXTMEM_f13b;
extern unsigned char volatile xdata DAT_EXTMEM_f13c, DAT_EXTMEM_f13d;

/*
 * gpio_write_reg_pair - write two values to the register pair of one numbered port.
 *   port          1..13; any other number writes nothing
 *   first_value   written to the first register (0xF0B0..0xF0B6 for ports 1..7, 0xF130..0xF135 for 8..13)
 *   second_value  written to the second register (0xF0C7..0xF0CB, 0xF0CE, 0xF0CF for ports 1..7,
 *                 0xF138..0xF13D for 8..13)
 * What the registers control is not shown in this program.
 * Nothing in the bank 1 program calls this routine.
 */
void gpio_write_reg_pair(unsigned char port, unsigned char first_value, unsigned char second_value)
{
    switch (port) {
    case 1: DAT_EXTMEM_f0b0 = first_value; DAT_EXTMEM_f0c7 = second_value; break;
    case 2: DAT_EXTMEM_f0b1 = first_value; DAT_EXTMEM_f0c8 = second_value; break;
    case 3: DAT_EXTMEM_f0b2 = first_value; DAT_EXTMEM_f0c9 = second_value; break;
    case 4: DAT_EXTMEM_f0b3 = first_value; DAT_EXTMEM_f0ca = second_value; break;
    case 5: DAT_EXTMEM_f0b4 = first_value; DAT_EXTMEM_f0cb = second_value; break;
    case 6: DAT_EXTMEM_f0b5 = first_value; DAT_EXTMEM_f0ce = second_value; break;
    case 7: DAT_EXTMEM_f0b6 = first_value; DAT_EXTMEM_f0cf = second_value; break;
    case 8: DAT_EXTMEM_f130 = first_value; DAT_EXTMEM_f138 = second_value; break;
    case 9: DAT_EXTMEM_f131 = first_value; DAT_EXTMEM_f139 = second_value; break;
    case 10: DAT_EXTMEM_f132 = first_value; DAT_EXTMEM_f13a = second_value; break;
    case 11: DAT_EXTMEM_f133 = first_value; DAT_EXTMEM_f13b = second_value; break;
    case 12: DAT_EXTMEM_f134 = first_value; DAT_EXTMEM_f13c = second_value; break;
    case 13: DAT_EXTMEM_f135 = first_value; DAT_EXTMEM_f13d = second_value; break;
    }
}
