/* leon2s FUN_a00b14dc @ 0xa00b14dc  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned int DAT_a006c540;
extern unsigned char DAT_a8079308;
extern int FUN_a0073044();

void FUN_a00b14dc(undefined1 param_1,undefined1 param_2)

{
  DAT_a8079308 = param_2;
  FUN_a0073044(&DAT_a006c540,param_1,param_2);
  return;
}