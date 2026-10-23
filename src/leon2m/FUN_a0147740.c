/* leon2m FUN_a0147740 @ 0xa0147740 (-mcpu=v8 -O3 -g)
 * Code: p1 = p1 & 0xffff; returns func_0x4008d594(p1).
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
extern int func_0x4008d594();

unsigned short FUN_a0147740(unsigned short param_1,undefined4 param_2)

{
  param_1 = param_1 & 0xffff;
  return func_0x4008d594(param_1);
}