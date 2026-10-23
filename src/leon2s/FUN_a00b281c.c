/* leon2s FUN_a00b281c @ 0xa00b281c (-mcpu=v8 -Os -g)
 * Writes v as eight upper-case hex digits (nibbles 7..0; '0'-'9', 'A'-'F' as nibble + '7') and a terminating 0 to buf;
 * returns 1 when buf is NULL (nothing written), else 0.
 */

int FUN_a00b281c(unsigned char *param_1, unsigned int param_2)
{
  int i;
  int shift;
  unsigned int nibble;
  char c;
  if (param_1 == ((unsigned char *) 0))
  {
    return 1;
  }
  *param_1 = 0;
  i = 0;
  shift = 0x1c;
  do
  {
    nibble = (param_2 >> shift) & 0xf;
    if (nibble <= 9)
    {
      c = ((char) nibble) + '0';
    }
    else
      if (((unsigned char) (nibble - 10)) <= 5)
    {
      c = ((char) nibble) + '7';
    }
    else
    {
      c = '0';
    }
    param_1[i] = c;
    i++;
    shift -= 4;
  }
  while (i < 8);
  param_1[8] = 0;
  return 0;
}
