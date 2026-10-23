/* leon2s FUN_a00a8210 @ 0xa00a8210 (-mcpu=v8 -Os -g)
 * For p1 (low byte) < 2: with t = halfword p1 of the table at 0xA00B4D40, sets the register R = 0xCF000000 | ((t +
 * p2) * 4) to ((R & ~p3) | p4) & 0xff. Other p1 return without an access.
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern unsigned char DAT_a00b4d40;

void FUN_a00a8210(uint param_1, unsigned short param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  
  if ((param_1 & 0xff) < 2) {
    puVar1 = (uint *)(((uint)*(ushort *)(&DAT_a00b4d40 + (param_1 & 0xff) * 2) + (param_2 & 0xffff))
                      * 4 | 0xcf000000);
    *puVar1 = (*puVar1 & ~param_3 | param_4) & 0xff;
  }
  return;
}