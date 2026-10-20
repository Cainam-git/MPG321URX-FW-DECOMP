/* leon2m FUN_a00fc15c @ 0xa00fc15c-0xa00fc1a0 (17 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 17 words.
 * Code facts: leaf. Hardware register 0xd0040200 (sethi/or into a register, plain [reg] loads and stores,
 * no relocation): when the u8 arg == 1, clear bit 31 (andn 0x80000000), else set bit 31 (or). Each arm does its
 * own ld/st. void.
 * Fix vs the autoc draft: the register is a constant hardware address (volatile pointer cast); an extern
 * symbol gives the sethi/%lo simm13 form (23.53). volatile is on a real 0xd0... hardware register. Aids: none.
 */
#define REG_D0040200 (*(volatile unsigned int *)0xd0040200)

void FUN_a00fc15c(unsigned char on)
{
  if (on == 1)
    REG_D0040200 &= 0x7fffffff;
  else
    REG_D0040200 |= 0x80000000;
}
