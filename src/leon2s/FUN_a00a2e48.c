/* leon2s FUN_a00a2e48 @ 0xa00a2e48 (-mcpu=v8 -Os -g)
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
extern unsigned char DAT_a807db00;

undefined4 FUN_a00a2e48(uint param_1)

{
  int iVar1;
  
  iVar1 = *(volatile int *)(&DAT_a807db00 + (param_1 & 0xff) * 0x34);
  *(volatile uint *)(iVar1 + 0x74) = *(volatile uint *)(iVar1 + 0x74) & 0xff;
  *(volatile uint *)(iVar1 + 0x78) = *(volatile uint *)(iVar1 + 0x78) & 0xffffff00;
  *(volatile uint *)(iVar1 + 0x7c) = *(volatile uint *)(iVar1 + 0x7c) & 0xff;
  *(volatile uint *)(iVar1 + 0x90) = *(volatile uint *)(iVar1 + 0x90) & 0xff00ff;
  *(volatile uint *)(iVar1 + 0xac) = *(volatile uint *)(iVar1 + 0xac) & 0xff000000;
  *(volatile uint *)(iVar1 + 0xc4) = *(volatile uint *)(iVar1 + 0xc4) & 0xff00ff;
  *(volatile uint *)(iVar1 + 200) = *(volatile uint *)(iVar1 + 200) & 0xffff00ff;
  return 0;
}