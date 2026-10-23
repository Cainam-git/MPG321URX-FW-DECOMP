/* leon2m FUN_a00d41b4 @ 0xa00d41b4-0xa00d4250 (39 words), flags -mcpu=v8 -O3 -g.
 * Code facts: level = u8 arg clamped to 100 (cmp 0x64; bleu). id = (u8)FUN_a0144414(). hi = (u16)FUN_a0145660
 * (id, 5) and lo = (u16)FUN_a0145660(id, 6), each extended right after its call (sll/srl 16); q = level * (hi
 * - lo) / 100 (signed, smul by 0x51eb851f, sra 5); tail FUN_a0145808(id, 4, (u16)(q + FUN_a0145660(id, 6)), 1).
 * FUN_a0145660's own retl extends its result to 16 bits; it is declared int and the caller casts to u16 into int
 * locals (a u16 local delays the extension past the 2nd call). void. Aids: none.
 */
extern unsigned char FUN_a0144414(void);
extern int FUN_a0145660(unsigned char, unsigned int);
extern void FUN_a0145808(unsigned char, unsigned int, unsigned short, int);
void FUN_a00d41b4(unsigned char level)
{
  unsigned char id = FUN_a0144414();
  int hi, lo;
  if (level > 100)
    level = 100;
  hi = (unsigned short)FUN_a0145660(id, 5);
  lo = (unsigned short)FUN_a0145660(id, 6);
  FUN_a0145808(id, 4, level * (hi - lo) / 100 + FUN_a0145660(id, 6), 1);
}
