/* leon2s FUN_a0094a10 @ 0xa0094a10  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern void FUN_a00a80cc();
extern int FUN_a00b1794();

void FUN_a0094a10(undefined1 param_1)

{
  
  FUN_a00a80cc(param_1,3,0xf1,0x80,1);
  FUN_a00b1794(1);
  FUN_a00a80cc(param_1,3,0xf1,0x80,0);
  return;
}