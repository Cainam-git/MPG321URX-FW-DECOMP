/* dbg_format_hex32  (FUN_a00b281c)
 *
 * Write a value as eight upper-case hexadecimal digits into a buffer.
 * Returns: 1 for a missing buffer, else 0
 * Name basis: proven - with a terminating zero
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b281c @ 0xa00b281c (-mcpu=v8 -Os -g)
 * Source form: the digit is chosen by two tests (nibble <= 9, then nibble - 10 <= 5 as unsigned char); the
 * final else branch ('0') cannot be reached. The buffer's first byte is cleared before the loop.
 */

#define HEX_DIGITS 8                    /* digits written: one per four bits of the value */
#define LETTER_OFFSET '7'               /* nibble 10..15 + '7' = 'A'..'F' */

/*
 * Write value as eight upper-case hexadecimal digits (most significant first) and a terminating 0 into buffer
 * (nine bytes). Returns 1 and writes nothing when buffer is NULL, else 0. The command line handler uses it
 * to build the reply lines of the tool protocol.
 */
int dbg_format_hex32(unsigned char *buffer, unsigned int value)
{
  int i;
  int shift;
  unsigned int nibble;
  char c;
  if (buffer == ((unsigned char *) 0))
  {
    return 1;
  }
  *buffer = 0;
  i = 0;
  shift = 0x1c;
  do
  {
    nibble = (value >> shift) & 0xf;
    if (nibble <= 9)
    {
      c = ((char) nibble) + '0';
    }
    else
      if (((unsigned char) (nibble - 10)) <= 5)
    {
      c = ((char) nibble) + LETTER_OFFSET;
    }
    else
    {
      c = '0';
    }
    buffer[i] = c;
    i++;
    shift -= 4;
  }
  while (i < HEX_DIGITS);
  buffer[HEX_DIGITS] = 0;
  return 0;
}
