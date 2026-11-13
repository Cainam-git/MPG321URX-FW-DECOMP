/* uart_set_baud_rate  (FUN_CODE_d393)
 *
 * Set the Timer 1 baud rate from a table index and a rate.
 *   factor_index: table index 0..8
 *   rate_div100: rate / 100
 * Name basis: derived - TH1 = -(k * 2000000 / 384 / (b * 100)) with k = CODE 0xE543[a]; 0x09D0 = k * 12.5;
 *   mailbox command 0x11
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. Parameters factor_index (XDATA 0x08EE) and rate_div100 (unsigned int, 0x08EF).
 * Source forms the bytes depend on: 'rate_div100 * 100' is an unsigned int product (?C?IMUL); the reload is a long
 * expression (?C?LMUL, ?C?ULDIV); the delay count is a float expression (?C?FCASTC, ?C?FPMUL, ?C?FPDIV, ?C?CASTF).
 */
#include <reg51.h>
extern unsigned char code uart_clock_factors[];
extern unsigned int xdata timer_delay_loop_count;

#define LAST_FACTOR_INDEX   8
#define FALLBACK_INDEX      7   /* used for an index above LAST_FACTOR_INDEX */

/* uart_set_baud_rate: set the serial port's rate.
 *
 * factor_index: entry of uart_clock_factors (CODE 0xE543: 0x0C, 0x18, 0x20, 0x30, 0x40, 0x60, 0x60, 0xC0).
 * rate_div100:  the rate divided by 100.
 *
 * With k = uart_clock_factors[factor_index]: TH1 = -(k * 2000000 / 384 / (rate_div100 * 100)), and
 * timer_delay_loop_count = k * 12.5 (written 8.0e8 / 6.4e7), the loop count of timer_delay_base.
 * Only caller: fwupd_run_mailbox_command, command MBOX_CMD_SET_BAUD_RATE (0x11), with mailbox bytes 0xF19E and
 * 0xF19F. */
void uart_set_baud_rate(unsigned char factor_index, unsigned int rate_div100)
{
    if (factor_index > LAST_FACTOR_INDEX) factor_index = FALLBACK_INDEX;
    TH1 = -(unsigned char)((unsigned long)uart_clock_factors[factor_index] * 2000000 / 384 / (rate_div100 * 100));
    timer_delay_loop_count = (float)uart_clock_factors[factor_index] * 8.0e8 / 6.4e7;
}
