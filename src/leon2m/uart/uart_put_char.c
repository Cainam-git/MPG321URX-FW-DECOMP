/* uart_put_char  (FUN_a00deef0)
 *
 * Send one character to the debug serial port.
 * Name basis: proven - waits for the ready bit of 0xC00B0014, then writes 0xC00B0000
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00deef0 @ 0xa00deef0 (-mcpu=v8 -O2 -g)
 * Source form: a while loop with the compare at the top (i <= bound, the bound held in a local), the bit test
 * inside, and the increment after the test. The parameter is a signed char (sll / sra sign extension).
 */
extern int reg_read32(unsigned int);
extern int reg_write32(unsigned int, signed char);

#define UART_DATA_REG        0xc00b0000
#define UART_STATUS_REG      0xc00b0014
#define UART_STATUS_TX_READY 0x20               /* status bit 5: the data register can take a character */
#define UART_TX_POLL_LIMIT   0xffffe            /* most status polls to wait for UART_STATUS_TX_READY */

/*
 * Write one character to the data register once the status register shows it can take one. The wait ends after
 * UART_TX_POLL_LIMIT + 1 polls; the character is written even then.
 *
 *   param_1  the character
 *
 * Called by dbg_command_shell and dbg_dump_memory_bytes.
 */
void uart_put_char(signed char param_1)
{
    unsigned int i = 0;
    unsigned int bound = UART_TX_POLL_LIMIT;

    while (i <= bound) {
        if (reg_read32(UART_STATUS_REG) & UART_STATUS_TX_READY)
            break;
        i++;
    }

    reg_write32(UART_DATA_REG, param_1);
}
