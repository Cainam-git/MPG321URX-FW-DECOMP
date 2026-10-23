/* leon2s FUN_a00acb40 @ 0xa00acb40 (-mcpu=v8 -Os -g)
 * Code: p1 = p1 & 0xff; returns FUN_a00a6e8c(p1, 0x90).
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
extern int FUN_a00a6e8c();

unsigned short FUN_a00acb40(uint param_1,undefined4 param_2)

{
  param_1 = param_1 & 0xff;
  return FUN_a00a6e8c(param_1,0x90);
}