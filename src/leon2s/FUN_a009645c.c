/* leon2s FUN_a009645c @ 0xa009645c (-mcpu=v8 -Os -g)
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
#define _DAT_cf0146fc (*(volatile unsigned int *)0xcf0146fc)
#define _DAT_cf01473c (*(volatile unsigned int *)0xcf01473c)

void FUN_a009645c(unsigned char param_1, unsigned char param_2)

{
  if (param_2 == '\x01') {
    if (param_1 == '\0') {
      _DAT_cf0146fc = _DAT_cf0146fc | 0x20;
    }
    else {
      _DAT_cf01473c = _DAT_cf01473c | 0x20;
    }
  }
  else if (param_1 == '\0') {
    _DAT_cf0146fc = _DAT_cf0146fc & 0xffffffdf;
  }
  else {
    _DAT_cf01473c = _DAT_cf01473c & 0xffffffdf;
  }
  return;
}