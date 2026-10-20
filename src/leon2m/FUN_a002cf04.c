/* leon2m FUN_a002cf04 @ 0xa002cf04  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, autoc)
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
#define _DAT_cf03c844 (*(volatile unsigned int *)0xcf03c844)
#define _DAT_cf03c848 (*(volatile unsigned int *)0xcf03c848)
extern int func_0x000bcf88();

int FUN_a002cf04(uint param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = func_0x000bcf88();
  if ((uVar1 & 0xff) == 0xe0) {
    do {
      if (_DAT_cf03c844 != 2) {
        _DAT_cf03c844 = 1;
      }
    } while (_DAT_cf03c844 != 1);
    do {
      if (_DAT_cf03c848 != 2) {
        _DAT_cf03c848 = 1;
      }
    } while (_DAT_cf03c848 != 1);
  }
  return CONCAT44(param_2,param_1);
}