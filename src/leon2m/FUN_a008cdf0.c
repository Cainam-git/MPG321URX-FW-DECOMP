/* leon2m FUN_a008cdf0 @ 0xa008cdf0-0xa008ce90 (40 words).
 * Formats bits 8..23 of the word 0xa802e1a8 as 5 characters with FUN_a01577f4 (format table at 0x100510), maps each character to a
 * number (space -> 0, otherwise character - 47) and passes them to FUN_a0146af4(0, a, b, 5, buf, 0). Same code as
 * FUN_a008cd58, which formats its third argument.
 */extern unsigned int DAT_a802e1a8;

extern void FUN_a0146af4(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char *, unsigned char);
extern void FUN_a01577f4(unsigned char *, unsigned int, unsigned short);

void FUN_a008cdf0(unsigned char a, unsigned char b)
{
  unsigned char buf[8];
  unsigned char i;

  FUN_a01577f4(buf, 0x100510, DAT_a802e1a8 >> 8);
  for (i = 0; i < 5; i++) {
    if (buf[i] == ' ')
      buf[i] = 0;
    else
      buf[i] -= 47;
  }
  FUN_a0146af4(0, a, b, 5, buf, 0);
}
