/* leon2m FUN_a009a2d0 @ 0xa009a2d0 (-mcpu=v8 -O3 -g)
 * Copies byte 0xA802D470 into byte 0xA8025C55, calls FUN_a00a93bc((word 0xA802AFEC + 0x45) & 0xff) and
 * FUN_a00ac718(0xbd), stores 0xF4 in word 0xA802AFEC, then calls FUN_a00a9650(b, 0) and FUN_a00a9650(b, 1, p3, p4,
 * p5, p6) with b = byte 0xA8025C55.
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
extern unsigned char DAT_a802d470;
extern unsigned int _DAT_a802afec;
extern int FUN_a00a93bc();
extern int FUN_a00a9650();
extern int FUN_a00ac718();

void FUN_a009a2d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  DAT_a8025c55 = DAT_a802d470;
  FUN_a00a93bc(_DAT_a802afec + 0x45U & 0xff);
  FUN_a00ac718(0xbd);
  _DAT_a802afec = 0xf4;
  FUN_a00a9650(DAT_a8025c55,0);
  FUN_a00a9650(DAT_a8025c55,1,param_3,param_4,param_5,param_6);
  return;
}