/* uart_set_line_format  (FUN_CODE_c389)
 *
 * Store a line-format code for the serial ports chosen by a bit mask.
 *   ports: port bits
 *   format: format code 0..8
 * Name basis: descriptive - v < 9 into shadow bytes 0xA763.. and the low nibble of 0xF054 / 0xF0F6 / 0xF032 /
 *   0xF06E; callers uart_open_ports, uart_setup_line_control
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c389, OPTIMIZE(8,SPEED) LARGE.
 * Source form: the last block uses '(char)format', which places the converted value in a temporary register (the firmware
 * has a copy in R7 there); the first three blocks use the parameter directly.
 */
extern unsigned char xdata uart_line_format_port1, uart_line_format_port2, uart_line_format_port3, uart_line_format_port4;
extern unsigned char xdata reg_uart1_line_ctrl, reg_uart2_line_ctrl, reg_uart3_line_ctrl, reg_uart4_line_ctrl;

/*
 * uart_set_line_format - for format codes 0..8 only: for each serial port chosen in ports (bit 0, 2, 3, 4), store the
 * code in the port's shadow byte (XDATA 0xA763..0xA766) and put its low nibble into the low nibble of the port's
 * line control register (0xF054, 0xF0F6, 0xF032, 0xF06E). Other codes do nothing.
 *   ports: port bits
 *   format: line format code
 * Callers: uart_open_ports and uart_setup_line_control.
 */
void uart_set_line_format(unsigned char ports, unsigned char format)
{
    if (format < 9) {
        if (ports & 0x01) { uart_line_format_port1 = format; reg_uart1_line_ctrl = (reg_uart1_line_ctrl & 0xf0) | (format & 0x0f); }
        if (ports & 0x04) { uart_line_format_port2 = format; reg_uart2_line_ctrl = (reg_uart2_line_ctrl & 0xf0) | (format & 0x0f); }
        if (ports & 0x08) { uart_line_format_port3 = format; reg_uart3_line_ctrl = (reg_uart3_line_ctrl & 0xf0) | (format & 0x0f); }
        if (ports & 0x10) { uart_line_format_port4 = (char)format; reg_uart4_line_ctrl = (reg_uart4_line_ctrl & 0xf0) | ((char)format & 0x0f); }
    }
}
