/* leon2m FUN_a00ccef4 @ 0xa00ccef4  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern int FUN_a0090fd8();
extern int FUN_a00b88cc();
extern int FUN_a00ba950();
extern int FUN_a00baa6c();
extern int FUN_a00bab80();
extern int FUN_a00dc3dc();

unsigned int FUN_a00ccef4(undefined1 param_1,uint param_2)

{
  FUN_a0090fd8();
  FUN_a00dc3dc();
  FUN_a00b88cc();
  FUN_a00baa6c(param_1);
  FUN_a00ba950(param_1);
  FUN_a00bab80(param_1,6);
  return (ulonglong)param_2 << 0x20;
}