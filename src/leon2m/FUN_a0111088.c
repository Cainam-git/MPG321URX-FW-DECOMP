/* leon2m FUN_a0111088 @ 0xa0111088 (-mcpu=v8 -O2 -g)
 * For p1 bit 0 calls FUN_a00fe880(9, m, 8) for m = 1, 2, 4, 8; for bit 1 FUN_a00fe880(9, m, 8) for m = 0x10, 0x20,
 * 0x40, 0x80; for bit 2 FUN_a00fe880(10, m, 8) for m = 1, 2, 4, 8; for bit 3 FUN_a00fe880(10, m, 8) for m = 0x10,
 * 0x20, 0x40, 0x80.
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
extern void FUN_a00fe880();

void FUN_a0111088(unsigned char param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((param_1 & 1) != 0) {
    FUN_a00fe880(9,1,8);
    FUN_a00fe880(9,2,8);
    FUN_a00fe880(9,4,8);
    FUN_a00fe880(9,8,8);
  }
  if ((param_1 & 2) != 0) {
    FUN_a00fe880(9,0x10,8);
    FUN_a00fe880(9,0x20,8);
    FUN_a00fe880(9,0x40,8);
    FUN_a00fe880(9,0x80,8);
  }
  if ((param_1 & 4) != 0) {
    FUN_a00fe880(10,1,8);
    FUN_a00fe880(10,2,8);
    FUN_a00fe880(10,4,8);
    FUN_a00fe880(10,8,8);
  }
  if ((param_1 & 8) != 0) {
    FUN_a00fe880(10,0x10,8);
    FUN_a00fe880(10,0x20,8);
    FUN_a00fe880(10,0x40,8);
    uVar1 = 10;
    uVar2 = 0x80;
    return FUN_a00fe880(10,0x80,8,param_4,param_5,param_6);
  }
  return 0x800000000a;
}