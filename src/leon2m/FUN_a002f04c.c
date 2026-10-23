/* leon2m FUN_a002f04c @ 0xa002f04c (-mcpu=v8 -O3 -g)
 * Clears registers 0xCF007730 and 0xCF007734, calls FUN_a002e3c4(3, 1) and sets bit 3 of word 0xA802C9E4. Returns
 * p1.
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
extern unsigned int _DAT_a802c9e4;
#define _DAT_cf007730 (*(volatile unsigned int *)0xcf007730)
#define _DAT_cf007734 (*(volatile unsigned int *)0xcf007734)
extern int FUN_a002e3c4();

uint FUN_a002f04c(uint param_1,uint param_2)

{
  _DAT_cf007730 = 0;
  _DAT_cf007734 = 0;
  FUN_a002e3c4(3,1);
  _DAT_a802c9e4 = _DAT_a802c9e4 | 8;
  return param_1;
}