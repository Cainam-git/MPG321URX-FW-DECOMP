/* leon2m FUN_a00b79d0 @ 0xa00b79d0 (-mcpu=v8 -O2 -g)
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
extern unsigned int _DAT_a802d47c;
extern int FUN_a00a9f30();

void FUN_a00b79d0(void)

{
  if ((_DAT_a802d47c & 0x80) != 0) {
    FUN_a00a9f30(0,1);
    return;
  }
  FUN_a00a9f30(0,0);
  return;
}