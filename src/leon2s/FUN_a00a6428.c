/* leon2s FUN_a00a6428 @ 0xa00a6428 (-mcpu=v8 -Os -g)
 * Code: *p1 = (p3 | *p1 & ~p2) & 0xff.
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();


void FUN_a00a6428(uint *param_1,uint param_2,uint param_3)

{
  *param_1 = (param_3 | *param_1 & ~param_2) & 0xff;
  return;
}