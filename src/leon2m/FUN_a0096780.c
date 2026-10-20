/* leon2m FUN_a0096780 @ 0xa0096780 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
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
extern int FUN_a00abc64();
extern int FUN_a00abe94();

void FUN_a0096780(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  _DAT_a802afec = 0xca;
  FUN_a00a93bc(1);
  FUN_a00abc64(0);
  FUN_a00a9650(0,1);
  FUN_a00abe94(1,param_2,param_3,param_4,param_5,param_6);
  return;
}