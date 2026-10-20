/* leon2m FUN_a010192c @ 0xa010192c (-mcpu=v8 -O2 -g)
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
#define _DAT_cf0160d8 (*(volatile unsigned int *)0xcf0160d8)

void FUN_a010192c(uint param_1)

{
  _DAT_cf0160d8 = _DAT_cf0160d8 & 0xf0 | param_1 & 0xf;
  return;
}