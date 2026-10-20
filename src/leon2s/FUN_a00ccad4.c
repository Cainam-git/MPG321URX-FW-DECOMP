/* leon2s FUN_a00ccad4 @ 0xa00ccad4 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int FUN_a00cc974();
extern int FUN_a00cca38();

void FUN_a00ccad4(byte param_1)

{
  if (param_1 < 2) {
    FUN_a00cc974(param_1);
    return;
  }
  FUN_a00cca38(0);
  return;
}