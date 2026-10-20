/* leon2s FUN_a00d36e4 @ 0xa00d36e4 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();


uint FUN_a00d36e4(int param_1,int param_2,int param_3)

{
  return param_2 * (0x100 - param_3) + param_1 * param_3 + 0x80U >> 8;
}