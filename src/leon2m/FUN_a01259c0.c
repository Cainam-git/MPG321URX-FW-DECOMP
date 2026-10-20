/* leon2m FUN_a01259c0 @ 0xa01259c0 (-mcpu=v8 -O2 -g)
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
extern int func_0x4008c86c();

void FUN_a01259c0(unsigned char param_1)

{
  if (param_1 != '\0') {
    func_0x4008c86c(7,0x80,0);
    return;
  }
  func_0x4008c86c(7,0x80,0xff);
  return;
}