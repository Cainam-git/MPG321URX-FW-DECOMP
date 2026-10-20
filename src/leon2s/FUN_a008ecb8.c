/* leon2s FUN_a008ecb8 @ 0xa008ecb8  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern void FUN_a008e098();
extern void FUN_a008e0f0();
extern void FUN_a008e200();
extern int FUN_a008e2c0();
extern int FUN_a008e3c0();
extern void FUN_a008e484();
extern int FUN_a008e73c();
extern void FUN_a00a80cc();

void FUN_a008ecb8(undefined1 param_1,char param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  unsigned char uVar1;
  
  FUN_a00a80cc(param_1,1,0x7d,0x80,1);
  FUN_a008e484(param_1,2);
  FUN_a008e098(param_1,0x1b);
  FUN_a008e0f0(param_1,3,0xb);
  FUN_a008e200(param_1,0x44);
  uVar1 = 0;
  if (1 < (byte)(param_2 - 1U)) {
    uVar1 = 0x30;
  }
  FUN_a008e3c0(param_1,uVar1);
  FUN_a008e73c(param_1,1);
  FUN_a008e2c0(param_1,3,2,param_4,param_5,param_6);
  return;
}