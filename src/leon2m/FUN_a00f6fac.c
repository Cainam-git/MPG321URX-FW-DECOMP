/* leon2m FUN_a00f6fac @ 0xa00f6fac (-mcpu=v8 -O3 -g)
 * When the low byte of FUN_a011cf88() is above 0x83, sets register 0xCF00EF40 to (register & 0xFE) | (p1 & 1).
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
#define _DAT_cf00ef40 (*(volatile unsigned int *)0xcf00ef40)
extern int FUN_a011cf88();

void FUN_a00f6fac(uint param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = FUN_a011cf88();
  if (0x83 < (uVar1 & 0xff)) {
    _DAT_cf00ef40 = _DAT_cf00ef40 & 0xfe | param_1 & 1;
  }
  return CONCAT44(param_2,param_1) & 0xffffffff00000001;
}