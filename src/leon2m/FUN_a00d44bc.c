/* leon2m FUN_a00d44bc @ 0xa00d44bc-0xa00d4558 (39 words).
 * Same code as FUN_a00d41b4, whose comment describes it, with other constants (template -> this function):
 * 0x4 -> 0xf, 0x5 -> 0x12, 0x6 -> 0x13
 */
extern unsigned char FUN_a0144414(void);
extern int FUN_a0145660(unsigned char, unsigned int);
extern void FUN_a0145808(unsigned char, unsigned int, unsigned short, int);
void FUN_a00d44bc(unsigned char level)
{
  unsigned char id = FUN_a0144414();
  int hi, lo;
  if (level > 100)
    level = 100;
  hi = (unsigned short)FUN_a0145660(id, 18);
  lo = (unsigned short)FUN_a0145660(id, 19);
  FUN_a0145808(id, 15, level * (hi - lo) / 100 + FUN_a0145660(id, 19), 1);
}
