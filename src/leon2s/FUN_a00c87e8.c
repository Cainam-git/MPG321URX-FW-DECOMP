/* leon2s FUN_a00c87e8 @ 0xa00c87e8 (-mcpu=v8 -Os -g)
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
extern void FUN_a00c7654();

void FUN_a00c87e8(undefined1 param_1,undefined1 param_2, unsigned short param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a00c7654(param_1,0,param_2);
  FUN_a00c7654(param_1,3,param_3 & 0xff);
  FUN_a00c7654(param_1,2,(param_3 & 0xffff) >> 8,param_4,param_5,param_6);
  return;
}