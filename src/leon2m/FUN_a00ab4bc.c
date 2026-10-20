/* FUN_a00ab4bc (leon2m, 0xa00ab4bc-0xa00ab5f0, 308 bytes, 77 words).
 * Flags: -mcpu=v8 -O3 -g.
 * Code facts: two nested u8 loops j = 0..2 and i = 0..2. For each pair, l0 = (u16)(i + j*5 + 6);
 * three FUN_a0146a80 calls (0x37,l0,1,0x992,0), (0x38,l0,2,0x349e,0), (0x3a,l0,1,0x992,0), then four
 * FUN_a0146b20 calls (0, 0x37/0x38/0x39/0x3a, l0, 1, byte, 0) with byte = 2i+0x2a, 2i+0x17, 2i+0x18, 2i+0x2b.
 * Draft behaviour bug fixed: the last byte is i*2 + 0x2b (fw: add %l1,0x2b with %l1 = 2i), the draft had i + 0x2b.
 * Aids: none.
 */

extern void FUN_a0146a80(unsigned short param_1, unsigned short param_2, unsigned char param_3, unsigned short param_4, unsigned char param_5);
extern void FUN_a0146b20(unsigned char param_1, unsigned short param_2, unsigned short param_3, unsigned char param_4, unsigned char param_5, unsigned char param_6);
void FUN_a00ab4bc(void)
{
  unsigned char i;
  unsigned char j;
  unsigned char l1;
  unsigned short l0;
  j = 0;
  do
  {
    l1 = (unsigned char) ((j * 5) & 0xff);
    i = 0;
    do
    {
      l0 = (unsigned short) ((i + l1) + 6);
      FUN_a0146a80(0x37, l0, 1, 0x992, 0);
      FUN_a0146a80(0x38, l0, 2, 0x349e, 0);
      FUN_a0146a80(0x3a, l0, 1, 0x992, 0);
      FUN_a0146b20(0, 0x37, l0, 1, (unsigned char) ((i * 2) + 0x2a), 0);
      FUN_a0146b20(0, 0x38, l0, 1, (unsigned char) ((i * 2) + 0x17), 0);
      FUN_a0146b20(0, 0x39, l0, 1, (unsigned char) ((i * 2) + 0x18), 0);
      FUN_a0146b20(0, 0x3a, l0, 1, (unsigned char) ((i * 2) + 0x2b), 0);
      i++;
    }
    while (i <= 2);
    j++;
  }
  while (j <= 2);
}
