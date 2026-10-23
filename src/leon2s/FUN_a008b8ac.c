/* leon2s FUN_a008b8ac @ 0xa008b8ac (-mcpu=v8 -Os -g)
 * Code: FUN_a00a6fc0(p1, 4, 0xff); FUN_a00a6fc0(p1, 3, 0xff, p4, p5, p6).
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int FUN_a00a6fc0();

void FUN_a008b8ac(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a00a6fc0(param_1,4,0xff);
  FUN_a00a6fc0(param_1,3,0xff,param_4,param_5,param_6);
  return;
}