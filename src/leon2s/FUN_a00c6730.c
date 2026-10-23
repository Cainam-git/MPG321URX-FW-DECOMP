/* leon2s FUN_a00c6730 @ 0xa00c6730 (-mcpu=v8 -Os -g)
 * Calls FUN_a00c32f4(), FUN_a00c3ae8(), FUN_a00c44e4() and FUN_a00d17a8(), then passes its six arguments to
 * FUN_a00c601c.
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int FUN_a00c32f4();
extern int FUN_a00c3ae8();
extern int FUN_a00c44e4();
extern int FUN_a00c601c();
extern int FUN_a00d17a8();

void FUN_a00c6730(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a00c32f4();
  FUN_a00c3ae8();
  FUN_a00c44e4();
  FUN_a00d17a8();
  FUN_a00c601c(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}