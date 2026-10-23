/* leon2s FUN_a0072fd8 @ 0xa0072fd8 (-mcpu=v8 -Os -g)
 * Writes n characters of s with FUN_a006122c, each '\n' followed by '\r' (0xd). Nothing for a NULL s or for n == 1 with
 * an empty string (param_1 = s, param_2 = n; the characters are passed as their low byte). FUN_a006122c writes one
 * character (it waits on bit 5 of register 0xc00c0014).
 */

extern int FUN_a006122c();
void FUN_a0072fd8(char *param_1, int param_2)
{
  int i;
  if (param_1 == 0)
  {
    return;
  }
  if ((param_2 == 1) && (param_1[0] == 0))
  {
    return;
  }
  i = 0;
  while (i < param_2)
  {
    FUN_a006122c(param_1[i] & 0xFF);
    if (param_1[i] == '\n')
    {
      FUN_a006122c(0xd);
    }
    i++;
  }
}
