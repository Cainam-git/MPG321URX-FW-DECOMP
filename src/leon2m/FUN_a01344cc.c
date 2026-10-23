/* leon2m FUN_a01344cc @ 0xa01344cc (-mcpu=v8 -O2 -g)
 * Clears a word w, reads into it through func_0x4008c4d0(0, 0xb4, &w, 1) and returns w.
 * Source form: Ghidra's type and symbol names are kept.
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

extern int func_0x4008c4d0();

uint FUN_a01344cc(uint param_1, uint param_2)

{
  uint local_c;

  local_c = 0;
  func_0x4008c4d0(0, 0xb4, &local_c, 1);
  return (uint)local_c;
}
