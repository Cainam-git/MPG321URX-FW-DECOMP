/* uart_putchar  (FUN_CODE_d511)
 *
 * Send one character on serial port 1, waiting while the transmit ring is full.
 *   ch: character
 * Returns: the character
 * Name basis: derived - character output used by the printf code (stub at 0x2817) and by message type 3 port 1
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d511 @ 0xd511  Options: OPTIMIZE(8,SPEED) REGFILE(R.ORC).
 * Source form: the character, the retry counter and the delay counter stay in R5 / R4 / R6:R7 only with
 * REGFILE(R.ORC) (without it they go to DATA: 20 %). 'j != 1000' also matches.
 * Callers: 0x1f41 (ipc_run_message) and an LJMP at 0x2817 (the character-output stub of the printf code).
 */
#include <reg51.h>
#define PUTCHAR_DELAY_COUNT 1000  /* empty-loop steps between two tries */
#define PUTCHAR_KICK_AFTER  0xf0  /* tries after which TI is set on every retry */

extern unsigned char xdata DAT_EXTMEM_f00a;
unsigned char uart_tx_ring_put(unsigned char c);

/*
 * Send one character on serial port 1. uart_tx_ring_put returns non-zero while the 16-entry transmit ring is
 * full; the character is retried with a delay between tries. After more than 0xF0 tries every retry also sets
 * TI, which starts the transmit interrupt that empties the ring. Afterwards 0x55 is written to XDATA 0xF00A (the
 * same write as in timer_delay_ticks; its purpose is not shown). Returns the character.
 */
unsigned char uart_putchar(unsigned char ch)
{
    unsigned char tries;
    unsigned int delay;

    tries = 0;
    while (uart_tx_ring_put(ch)) {
        for (delay = 0; delay < PUTCHAR_DELAY_COUNT; delay++) ;
        tries++;
        if (tries > PUTCHAR_KICK_AFTER) TI = 1;
    }
    DAT_EXTMEM_f00a = 0x55;
    return ch;
}
