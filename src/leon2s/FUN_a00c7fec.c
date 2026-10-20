/* leon2s FUN_a00c7fec @ 0xa00c7fec  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern int func_0xa0fb7fd8();
extern int func_0xa0fc1794();

void FUN_a00c7fec(undefined1 param_1,int param_2,ushort param_3, unsigned short param_4,undefined4 param_5,
                 undefined4 param_6)

{
  undefined1 uVar1;
  ushort uVar2;
  ushort uVar3;
  
  param_3 = param_3 & 0xff;
  uVar3 = 0;
  if (param_3 != 0) {
    do {
      uVar1 = func_0xa0fb7fd8(param_1,0,param_4 & 0xffff);
      *(undefined1 *)(param_2 + (uint)uVar3) = uVar1;
      uVar2 = uVar3 + 1;
      uVar3 = uVar2;
    } while (uVar2 < param_3);
  }
  func_0xa0fc1794(1,param_2);
  return;
}