/* leon2m FUN_a01334ec @ 0xa01334ec  MATCH (-mcpu=v8 -O2 -g)
 * Calls func_0x4008c4d0(0, 0xC, &local_c, 1) with local_c = 0 and returns the low byte of local_c. The two
 * parameters are not used.
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

// 0x4008c4d0
extern int func_0x4008c4d0();

uint FUN_a01334ec(uint param_1, uint param_2)

{
  uint local_c;

  local_c = 0;
  func_0x4008c4d0(0, 0xc, &local_c, 1);
  return (uint)(unsigned char)local_c;
}
