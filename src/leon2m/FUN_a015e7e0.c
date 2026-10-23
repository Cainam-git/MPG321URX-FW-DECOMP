/* leon2m FUN_a015e7e0 @ 0xa015e7e0 (-mcpu=v8 -Os -g)
 * Stores halfword 0x2000 at p2 + 8 and word 0 at p2 + 0x30; returns 0.
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();


undefined4 FUN_a015e7e0(undefined4 param_1,int param_2)

{
  *(undefined2 *)(param_2 + 8) = 0x2000;
  *(undefined4 *)(param_2 + 0x30) = 0;
  return 0;
}