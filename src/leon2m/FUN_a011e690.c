/* leon2m FUN_a011e690 @ 0xa011e690 (-mcpu=v8 -O3 -g)
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
#define _DAT_cf016404 (*(volatile unsigned int *)0xcf016404)
extern int func_0x4008e2a4();

void FUN_a011e690(uint param_1,undefined4 param_2)

{
  func_0x4008e2a4();
  if ((param_1 & 0xff) == 1) {
    _DAT_cf016404 = _DAT_cf016404 & 0x3f | 0x80;
  }
  else {
    _DAT_cf016404 = _DAT_cf016404 & 0x3f | 0x40;
  }
  return CONCAT44(param_2,param_1) & 0xffffffff000000ff;
}