/* leon2s FUN_a00b281c @ 0xa00b281c  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: decomp-permuter (AST mutations), judged by exact bytes
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
