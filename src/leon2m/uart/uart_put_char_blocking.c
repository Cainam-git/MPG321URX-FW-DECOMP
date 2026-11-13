/* uart_put_char_blocking  (FUN_a00df4d4)
 *
 * Send one character to the debug serial port, waiting without a limit.
 * Name basis: proven - used by the memory training script
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df4d4 @ 0xa00df4d4 (-mcpu=v8 -O2 -g)
 * Source form: the signed char parameter produces the sll / sra sign extension.
 */
extern int reg_read32(unsigned int);
extern int reg_write32(unsigned int, signed char);

#define UART_DATA_REG        0xc00b0000
#define UART_STATUS_REG      0xc00b0014
#define UART_STATUS_TX_READY 0x20               /* status bit 5: the data register can take a character */

/*
 * Write one character to the data register once the status register shows it can take one. The wait has no
 * limit.
 *
 *   param_1  the character
 *
 * Called by sys_ddr_run_script (the memory training script).
 */
void uart_put_char_blocking(signed char param_1)
{
    while ((reg_read32(UART_STATUS_REG) & UART_STATUS_TX_READY) == 0)
        ;
    reg_write32(UART_DATA_REG, param_1);
}
