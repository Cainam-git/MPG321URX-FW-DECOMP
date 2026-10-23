/* leon2m FUN_a014e010 @ 0xa014e010 (-mcpu=v8 -Os -g)
 * Returns (word 0xA802DFA0) >> 0x13 & 1.
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned int _DAT_a802dfa0;

uint FUN_a014e010(void)

{
  return _DAT_a802dfa0 >> 0x13 & 1;
}