/* leon2m FUN_a012ad6c @ 0xa012ad6c (-mcpu=v8 -Os -g)
 * Returns (word 0xA802E1A0) >> 0x19 & 1.
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned int _DAT_a802e1a0;

uint FUN_a012ad6c(void)

{
  return _DAT_a802e1a0 >> 0x19 & 1;
}