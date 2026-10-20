/* leon2m FUN_a0029820 @ 0xa0029820  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int FUN_a002c25c();
extern int FUN_a002c268();

void FUN_a0029820(int param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a002c268(param_1 * 4 + -0x60fdffcc,0,param_2);
  FUN_a002c25c(param_1 * 4 + -0x60fdff94,param_2,param_3,param_4,param_5,param_6);
  return;
}