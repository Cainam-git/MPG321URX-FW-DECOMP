/* uart_init  (FUN_CODE_def4)
 *
 * Set up the serial ports, the timers and their interrupts.
 * Name basis: derived - uart_setup_line_control then uart_init_8051_serial; called in the application start-up
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_def4 @ 0xdef4  OPTIMIZE(8,SPEED)
 * The second call is a tail jump (LCALL uart_setup_line_control, then LJMP uart_init_8051_serial).
 */
extern void uart_setup_line_control(void);
extern void uart_init_8051_serial(void);

/*
 * Set up the serial lines: first the line control registers and the default port mode
 * (uart_setup_line_control), then the 8051's own serial port, both timers and their interrupts
 * (uart_init_8051_serial). Only caller: sys_main, in its first start-up step with interrupts off.
 */
void uart_init(void)
{
    uart_setup_line_control();
    uart_init_8051_serial();
}
