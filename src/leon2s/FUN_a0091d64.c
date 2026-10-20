/* leon2s FUN_a0091d64 @ 0xa0091d64  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern int FUN_a00a7fd8();
extern int FUN_a00b1794();
extern int func_0x9f1b8048();

unsigned char FUN_a0091d64(uint param_1,uint param_2)

{
  param_1 = param_1 & 0xff;
  func_0x9f1b8048(param_1,0xa8,param_2 & 0xff,1);
  FUN_a00b1794(2);
  FUN_a00a7fd8(param_1,0,0xf4);
  return FUN_a00a7fd8(param_1,0,0xf4);
}