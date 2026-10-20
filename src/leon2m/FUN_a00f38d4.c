/* leon2m FUN_a00f38d4 @ 0xa00f38d4 (-mcpu=v8 -O2 -g)
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
#define _DAT_cf020008 (*(volatile unsigned int *)0xcf020008)

void FUN_a00f38d4(uint param_1)

{
  _DAT_cf020008 = param_1 & 0xff;
  return;
}