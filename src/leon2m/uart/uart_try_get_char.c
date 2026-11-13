/* uart_try_get_char  (FUN_a00dee6c)
 *
 * Fetch a character from the debug serial port if one has arrived.
 * Returns: 1 when a character was fetched
 * Name basis: proven - status bit 0 of 0xC00B0014, data 0xC00B0000; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dee6c @ 0xa00dee6c-0xa00deea4 (14 words), flags -mcpu=v8 -O2 -g.
 * The data register is read at 0xc00b0000 (the firmware moves the address from %l0, which holds the sethi only).
 */
extern unsigned int reg_read32(unsigned int);

#define UART_DATA_REG        0xc00b0000
#define UART_STATUS_REG      0xc00b0014
#define UART_STATUS_RX_READY 0x01               /* status bit 0: a character has arrived */

/*
 * Take the received character from the data register when the status register says one has arrived.
 *
 *   out  receives the character
 *
 * Returns 1 when a character was stored through out, 0 when none had arrived (out is left alone). Nothing calls
 * it.
 */
int uart_try_get_char(unsigned char *out)
{
    if (reg_read32(UART_STATUS_REG) & UART_STATUS_RX_READY) {
        *out = reg_read32(UART_DATA_REG);
        return 1;
    }
    return 0;
}
