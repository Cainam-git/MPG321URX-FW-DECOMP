/* uart_put_hex32  (FUN_a00deffc)
 *
 * Send a 32-bit value as eight hexadecimal digits to the debug serial port.
 * Name basis: proven - digit table at 0x198FA0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00deffc @ 0xa00deffc-0xa00df074 (30 words), flags -mcpu=v8 -O3 -g.
 * Loops are do/while (cmp 7; ble). The wait counter is an unsigned int incremented before the test (cmp 0xffffe;
 * bleu). The shift is written 28 - i * 4: loop strength reduction then makes the shift count a variable that
 * starts at 0x1c and drops by 4 per pass, and its initial value lands after the hoisted 0xc00b0000 sethi like the
 * firmware. A separate shift variable puts 'mov 0x1c' first; a constant table pointer gives [idx + base]; the
 * table is the symbol uart_hex_digits.
 */
extern char uart_hex_digits[];                  /* the characters of the sixteen hexadecimal digits, in ROM */
extern int reg_read32(unsigned int);
extern int reg_write32(unsigned int, signed char);

#define UART_DATA_REG        0xc00b0000
#define UART_STATUS_REG      0xc00b0014
#define UART_STATUS_TX_READY 0x20               /* status bit 5: the data register can take a character */
#define UART_TX_POLL_LIMIT   0xffffe            /* most status polls to wait for UART_STATUS_TX_READY */

/*
 * Write a 32-bit value as eight hexadecimal digits, most significant digit first. Before each digit it waits
 * until the data register can take a character, for at most UART_TX_POLL_LIMIT + 1 polls; the digit is written
 * even then.
 *
 *   val  the value
 *
 * Called by dbg_write_memory_word, dbg_dump_memory_words and dbg_dump_memory_bytes.
 */
void uart_put_hex32(unsigned int val)
{
  int i = 0;

  do {
    signed char c = uart_hex_digits[(val >> (28 - i * 4)) & 0xf];
    unsigned int n = 0;
    do {
      n++;
      if (reg_read32(UART_STATUS_REG) & UART_STATUS_TX_READY)
        break;
    } while (n < UART_TX_POLL_LIMIT + 1);
    reg_write32(UART_DATA_REG, c);
    i++;
  } while (i <= 7);                             /* eight digits */
}
