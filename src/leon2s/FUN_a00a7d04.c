/* leon2s FUN_a00a7d04 @ 0xa00a7d04-0xa00a7d88 (33 words), flags -mcpu=v8 -Os -g.
 * ch = arg & 0xff; ch < 2 only: addr = ((u16 table 0xa00b4d6c[ch] + (u16)off) << 2) | 0xcf000000;
 * v = word at addr; mode (arg4 & 0xff) == 1 -> v |= mask, else v &= ~mask (andn); the store re-reads the
 * table entry and recomputes the address, then writes (v & 0xff). The store address uses (u16)param_2
 * (firmware srl 16), like the load.
 */

extern unsigned char DAT_a00b4d6c;
void FUN_a00a7d04(unsigned int param_1, short param_2, unsigned int param_3, unsigned int param_4)
{
  unsigned int uVar1;
  unsigned char uVar2;
  if ((param_1 & 0xff) < 2)
  {
    uVar1 = param_2;
    uVar1 = (((*((unsigned short *) ((&DAT_a00b4d6c) + ((param_1 & 0xff) * 2)))) + ((uVar1 << 16) >> 16)) * 4) | 0xcf000000;
    uVar2 = *((unsigned int *) uVar1);
    if ((param_4 & 0xff) == 1)
    {
      uVar2 |= param_3;
    }
    else
    {
      uVar2 &= ~param_3;
    }
    *((unsigned int *) ((((*((unsigned short *) ((&DAT_a00b4d6c) + ((param_1 & 0xff) * 2)))) + (unsigned short)param_2) * 4) | 0xcf000000)) = uVar2 & 0xff;
  }
}
