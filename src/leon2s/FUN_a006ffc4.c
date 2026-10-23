/* leon2s FUN_a006ffc4 @ 0xa006ffc4 (-mcpu=v8 -Os -g)
 * Returns (byte 0xA80788D4) & 0x10.
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned char DAT_a80788d4;

byte FUN_a006ffc4(void)

{
  return DAT_a80788d4 & 0x10;
}