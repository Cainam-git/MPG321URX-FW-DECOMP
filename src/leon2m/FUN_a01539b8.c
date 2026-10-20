/* leon2m FUN_a01539b8 @ 0xa01539b8 (-mcpu=v8 -O3 -g)
 */

extern int FUN_a013c910();
extern int FUN_a0140e74();
void FUN_a01539b8()
{
  unsigned short i;
  unsigned short rem;
  unsigned char stack_buf[16];
  FUN_a013c910(stack_buf, 0x1a75e6, 0x10);
  i = 0;
  for (;;)
  {
    rem = 20;
    FUN_a0140e74(0, (unsigned short) ((i * 16) + 0x300), 0x10, stack_buf, 0);
    i = (unsigned short) (i + 1);
    if (i >= rem)
    {
      break;
    }
  }

  rem = (unsigned short) (0x140 - (i * 16));
  if (rem != 0)
  {
    FUN_a0140e74(0, (unsigned short) ((i * 16) + 0x300), rem, stack_buf, 0);
  }
  return 0;
}
