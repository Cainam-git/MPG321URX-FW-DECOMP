/* leon2m FUN_a0099b18 @ 0xa0099b18 (-mcpu=v8 -O3 -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
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
extern unsigned char DAT_a802d33c;
extern unsigned int _DAT_a802afec;
extern int FUN_a00a93bc();
extern int FUN_a00a9650();
extern int FUN_a00ac0c4();

void FUN_a0099b18(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a00a93bc(_DAT_a802afec + 0x4fU & 0xff);
  FUN_a00ac0c4();
  DAT_a8025c55 = DAT_a802d33c;
  _DAT_a802afec = 0xf0;
  FUN_a00a9650(DAT_a802d33c,1,param_3,param_4,param_5,param_6);
  return;
}