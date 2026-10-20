/* leon2m FUN_a013b44c @ 0xa013b44c  MATCH (-mcpu=v8 -O2 -g, gcc 3.4.4, autoc)
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
extern unsigned char DAT_a802a460;
extern unsigned short _DAT_a802a46e;
extern int FUN_a013ae00();

void FUN_a013b44c(undefined2 param_1)

{
  _DAT_a802a46e = param_1;
  FUN_a013ae00(DAT_a802a460);
  return;
}