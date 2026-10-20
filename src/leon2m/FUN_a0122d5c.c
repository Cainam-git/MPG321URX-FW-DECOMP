/* leon2m FUN_a0122d5c @ 0xa0122d5c  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, autoc)
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
#define _DAT_cf009bb8 (*(volatile unsigned int *)0xcf009bb8)
#define _DAT_cf00ed00 (*(volatile unsigned int *)0xcf00ed00)
#define _DAT_cf012c00 (*(volatile unsigned int *)0xcf012c00)
#define _DAT_cf012c40 (*(volatile unsigned int *)0xcf012c40)
#define _DAT_cf017000 (*(volatile unsigned int *)0xcf017000)

void FUN_a0122d5c(void)

{
  _DAT_cf009bb8 = _DAT_cf009bb8 | 4;
  _DAT_cf012c00 = _DAT_cf012c00 | 0x10;
  _DAT_cf012c40 = _DAT_cf012c40 | 0x10;
  _DAT_cf00ed00 = _DAT_cf00ed00 | 0x40;
  _DAT_cf017000 = _DAT_cf017000 | 0x10;
  return;
}