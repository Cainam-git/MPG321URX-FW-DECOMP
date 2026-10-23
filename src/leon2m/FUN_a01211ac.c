/* leon2m FUN_a01211ac @ 0xa01211ac (-mcpu=v8 -O2 -g)
 * k = p1 & 0xff; returns FUN_a0120de4(FUN_a00fd820(k) & 0xff, k) as a byte.
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
extern int FUN_a00fd820();
extern int FUN_a0120de4();

unsigned char FUN_a01211ac(uint param_1,undefined4 param_2)

{
  uint uVar1;
  
  param_1 = param_1 & 0xff;
  uVar1 = param_1;
  uVar1 = FUN_a00fd820(param_1) & 0xff;
  return FUN_a0120de4(uVar1,param_1);
}