/* leon2m FUN_a008cc28 @ 0xa008cc28-0xa008ccc0 (38 words).
 * Same code as FUN_a008cd58, whose comment describes it, with other constants (template -> this function):
 * 0x5 -> 0x2, 0x100510 -> 0x100508
 */
extern void FUN_a0146af4(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char *, unsigned char);
extern void FUN_a01577f4(unsigned char *, unsigned int, unsigned short);

void FUN_a008cc28(unsigned char a, unsigned char b, unsigned short v)
{
  unsigned char buf[8];
  unsigned char i;

  FUN_a01577f4(buf, 0x100508, v);
  for (i = 0; i < 2; i++) {
    if (buf[i] == ' ')
      buf[i] = 0;
    else
      buf[i] -= 47;
  }
  FUN_a0146af4(0, a, b, 2, buf, 0);
  __asm__ volatile ("nop");
}
