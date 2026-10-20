/* leon2s FUN_a00b288c @ 0xa00b288c (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();


int FUN_a00b288c(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  for (; param_1 != 0; param_1 = param_1 >> 8) {
    uVar1 = uVar1 + (param_1 & 0xff);
  }
  for (; param_2 != 0; param_2 = param_2 >> 8) {
    uVar1 = uVar1 + (param_2 & 0xff);
  }
  return (uVar1 & 0xf) + 0x30;
}