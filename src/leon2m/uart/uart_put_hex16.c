/* uart_put_hex16  (FUN_a00df074)
 *
 * Send a 16-bit value as four hexadecimal digits to the debug serial port.
 * Name basis: proven - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df074 @ 0xa00df074-0xa00df0f4 (32 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Loops are do/while (cmp 3; ble). The wait counter is an unsigned int incremented before the test (cmp 0xffffe;
 * bleu).
 * Source form: the shift count is its own variable 'int sh = 12 - i * 4;' computed before the table read. The
 *   zero-extension of val (srl) then lives one instruction in the loop body; with -msoft-float the first loop
 *   pass leaves it in place and the second pass hoists it after the table address and the 0xffffe bound, which
 *   gives the firmware's entry order and registers. The neighbouring matched functions of this file
 *   (uart_put_hex32, uart_put_string, uart_put_string_crlf) give the same bytes with -msoft-float.
 */
extern char uart_hex_digits[];                  /* the characters of the sixteen hexadecimal digits, in ROM */
extern int reg_read32(unsigned int);
extern int reg_write32(unsigned int, signed char);

#define UART_DATA_REG        0xc00b0000
#define UART_STATUS_REG      0xc00b0014
#define UART_STATUS_TX_READY 0x20               /* status bit 5: the data register can take a character */
#define UART_TX_POLL_LIMIT   0xffffe            /* most status polls to wait for UART_STATUS_TX_READY */

/*
 * Write a 16-bit value as four hexadecimal digits, most significant digit first. Same code as uart_put_hex32
 * for four digits: before each digit it waits until the data register can take a character, for at most
 * UART_TX_POLL_LIMIT + 1 polls; the digit is written even then.
 *
 *   val  the value
 *
 * Nothing calls it.
 */
void uart_put_hex16(unsigned short val)
{
  int i = 0;

  do {
    int sh = 12 - i * 4;
    signed char c = uart_hex_digits[(val >> sh) & 0xf];
    unsigned int n = 0;
    do {
      n++;
      if (reg_read32(UART_STATUS_REG) & UART_STATUS_TX_READY)
        break;
    } while (n < UART_TX_POLL_LIMIT + 1);
    reg_write32(UART_DATA_REG, c);
    i++;
  } while (i <= 3);                             /* four digits */
}
