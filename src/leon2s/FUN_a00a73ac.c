/* leon2s FUN_a00a73ac @ 0xa00a73ac (-mcpu=v8 -Os -g)
 * Sets bit (p1 & 0x1f) of word p1 >> 5 of the word array at p2.
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
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))


void FUN_a00a73ac(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (param_1 >> 5) * 4;
  *(volatile uint *)(param_2 + iVar1) = *(volatile uint *)(param_2 + iVar1) | 1 << ((byte)param_1 & 0x1f);
  return;
}