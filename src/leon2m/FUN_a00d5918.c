/* leon2m FUN_a00d5918 @ 0xa00d5918  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned int _DAT_a802d290;
extern int FUN_a0148d98();

void FUN_a00d5918(void)

{
  FUN_a0148d98(_DAT_a802d290 >> 9 & 1);
  return;
}