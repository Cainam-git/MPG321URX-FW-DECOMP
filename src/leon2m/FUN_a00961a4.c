/* leon2m FUN_a00961a4 @ 0xa00961a4 (-mcpu=v8 -O3 -g)
 * Code: FUN_a00b6d94(); FUN_a00aa258((word 0xA802AFEC) - 0x15U & 0xff, 1); FUN_a00d9764(p1, p2, p3, p4, p5, p6).
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
extern void FUN_a00aa258();
extern int FUN_a00b6d94();
extern int FUN_a00d9764();

void FUN_a00961a4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a00b6d94();
  FUN_a00aa258(_DAT_a802afec - 0x15U & 0xff,1);
  FUN_a00d9764(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}