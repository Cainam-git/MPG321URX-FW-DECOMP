/* leon2m FUN_a00e21a4 @ 0xa00e21a4  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
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
extern int FUN_a00e021c();
extern int FUN_a00e0228();

void FUN_a00e21a4(uint param_1, int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (1 << (param_2 + 1U)) - (1 << param_3);
  uVar3 = param_4 << param_3 & uVar2;
  uVar1 = FUN_a00e021c(param_1);
  FUN_a00e0228(param_1,uVar1 & ~uVar2 | uVar3,param_3,uVar3,param_5,param_6);
  return;
}