/* leon2s FUN_a00a5cb4 @ 0xa00a5cb4 (-mcpu=v8 -Os -g)
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
extern void FUN_a00a507c();
extern int VBP_tmp();

void FUN_a00a5cb4(uint param_1,undefined4 param_2)

{
  undefined1 auStack_58 [80];
  
  FUN_a00a507c(param_1 & 0xff,auStack_58);
  VBP_tmp(param_1 & 0xff,auStack_58,1);
  return CONCAT44(param_2,param_1) & 0xffffffff000000ff;
}