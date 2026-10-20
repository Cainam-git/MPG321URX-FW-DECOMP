/* leon2s FUN_a00a72c0 @ 0xa00a72c0-0xa00a7314 (21 words), flags -mcpu=v8 -Os -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp_l2s.py 0 mismatches / 21 words. The autoc draft was empty (asm only).
 * Code facts: leaf paged register write. page = hw register ((ch + 0xf401) << 2) | 0xcf000000; old = *page;
 * *page = (u16)reg >> 8 (sll 16 / srl 24); hw word 0xce008100 + (ch << 8) + (reg & 0xff) = val (st [reg+reg]);
 * *page = old & 0xff. u8 ch, u32 reg and val. volatile only on the 0xcf... / 0xce... hardware registers.
 * The low byte is its own local (it keeps the fw and-before-sll order). Aids: none.
 */
void FUN_a00a72c0(unsigned char ch, unsigned int reg, unsigned int val)
{
  volatile unsigned int *page = (volatile unsigned int *)(((ch + 0xf401) << 2) | 0xcf000000);
  unsigned int old = *page;

  *page = (unsigned short)reg >> 8;
  { unsigned int lo = reg & 0xff;
  *(volatile unsigned int *)(0xce008100 + (ch << 8) + lo) = val; }
  *page = old & 0xff;
}
