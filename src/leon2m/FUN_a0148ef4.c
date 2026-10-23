/* leon2m FUN_a0148ef4 @ 0xa0148ef4 (-mcpu=v8 -O3 -g)
 * Copies bit 0 of p1 into bit 25 of word 0xA802E3D0, then calls FUN_a012f1ec(k, 1) for k = 0 .. 3.
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
extern unsigned int _DAT_a802e3d0;
extern void FUN_a012f1ec();

void FUN_a0148ef4(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  _DAT_a802e3d0 = _DAT_a802e3d0 & 0xfdffffff | (param_1 & 1) << 0x19;
  FUN_a012f1ec(0,1);
  FUN_a012f1ec(1,1);
  FUN_a012f1ec(2,1);
  FUN_a012f1ec(3,1,param_3,param_4,param_5,param_6);
  return;
}