/* leon2m FUN_a0109b70 @ 0xa0109b70  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, autoc)
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
#define _DAT_cf011ec0 (*(volatile unsigned int *)0xcf011ec0)
#define _DAT_cf011ec4 (*(volatile unsigned int *)0xcf011ec4)
extern void FUN_a00f308c();

void FUN_a0109b70(unsigned short param_1,undefined4 param_2)

{
  uint uVar1;
  
  FUN_a00f308c(0xcf011d08,param_1 & 0xffff);
  FUN_a00f308c(0xcf011d00,0);
  _DAT_cf011ec4 = param_1 & 0xff;
  uVar1 = (param_1 & 0xffff) >> 8;
  _DAT_cf011ec0 = uVar1 | 0x80;
  return CONCAT44(param_2,uVar1) | 0x80;
}