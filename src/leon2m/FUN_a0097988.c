/* leon2m FUN_a0097988 @ 0xa0097988 (-mcpu=v8 -O3 -g)
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
extern unsigned char DAT_a802b08f;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a900c();
extern int FUN_a00a93bc();
extern void FUN_a00a9468();
extern int FUN_a00b34d4();

int FUN_a0097988(undefined4 param_1,undefined4 param_2)

{
  FUN_a00a93bc(_DAT_a802afec - 0x7aU & 0xff);
  FUN_a00a9468(1,2);
  _DAT_a802afec = 0x24;
  FUN_a00a900c(1,1);
  FUN_a00a9468(1,2);
  FUN_a00b34d4(0,1);
  DAT_a802b08f = 5;
  return CONCAT44(param_2,param_1);
}