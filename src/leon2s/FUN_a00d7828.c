/* leon2s FUN_a00d7828 @ 0xa00d7828 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();


void FUN_a00d7828(byte *param_1,byte *param_2)

{
  *param_2 = *param_1 & 0x7f;
  param_2[1] = param_1[1] & 0xf;
  return;
}