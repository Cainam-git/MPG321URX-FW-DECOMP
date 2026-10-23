/* leon2m FUN_a0134834 @ 0xa0134834 (-mcpu=v8 -O3 -g)
 * Copies ((p3 + 3) >> 2) & 0xff groups of four bytes from p2 to p1; each destination byte is stored on its own
 * (the source is read with byte, halfword and word loads). Returns p1.
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


int FUN_a0134834(int param_1,int param_2, unsigned short param_3)

{
  unsigned char uVar1;
  uint uVar2;
  int iVar3;
  unsigned char uVar4;
  int iVar5;
  
  uVar1 = (param_3 & 0xffff) + 3 >> 2 & 0xff;
  uVar2 = 0;
  if (uVar1 != 0) {
    uVar4 = 0;
    do {
      iVar5 = uVar4 * 4;
      *(undefined1 *)(param_1 + iVar5) = *(undefined1 *)(param_2 + iVar5);
      iVar3 = iVar5 + param_1;
      *(char *)(iVar3 + 1) = (char)*(undefined2 *)(param_2 + iVar5);
      *(char *)(iVar3 + 2) = (char)(*(undefined4 *)(param_2 + iVar5) >> 8);
      uVar2 = uVar2 + 1;
      uVar4 = uVar2 & 0xff;
      *(char *)(iVar3 + 3) = (char)*(undefined4 *)(param_2 + iVar5);
    } while (uVar4 < uVar1);
  }
  return CONCAT44(param_2,param_1);
}