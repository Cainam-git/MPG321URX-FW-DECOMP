/* leon2m FUN_a008cd58 @ 0xa008cd58-0xa008cdf0 (38 words), flags -mcpu=v8 -O3 -g.
 * Code facts: stack buf[8] at %fp-16; FUN_a01577f4(buf, 0x100510, (u16)v) (a format-to-buffer call; 0x100510
 * is a ROM address); for u8 i = 0..4: buf[i] = 0 when it is ' ', else buf[i] -= 47 ('0' - 1); then
 * FUN_a0146af4(0, a, b, 5, buf, 0) with u8 a/b. The fw ends with a real 'nop' after that call's delay slot,
 * before ret/restore. void.
 * Fix vs the autoc draft: a plain indexed loop over buf (the draft used Ghidra's base + 8 / p[-8] pointer form),
 * u8 params. Aids: one asm nop at the end (fw real nop, not a delay slot).
 */
extern void FUN_a0146af4(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char *, unsigned char);
extern void FUN_a01577f4(unsigned char *, unsigned int, unsigned short);

void FUN_a008cd58(unsigned char a, unsigned char b, unsigned short v)
{
  unsigned char buf[8];
  unsigned char i;

  FUN_a01577f4(buf, 0x100510, v);
  for (i = 0; i < 5; i++) {
    if (buf[i] == ' ')
      buf[i] = 0;
    else
      buf[i] -= 47;
  }
  FUN_a0146af4(0, a, b, 5, buf, 0);
  __asm__ volatile ("nop");
}
