/* uart_init  (FUN_a0072b7c)
 *
 * Reset and configure the debug console UART and enable its receive interrupt.
 * Note: Also empties the receive ring buffer.
 * Name basis: derived - 0xC00C0000 registers, divisor 0x34 at 96 MHz else 0x0D; clears bit 4 of 0x9F120028 and
 *   bit 6 of 0x9F120044, writes 0x40 to 0x9F12007C and 0x10 to 0x9F120034 (interrupt block registers of level
 *   4, source bit 6); caller system init
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g.
 * Source form: the two index clears are written before the first register update, read index (+0x81) first.
 * Only the hardware registers are volatile.
 */
#define RX_HEAD_INDEX 0x80 /* write index behind the 128 data bytes of the receive ring */
#define RX_TAIL_INDEX 0x81 /* read index */
#define SYS_CLOCK_96MHZ 96000000
#define UART_DIVISOR_96MHZ 0x34 /* divisor written when sys_clock_hz is 96 MHz */
#define UART_DIVISOR_OTHER 0x0d /* divisor written for any other clock value */
extern unsigned char uart_rx_buffer[];
extern unsigned int sys_clock_hz;
extern void timer_delay_long_units(unsigned int);

#define R(a) (*(volatile unsigned int *)(a))

/*
 * Set up the debug console UART: empty the receive ring, pulse bit 6 of register 0xc0000000 around a
 * short wait, program the divisor for the system clock, then write the register sequence of the UART
 * block at 0xc00c0000, then change bits in registers 0x9f100090 and 0x9f120028..0x9f12007c.
 * The meaning of these register writes is not shown by the code.
 */
void uart_init(void)
{
    uart_rx_buffer[RX_TAIL_INDEX] = 0;
    uart_rx_buffer[RX_HEAD_INDEX] = 0;
    R(0xc0000000) |= 0x40;
    timer_delay_long_units(1);
    R(0xc0000000) &= ~0x40;
    R(0xc00c000c) = 0x80;
    R(0xc00c0000) = sys_clock_hz == SYS_CLOCK_96MHZ ? UART_DIVISOR_96MHZ : UART_DIVISOR_OTHER;
    R(0xc00c0004) = 0;
    R(0xc00c000c) = 0;
    R(0xc00c000c) = 3;
    R(0xc00c0008) = 6;
    R(0xc00c0008) = 0;
    R(0xc00c0004) = 1;
    R(0x9f100090) |= 0x10;
    R(0x9f120028) &= ~0x10;
    R(0x9f120044) &= ~0x40;
    R(0x9f12007c) = 0x40;
    R(0x9f120034) = 0x10;
}
