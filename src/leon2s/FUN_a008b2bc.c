/* leon2s FUN_a008b2bc @ 0xa008b2bc (-mcpu=v8 -Os -g)
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
#define _DAT_cf011254 (*(volatile unsigned int *)0xcf011254)
#define _DAT_cf011258 (*(volatile unsigned int *)0xcf011258)

undefined4 FUN_a008b2bc(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((_DAT_cf011258 & 0xf0) >> 4 == (param_1 & 0xf)) ||
     ((_DAT_cf011254 & 0xf0) >> 4 == (param_1 & 0xf))) {
    uVar1 = 1;
  }
  return uVar1;
}