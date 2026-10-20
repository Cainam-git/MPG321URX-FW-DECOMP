/* leon2m FUN_a0101a28 @ 0xa0101a28 (-mcpu=v8 -O2 -g)
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
#define _DAT_cf0160c8 (*(volatile unsigned int *)0xcf0160c8)
#define _DAT_cf0160dc (*(volatile unsigned int *)0xcf0160dc)

void FUN_a0101a28(uint param_1,uint param_2)

{
  _DAT_cf0160dc = param_2 & 0xff;
  _DAT_cf0160c8 = param_1 & 0xff;
  return;
}