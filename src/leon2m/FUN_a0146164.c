/* leon2m FUN_a0146164 @ 0xa0146164 (-mcpu=v8 -O2 -g)
 * Returns the low byte of FUN_a011966c(p1 & 0xff).
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
extern undefined2 FUN_a011966c(uint param_1);

int FUN_a0146164(uint param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = FUN_a011966c(param_1 & 0xff);
  return CONCAT44(param_2,(uint)uVar1) & 0xffffffff000000ff;
}