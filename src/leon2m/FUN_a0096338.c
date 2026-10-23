/* leon2m FUN_a0096338 @ 0xa0096338 (-mcpu=v8 -O3 -g)
 * Code: FUN_a00a900c((word 0xA802AFEC) - 0x18U & 0xff, 2); (word 0xA802AFEC) = 0x69; FUN_a00b7054(1);
 * FUN_a00a9650(0, 1, p3, p4, p5, p6).
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
extern void FUN_a00a900c();
extern int FUN_a00a9650();
extern int FUN_a00b7054();

void FUN_a0096338(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a00a900c(_DAT_a802afec - 0x18U & 0xff,2);
  _DAT_a802afec = 0x69;
  FUN_a00b7054(1);
  FUN_a00a9650(0,1,param_3,param_4,param_5,param_6);
  return;
}