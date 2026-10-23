/* leon2m FUN_a00daad4 @ 0xa00daad4 (-mcpu=v8 -Os -g)
 * Returns (halfword 0xA802D00C) >> 10 & 1.
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned short _DAT_a802d00c;

ushort FUN_a00daad4(void)

{
  return _DAT_a802d00c >> 10 & 1;
}