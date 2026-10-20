/* leon2m FUN_a0106228 @ 0xa0106228  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, autoc)
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
#define _DAT_cf00ed80 (*(volatile unsigned int *)0xcf00ed80)

uint FUN_a0106228(void)

{
  unsigned char uVar1;
  
  uVar1 = 1;
  if ((((_DAT_cf00ed80 & 1) == 0) && (uVar1 = 2, (_DAT_cf00ed80 & 2) == 0)) &&
     (uVar1 = 3, (_DAT_cf00ed80 & 4) == 0)) {
    uVar1 = _DAT_cf00ed80 >> 2 & 4;
  }
  return uVar1;
}