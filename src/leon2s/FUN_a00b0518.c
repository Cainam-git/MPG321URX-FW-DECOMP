/* leon2s FUN_a00b0518 @ 0xa00b0518  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern int FUN_a00b1b18();
extern int FUN_a00b1be4();

void FUN_a00b0518(unsigned char param_1)

{
  if (param_1 == '\0') {
    FUN_a00b1b18();
    return;
  }
  FUN_a00b1be4();
  return;
}