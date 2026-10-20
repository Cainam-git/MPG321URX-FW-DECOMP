/* leon2m FUN_a002992c @ 0xa002992c (-mcpu=v8 -O3 -g)
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
extern int FUN_a002c25c();

void FUN_a002992c(unsigned char param_1)

{
  if (param_1 != '\0') {
    FUN_a002c25c(0x9f000090,0x10);
    return;
  }
  FUN_a002c25c(0x9f000090,0);
  return;
}