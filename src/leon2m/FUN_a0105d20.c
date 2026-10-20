/* leon2m FUN_a0105d20 @ 0xa0105d20 (-mcpu=v8 -O2 -g)
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
extern int FUN_a00f2488();
extern int FUN_a00f2708();

void FUN_a0105d20(void)

{
  unsigned short uVar1;
  
  uVar1 = FUN_a00f2708(5,0x82);
  FUN_a00f2488(5,0x5e,uVar1 & 0xffff);
  FUN_a00f2488(5,0x79,uVar1 & 0xffff);
  return;
}