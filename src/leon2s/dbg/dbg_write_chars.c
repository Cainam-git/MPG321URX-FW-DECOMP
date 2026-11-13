/* dbg_write_chars  (FUN_a0072fd8)
 *
 * Write n characters to the debug console, adding a carriage return after each line feed.
 *   text
 *   count
 * Name basis: proven - uart_put_char per character; only caller dbg_printf
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0072fd8 @ 0xa0072fd8 (-mcpu=v8 -Os -g)
 * uart_put_char is declared without a prototype; each character is passed as its low byte.
 */
extern int uart_put_char();

/*
 * Write n characters to the debug console; each line feed is followed by a carriage return.
 *   text:  the characters
 *   count: how many characters to write
 * Nothing is written for a NULL text, or when count is 1 and the first character is 0. Only caller: dbg_printf.
 */
void dbg_write_chars(char *text, int count)
{
  int i;
  if (text == 0)
  {
    return;
  }
  if ((count == 1) && (text[0] == 0))
  {
    return;
  }
  i = 0;
  while (i < count)
  {
    uart_put_char(text[i] & 0xFF);
    if (text[i] == '\n')
    {
      uart_put_char(0xd);
    }
    i++;
  }
}
