/* leon2m FUN_a0093988 @ 0xa0093988 (-mcpu=v8 -Os -g)
 * Code: (word 0xA802AFEC) = 200; FUN_a00b6290(0); FUN_a00b6514(3, 1, p3, p4, p5, p6).
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
extern int FUN_a00b6290();
extern int FUN_a00b6514();

void FUN_a0093988(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  _DAT_a802afec = 200;
  FUN_a00b6290(0);
  FUN_a00b6514(3,1,param_3,param_4,param_5,param_6);
  return;
}