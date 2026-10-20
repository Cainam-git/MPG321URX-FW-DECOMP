/* leon2m FUN_a00e406c @ 0xa00e406c  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern void FUN_a00e05d8();
extern void FUN_a00e0774();
extern int FUN_a00e3f6c();

void FUN_a00e406c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a00e05d8(param_1,0x2c,0x60,0x60);
  FUN_a00e3f6c(param_1,param_2,param_3,param_4);
  FUN_a00e0774(param_1,0x2c,0x80,7,1);
  FUN_a00e0774(param_1,0x2c,0x80,7,0);
  FUN_a00e0774(param_1,0x2c,0x40,6,0);
  FUN_a00e3f6c(param_1,0,0,0,param_5,param_6);
  return;
}