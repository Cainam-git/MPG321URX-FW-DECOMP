/* uart_put_char  (FUN_a006122c)
 *
 * Send one character on the debug console UART.
 *   c: character to send
 * Note: Waits at most about one million status polls, then writes the character anyway
 * Name basis: proven - waits for bit 5 (transmit ready) of status 0xC00C0014, writes data 0xC00C0000; used by
 *   the printf output
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g.
 * Source form: a plain while loop with the counter test inside (gives the firmware's annulled bgu,a);
 * the register address is a constant (firmware 'st %o5,[%g1]' reg+reg form; an extern symbol gives
 * the simm13 form).
 */
/* Debug console UART registers (leon2s). */
#define UART_DATA_REG   (*(volatile unsigned int *)0xc00c0000) /* write: character to send; read: received byte */
#define UART_STATUS_REG (*(volatile unsigned int *)0xc00c0014)
#define UART_STATUS_RX_READY 0x01 /* a received byte is waiting */
#define UART_STATUS_TX_READY 0x20 /* the transmitter can take a character */
/* Give up waiting for TX_READY after this many polls. */
#define UART_TX_POLL_LIMIT 0xffffe

/*
 * Wait until the transmitter is ready (at most UART_TX_POLL_LIMIT polls), then write the character.
 * When the wait runs out the character is written anyway.
 */
void uart_put_char(unsigned char c)
{
    unsigned int polls = 0;

    while ((UART_STATUS_REG & UART_STATUS_TX_READY) == 0) {
        if (++polls > UART_TX_POLL_LIMIT)
            break;
    }
    UART_DATA_REG = c;
}
