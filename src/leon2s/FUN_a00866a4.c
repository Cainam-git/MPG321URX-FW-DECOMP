/* leon2s FUN_a00866a4 @ 0xa00866a4 (-mcpu=v8 -Os -g)
 * Returns (word 0xA807A928) >> 0x1d & 1.
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned int _DAT_a807a928;

uint FUN_a00866a4(void)

{
  return _DAT_a807a928 >> 0x1d & 1;
}