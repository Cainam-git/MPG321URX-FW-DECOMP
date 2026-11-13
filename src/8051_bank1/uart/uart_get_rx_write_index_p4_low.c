/* uart_get_rx_write_index_p4_low  (FUN_CODE_defa)
 *
 * Return the low byte of the serial port 4 receive ring write position (IDATA 0x4B).
 * Returns: the byte
 * Note: Not called anywhere.
 * Name basis: descriptive - IDATA 0x4B = low byte of uart_rx_write_index_port4 (0x4A); no caller in the image
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_defa @ 0xdefa (code in a gap of the function table).
 * MOV R0,#4BH; MOV A,@R0; MOV R7,A: the idata byte is read through R0.
 */
extern unsigned char idata uart_rx_write_index_port4_low;

/*
 * Return the byte at IDATA 0x4B, the low byte of the 16-bit write position of the serial port 4 receive ring
 * (uart_rx_write_index_port4 at 0x4A). No call, jump or stored address in this program leads here.
 */
unsigned char uart_get_rx_write_index_p4_low(void)
{
    return uart_rx_write_index_port4_low;
}
