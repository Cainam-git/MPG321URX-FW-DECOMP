/* leon2m FUN_a0114374 @ 0xa0114374 (-mcpu=v8 -O3 -g)
 * k = p2 & 0xff. When k differs from bits 0-1 of register 0xCF01166C calls FUN_a00f1b5c(k, 0, 0x40, 0). Otherwise
 * writes 1 (p1 != 0) or 0 (p1 == 0) to registers 0xCF015A00 and 0xCF011670 and calls FUN_a00f1b5c(k, 0, 0x40, 1)
 * or FUN_a00f1b5c(k, 0, 0x40, 0) respectively.
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
#define _DAT_cf01166c (*(volatile unsigned int *)0xcf01166c)
#define _DAT_cf011670 (*(volatile unsigned int *)0xcf011670)
#define _DAT_cf015a00 (*(volatile unsigned int *)0xcf015a00)
extern int FUN_a00f1b5c();

void FUN_a0114374(unsigned char param_1, int param_2)

{
  param_2 = param_2 & 0xff;
  if (param_2 != (_DAT_cf01166c & 3)) {
    FUN_a00f1b5c(param_2,0,0x40,'\0');
    return;
  }
  if (param_1 != '\0') {
    _DAT_cf015a00 = 1;
    _DAT_cf011670 = 1;
    FUN_a00f1b5c(param_2,0,0x40,'\x01');
    return;
  }
  _DAT_cf015a00 = 0;
  _DAT_cf011670 = 0;
  FUN_a00f1b5c(param_2,0,0x40,'\0');
  return;
}