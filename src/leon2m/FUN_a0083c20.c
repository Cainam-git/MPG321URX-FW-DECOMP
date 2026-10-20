/* leon2m FUN_a0083c20 @ 0xa0083c20 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned short _DAT_a802af42;

ushort FUN_a0083c20(void)

{
  return _DAT_a802af42 >> 5 & 1;
}