/* leon2m FUN_a01492b8 @ 0xa01492b8 (-mcpu=v8 -Os -g)
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
extern unsigned char DAT_a802e3d7;
extern int FUN_a012a774();
extern int FUN_a012ad64();

void FUN_a01492b8(unsigned char param_1)

{
  DAT_a802e3d7 = param_1;
  if (param_1 != '\x01') {
    FUN_a012ad64();
    return;
  }
  FUN_a012a774(1);
  return;
}