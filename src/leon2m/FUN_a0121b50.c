/* leon2m FUN_a0121b50 @ 0xa0121b50 (-mcpu=v8 -O2 -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern int FUN_a00f2068();

void FUN_a0121b50(undefined1 param_1, unsigned char param_2)

{
  if (param_2 != '\0') {
    FUN_a00f2068(param_1,0x40,1,1);
    return;
  }
  FUN_a00f2068(param_1,0x40,1,0);
  return;
}