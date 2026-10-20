/* leon2m FUN_a00f67d0 @ 0xa00f67d0-0xa00f6834 (25 words), flags -mcpu=v8 -O3 -g.
 * BYTE-EXACT: jf 100.00 match=True, rawcmp 0.
 * Code facts: clears one enable bit in a hardware register chosen by p: p 0 -> bit 0 and p 1 -> bit 1 of
 * 0xcf00ec80; p 2 -> bit 0 and p 3 -> bit 1 of 0xcf00eca8 (read, and 0xfe / 0xfd, write back; the mask also
 * clears bits 8..31). Other p: nothing. volatile only on the two real hardware registers. Aids: none.
 */
void FUN_a00f67d0(int p)
{
  if (p == 0)
    *(volatile unsigned int *)0xcf00ec80 &= 0xfe;
  else if (p == 1)
    *(volatile unsigned int *)0xcf00ec80 &= 0xfd;
  else if (p == 2)
    *(volatile unsigned int *)0xcf00eca8 &= 0xfe;
  else if (p == 3)
    *(volatile unsigned int *)0xcf00eca8 &= 0xfd;
}
