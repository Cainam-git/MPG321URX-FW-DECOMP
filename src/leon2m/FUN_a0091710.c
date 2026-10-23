/* leon2m FUN_a0091710 @ 0xa0091710 (-mcpu=v8 -O3 -g)
 * With v = (word 0xA802AFEC - 0xB) & 0xff calls FUN_a00a8ee8(v), FUN_a00aa4c0(v, 0), FUN_a00af44c(0xb, 0) and
 * FUN_a00a900c(0, 0), stores 2 in word 0xA802AFEC, then calls FUN_a00b4144(0, 1), FUN_a00a9468(1, 2) and
 * FUN_a00b34d4(0, 1, p3, p4, p5, p6).
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
extern unsigned int _DAT_a802afec;
extern int FUN_a00a8ee8();
extern void FUN_a00a900c();
extern int FUN_a00a9468();
extern void FUN_a00aa4c0();
extern void FUN_a00af44c();
extern int FUN_a00b34d4();
extern void FUN_a00b4144();

void FUN_a0091710(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a00a8ee8(_DAT_a802afec - 0xbU & 0xff);
  FUN_a00aa4c0(_DAT_a802afec - 0xbU & 0xff,0);
  FUN_a00af44c(0xb,0);
  FUN_a00a900c(0,0);
  _DAT_a802afec = 2;
  FUN_a00b4144(0,1);
  FUN_a00a9468(1,2);
  FUN_a00b34d4(0,1,param_3,param_4,param_5,param_6);
  return;
}