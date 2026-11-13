/* uart_setup_line_control  (FUN_CODE_dcf6)
 *
 * Set the serial line control registers and select the default port mode.
 * Name basis: descriptive - reg 0xF053 = 0x83, 0xF055 = 6, then uart_set_line_format(1, 0) (per-port mode
 *   nibbles); part of the UART set-up
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dcf6 @ 0xdcf6  OPTIMIZE(8,SPEED)
 */
extern xdata unsigned char DAT_EXTMEM_f053;
extern xdata unsigned char DAT_EXTMEM_f055;
void uart_set_line_format(unsigned char, unsigned char);

/* Write 0x83 to the register at 0xF053 and 6 to the one at 0xF055, then
 * call uart_set_line_format(1, 0). */
void uart_setup_line_control(void)
{
    DAT_EXTMEM_f053 = 0x83;
    DAT_EXTMEM_f055 = 0x06;
    uart_set_line_format(1, 0);
}
