/* FUN_a00d430c (leon2m 0xa00d430c-0xa00d43b4, 168 bytes), flags -mcpu=v8 -O3 -g.
 * With id = FUN_a0144414() and level clamped to 100, calls FUN_a0145808(id, 0xb, v * (hi - lo) / 100 +
 * FUN_a0145660(id, 0xe), 1) as a tail call, where v = (100 - level) & 0xff, hi = FUN_a0145660(id, 0xd) and lo =
 * FUN_a0145660(id, 0xe) (halfwords, signed division). Called by FUN_a0088724.
 * Source form: the form of FUN_a00d41b4 with v = (100 - level) & 0xff in an unsigned short local (the masked
 * '100 - value' of the getter FUN_a00d43b4).
 */
extern unsigned char FUN_a0144414(void);
extern int FUN_a0145660(unsigned char, unsigned int);
extern void FUN_a0145808(unsigned char, unsigned int, unsigned short, int);
void FUN_a00d430c(unsigned char level)
{
  unsigned char id = FUN_a0144414();
  int hi, lo;
  unsigned short v;

  if (level > 100)
    level = 100;
  v = (100 - level) & 0xff;
  hi = (unsigned short)FUN_a0145660(id, 0xd);
  lo = (unsigned short)FUN_a0145660(id, 0xe);
  FUN_a0145808(id, 0xb, v * (hi - lo) / 100 + FUN_a0145660(id, 0xe), 1);
}
