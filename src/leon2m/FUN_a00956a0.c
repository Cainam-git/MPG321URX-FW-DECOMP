/* leon2m FUN_a00956a0 @ 0xa00956a0 (-mcpu=v8 -O3 -g)
 * Calls FUN_a00a8c88(), FUN_a00a82c4() and FUN_a00ba184(1), stores 0x40 in word 0xA802AFEC, calls FUN_a00a9650(1,
 * 1), FUN_a00a9468(1, 2) and FUN_a00b34d4(0, 1), sets bit 1 of byte 0xA802B08E. Returns p1.
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
extern int FUN_a00a82c4();
extern int FUN_a00a8c88();
extern void FUN_a00a9468();
extern void FUN_a00a9650();
extern int FUN_a00b34d4();
extern int FUN_a00ba184();

int FUN_a00956a0(undefined4 param_1,undefined4 param_2)

{
  FUN_a00a8c88();
  FUN_a00a82c4();
  FUN_a00ba184(1);
  _DAT_a802afec = 0x40;
  FUN_a00a9650(1,1);
  FUN_a00a9468(1,2);
  FUN_a00b34d4(0,1);
  DAT_a802b08e = DAT_a802b08e | 2;
  return CONCAT44(param_2,param_1);
}