/* leon2m FUN_a009e2ac @ 0xa009e2ac (-mcpu=v8 -Os -g)
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
extern int FUN_a00b83e4();

int FUN_a009e2ac(undefined4 param_1,undefined4 param_2)

{
  _DAT_a802afec = 0x105;
  FUN_a00b83e4();
  _DAT_a802afec = 0;
  return param_1;
}