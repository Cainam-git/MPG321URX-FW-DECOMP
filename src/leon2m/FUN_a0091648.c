/* leon2m FUN_a0091648 @ 0xa0091648 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned int _DAT_a802afec;
extern int FUN_a00a45a8();
extern int FUN_a00b5d10();

void FUN_a0091648(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  _DAT_a802afec = 0xfe;
  FUN_a00b5d10();
  FUN_a00a45a8(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}