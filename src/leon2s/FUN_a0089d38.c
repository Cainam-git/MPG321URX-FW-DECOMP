/* leon2s FUN_a0089d38 @ 0xa0089d38 (-mcpu=v8 -Os -g)
 * Calls DPTX_IsHPDAction_Off(0) when FUN_a0070424() is nonzero and eDP_IsHPDAction_Off(byte 0xA80761C0). Then for
 * (f, k) = (FUN_a0070424, 0), (FUN_a006ffb4, 1), (FUN_a006ffc4, 2), (FUN_a006ffd4, 3), (FUN_a006ffe4, 4): when the
 * byte result of f() is nonzero, calls DPTX_SetBrilliantMode(k) and FUN_a008996c(k).
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
extern unsigned char DAT_a80761c0;
extern int DPTX_IsHPDAction_Off();
extern int DPTX_SetBrilliantMode();
extern byte FUN_a006ffb4(void);
extern byte FUN_a006ffc4(void);
extern byte FUN_a006ffd4(void);
extern byte FUN_a006ffe4(void);
extern byte FUN_a0070424(void);
extern int FUN_a008996c();
extern int eDP_IsHPDAction_Off();

int FUN_a0089d38(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  byte bVar2;
  undefined4 uVar1;
  
  bVar2 = FUN_a0070424();
  if (bVar2 != 0) {
    DPTX_IsHPDAction_Off(0);
  }
  eDP_IsHPDAction_Off(DAT_a80761c0);
  bVar2 = FUN_a0070424();
  if (bVar2 != 0) {
    DPTX_SetBrilliantMode(0);
    FUN_a008996c(0);
  }
  bVar2 = FUN_a006ffb4();
  if (bVar2 != 0) {
    DPTX_SetBrilliantMode(1);
    FUN_a008996c(1);
  }
  bVar2 = FUN_a006ffc4();
  if (bVar2 != 0) {
    DPTX_SetBrilliantMode(2);
    FUN_a008996c(2);
  }
  bVar2 = FUN_a006ffd4();
  if (bVar2 != 0) {
    DPTX_SetBrilliantMode(3);
    FUN_a008996c(3);
  }
  bVar2 = FUN_a006ffe4();
  if (bVar2 == 0) {
    return CONCAT44(param_2,param_1);
  }
  DPTX_SetBrilliantMode(4);
  uVar1 = 4;
  return FUN_a008996c(4,param_2,param_3,param_4,param_5,param_6);
}