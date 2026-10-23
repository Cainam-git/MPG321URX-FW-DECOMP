/* leon2m FUN_a00e2258 @ 0xa00e2258 (-mcpu=v8 -Os -g)
 * Calls FUN_a00e02a0(i, p1, p2) for i = 0, 1, 2 and returns p1.
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int FUN_a00e02a0();

int FUN_a00e2258(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    FUN_a00e02a0(iVar1,param_1,param_2);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  return param_1;
}