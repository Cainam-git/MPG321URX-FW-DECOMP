/* FUN_a00dd6c8 (leon2m, 0xa00dd6c8-0xa00dd7f0, 296 bytes, 74 words).
 * Flags: -mcpu=v8 -O3 -g.
 * Code facts: mode == 2 sets the byte DAT_a802b0ae = 1. Mode 1 or 2: DAT_a802b0ad = 1, then twelve FUN_a0107xxx(0)
 * calls (783c, 7884, 78cc, 7914, 765c, 76bc, 771c, 777c, 77dc, 7554, 75f8, 795c) and a tail call
 * FUN_a00def40(DAT_00198c60, param_2). Other modes: both bytes = 0, the hardware word 0xcf009bb8 = 0, the same
 * twelve calls with 1, tail call FUN_a00def40(DAT_00198c78, param_2).
 * Source form: the two strings are the symbols DAT_00198c60 / DAT_00198c78 (fw: 'restore %i0, %lo, %o0' builds the
 * address in the delay slot; a constant gives a separate 'or' and a bare restore).
 * Compiler aids: none (volatile only on the 0xcf009bb8 hardware register).
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
extern unsigned char DAT_a802b0ad;
extern unsigned char DAT_a802b0ae;
#define _DAT_cf009bb8 (*(volatile unsigned int *)0xcf009bb8)
extern int FUN_a00def40();
extern const char DAT_00198c60[];
extern const char DAT_00198c78[];
extern int FUN_a0107554();
extern int FUN_a01075f8();
extern int FUN_a010765c();
extern int FUN_a01076bc();
extern int FUN_a010771c();
extern int FUN_a010777c();
extern int FUN_a01077dc();
extern int FUN_a010783c();
extern int FUN_a0107884();
extern int FUN_a01078cc();
extern int FUN_a0107914();
extern int FUN_a010795c();

void FUN_a00dd6c8(int param_1,uint param_2)

{
  if (param_1 == 2) {
    DAT_a802b0ae = 1;
  }
  if (param_1 - 1U < 2) {
    DAT_a802b0ad = 1;
    FUN_a010783c(0);
    FUN_a0107884(0);
    FUN_a01078cc(0);
    FUN_a0107914(0);
    FUN_a010765c(0);
    FUN_a01076bc(0);
    FUN_a010771c(0);
    FUN_a010777c(0);
    FUN_a01077dc(0);
    FUN_a0107554(0);
    FUN_a01075f8(0);
    FUN_a010795c(0);
    FUN_a00def40(DAT_00198c60, param_2);
    return;
  }
  DAT_a802b0ae = 0;
  DAT_a802b0ad = 0;
  _DAT_cf009bb8 = 0;
  FUN_a010783c(1);
  FUN_a0107884(1);
  FUN_a01078cc(1);
  FUN_a0107914(1);
  FUN_a010765c(1);
  FUN_a01076bc(1);
  FUN_a010771c(1);
  FUN_a010777c(1);
  FUN_a01077dc(1);
  FUN_a0107554(1);
  FUN_a01075f8(1);
  FUN_a010795c(1);
  FUN_a00def40(DAT_00198c78, param_2);
  return;
}