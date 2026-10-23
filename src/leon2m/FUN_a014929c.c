/* leon2m FUN_a014929c @ 0xa014929c (-mcpu=v8 -Os -g)
 * Code: (byte 0xA802E3DA) = p1; FUN_a013b684(p1).
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned char DAT_a802e3da;
extern int FUN_a013b684();

void FUN_a014929c(undefined1 param_1)

{
  DAT_a802e3da = param_1;
  FUN_a013b684(param_1);
  return;
}