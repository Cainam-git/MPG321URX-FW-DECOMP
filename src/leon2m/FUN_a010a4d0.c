/* leon2m FUN_a010a4d0 (34 insns) BYTE-EXACT at -mcpu=v8 -O3 -g, no aids (hand). Inlined into FUN_a010a558.
 * Reads a 16-bit counter: FUN_a0106274(0) if 0xCF011A80 bit 0, else FUN_a00f3078(0xCF011AD8 if bit 7, else 0xCF011C18);
 * writes value >> 2 as low byte to 0xCF01EAC4 and high byte | 0x80 to 0xCF01EAC0. */
#define R(a) (*(volatile unsigned int *)(a))
extern int FUN_a0106274(unsigned char);
extern int FUN_a00f3078(int);
static unsigned short rdx(void)
{
  if (R(0xcf011a80) & 0x80)
    return FUN_a00f3078(0xcf011ad8);
  return FUN_a00f3078(0xcf011c18);
}
void FUN_a010a4d0(void)
{
  unsigned short v;
  if (R(0xcf011a80) & 1)
    v = FUN_a0106274(0);
  else
    v = rdx();
  v >>= 2;
  R(0xcf01eac4) = v & 0xff;
  R(0xcf01eac0) = (v >> 8) | 0x80;
}
