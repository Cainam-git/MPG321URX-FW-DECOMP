/* leon2m FUN_a0118a80 @ 0xa0118a80 (-mcpu=v8 -O2 -g)
 * k = p1 & 0xff. For k <= 3 calls FUN_a00f2b8c(k, 0x14, p2), FUN_a00f2b8c(k, 0x15, p3) and FUN_a00f2b8c(k, 0x16,
 * p4 & 0xff); other k return without a call.
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
extern void FUN_a00f2b8c();

void FUN_a0118a80(uint param_1,undefined1 param_2,undefined1 param_3,uint param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 uVar1;
  
  param_1 = param_1 & 0xff;
  if (3 < param_1) {
    return CONCAT44(0x16,param_1);
  }
  FUN_a00f2b8c(param_1,0x14,param_2);
  FUN_a00f2b8c(param_1,0x15,param_3);
  uVar1 = 0x16;
  return FUN_a00f2b8c(param_1,0x16,param_4 & 0xff,param_4,param_5,param_6);
}