/* FUN_a00a7bf8 (leon2s 0xa00a7bf8-0xa00a7cc0, 200 bytes), flags -mcpu=v8 -Os -g.
 * Read-modify-write of one 8-bit register of the FUN_a00a7acc block (banks 0..4, table DAT_a00b4d70, page select
 * at offset 0x60 for banks 1..4 and reg <= 0x5f): mode 1 sets the bits of mask, any other mode clears them; the
 * store re-reads the table entry and writes (v & 0xff). Source forms of FUN_a00a7940 (two truncations of reg,
 * unsigned char value, plain pointer accesses for the data register) and FUN_a00a7acc (page write).
 */
extern unsigned short DAT_a00b4d70[];
void FUN_a00a7bf8(unsigned char bank, short reg, unsigned char mask, unsigned char mode)
{
  unsigned int addr;
  unsigned char v;
  if (bank <= 4)
  {
    if (bank != 0)
    {
      if (((unsigned short) reg) <= 0x5f)
      {
        *((volatile unsigned int *) (((DAT_a00b4d70[bank] + 0x60) << 2) | 0xcf000000)) = ((*((volatile unsigned int *) (((DAT_a00b4d70[bank] + 0x60) << 2) | 0xcf000000))) & 0x3f) | ((bank - 1) << 6);
      }
    }
    addr = reg;
    addr = ((DAT_a00b4d70[bank] + ((addr << 16) >> 16)) * 4) | 0xcf000000;
    v = *((unsigned int *) addr);
    if (mode == 1)
    {
      v |= mask;
    }
    else
    {
      v &= ~mask;
    }
    *((unsigned int *) (((DAT_a00b4d70[bank] + ((unsigned short) reg)) * 4) | 0xcf000000)) = v & 0xff;
  }
}
