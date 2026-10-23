/* leon2m FUN_a00cbe2c @ 0xa00cbe2c (-mcpu=v8 -Os -g)
 * Calls FUN_a014b4b4(0xfe, 1), FUN_a00baa6c(p1), FUN_a00ba950(p1) and FUN_a00bab80(p1, 6). Returns 0.
 * Source form: Ghidra's type and symbol names are kept.
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
extern int FUN_a00ba950();
extern int FUN_a00baa6c();
extern int FUN_a00bab80();
extern int FUN_a014b4b4();

unsigned int FUN_a00cbe2c(undefined1 param_1,uint param_2)

{
  FUN_a014b4b4(0xfe,1);
  FUN_a00baa6c(param_1);
  FUN_a00ba950(param_1);
  FUN_a00bab80(param_1,6);
  return (ulonglong)param_2 << 0x20;
}