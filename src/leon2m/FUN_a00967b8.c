/* leon2m FUN_a00967b8 @ 0xa00967b8 (-mcpu=v8 -Os -g)
 * Stores 0xCB in word 0xA802AFEC and calls FUN_a00a93bc(2), FUN_a00aba34(0), FUN_a00a9650(1, 1) and
 * FUN_a00abc64(1, p2, p3, p4, p5, p6).
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned int _DAT_a802afec;
extern int FUN_a00a93bc();
extern int FUN_a00a9650();
extern int FUN_a00aba34();
extern int FUN_a00abc64();

void FUN_a00967b8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  _DAT_a802afec = 0xcb;
  FUN_a00a93bc(2);
  FUN_a00aba34(0);
  FUN_a00a9650(1,1);
  FUN_a00abc64(1,param_2,param_3,param_4,param_5,param_6);
  return;
}