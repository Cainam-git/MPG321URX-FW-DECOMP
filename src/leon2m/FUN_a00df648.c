/* leon2m FUN_a00df648 @ 0xa00df648 (-mcpu=v8 -O3 -g)
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


void FUN_a00df648(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_2 << 0x11;
  param_1 = param_1 * 4;
  *(volatile uint *)(param_1 + -0x31000000) = uVar1 / 0xc & 0xff;
  *(volatile uint *)(param_1 + -0x30fffffc) = uVar1 / 0xc00 & 0xff;
  *(volatile uint *)(param_1 + -0x30fffff8) = uVar1 / 0xc0000 & 0xff;
  return;
}