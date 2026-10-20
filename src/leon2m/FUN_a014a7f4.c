/* leon2m FUN_a014a7f4 @ 0xa014a7f4 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned int _DAT_a802e3d0;

void FUN_a014a7f4(uint param_1)

{
  _DAT_a802e3d0 = _DAT_a802e3d0 & 0xffdfffff | (param_1 & 1) << 0x15;
  return;
}