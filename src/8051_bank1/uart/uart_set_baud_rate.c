/* uart_set_baud_rate  (FUN_CODE_9975)
 *
 * Set the baud rate of the serial ports chosen by a bit mask.
 *   port_mask: port bits
 *   baud: baud rate
 * Name basis: proven - Timer 1 reload for port 1, divisor 12000000 / baud - 1 into 0xF0F7/F8, 0xF033/34,
 *   0xF06F/70 for bits 2/3/4; default 4800
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_9975 @ 0x9975..0x9a43 (206 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Source form: one local divisor (R4:R5). It starts as 0x9C3 (= 12000000 / 4800 - 1); the firmware keeps that
 *   store ('MOV R5,#C3H; MOV R4,#09H') before the bit 0 test. With bit 0, divisor first holds the timer 1 reload
 *   count and TH1 = TL1 = -divisor; then divisor = 12000000.0 / baud - 1 (copied high byte first,
 *   'MOV R4,AR6; MOV R5,AR7'). The float arithmetic runs through ?C?FCASTL, ?C?FPMUL, ?C?FPDIV, ?C?FPADD and
 *   ?C?CASTF.
 */
sfr TL1 = 0x8B;
sfr TH1 = 0x8D;
extern unsigned char xdata reg_uart2_divisor_high, reg_uart2_divisor_low, reg_uart3_divisor_high, reg_uart3_divisor_low, reg_uart4_divisor_high, reg_uart4_divisor_low;
extern unsigned long sys_get_cpu_clock_hz(void);

#define UART_PORT1          0x01  /* port_mask bits; port 1 runs on timer 1 */
#define UART_PORT2          0x04
#define UART_PORT3          0x08
#define UART_PORT4          0x10
#define UART_DIVISOR_CLOCK  12000000.0  /* ports 2..4: divisor = this / baud - 1 */

/*
 * uart_set_baud_rate - set the speed of the serial ports in port_mask.
 *   port_mask  bit 0 = port 1, bits 2..4 = ports 2..4
 *   baud       bits per second
 * Port 1: timer 1 reload TH1 = TL1 = -(clock * 2 / 384 / baud), rounded, with the clock from
 * sys_get_cpu_clock_hz. Ports 2..4: the 16-bit divisor 12000000 / baud - 1, high byte first.
 * Callers: uart_open_ports (baud = 1200 * the requested factor), timer_set_clock_rates and
 * timer_set_crystal_rates (port 1, 4800) and timer_apply_clock_rates (ports 1..4, 4800).
 */
void uart_set_baud_rate(unsigned char port_mask, unsigned long baud)
{
    unsigned int divisor = 0x9c3;
    if (port_mask & UART_PORT1) {
        divisor = (unsigned char)((float)sys_get_cpu_clock_hz() * 2 / 384 / baud + 0.5);
        TH1 = TL1 = -divisor;
    }
    divisor = UART_DIVISOR_CLOCK / baud - 1;
    if (port_mask & UART_PORT2) { reg_uart2_divisor_high = divisor >> 8; reg_uart2_divisor_low = divisor; }
    if (port_mask & UART_PORT3) { reg_uart3_divisor_high = divisor >> 8; reg_uart3_divisor_low = divisor; }
    if (port_mask & UART_PORT4) { reg_uart4_divisor_high = divisor >> 8; reg_uart4_divisor_low = divisor; }
}
