/* leon2m FUN_a013b710 @ 0xa013b710  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, autoc)
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
extern unsigned char DAT_a802cbbc;
extern int FUN_a00f6ca4();
extern int FUN_a00f6cc0();

void FUN_a013b710(unsigned char param_1)

{
  if (param_1 != '\0') {
    DAT_a802cbbc = DAT_a802cbbc | 2;
    FUN_a00f6cc0();
    return;
  }
  DAT_a802cbbc = DAT_a802cbbc & 0xfd;
  FUN_a00f6ca4();
  return;
}