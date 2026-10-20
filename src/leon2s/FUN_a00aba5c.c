/* leon2s FUN_a00aba5c @ 0xa00aba5c  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern void FUN_a00a6c00();
extern void FUN_a00a6c98();
extern void FUN_a00a7058();

void FUN_a00aba5c(undefined1 param_1,undefined1 param_2,undefined1 param_3,uint param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a00a7058(param_1,0x3e,1,1);
  FUN_a00a6c00(param_1,0xf7,7);
  FUN_a00a6c00(param_1,0xf7,5);
  FUN_a00a6c98(param_1,0x20,1,1);
  FUN_a00a6c98(param_1,0x20,1,0);
  FUN_a00a6c98(param_1,0xf7,0x40,param_2);
  FUN_a00a6c98(param_1,0xf7,0x10,param_3);
  FUN_a00a6c98(param_1,0xf7,0x20,param_4 & 0xff);
  FUN_a00a6c98(param_1,0xf7,0x80,1);
  FUN_a00a6c00(param_1,0xf4,0xa0,param_4,param_5,param_6);
  return;
}