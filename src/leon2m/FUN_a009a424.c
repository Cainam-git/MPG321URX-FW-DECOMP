/* leon2m FUN_a009a424 @ 0xa009a424 (-mcpu=v8 -O3 -g)
 * Calls FUN_a00a93bc(0), FUN_a00b7d14(0) and FUN_a00af44c(0x34, 3), stores 0xBF in word 0xA802AFEC, calls
 * FUN_a00a9650(4, 1), clears byte 0xA8025C55, calls FUN_a00dab20() and sets bit 1 of byte 0xA802B08E. Returns p1.
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
extern unsigned char DAT_a802b08e;
extern unsigned int _DAT_a802afec;
extern int FUN_a00a93bc();
extern void FUN_a00a9650();
extern void FUN_a00af44c();
extern int FUN_a00b7d14();
extern void FUN_a00dab20();

int FUN_a009a424(undefined4 param_1,undefined4 param_2)

{
  FUN_a00a93bc(0);
  FUN_a00b7d14(0);
  FUN_a00af44c(0x34,3);
  _DAT_a802afec = 0xbf;
  FUN_a00a9650(4,1);
  DAT_a8025c55 = 0;
  FUN_a00dab20();
  DAT_a802b08e = DAT_a802b08e | 2;
  return CONCAT44(param_2,param_1);
}