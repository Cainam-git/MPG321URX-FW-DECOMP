/* leon2m FUN_a002c11c @ 0xa002c11c-0xa002c194 (30 words), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf. Writes the u8 value v (and 0xff) as a full word to the hardware register 0xcf03c800 +
 * 4 * (ch - 1) for ch = 1..4 (case tree rooted at 2, constant addresses sethi/or, st [reg]); any other ch does
 * nothing. void. volatile only on the 0xcf... hardware registers. Aids: none.
 */
#define REG(a) (*(volatile unsigned int *)(a))

void FUN_a002c11c(unsigned char ch, unsigned char v)
{
  switch (ch) {
  case 1: REG(0xcf03c800) = v; break;
  case 2: REG(0xcf03c804) = v; break;
  case 3: REG(0xcf03c808) = v; break;
  case 4: REG(0xcf03c80c) = v; break;
  }
}
