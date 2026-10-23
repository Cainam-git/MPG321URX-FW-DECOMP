/* leon2m FUN_a0093b04 @ 0xa0093b04 (-mcpu=v8 -O3 -g)
 * Calls FUN_a00a93bc(byte 0xA8025C55) and FUN_a00a813c(1, byte 0xA8025C55, 0); stores v = bits 4-7 of word
 * 0xA802D2C0 in byte 0xA8025C55, calls FUN_a00a9650(v, 1), FUN_a00a9468(1, 2) and FUN_a00b34d4(0, 1), stores 0x107
 * in word 0xA802AFEC and calls FUN_a0146dc0(0, 0, p3, p4, p5, p6).
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
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern unsigned int _DAT_a802d2c0;
extern void FUN_a00a813c();
extern int FUN_a00a93bc();
extern void FUN_a00a9468();
extern void FUN_a00a9650();
extern int FUN_a00b34d4();
extern int FUN_a0146dc0();

void FUN_a0093b04(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  uint uVar1;
  
  FUN_a00a93bc(DAT_a8025c55);
  FUN_a00a813c(1,DAT_a8025c55,0);
  uVar1 = _DAT_a802d2c0 >> 4 & 0xf;
  DAT_a8025c55 = (undefined1)uVar1;
  FUN_a00a9650(uVar1,1);
  FUN_a00a9468(1,2);
  FUN_a00b34d4(0,1);
  _DAT_a802afec = 0x107;
  FUN_a0146dc0(0,0,param_3,param_4,param_5,param_6);
  return;
}