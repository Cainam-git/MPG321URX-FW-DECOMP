/* leon2m FUN_a00f8cc4 @ 0xa00f8cc4 (-mcpu=v8 -Os -g)
 * Code: FUN_a00f1ed8(p1, 0x41, (p2 & 0xffff) >> 2).
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
extern int FUN_a00f1ed8();

void FUN_a00f8cc4(undefined1 param_1, unsigned short param_2)

{
  FUN_a00f1ed8(param_1,0x41,(param_2 & 0xffff) >> 2);
  return;
}