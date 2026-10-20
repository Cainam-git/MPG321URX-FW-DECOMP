/* leon2m FUN_a014f620 @ 0xa014f620 (-mcpu=v8 -O2 -g)
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

void FUN_a014f620(unsigned char param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == '\0') {
    FUN_a00fe880(0x11,1,0xb);
    FUN_a00fe880(0x11,2,0xb);
    FUN_a00fe880(0x11,4,0xb);
    FUN_a00fe880(0x11,8,0xb);
    uVar1 = 0x11;
    uVar2 = 0x10;
    return FUN_a00fe880(0x11,0x10,0xb,param_4,param_5,param_6);
  }
  if (param_1 != '\x01') {
    return 0x800000000a;
  }
  FUN_a00fe880(10,8,0xb);
  FUN_a00fe880(10,0x10,0xb);
  FUN_a00fe880(10,0x20,0xb);
  FUN_a00fe880(10,0x40,0xb);
  uVar1 = 10;
  uVar2 = 0x80;
  return FUN_a00fe880(10,0x80,0xb,param_4,param_5,param_6);
}