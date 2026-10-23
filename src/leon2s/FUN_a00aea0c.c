/* leon2s FUN_a00aea0c @ 0xa00aea0c (-mcpu=v8 -Os -g)
 * Calls FUN_a00ae5e4(1) when byte 0xA807DE63 == 1, then FUN_a00856fc(1, p2, p3, p4, p5, p6).
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned char DAT_a807de63;
extern int FUN_a00856fc();
extern int FUN_a00ae5e4();

void FUN_a00aea0c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  if (DAT_a807de63 == '\x01') {
    FUN_a00ae5e4(1);
  }
  FUN_a00856fc(1,param_2,param_3,param_4,param_5,param_6);
  return;
}