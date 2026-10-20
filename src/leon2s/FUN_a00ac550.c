/* leon2s FUN_a00ac550 @ 0xa00ac550  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int FUN_a00a6c00();

void FUN_a00ac550(undefined1 param_1,ushort param_2,undefined1 param_3)

{
  if (param_2 < 0x200) {
    FUN_a00a6c00(param_1,param_2,param_3);
    return;
  }
  return;
}