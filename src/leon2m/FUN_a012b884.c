/* leon2m FUN_a012b884 @ 0xa012b884 (-mcpu=v8 -Os -g)
 * Code: FUN_a0138b98(p1, (word 0xA802E1A0) >> 0x1b & 1).
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
extern int FUN_a0138b98();

void FUN_a012b884(undefined1 param_1)

{
  FUN_a0138b98(param_1,_DAT_a802e1a0 >> 0x1b & 1);
  return;
}