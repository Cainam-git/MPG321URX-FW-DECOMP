/* leon2m FUN_a011d194 @ 0xa011d194 (-mcpu=v8 -O3 -g)
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
#define _DAT_cf0115c0 (*(volatile unsigned int *)0xcf0115c0)
extern int FUN_a00f328c();
extern int FUN_a0101e68();
extern void FUN_a0104b2c();
extern int FUN_a0106ba8();
extern int FUN_a011552c();
extern void FUN_a011e028();
extern int FUN_a0123384();

int FUN_a011d194(undefined4 param_1,undefined4 param_2)

{
  FUN_a0104b2c(8,0xb0);
  FUN_a011e028(0,0);
  FUN_a011e028(0x1f,0);
  FUN_a0101e68();
  FUN_a00f328c();
  FUN_a0123384();
  FUN_a0106ba8(8);
  FUN_a011552c();
  _DAT_cf0115c0 = 0xf;
  return CONCAT44(param_2,param_1);
}