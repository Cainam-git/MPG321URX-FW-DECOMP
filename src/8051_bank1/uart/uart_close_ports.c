/* uart_close_ports  (FUN_CODE_c9b0)
 *
 * Disable the serial ports chosen by a bit mask.
 *   port_mask: port bits
 * Name basis: derived - clears the register bits uart_open_ports sets; command 0x06
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c9b0 @ 0xc9b0  OPTIMIZE(8,SPEED) LARGE
 */
extern xdata unsigned char reg_uart2_line_ctrl;
extern xdata unsigned char reg_uart2_status;
extern xdata unsigned char reg_uart_irq_enable;
extern xdata unsigned char reg_uart3_line_ctrl;
extern xdata unsigned char reg_uart3_status;
extern xdata unsigned char reg_uart4_line_ctrl;
extern xdata unsigned char reg_uart4_status;
extern xdata unsigned char DAT_EXTMEM_f030;

/*
 * Close the serial ports selected in port_mask: bit 2 = port 2, bit 3 =
 * port 3, bit 4 = port 4 (bits 0 and 1 do nothing). For each selected port
 * bit 7 of its line control register is cleared, its status register is set
 * to 0xF0 and one more bit is cleared (0xF02C bit 6 for port 2, 0xF02C bit 7
 * for port 3, 0xF030 bit 6 for port 4).
 * Undoes uart_open_ports. Command 0x06 of the command switch.
 */
void uart_close_ports(unsigned char port_mask)
{
    if (port_mask & 0x04) {
        reg_uart2_line_ctrl &= 0x7f;
        reg_uart2_status = 0xf0;
        reg_uart_irq_enable &= 0xbf;
    }
    if (port_mask & 0x08) {
        reg_uart3_line_ctrl &= 0x7f;
        reg_uart3_status = 0xf0;
        reg_uart_irq_enable &= 0x7f;
    }
    if (port_mask & 0x10) {
        reg_uart4_line_ctrl &= 0x7f;
        reg_uart4_status = 0xf0;
        DAT_EXTMEM_f030 &= 0xbf;
    }
}
