/* leon2m FUN_a0146bb4 @ 0xa0146bb4 (-mcpu=v8 -O2 -g)
 * r = FUN_a011b384(p1 & 0xff) & 0xff; returns 1 when r == 1, 2 when r == 2, otherwise 0.
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
extern uint FUN_a011b384(uint param_1);

int FUN_a0146bb4(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_a011b384(param_1 & 0xff);
  iVar2 = 1;
  if ((uVar1 & 0xff) != 1) {
    iVar2 = (uint)((uVar1 & 0xff) == 2) * 2;
  }
  return CONCAT44(param_2,iVar2);
}