/* leon2s FUN_a0088f4c @ 0xa0088f4c (-mcpu=v8 -Os -g)
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
#define _DAT_cf018e80 (*(volatile unsigned int *)0xcf018e80)

void FUN_a0088f4c(unsigned char param_1)

{
  if (param_1 == '\x01') {
    _DAT_cf018e80 = _DAT_cf018e80 & 0xfffffffd;
  }
  else {
    _DAT_cf018e80 = _DAT_cf018e80 | 2;
  }
  return;
}