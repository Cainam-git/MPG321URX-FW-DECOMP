/* leon2m FUN_a008e5b8 @ 0xa008e5b8-0xa008e650 (38 words).
 * Formats the byte 0xa802d285 as 2 characters with FUN_a01577f4 (format table at 0x100508), maps each character to a
 * number (space -> 0, otherwise character - 47) and passes them to FUN_a0146af4(0, a, b, 2, buf, 0). Same code as
 * FUN_a008cd58, which formats its third argument.
 */
extern unsigned char DAT_a802d285;

extern void FUN_a0146af4(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char *, unsigned char);
extern void FUN_a01577f4(unsigned char *, unsigned int, unsigned short);

void FUN_a008e5b8(unsigned char a, unsigned char b)
{
  unsigned char buf[8];
  unsigned char i;

  FUN_a01577f4(buf, 0x100508, DAT_a802d285);
  for (i = 0; i < 2; i++) {
    if (buf[i] == ' ')
      buf[i] = 0;
    else
      buf[i] -= 47;
  }
  FUN_a0146af4(0, a, b, 2, buf, 0);
}
