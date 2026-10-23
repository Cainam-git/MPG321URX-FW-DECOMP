/* leon2m FUN_a00b87d4 @ 0xa00b87d4 (-mcpu=v8 -O2 -g)
 * Code: FUN_a014512c(1, 0); (halfword 0xA802B092) = 0x72c; (halfword 0xA802B094) = 0; FUN_a00b7f9c(0x18, p2, p3, p4,
 * p5, p6).
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
extern unsigned short _DAT_a802b092;
extern unsigned short _DAT_a802b094;
extern int FUN_a00b7f9c();
extern int FUN_a014512c();

void FUN_a00b87d4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a014512c(1,0);
  _DAT_a802b092 = 0x72c;
  _DAT_a802b094 = 0;
  FUN_a00b7f9c(0x18,param_2,param_3,param_4,param_5,param_6);
  return;
}