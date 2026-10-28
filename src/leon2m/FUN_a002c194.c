/* leon2m FUN_a002c194 @ 0xa002c194-0xa002c204 (28 words), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf. Returns the low byte of the word at hardware register 0xcf03c800 + 4 * (ch - 1) for
 * ch = 1..4 (case tree rooted at 2, one shared ld/and block), 0 for any other ch.
 * Same form as the neighbour FUN_a002c11c (one return per case). volatile only on the 0xcf... hardware
 * registers. Aids: none.
 */
#define REG(a) (*(volatile unsigned int *)(a))

unsigned char FUN_a002c194(unsigned char ch)
{
  switch (ch) {
  case 1: return REG(0xcf03c800);
  case 2: return REG(0xcf03c804);
  case 3: return REG(0xcf03c808);
  case 4: return REG(0xcf03c80c);
  }
  return 0;
}
