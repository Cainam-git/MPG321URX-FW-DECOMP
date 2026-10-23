/* leon2m FUN_a014bcf0 @ 0xa014bcf0 (-mcpu=v8 -Os -g)
 * Code: (byte 0xA802E3D9) = p1; FUN_a013ae00(p1).
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern unsigned char DAT_a802e3d9;
extern int FUN_a013ae00();

void FUN_a014bcf0(undefined1 param_1)

{
  DAT_a802e3d9 = param_1;
  FUN_a013ae00(param_1);
  return;
}