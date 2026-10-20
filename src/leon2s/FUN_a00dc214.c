/* leon2s FUN_a00dc214 @ 0xa00dc214  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a807883e;
extern int FUN_a00d9be4();
extern int FUN_a00dac08();
extern int FUN_a00dbe74();
extern int FUN_a00dbed4();
extern int FUN_a00dbf24();

int FUN_a00dc214(undefined4 param_1,undefined4 param_2)

{
  FUN_a00d9be4();
  FUN_a00dac08();
  if (DAT_a8078832 == '\0') {
    FUN_a00dbed4();
    FUN_a00dbe74();
  }
  FUN_a00dbf24();
  return (uint)DAT_a807883e;
}