/* leon2m FUN_a0095984 @ 0xa0095984 (-mcpu=v8 -O3 -g)
 * Calls FUN_a00a8c88(), FUN_a0146c40(3, 0, 0), FUN_a0146c40(4, 0, 0) and FUN_a00a82c4(), stores 0x3F in word
 * 0xA802AFEC, calls FUN_a00a9650(0, 1), FUN_a00a9468(2, 5), FUN_a00a9468(0, 0), FUN_a00a9468(1, 2),
 * FUN_a00b34d4(0, 1) and FUN_a00b344c(7), and sets bit 1 of byte 0xA802B08E. Returns p1.
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
extern unsigned char DAT_a802b08e;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a82c4();
extern int FUN_a00a8c88();
extern void FUN_a00a9468();
extern void FUN_a00a9650();
extern int FUN_a00b344c();
extern void FUN_a00b34d4();
extern void FUN_a0146c40();

int FUN_a0095984(undefined4 param_1,undefined4 param_2)

{
  FUN_a00a8c88();
  FUN_a0146c40(3,0,0);
  FUN_a0146c40(4,0,0);
  FUN_a00a82c4();
  _DAT_a802afec = 0x3f;
  FUN_a00a9650(0,1);
  FUN_a00a9468(2,5);
  FUN_a00a9468(0,0);
  FUN_a00a9468(1,2);
  FUN_a00b34d4(0,1);
  FUN_a00b344c(7);
  DAT_a802b08e = DAT_a802b08e | 2;
  return CONCAT44(param_2,param_1);
}