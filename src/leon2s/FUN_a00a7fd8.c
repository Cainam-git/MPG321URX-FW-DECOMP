/* leon2s FUN_a00a7fd8 @ 0xa00a7fd8 (-mcpu=v8 -Os -g)
 */
typedef unsigned int uint;
typedef unsigned short ushort;

extern unsigned char DAT_a00b4d44;

short FUN_a00a7fd8(uint param_1, unsigned short param_2, unsigned short param_3)
{
  uint uVar1;
  uint cond1;
  uint cond2;

  uVar1 = 0;
  cond1 = (param_1 & 0xff) > 1;
  cond2 = ((unsigned char)param_2) > 5;
  if (cond1 || cond2) {
    return uVar1;
  }
  uVar1 = *(volatile uint *)((*(unsigned short *)(&DAT_a00b4d44 + ((param_1 & 0xff) * 6 + ((unsigned char)param_2)) * 2) + (param_3 & 0xffff))
                    * 4 | 0xcf000000) & 0xff;
  return uVar1;
}
