/* leon2s FUN_a00a7408 @ 0xa00a7408 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();


uint FUN_a00a7408(uint param_1,int param_2)

{
  return *(uint *)(param_2 + (param_1 >> 5) * 4) >> ((byte)param_1 & 0x1f) & 1;
}