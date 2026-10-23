/* leon2m FUN_a0147b70 @ 0xa0147b70 (-mcpu=v8 -O2 -g)
 * Code: p1 = p1 & 0xff; returns FUN_a01257f0(p1, p2, p3, p4, p5, p6, p7).
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
extern int FUN_a01257f0();

unsigned short FUN_a0147b70(uint param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4,
                      undefined1 param_5,undefined4 param_6,undefined2 param_7)

{
  param_1 = param_1 & 0xff;
  return FUN_a01257f0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
}