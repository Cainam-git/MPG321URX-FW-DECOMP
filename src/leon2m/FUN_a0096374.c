/* leon2m FUN_a0096374 @ 0xa0096374  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern unsigned int _DAT_a802afec;
extern void FUN_a00a900c();
extern int FUN_a00a93bc();
extern int FUN_a00b7054();
extern int FUN_a00d4998();

void FUN_a0096374(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a00a93bc(0);
  _DAT_a802afec = 0x18;
  FUN_a00a900c(0,1);
  FUN_a00d4998();
  FUN_a00b7054(0,param_2,param_3,param_4,param_5,param_6);
  return;
}