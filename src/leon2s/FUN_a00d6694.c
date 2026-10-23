/* leon2s FUN_a00d6694 @ 0xa00d6694 (-mcpu=v8 -Os -g)
 * Code: p1 = p1 & 0xff; returns func_0xa0fb6bb8(p1, 0xc1) & 1.
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
extern int func_0xa0fb6bb8();

unsigned char FUN_a00d6694(uint param_1,undefined4 param_2)

{
  param_1 = param_1 & 0xff;
  return func_0xa0fb6bb8(param_1,0xc1) & 1;
}