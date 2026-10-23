/* leon2m FUN_a0119114 @ 0xa0119114 (-mcpu=v8 -O3 -g)
 * Clears bit 1 of register 0xCF012F74 when the low byte of FUN_a011cf88() is above 0x83. Returns p1.
 * Source form: Ghidra's type and symbol names are kept.
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
#define _DAT_cf012f74 (*(volatile unsigned int *)0xcf012f74)
extern int FUN_a011cf88();

int FUN_a0119114(uint param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = FUN_a011cf88();
  if (0x83 < (uVar1 & 0xff)) {
    _DAT_cf012f74 = _DAT_cf012f74 & 0xfffffffd;
  }
  return CONCAT44(param_2,param_1);
}