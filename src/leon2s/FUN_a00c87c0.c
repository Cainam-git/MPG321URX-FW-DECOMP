/* leon2s FUN_a00c87c0 @ 0xa00c87c0  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern int FUN_a00c8048();

unsigned int FUN_a00c87c0(undefined1 param_1,uint param_2)

{
  FUN_a00c8048(param_1,0xa0,(param_2 & 0xff) * 0x80 + 0x78,8);
  return (ulonglong)param_2 << 0x20;
}