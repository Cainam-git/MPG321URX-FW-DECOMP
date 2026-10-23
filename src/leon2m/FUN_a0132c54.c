/* leon2m FUN_a0132c54 @ 0xa0132c54 (-mcpu=v8 -O3 -g)
 * For ((p3 + 3) >> 2) & 0xff groups of four bytes: builds the big-endian word from the bytes at p1 + 4 * i and
 * stores it in the word at p2 + 4 * i (the partial value is stored after each byte). Returns p1.
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
#define CONCAT11(a, b) ((unsigned short)(((unsigned)(a) << 8) | (unsigned char)(b)))
#define CONCAT12(a, b) (((unsigned)(a) << 16) | (unsigned short)(b))
#define CONCAT13(a, b) (((unsigned)(a) << 24) | ((unsigned)(b) & 0xffffff))
#define CONCAT21(a, b) (((unsigned)(a) << 8) | (unsigned char)(b))
#define CONCAT22(a, b) (((unsigned)(a) << 16) | (unsigned short)(b))
#define CONCAT31(a, b) (((unsigned)(a) << 8) | (unsigned char)(b))
#define SUB41(x, c) ((unsigned char)((unsigned)(x) >> ((c) * 8)))
#define SUB42(x, c) ((unsigned short)((unsigned)(x) >> ((c) * 8)))
#define SUB43(x, c) (((unsigned)(x) >> ((c) * 8)) & 0xffffff)
#define SUB21(x, c) ((unsigned char)((unsigned)(x) >> ((c) * 8)))
#define ZEXT14(x) ((unsigned)(unsigned char)(x))
#define ZEXT24(x) ((unsigned)(unsigned short)(x))
#define ZEXT12(x) ((unsigned short)(unsigned char)(x))
#define SEXT14(x) ((int)(signed char)(x))
#define SEXT24(x) ((int)(short)(x))
#define SEXT12(x) ((short)(signed char)(x))


uint FUN_a0132c54(int param_1,int param_2, unsigned short param_3)

{
  byte bVar1;
  int iVar2;
  unsigned char uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  unsigned char uVar7;
  
  uVar3 = (param_3 & 0xffff) + 3 >> 2 & 0xff;
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar7 = 0;
    do {
      iVar5 = uVar7 * 4;
      bVar1 = *(byte *)(param_1 + iVar5);
      *(uint *)(param_2 + iVar5) = (uint)bVar1;
      iVar6 = iVar5 + param_1;
      iVar2 = (uint)bVar1 * 0x100 + (uint)*(byte *)(iVar6 + 1);
      *(int *)(param_2 + iVar5) = iVar2;
      iVar2 = iVar2 * 0x100 + (uint)*(byte *)(iVar6 + 2);
      *(int *)(param_2 + iVar5) = iVar2;
      uVar4 = uVar4 + 1;
      uVar7 = uVar4 & 0xff;
      *(uint *)(param_2 + iVar5) = iVar2 * 0x100 + (uint)*(byte *)(iVar6 + 3);
    } while (uVar7 < uVar3);
  }
  return param_1;
}