/* leon2s FUN_a00a8260 @ 0xa00a8260  MATCH (-mcpu=v8 -Os -g, twin)
 * Twin of FUN_a00a7d04: same code, constants swapped; byte-exact.
 * See FUN_a00a7d04 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_a00b4d40;
void FUN_a00a8260(unsigned int param_1, short param_2, unsigned int param_3, unsigned int param_4)
{
  unsigned int uVar1;
  unsigned char uVar2;
  if ((param_1 & 0xff) < 2)
  {
    uVar1 = param_2;
    uVar1 = (((*((unsigned short *) ((&DAT_a00b4d40) + ((param_1 & 0xff) * 2)))) + ((uVar1 << 16) >> 16)) * 4) | 0xcf000000;
    uVar2 = *((unsigned int *) uVar1);
    if ((param_4 & 0xff) == 1)
    {
      uVar2 |= param_3;
    }
    else
    {
      uVar2 &= ~param_3;
    }
    *((unsigned int *) ((((*((unsigned short *) ((&DAT_a00b4d40) + ((param_1 & 0xff) * 2)))) + (unsigned short)param_2) * 4) | 0xcf000000)) = uVar2 & 0xff;
  }
}
