/* uart_put_hex8  (FUN_a00df0f4)
 *
 * Send an 8-bit value as two hexadecimal digits to the debug serial port.
 * Name basis: proven - same output register
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df0f4 @ 0xa00df0f4-0xa00df170 (31 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the wait-and-write is a static helper (wait loop 'for (t = 0; !(status & 0x20); ) if (++t >
 *   0xffffe) break;'), inlined. Its loop shape gives the block frequencies with which global allocation puts
 *   the shift count in %l2 and 0xc00b0000 in %l3 as in the firmware. The same bytes come out without
 *   -msoft-float.
 */
extern char uart_hex_digits[];                  /* the characters of the sixteen hexadecimal digits, in ROM */
extern int reg_read32(unsigned int);
extern int reg_write32(unsigned int, signed char);

#define UART_DATA_REG        0xc00b0000
#define UART_STATUS_REG      0xc00b0014
#define UART_STATUS_TX_READY 0x20               /* status bit 5: the data register can take a character */
#define UART_TX_POLL_LIMIT   0xffffe            /* most status polls to wait for UART_STATUS_TX_READY */

/* Write one character once the data register can take it (at most UART_TX_POLL_LIMIT + 1 polls; written even
   then). */
static void uart_putc(signed char c)
{
  unsigned int t;
  for (t = 0; !(reg_read32(UART_STATUS_REG) & UART_STATUS_TX_READY); )
    if (++t > UART_TX_POLL_LIMIT) break;
  reg_write32(UART_DATA_REG, c);
}

/*
 * Write an 8-bit value as two hexadecimal digits, the high digit first.
 *
 *   val  the value
 *
 * Called by dbg_dump_memory_bytes.
 */
void uart_put_hex8(unsigned char val)
{
  int i;
  for (i = 0; i < 2; i++)
    uart_putc(uart_hex_digits[(val >> (4 - i * 4)) & 0xf]);
}
