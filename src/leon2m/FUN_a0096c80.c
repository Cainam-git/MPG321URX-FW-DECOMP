/* leon2m FUN_a0096c80 @ 0xa0096c80 (-mcpu=v8 -O3 -g)
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
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern unsigned int _DAT_a802d33c;
extern void FUN_a00a813c();
extern int FUN_a00a900c();
extern int FUN_a00a9650();

void FUN_a0096c80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
    volatile unsigned char *pb1_ = (volatile unsigned char *)0xA802D290;
  uint uVar1;
  
  uVar1 = (*(volatile unsigned int *)(pb1_ + 172)) >> 0x12 & 3;
  DAT_a8025c56 = (undefined1)uVar1;
  FUN_a00a813c(1,uVar1,0);
  FUN_a00a900c(_DAT_a802afec - 0x18U & 0xff,2);
  uVar1 = (*(volatile unsigned int *)(pb1_ + 172)) >> 0x12 & 3;
  _DAT_a802afec = uVar1 + 0x77;
  FUN_a00a9650(uVar1,1,param_3,param_4,param_5,param_6);
  return;
}