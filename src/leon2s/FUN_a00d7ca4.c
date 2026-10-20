/* leon2s FUN_a00d7ca4 @ 0xa00d7ca4 (-mcpu=v8 -Os -g)
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
extern unsigned char DAT_a8078832;
extern int ARR_a80760a4[];

void FUN_a00d7ca4(void)

{
  int iVar1;
  
  iVar1 = ARR_a80760a4[(uint)DAT_a8078832];
  *(volatile uint *)(iVar1 + 0xc0) = *(volatile uint *)(iVar1 + 0xc0) & 0xffffff7f;
  return;
}