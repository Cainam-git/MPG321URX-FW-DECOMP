/* leon2m FUN_a00daae8 @ 0xa00daae8 (-mcpu=v8 -Os -g)
 * Code: FUN_a0126ae4((word 0xA802D46C) >> 0x1d & 1).
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned int _DAT_a802d46c;
extern int FUN_a0126ae4();

void FUN_a00daae8(void)

{
  FUN_a0126ae4(_DAT_a802d46c >> 0x1d & 1);
  return;
}