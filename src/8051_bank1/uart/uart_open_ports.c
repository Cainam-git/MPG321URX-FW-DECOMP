/* uart_open_ports  (FUN_CODE_a775)
 *
 * Enable the serial ports chosen by a bit mask and set their format and baud rate.
 *   port_mask: port bits
 *   line_format
 *   baud_factor: baud rate / 1200
 * Name basis: derived - command 0x05 (main side sends the rate / 1200); per-port registers for bits 2/3/4,
 *   uart_set_line_format, uart_set_baud_rate(m, d * 1200)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_a775 @ 0xa775 (164 bytes), OPTIMIZE(8,SPEED) LARGE.
 * LARGE parameters port_mask (XDATA 0xA4B3) and baud_factor (0xA4B4); line_format stays in R5 and is passed on to
 *   uart_set_line_format; local baud (unsigned long) at 0xA4B5..0xA4B8.
 * Source form: baud = (unsigned long)baud_factor * 1200 (?C?LIMUL), then the tail call uart_set_baud_rate, whose
 *   LARGE parameter block is at 0xA4BA.
 */
extern unsigned char xdata reg_uart1_line_ctrl, reg_uart2_config, reg_uart2_line_ctrl, reg_uart2_status, reg_uart_irq_enable;
extern unsigned char xdata reg_uart3_config, reg_uart3_line_ctrl, reg_uart3_status;
extern unsigned char xdata reg_uart4_config, reg_uart4_line_ctrl, reg_uart4_status, DAT_EXTMEM_f030;
extern void uart_set_line_format(unsigned char port_mask, unsigned char line_format);
extern void uart_set_baud_rate(unsigned char port_mask, unsigned long baud) large;

#define UART_PORT2          0x04  /* port_mask bits, as uart_set_baud_rate */
#define UART_PORT3          0x08
#define UART_PORT4          0x10
#define UART_BAUD_UNIT      1200  /* the command gives the rate in units of 1200 bit/s */

/*
 * uart_open_ports - open the serial ports in port_mask (mailbox command 0x05, IPC_8051_CMD_OPEN_UART).
 *   port_mask    bit 0 = port 1, bits 2..4 = ports 2..4
 *   line_format  line format for uart_set_line_format (values 0..8 are taken)
 *   baud_factor  baud rate / 1200
 * Ports 2..4 are first switched on: config register 0xEA, line control bit 7 set, status 0xF0 written, and the
 * port's interrupt enable bit set (reg_uart_irq_enable bit 6 for port 2, bit 7 for port 3; bit 6 of 0xF030 for
 * port 4). Port 2 also sets bit 7 of 0xF054. Port 1 gets only its format and rate.
 * Only caller: the command switch ipc_run_command.
 */
void uart_open_ports(unsigned char port_mask, unsigned char line_format, unsigned char baud_factor)
{
    unsigned long baud;
    if (port_mask & UART_PORT2) {
        reg_uart1_line_ctrl |= 0x80;
        reg_uart2_config = 0xea;
        reg_uart2_line_ctrl |= 0x80;
        reg_uart2_status = 0xf0;
        reg_uart_irq_enable |= 0x40;
    }
    if (port_mask & UART_PORT3) {
        reg_uart3_config = 0xea;
        reg_uart3_line_ctrl |= 0x80;
        reg_uart3_status = 0xf0;
        reg_uart_irq_enable |= 0x80;
    }
    if (port_mask & UART_PORT4) {
        reg_uart4_config = 0xea;
        reg_uart4_line_ctrl |= 0x80;
        reg_uart4_status = 0xf0;
        DAT_EXTMEM_f030 |= 0x40;
    }
    uart_set_line_format(port_mask, line_format);
    baud = (unsigned long)baud_factor * UART_BAUD_UNIT;
    uart_set_baud_rate(port_mask, baud);
}
